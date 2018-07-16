
#include "stdafx.h"

typedef unsigned char uchar;
typedef unsigned int uint;

#define	YYCTYPE		uchar
#define	YYCURSOR	cursor
#define	YYLIMIT		s->lim
#define	YYMARKER	s->ptr

#define	RET(i)	{s->cur = cursor; return i;}
#define	RETT(i, typeid)	{s->cur = cursor; s->type = typeid; return i;}

class CMYMaterial
{
public:
  CMYMaterial() : shader(SHADER_Phong), uid(0), vcol(false), dbls(false), dif(0.8), amb(0.6), emi(0.0), spc(0.0), power(5.0), reflect(0.0), refract(1.0), proj_type(PROJTYPE_UV)
  {
    for(int i=0;i<4;i++)col[i]=1.0;
    for(int i=0;i<3;i++)
    {
      proj_scale[i]=1.0;
      proj_pos[i] = proj_angle[i] = amb_col[i] = emi_col[i] = spc_col[i] = 0;
    }
  }
public:
  CString name;
  enum SHADER {SHADER_Classic = 0, SHADER_Constant, SHADER_Lambert, SHADER_Phong, SHADER_Blinn } shader;
  uint uid;
  bool vcol;
  bool dbls; //double face
  double col[4];
  double dif;
  double amb;
  double amb_col[3];
  double emi;
  double emi_col[3];
  double spc;
  double spc_col[3];
  double power;
  double reflect;
  double refract;
  CString tex;
  CString aplane;
  CString bump;
  enum PROJTYPE {PROJTYPE_UV=0, PROJTYPE_PLANE, PROJTYPE_CYLINDER, PROJTYPE_SPHERE} proj_type;
  double proj_pos[3];
  double proj_scale[3];
  double proj_angle[3];
};

class CMYVertex
{
public:
  CMYVertex(double _x, double _y, double _z)
  {
    x = _x;
    y = _y;
    z = _z;
  }
	double x, y, z;
};

class CMYFace
{
public:
  CMYFace() : M(0), V(NULL), UV(NULL), COL(NULL)/*, N(NULL)*/
  {
  }
  ~CMYFace()
  {
    if(V)
    {
      delete V;
      V = NULL;
    }
    if(UV)
    {
      delete UV;
      UV = NULL;
    }
    if(COL)
    {
      delete COL;
      COL = NULL;
    }
/*    if(N)
    {
      delete N;
      N = NULL;
    }*/
  }
  CAtlArray<uint> *V;
  int M;
  CAtlArray<double> *UV;
  CAtlArray<COLORREF> *COL;
//  CAtlArray<double> *N;
//  CAtlArray<double> *CRS;
};

class CMYObject
{
public:
  CMYObject() : vertex(NULL), face(NULL), pFbxNode(NULL), vertexattrUID(NULL)
  {
  }
  ~CMYObject()
  {
    if(vertex)
    {
      size_t m=vertex->GetCount();;
      for(size_t i=0;i<m;i++)delete (*vertex)[i];
	  delete vertex;
      vertex = NULL;
    }
    if(face)
    {
      size_t m=face->GetCount();;
      for(size_t i=0;i<m;i++)delete (*face)[i];
	  delete face;
      face = NULL;
    }
    if(vertexattrUID)
    {
	  delete vertexattrUID;
      vertexattrUID = NULL;
    }
  }
  FbxNode *pFbxNode;
  CString name;
  int uid;
  int depth;
  bool folding;
  double scale[3];
  double rotation[3];
  double translation[3];
  //enum {PATCH_PLANE=0, PATCH_SPLINE1, PATCH_SPLINE2, PATCH_CATMULLCLARK, PATCH_OPENSUBDIV} patch;
  //bool patchtri;
  //int segment;
  bool visible;
  //bool locking;
  enum SHADING {SHADING_FLAT=0, SHADING_GLOW} shading;
  //double facet;
  double color[3];
  bool color_type;
  //enum MIRROR {MIRROR_NONE=0, MIRROR_SPLIT, MIRROR_CONNECT} mirror;
  //enum MIRRORAXIS {MIRRORAXIS_X=0, MIRRORAXIS_Y, MIRRORAXIS_Z} mirroraxis;
  //double mirror_dis;
  //bool lathe;
  //enum LATHEAXIS {LATHEAXIS_X=0, LATHEAXIS_Y, LATHEAXIS_Z} lathe_axis;
  //int lathe_seg;
  CAtlArray<CMYVertex*> *vertex;
  CAtlArray<CMYFace*> *face;
  CAtlArray<int> *vertexattrUID;
};

class CMYBone
{
  public:
    CMYBone() : parent(NULL), id(0), P(0), rtX(0), rtY(0), rtZ(0), tpX(0), tpY(0), tpZ(0), rotB(0), rotH(0), rotP(0), mvX(0), mvY(0), mvZ(0), scX(0), scY(0), scZ(0), fbxNode(NULL), isDummy(false)
    {
    }
    ~CMYBone()
    {
    }
    CMYBone *parent;
    CAtlArray<CMYBone*> childs;
    int id;
    CString name;
    FbxNode *fbxNode;
    
    int P;
    CAtlArray<int> C;
    CAtlArray<int> oi;
    CAtlArray<int> vi;
    CAtlArray<double> w;
    
    double rtX, rtY, rtZ;
    double tpX, tpY, tpZ;
    double rotB, rotH, rotP;
    double mvX, mvY, mvZ;
    double scX, scY, scZ;
    
    bool isDummy;
};

class CMYMQO
{
public:
  int m_currentMaterialIndex;
  CAtlArray<CMYMaterial*> m_materials;
  CAtlArray<CMYObject*> m_objects;
  CAtlArray<CMYBone> m_bones;
//  CAtlArray<int> m_boneObjIndex;
  
  CMYMQO() : m_currentMaterialIndex(-1)
  {
  }
  
  ~CMYMQO()
  {
    int s = m_materials.GetCount();
    for(int i=0;i<s;i++)
    {
      delete m_materials[i];
    }
    m_materials.RemoveAll();
  }
  
  void VisibleObjOnly()
  {
    int s = m_objects.GetCount();
    for(int i=s-1;i>=0;i--)
    {
      if(m_objects[i]->visible == false)
      {
        delete m_objects[i];
        m_objects.RemoveAt(i);
      }
    }
  }
  
  CMYMaterial* GetCurrentMaterial()
  {
    if(m_currentMaterialIndex==-1)
    {
      CMYMaterial *pMat = new CMYMaterial();
      if(pMat==NULL)return NULL;
      m_materials.Add(pMat);
      m_currentMaterialIndex = m_materials.GetCount()-1;
      return pMat;
    } else {
      return m_materials[m_currentMaterialIndex];
    }
  }
  CMYMaterial* ClearCurrentMaterial()
  {
    m_currentMaterialIndex = -1;
  }
  void AddMaterial(CMYMaterial *pMat)
  {
    m_materials.Add(pMat);
  }
  
  CMYBone *AddBone(const char *name)
  {
    int idx = m_bones.Add();
    m_bones[idx].name = name;
    return &(m_bones[idx]);
  }
  CMYBone *FindBone(int id)
  {
    int m = m_bones.GetCount();
    for(int i=0;i<m;i++)
    {
      if(m_bones[i].id==id)return &(m_bones[i]);
    }
    return NULL;
  }
};

class __CMyVertexAttr
{
public:
  __CMyVertexAttr() : uid(NULL)
  {
  }
  CAtlArray<int> *uid;
};

typedef struct PassData
{
  union {
    __int64 i;
    double dbl;
    CString *str;
  };
} PassData;

typedef struct Scanner
{
    int			fd;
    uchar		*bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
    uint		line;
    PassData val;
} Scanner;

/*enum {
 TAG_MetasequoiaDocument, TAG_FormatTextVer11, TAG_Thumbnail, TAG_IncludeXml, TAG_Scene, TAG_pos, TAG_lookat, TAG_head, TAG_pich, TAG_bank, TAG_ortho, TAG_zoom2, TAG_amb, TAG_frontclip, TAG_backclip, TAG_dirlights, TAG_light, TAG_dir, TAG_color, 
 TAG_Material, TAG_shader, TAG_vcol, TAG_dbls, TAG_col, TAG_uid, TAG_dif, TAG_amb, TAG_emi, TAG_spc, TAG_power, TAG_reflect, TAG_refract, TAG_tex, TAG_aplane, TAG_bump, TAG_proj_type, TAG_proj_pos, TAG_proj_scale, TAG_proj_angle, 
 TAG_Object, TAG_depth, TAG_folding, TAG_scale, TAG_rotation, TAG_translation, TAG_patch, TAG_patchtri, TAG_patchsmoothtri, TAG_patchlimitsurface, TAG_patchmeshinterp, TAG_patchuvinterp, TAG_segment, TAG_visible, TAG_locking, TAG_shading, TAG_facet, TAG_normal_weight, TAG_color, TAG_color_type, TAG_mirror, TAG_mirror_axis, TAG_mirror_dis, TAG_lathe, TAG_lathe_axis, TAG_lathe_seg, TAG_vertex, TAG_BVertex, TAG_vertexattr, TAG_weit, TAG_face, TAG_V, TAG_M, TAG_UID, TAG_UV, TAG_COL, TAG_N, TAG_CRS, TAG_Blob, 
 TAG_Eof};*/


#include "MQOParser.h"
#include "MQOParser.c"


CString ReadStr(uchar *token, uint len)
{
  CStringA tmpA;
  tmpA.SetString((const char *)token, len);
  CStringW tmpB = CA2W(tmpA, CP_UTF8);
  tmpB.Replace(L"%", L"%%");
  CString retStr;
  retStr.Format(tmpB);
  return retStr;
}

BOOL fill(int n) { return FALSE; }

int scan(Scanner *s){
	uchar *cursor = s->cur;
std:
	s->tok = cursor;
/*!re2c

re2c:define:YYFILL:naked = 1;
re2c:define:YYFILL@len = #;
re2c:define:YYFILL = "if(!fill(#)) { return 0; }";
re2c:yyfill:enable = 1;

any	= [\000-\xFF];
O	= [0-7];
D	= [0-9];
L	= [a-zA-Z_];
H	= [a-fA-F0-9];
ESC	= [\\] ([abfnrtv?'"\\] | "x" H+ | O+);
*/

/*!re2c
	
	"Metasequoia Document" { RET(TAG_MetasequoiaDocument); }
	"Format Text Ver 1.1" { RET(TAG_FormatTextVer11); }
	"Thumbnail" { goto brskip; }
  "IncludeXml" { RET(TAG_IncludeXml); }
  "Scene" { goto brskip; }
  "BackImage" { goto brskip; }
  "Blob" { goto brskip; }
//  "pos" { RET(TAG_pos); }
//  "lookat" { RET(TAG_lookat); }
//  "head" { RET(TAG_head); }
//  "pich" { RET(TAG_pich); }
//  "bank" { RET(TAG_bank); }
//  "ortho" { RET(TAG_ortho); }
//  "zoom2" { RET(TAG_zoom2); }
//  "amb" { RET(TAG_amb); }
//  "frontclip" { RET(TAG_frontclip); }
//  "backclip" { RET(TAG_backclip); }
//  "dirlights" { RET(TAG_dirlights); }
//  "light" { RET(TAG_light); }
//  "dir" { RET(TAG_dir); }
  "color" { RET(TAG_color); }
  
  "Material" { RET(TAG_Material); }
  "MaterialEx" { goto brskip; }
  "shader" { RET(TAG_shader); }
  "vcol" { RET(TAG_vcol); }
  "dbls" { RET(TAG_dbls); }
  "col" { RET(TAG_col); }
  "uid" { RET(TAG_uid); }
  "dif" { RET(TAG_dif); }
  "amb" { RET(TAG_amb); }
  "emi" { RET(TAG_emi); }
  "spc" { RET(TAG_spc); }
  "amb_col" { RET(TAG_amb_col); }
  "emi_col" { RET(TAG_emi_col); }
  "spc_col" { RET(TAG_spc_col); }
  "power" { RET(TAG_power); }
  "reflect"	{ RET(TAG_reflect); }
  "refract"	{ RET(TAG_refract); }
  "tex"	{ RET(TAG_tex); }
  "aplane"	{ RET(TAG_aplane); }
  "bump"	{ RET(TAG_bump); }
  "proj_type"	{ RET(TAG_proj_type); }
  "proj_pos"	{ RET(TAG_proj_pos); }
  "proj_scale"	{ RET(TAG_proj_scale); }
  "proj_angle"	{ RET(TAG_proj_angle); }
  
  "Object"	{ RET(TAG_Object); }
  "depth"	{ RET(TAG_depth); }
  "folding"	{ RET(TAG_folding); }
  "scale"	{ RET(TAG_scale); }
  "rotation"	{ RET(TAG_rotation); }
  "translation"	{ RET(TAG_translation); }
  "patch"	{ RET(TAG_patch); }
  "patchtri"	{ RET(TAG_patchtri); }
  "patchsmoothtri"	{ RET(TAG_patchsmoothtri); }
  "patchlimitsurface"	{ RET(TAG_patchlimitsurface); }
  "patchmeshinterp"	{ RET(TAG_patchmeshinterp); }
  "patchuvinterp"	{ RET(TAG_patchuvinterp); }
  "segment"	{ RET(TAG_segment); }
  "visible"	{ RET(TAG_visible); }
  "locking"	{ RET(TAG_locking); }
  "shading"	{ RET(TAG_shading); }
  "facet"	{ RET(TAG_facet); }
  "normal_weight" { RET(TAG_normal_weight) }
  "color"	{ RET(TAG_color); }
  "color_type"	{ RET(TAG_color_type); }
  "mirror"	{ RET(TAG_mirror); }
  "mirror_axis"	{ RET(TAG_mirror_axis); }
  "mirror_dis"	{ RET(TAG_mirror_dis); }
  "lathe"	{ RET(TAG_lathe); }
  "lathe_axis"	{ RET(TAG_lathe_axis); }
  "lathe_seg"	{ RET(TAG_lathe_seg); }
  "vertex"	{ RET(TAG_vertex); }
  "BVertex"	{ goto brskip; }
  "vertexattr"	{ RET(TAG_vertexattr); }
  "weit"	{ RET(TAG_weit); }
  "face"	{ RET(TAG_face); }
  "V"	{ RET(TAG_V); }
  "M"	{ RET(TAG_M); }
  "UID"	{ RET(TAG_UID); }
  "UV"	{ RET(TAG_UV); }
  "COL"	{ RET(TAG_COL); }
  "N"	{ RET(TAG_N); }
  "CRS"	{ RET(TAG_CRS); }
  "Blob"	{ RET(TAG_Blob); }
  
  "Eof"	{ RET(TAG_Eof); }
	
	[+-]? [ \t]* ((D+) [\.] (D*) | (D*) [\.] (D+))	{ uchar *start = s->tok;
				bool bMinus = false;
				if(*start == '-')bMinus = true;
				while(!((*start>='0' && *start<='9') || *start=='.'))start++;
				CStringA tmp;
				tmp.SetString((const char *)(start), cursor - start);
				s->val.dbl = bMinus ? -atof(tmp) : atof(tmp);
				RET(DBLVAL); }
	
	[+-]? [ \t]* (D+)	{ uchar *start = s->tok;
				bool bMinus = false;
				if(*start == '-')bMinus = true;
				while(*start<'0' || *start>'9')start++;
				CStringA tmp;
				tmp.SetString((const char *)(start), cursor - start);
				s->val.i = bMinus ? -_atoi64(tmp) : _atoi64(tmp);
				RET(INTVAL); }
	
	(["] (ESC|any\[\n\"])* ["])
				{ s->val.str = new CString(); *(s->val.str) = ReadStr(s->tok + 1, cursor - s->tok -2); RET(STRVAL); }
	
	"("			{ RET(BR3); }
	")"			{ RET(BR4); }
//	"."			{ RET('.'); }
	"{"			{ RET(BR1); }
	"}"			{ RET(BR2); }
//	","			{ RET(COMMA); }
	[\x1a]			{ RET(0);/*EOF*/ }


	[ \t\v\f]+		{ if(cursor == s->eof)RET(0); goto std; }

	([\n]|[\r]|[\r][\n]) {
    if(cursor == s->eof)RET(0);
    s->pos = cursor; s->line++;
    goto std;
  }

	any {
    ATLTRACE("unexpected character: %c\n", *s->tok);
    goto std;
  }
*/

brskip:
  {
    int cntBr = 0;
brskip2:
/*!re2c
  "{"  { if(cursor == s->eof)RET(0); cntBr++; goto brskip2; }
	"}"  { if(cursor == s->eof || cursor+1 == s->eof)RET(0); cntBr--; if(cntBr<=0)goto std; }
	"\n"  { if(cursor == s->eof) RET(0); s->tok = s->pos = cursor; s->line++; goto brskip2; }
  any   { if(cursor == s->eof)RET(0); goto brskip2; }
*/
  }
}