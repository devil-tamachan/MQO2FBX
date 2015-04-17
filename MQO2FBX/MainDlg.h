/*
licenced by New BSD License

Copyright (c) 2014, devil.tamachan@gmail.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

//#define ENABLE_SHELLEXECUTEBUG
#include "Mqo.cpp"
#include "ReadFile.cpp"


#include <Common/Common.cxx>//fbxsdk

class CMainDlg : public CDialogImpl<CMainDlg>, public CDialogResize<CMainDlg>, public CIdleHandler
{
public:
	enum { IDD = IDD_MAINDLG };

  CListViewCtrl m_list_files;

  CMainDlg()
  {
  }

  void SetStatusText(int idx, LPCTSTR status)
  {
    m_list_files.SetItemText(idx, 1, status);
    m_list_files.UpdateWindow();
  }
  void SetRunning(int idx)
  {
    SetStatusText(idx, _T("-"));
  }
  void SetSuccess(int idx)
  {
    SetStatusText(idx, _T("OK"));
  }
  void SetFail(int idx)
  {
    SetStatusText(idx, _T("!"));
  }


  virtual BOOL OnIdle()
  {
    
    //GetExitCodeProcess
    return FALSE;
  }

  BEGIN_DLGRESIZE_MAP(CMainDlg)
    DLGRESIZE_CONTROL(IDL_FILES, DLSZ_SIZE_X | DLSZ_SIZE_Y)
    DLGRESIZE_CONTROL(IDB_CLEAR, DLSZ_MOVE_X)
  END_DLGRESIZE_MAP()

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    MSG_WM_SIZE(OnSize)
    MSG_WM_CLOSE(OnClose)
    MSG_WM_DESTROY(OnDestroy)
    MSG_WM_DROPFILES(OnDropFiles)
		//COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		//COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    CHAIN_MSG_MAP(CDialogResize<CMainDlg>)
	END_MSG_MAP()

  void OnDestroy()
  {
    CMessageLoop* pLoop = _Module.GetMessageLoop();
    pLoop->RemoveIdleHandler(this);
    SetMsgHandled(FALSE);
  }

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		// center the dialog on the screen
		CenterWindow();

		// set icons
		HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
		SetIcon(hIcon, TRUE);
		HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
		SetIcon(hIconSmall, FALSE);

    m_list_files = GetDlgItem(IDL_FILES);
    m_list_files.SetExtendedListViewStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    m_list_files.InsertColumn(0, _T("Path"), LVCFMT_LEFT, 250);
    m_list_files.InsertColumn(1, _T("Result"), LVCFMT_LEFT, 50);

    DragAcceptFiles();

    DlgResize_Init(true, true, WS_THICKFRAME | WS_MAXIMIZEBOX | WS_CLIPCHILDREN);

    CMessageLoop* pLoop = _Module.GetMessageLoop();
    pLoop->AddIdleHandler(this);

    
    int numArgs = 0;
    LPWSTR *lpArgv = CommandLineToArgvW(GetCommandLineW(), &numArgs);
    for(int i=1; i<numArgs; i++)AddPath(lpArgv[i]);

		return TRUE;
	}

  void OnSize(UINT nType, CSize size)
  {
    int newWidth = size.cx - 80;
    m_list_files.SetColumnWidth(0, newWidth);
    SetMsgHandled(FALSE);
  }

  void AddDir(LPCTSTR _dirpath)
  {
    CFindFile finder;

    CString dirpath(_dirpath);
    PathAddBackslash(dirpath.GetBuffer(dirpath.GetLength()+2));
    dirpath.ReleaseBuffer();
    dirpath += _T("*");

    BOOL bWorking = finder.FindFile(dirpath);

    while (bWorking)
    {
      bWorking = finder.FindNextFile();
      CString file = finder.GetFilePath();
      if (finder.IsDots())continue;
      else if (finder.IsDirectory())AddDir(file);
      else if(IsMqoExt(file))AddMqo(file);
    }
   finder.Close();
  }
  

  
HRESULT LoadFromFile(LPCTSTR path)
{
  DWORD len=0, lenPlusSpace=0;
  unsigned char *pFile = (unsigned char *)ReadFile(path, &len, &lenPlusSpace, 30, TRUE, FALSE);
  if(pFile==NULL)return E_FAIL;
  void *pParser = ParseAlloc(malloc);
  unsigned int type = 0;
  Scanner s = {0};
  s.cur = pFile;
  s.lim = pFile+lenPlusSpace;
  s.eof = pFile+len;

#ifdef _DEBUG
//  FILE *fpErr = fopen("err.txt", "w");
//  ParseTrace(fpErr, (char*)"LP: ");
#endif

  CMYMQO mqo;

  while(type = scan(&s))
  {
    //ATLTRACE("type = %d\n", type);
    Parse(pParser, type, s.val, &mqo);
  }
  ATLTRACE("ParseTerminate\n", type);
  Parse(pParser, 0, s.val, &mqo);
  ParseFree(pParser, free);
  delete pFile;

  for(size_t i=0;i<mqo.m_materials.GetCount();i++)
  {
    CMYMaterial *m = mqo.m_materials[i];
    ATLTRACE(_T("Material %s:\n"), m->name);
    ATLTRACE("   shader: %d\n", m->shader);
    ATLTRACE("   uid: %u\n", m->uid);
    ATLTRACE("   vcol: %s\n", m->vcol ? "true" : "false");
    ATLTRACE("   dbls: %s\n", m->vcol ? "true" : "false");
    ATLTRACE("   col: %lf,%lf,%lf,%lf\n", m->col[0], m->col[1], m->col[2], m->col[3]);
    ATLTRACE("   dif: %f\n", m->dif);
    ATLTRACE("   amb: %f\n", m->amb);
    ATLTRACE("   emi: %f\n", m->emi);
    ATLTRACE("   spc: %f\n", m->spc);
    ATLTRACE("   power: %f\n", m->power);
    ATLTRACE("   reflect: %f\n", m->reflect);
    ATLTRACE("   refract: %f\n", m->refract);
    ATLTRACE(_T("   tex: %s\n"), m->tex);
    ATLTRACE(_T("   aplane: %s\n"), m->aplane);
    ATLTRACE(_T("   bump: %s\n"), m->bump);
    ATLTRACE("   proj_type: %d\n", m->proj_type);
    ATLTRACE("   proj_pos: %f,%f,%f\n", m->proj_pos[0], m->proj_pos[1], m->proj_pos[2]);
    ATLTRACE("   proj_scale: %f,%f,%f\n", m->proj_scale[0], m->proj_scale[1], m->proj_scale[2]);
    ATLTRACE("   proj_angle: %f,%f,%f\n", m->proj_angle[0], m->proj_angle[1], m->proj_angle[2]);
  }

  CPath mqxpath(path);
  mqxpath.RenameExtension(_T(".mqx"));
  /*if(mqxpath.FileExists())*/ParseMqx(mqxpath, &mqo);
  
  CPath fbxpath(path);
  fbxpath.RenameExtension(_T(".fbx"));
  WriteFBX(fbxpath, &mqo);

  return S_OK;
}

  void ParseMqx(LPCTSTR pathMqx, CMYMQO *mqo)
  {
    tinyxml2::XMLDocument xml;
    FILE *fp = NULL;
    if(_tfopen_s(&fp, pathMqx, _T("rb"))!=0)return;
    xml.LoadFile(fp);

    tinyxml2::XMLElement* MetasequoiaDocument = xml.FirstChildElement("MetasequoiaDocument");
    tinyxml2::XMLElement* BonePlugin = MetasequoiaDocument->FirstChildElement("Plugin.56A31D20.71F282AB");
    tinyxml2::XMLElement* BoneSet = BonePlugin->FirstChildElement("BoneSet");
    for(tinyxml2::XMLElement* Bone = BoneSet->FirstChildElement("Bone"); Bone!=NULL; Bone = Bone->NextSiblingElement("Bone"))
    {
      const char *boneName = Bone->Attribute("name");
      if(boneName==NULL)continue;
      CMYBone *pBone = mqo->AddBone(boneName);

      int bid=0;
      if(Bone->QueryIntAttribute("id", &bid)==tinyxml2::XML_NO_ERROR)pBone->id = bid;

      double dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rtX", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rtX = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rtY", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rtY = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rtZ", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rtZ = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("tpX", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->tpX = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("tpY", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->tpY = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("tpZ", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->tpZ = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rotB", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rotB = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rotH", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rotH = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("rotP", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->rotP = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("mvX", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->mvX = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("mvY", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->mvY = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("mvZ", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->mvZ = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("scX", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->scX = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("scY", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->scY = dTmp;
      dTmp=0.0;
      if(Bone->QueryDoubleAttribute("scZ", &dTmp)==tinyxml2::XML_NO_ERROR)pBone->scZ = dTmp;

      tinyxml2::XMLElement* P = Bone->FirstChildElement("P");
      if(P!=NULL)
      {
        int id=0;
        if(P->QueryIntAttribute("id", &id)==tinyxml2::XML_NO_ERROR)pBone->P = id;
      }
      for(tinyxml2::XMLElement* C = Bone->FirstChildElement("C"); C!=NULL; C = C->NextSiblingElement("C"))
      {
        int id=0;
        if(C->QueryIntAttribute("id", &id)==tinyxml2::XML_NO_ERROR)pBone->C.Add(id);
      }
/*      for(tinyxml2::XMLElement* B = Bone->FirstChildElement("B"); B!=NULL; B = B->NextSiblingElement("B"))
      {
      }*/
      for(tinyxml2::XMLElement* W = Bone->FirstChildElement("W"); W!=NULL; W = W->NextSiblingElement("W"))
      {
        int oi=0;
        W->QueryIntAttribute("oi", &oi);
        pBone->oi.Add(oi);
        int vi=0;
        W->QueryIntAttribute("vi", &vi);
        pBone->vi.Add(vi);
        double w=0;
        W->QueryDoubleAttribute("w", &w);
        pBone->w.Add(w);
      }
    }
/*    mqo->m_boneObjIndex.Add(0);
    for(tinyxml2::XMLElement* Obj = BoneSet->FirstChildElement("Obj"); Obj!=NULL; Obj = Obj->NextSiblingElement("Obj"))
    {
      int id=0;
      Obj->QueryIntAttribute("id", &id);
      mqo->m_boneObjIndex.Add(id);
    }*/

    fclose(fp);

    int m = mqo->m_bones.GetCount();
    for(int i=0;i<m;i++)
    {
      CMYBone *b = &(mqo->m_bones[i]);
      int cm = b->C.GetCount();
      for(int j=0;j<cm;j++)
      {
        CMYBone *child = mqo->FindBone(b->C[j]);
        if(child!=NULL)
        {
          b->childs.Add(child);
          child->parent = b;
        }
      }
    }
  }
  HRESULT WriteFBX(LPCTSTR pathfbx, CMYMQO *mqo)
  {
    FbxManager* pManager = NULL;
    FbxScene* lScene = NULL;

    InitializeSdkObjects(pManager, lScene);

    if(FAILED(CreateScene(pManager, lScene, mqo)))
    {
        DestroySdkObjects(pManager, false);
        return E_FAIL;
    }

    FbxExporter* lExporter = FbxExporter::Create(pManager, "");
//#undef IOS_REF
//	#define IOS_REF (*(lSdkManager->GetIOSettings()))
    IOS_REF.SetBoolProp(EXP_FBX_MATERIAL,        true);
    IOS_REF.SetBoolProp(EXP_FBX_TEXTURE,         true);
    IOS_REF.SetBoolProp(EXP_FBX_SHAPE,           true);
    IOS_REF.SetBoolProp(EXP_FBX_GOBO,            true);
    IOS_REF.SetBoolProp(EXP_FBX_ANIMATION,       false);
    IOS_REF.SetBoolProp(EXP_FBX_GLOBAL_SETTINGS, true);
    IOS_REF.SetBoolProp(EXP_ASCIIFBX, false);

    lExporter->Initialize(CW2A(pathfbx, CP_UTF8), -1, pManager->GetIOSettings());
    lExporter->Export(lScene);
    lExporter->Destroy();

    DestroySdkObjects(pManager, true);
    return S_OK;
  }
  HRESULT CreateScene(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo)
  {
    
    CreateSkelton(pSdkManager, pScene, mqo);
    int m = mqo->m_objects.GetCount();
    for(int i=0;i<m;i++)
    {
      CreateObject(pSdkManager, pScene, mqo, mqo->m_objects[i]);
    }
    CreateWeight(pSdkManager, pScene, mqo);

    return S_OK;
  }
  HRESULT CreateMaterial(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo, CMYMaterial *mat, FbxNode* lMeshNode)
  {
    switch(mat->shader)
    {
    case CMYMaterial::SHADER_Constant:
      {
        FbxString lShadingName = "Lambert";
        FbxDouble3 lBlack(0.0, 0.0, 0.0);
        FbxDouble3 lRed(1.0, 0.0, 0.0);
        FbxDouble3 lColor;
        FbxSurfaceLambert *lMaterial = FbxSurfaceLambert::Create(pScene, CW2A(mat->name, CP_UTF8));
        
        lMaterial->DiffuseFactor.Set(1.0);
        lMaterial->EmissiveFactor.Set(1.0);
        lMaterial->AmbientFactor.Set(0.0);
        lMaterial->Diffuse.Set(FbxDouble3(mat->col[0], mat->col[1], mat->col[2]));
        lMaterial->TransparencyFactor.Set(mat->col[3]);
        lMaterial->ShadingModel.Set(lShadingName);
        //lMaterial->SpecularFactor.Set(mat->spc);
        
        lMeshNode->AddMaterial(lMaterial);
      }
      break;
    case CMYMaterial::SHADER_Classic:
    case CMYMaterial::SHADER_Lambert:
      {
        FbxString lShadingName = "Lambert";
        FbxDouble3 lBlack(0.0, 0.0, 0.0);
        FbxDouble3 lRed(1.0, 0.0, 0.0);
        FbxDouble3 lColor;
        FbxSurfaceLambert *lMaterial = FbxSurfaceLambert::Create(pScene, CW2A(mat->name, CP_UTF8));
        
        lMaterial->DiffuseFactor.Set(mat->dif);
        lMaterial->EmissiveFactor.Set(mat->emi);
        lMaterial->AmbientFactor.Set(mat->amb);
        lMaterial->Diffuse.Set(FbxDouble3(mat->col[0], mat->col[1], mat->col[2]));
        lMaterial->TransparencyFactor.Set(mat->col[3]);
        lMaterial->ShadingModel.Set(lShadingName);
        //lMaterial->SpecularFactor.Set(mat->spc);
        
        lMeshNode->AddMaterial(lMaterial);
      }
      break;
    case CMYMaterial::SHADER_Phong:
    case CMYMaterial::SHADER_Blinn:
    //case CMYMaterial::SHADER_PMD:
      {
        FbxString lShadingName = "Phong";
        FbxSurfacePhong *lMaterial = FbxSurfacePhong::Create(pScene, CW2A(mat->name, CP_UTF8));

        lMaterial->EmissiveFactor.Set(mat->emi);
        lMaterial->AmbientFactor.Set(mat->amb);
        lMaterial->Diffuse.Set(FbxDouble3(mat->col[0], mat->col[1], mat->col[2]));
        lMaterial->TransparencyFactor.Set(mat->col[3]);
        lMaterial->ShadingModel.Set(lShadingName);
        lMaterial->SpecularFactor.Set(mat->spc);
        lMaterial->Shininess.Set(mat->power);
        lMaterial->ReflectionFactor.Set(mat->reflect);

        
        lMeshNode->AddMaterial(lMaterial);
      }
      break;
    }
    return S_OK;
  }
  HRESULT CreateSkelton(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo)
  {
    FbxSkeleton* lSkeletonAttribute = FbxSkeleton::Create(pScene, CW2A(CString(L"SkeltonRoot"), CP_UTF8));
    lSkeletonAttribute->SetSkeletonType(FbxSkeleton::eRoot);
    FbxNode* lSkeleton = FbxNode::Create(pScene, CW2A(CString(L"SkeltonRoot"), CP_UTF8));
    lSkeleton->SetNodeAttribute(lSkeletonAttribute);
    lSkeleton->LclTranslation.Set(FbxVector4(0.0, 0.0, 0.0));
    lSkeleton->LclRotation.Set(FbxDouble3(0.0,0.0,0.0));
    lSkeleton->LclScaling.Set(FbxDouble3(1.0,1.0,1.0));
    FbxNode* lRootNode = pScene->GetRootNode();
    lRootNode->AddChild(lSkeleton);

    int m = mqo->m_bones.GetCount();
    for(int i=0;i<m;i++)
    {
      CMYBone &bone = mqo->m_bones[i];
      if(bone.parent)continue;
      FbxSkeleton* lSkeletonAttribute2 = FbxSkeleton::Create(pScene, CW2A(CString(L"Skelton")+bone.name, CP_UTF8));
      lSkeletonAttribute2->SetSkeletonType(FbxSkeleton::eRoot);
      FbxNode* lSkeleton2 = FbxNode::Create(pScene, CW2A(CString(L"Skelton")+bone.name, CP_UTF8));
      lSkeleton2->SetNodeAttribute(lSkeletonAttribute2);    
      lSkeleton2->LclTranslation.Set(FbxDouble3(bone.rtX, bone.rtY, bone.rtZ));
      bone.fbxNode = lSkeleton2;
      __CreateChildSkelton(pSdkManager, pScene, mqo, bone, lSkeleton2);
      lSkeleton->AddChild(lSkeleton2);
    }
    return S_OK;
  }
  HRESULT __CreateChildSkelton(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo, CMYBone &parentBone, FbxNode* lParentSkeleton)
  {
    int m = parentBone.childs.GetCount();
    for(int i=0;i<m;i++)
    {
      CMYBone* child = parentBone.childs[i];
      FbxSkeleton* lSkeletonAttribute = FbxSkeleton::Create(pScene, CW2A(CString(L"Skelton")+child->name, CP_UTF8));
      lSkeletonAttribute->SetSkeletonType(FbxSkeleton::eLimbNode);
      lSkeletonAttribute->Size.Set(1.0);
      FbxNode* lSkeleton = FbxNode::Create(pScene, CW2A(CString(L"Skelton")+child->name, CP_UTF8));
      lSkeleton->SetNodeAttribute(lSkeletonAttribute);    
      lSkeleton->LclTranslation.Set(FbxDouble3(child->rtX - parentBone.rtX, child->rtY - parentBone.rtY, child->rtZ - parentBone.rtZ));
      child->fbxNode = lSkeleton;
      __CreateChildSkelton(pSdkManager, pScene, mqo, *child, lSkeleton);
      lParentSkeleton->AddChild(lSkeleton);
    }
    return S_OK;
  }
  HRESULT CreateObject(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo, CMYObject *obj)
  {
    if(obj->vertex==NULL || !obj->vertex->GetCount())return S_OK;
    FbxMesh* lMesh = FbxMesh::Create(pScene, CW2A(obj->name, CP_UTF8));

    {
      CAtlArray<CMYVertex*> *vertex = obj->vertex;
      int vm = vertex->GetCount();
      if(vm==0)return E_FAIL;

      lMesh->InitControlPoints(vm);
      FbxVector4* lControlPoints = lMesh->GetControlPoints();

      for(int i=0;i<vm;i++)
      {
        CMYVertex *v = (*vertex)[i];
        lControlPoints[i] = FbxVector4(v->x, v->y, v->z);
      }
    }
    
    FbxGeometryElementUV* lUVDiffuseElement = lMesh->CreateElementUV("DiffuseUV");
    lUVDiffuseElement->SetMappingMode(FbxGeometryElement::eByPolygonVertex);
    lUVDiffuseElement->SetReferenceMode(FbxGeometryElement::eIndexToDirect);

    FbxGeometryElementMaterial* lMaterialElement = lMesh->CreateElementMaterial();
    lMaterialElement->SetMappingMode(FbxGeometryElement::eByPolygon);
    lMaterialElement->SetReferenceMode(FbxGeometryElement::eIndexToDirect);

    {
      if(obj->face==NULL)return E_FAIL;
      CAtlArray<CMYFace*> *faces = obj->face;
      int fm = faces->GetCount();
      if(fm==0)return E_FAIL;

      for(int i=0;i<fm;i++)
      {
        CMYFace *f = (*faces)[i];
        lMesh->BeginPolygon(f->M);
        CAtlArray<uint> &V = *(f->V);
        size_t Vmax = V.GetCount();
        CAtlArray<double> *pUV = (f->UV);
        ATLASSERT(!pUV || Vmax*2 == pUV->GetCount());

        if(Vmax>=1)
        {
          for(size_t j = Vmax-1; j != SIZE_MAX; j--)
          {
            lMesh->AddPolygon(V[j]);
            lUVDiffuseElement->GetIndexArray().Add(pUV ? lUVDiffuseElement->GetDirectArray().Add(FbxVector2( ((*pUV)[j*2]), 1.0-((*pUV)[j*2+1]) )) : 0 );
          }
        }

        lMesh->EndPolygon();
      }
    }
    FbxNode* lNode = FbxNode::Create(pScene,CW2A(obj->name, CP_UTF8));
    obj->pFbxNode = lNode;

    lNode->SetNodeAttribute(lMesh);

    FbxNode* lRootNode = pScene->GetRootNode();
    lRootNode->AddChild(lNode);

    int m = mqo->m_materials.GetCount();
    for(int i=0;i<m;i++)
    {
      CreateMaterial(pSdkManager, pScene, mqo, mqo->m_materials[i], lNode);
    }
    return S_OK;
  }

  int _SearchObjIndex(CAtlArray<CMYObject*> &objects, int oi)
  {
    int objCnt = objects.GetCount();
    for(int i=0;i<objCnt;i++)
    {
      if(objects[i]->uid==oi)return i+1;
    }
    return 0;
  }
  size_t _ConvertVIDtoVIdx(CAtlArray<int> *pVertexAttrUID, int vid)
  {
    if(pVertexAttrUID==NULL)return vid-1;
    CAtlArray<int> &vertexAttrUID = *pVertexAttrUID;
    size_t vidMax = pVertexAttrUID->GetCount();
    for(size_t i=0;i<vidMax; i++)
    {
      if(vertexAttrUID[i]==vid)return i;
    }
    return 0;
  }

  HRESULT CreateWeight(FbxManager *pSdkManager, FbxScene* pScene, CMYMQO *mqo)
  {
    FbxAMatrix lXMatrix;
    CAtlArray<FbxSkin*> skins;
    skins.Add(NULL);
    int objCnt = mqo->m_objects.GetCount();
    for(int i=0;i<objCnt;i++)skins.Add(NULL);

    int m = mqo->m_bones.GetCount();
    for(int i=0;i<m;i++)
    {
      CMYBone &bone = (mqo->m_bones)[i];

      CAtlArray<FbxCluster*> clu;
      clu.Add(NULL);
      for(int j=0;j<objCnt;j++)clu.Add(NULL);

      ATLASSERT(bone.vi.GetCount() == bone.oi.GetCount() && bone.vi.GetCount() == bone.w.GetCount());
      size_t len = bone.vi.GetCount();
      for(size_t j=0;j<len;j++)
      {
        size_t oi = bone.oi[j];
        int objIndex = _SearchObjIndex(mqo->m_objects, oi);
        ATLASSERT(objIndex>=1);
        CMYObject *curObj = mqo->m_objects[objIndex-1];
        FbxSkin *pSkin = skins[objIndex];
        if(pSkin==NULL)
        {
          pSkin = FbxSkin::Create(pScene, CW2A(CString(L"Skin")+curObj->name, CP_UTF8));
          skins[objIndex] = pSkin;
        }

        FbxCluster *pCluster = clu[objIndex];
        if(pCluster==NULL)
        {
          CString cluName(L"Cluster");
          cluName += curObj->name;
          cluName.AppendFormat(L"%d",i);
          pCluster = FbxCluster::Create(pScene,CW2A(cluName, CP_UTF8));
          pCluster->SetLink(bone.fbxNode);
          pCluster->SetLinkMode(FbxCluster::eTotalOne);
          clu[objIndex] = pCluster;
        }
        size_t vidx = _ConvertVIDtoVIdx(curObj->vertexattrUID, bone.vi[j]);
        pCluster->AddControlPointIndex(vidx, bone.w[j]/100.0);
      }
      for(int j=1;j<=objCnt;j++)
      {
        FbxCluster *pCluster = clu[j];
        if(pCluster!=NULL)
        {
          FbxNode *pFbxNode = mqo->m_objects[j-1]->pFbxNode;
          FbxScene* lScene = pFbxNode->GetScene();
          if(lScene)
            lXMatrix = pFbxNode->EvaluateGlobalTransform();
          pCluster->SetTransformMatrix(lXMatrix);

          FbxNode *pBoneNode = bone.fbxNode;
          if(lScene)
            lXMatrix = pBoneNode->EvaluateGlobalTransform();
          pCluster->SetTransformLinkMatrix(lXMatrix);

          FbxSkin *pSkin = skins[j];
          pSkin->AddCluster(pCluster);
        }
      }
    }
    for(int j=1;j<=objCnt;j++)
    {
      FbxSkin *pSkin = skins[j];
      if(pSkin!=NULL)
      {
        FbxNode *pFbxNode = mqo->m_objects[j-1]->pFbxNode;
        FbxGeometry *pFbxGeo = (FbxGeometry*)(pFbxNode->GetNodeAttribute());
        pFbxGeo->AddDeformer(pSkin);
      }
    }
    return S_OK;
  }

  void AddMqo(LPCTSTR path)
  {
    m_list_files.InsertItem(0, path);
    if(SUCCEEDED(LoadFromFile(path)))SetSuccess(0);
    else SetFail(0);
  }

  BOOL IsMqoExt(LPCTSTR path)
  {
    CString ext = PathFindExtension(path);
    if(ext.CompareNoCase(_T(".mqo"))==0)return TRUE;
    return FALSE;
  }
  
  void AddPath(LPCTSTR path)
  {
    if(PathIsDirectory(path))AddDir(path);
    else if(PathFileExists(path))
    {
      if(IsMqoExt(path))AddMqo(path);
    }
  }

  void OnDropFiles(HDROP hDropInfo)
  {
    unsigned int numFile = ::DragQueryFile(hDropInfo, -1, NULL, 0);
    for(unsigned int i=0; i<numFile; i++)
    {
      CString path;
      ::DragQueryFile(hDropInfo, i, path.GetBuffer(1024+2), 1024);
      path.ReleaseBuffer();
      AddPath(path);
    }
    ::DragFinish(hDropInfo);
  }

  
	//LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	//{
//		CSimpleDialog<IDD_ABOUTBOX, FALSE> dlg;
//		dlg.DoModal();
//		return 0;
//	}
//
  void OnClose()
  {
    DestroyWindow();
    ::PostQuitMessage(0);
  }
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
    DestroyWindow();
    ::PostQuitMessage(wID);
		return 0;
	}

//	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	{
//		EndDialog(wID);
//		return 0;
//	}
};
