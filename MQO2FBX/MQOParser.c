/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 25 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"

//#include "stdafx.h"
#define assert ATLASSERT
#line 12 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 90
#define YYACTIONTYPE unsigned short int
#define ParseTOKENTYPE PassData
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  CMYMaterial* yy3;
  CAtlArray<CMYFace*>* yy8;
  __int64 yy12;
  CAtlArray<int>* yy13;
  CAtlArray<CMYVertex*>* yy17;
  CAtlArray<double>* yy29;
  __CMyVertexAttr* yy31;
  CAtlArray<COLORREF>* yy56;
  CMYObject* yy61;
  double yy116;
  CString* yy117;
  CMYFace* yy145;
  CAtlArray<uint>* yy164;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  CMYMQO *pMqo ;
#define ParseARG_PDECL , CMYMQO *pMqo 
#define ParseARG_FETCH  CMYMQO *pMqo  = yypParser->pMqo 
#define ParseARG_STORE yypParser->pMqo  = pMqo 
#define YYNSTATE 243
#define YYNRULE 90
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (379)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   213,  115,  114,  112,  110,  109,  108,  242,   87,   77,
 /*    10 */   243,   78,   57,  191,  232,  233,  232,  233,  107,  175,
 /*    20 */   102,  232,  233,  232,  233,  237,  171,  334,  169,  101,
 /*    30 */    76,   75,   27,   24,   21,   74,   73,   72,   71,   70,
 /*    40 */    69,   18,   17,   68,   67,   66,   14,   65,   64,   63,
 /*    50 */    62,  120,   60,  166,  236,   86,  164,  162,  160,  158,
 /*    60 */   156,  154,  152,  150,  148,  146,  144,  142,  140,  138,
 /*    70 */   136,  134,  132,  130,  128,  126,  124,  189,  188,  180,
 /*    80 */    61,  238,  238,  238,  238,  100,  119,   10,  179,  173,
 /*    90 */   241,  186,   85,  183,  238,  240,  238,  235,    3,   84,
 /*   100 */   239,  182,   83,  104,  234,   56,   52,  185,  231,  230,
 /*   110 */    51,    6,  229,   50,  103,  228,   49,  106,   48,  117,
 /*   120 */   227,  226,   45,   11,  225,  224,   42,   39,    9,   38,
 /*   130 */   118,  223,    2,  222,   37,    1,  221,  220,   82,   81,
 /*   140 */   105,  219,  218,   80,   79,    8,  217,   36,   99,  216,
 /*   150 */    33,  135,  215,   30,   98,   97,  214,   91,   96,   95,
 /*   160 */    94,   93,  177,  167,   59,  335,    5,    7,  238,  165,
 /*   170 */    58,  163,  176,   90,   89,   88,  240,    4,  335,  161,
 /*   180 */   335,  335,  159,  335,  335,  335,  335,  133,  335,  131,
 /*   190 */   335,  129,  335,  335,  335,  335,  335,  335,  122,  335,
 /*   200 */   212,  335,  335,  211,  335,  335,  210,  335,  206,  335,
 /*   210 */   335,  335,  205,  204,  203,  335,  335,  335,  335,  202,
 /*   220 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   230 */   201,  198,  335,  335,  197,  196,  194,  193,  192,  121,
 /*   240 */   181,  116,  113,  111,  335,  187,  170,  335,   55,  335,
 /*   250 */   335,   54,  335,  335,  335,  335,   53,  335,  157,  335,
 /*   260 */   155,  335,  335,  335,  335,  335,  335,  153,  335,  151,
 /*   270 */   335,  335,  149,  335,  335,   47,  335,   46,  335,  335,
 /*   280 */   335,  147,   44,   43,  335,  335,  335,  335,  145,  335,
 /*   290 */   335,  335,  335,  335,  335,  335,  335,  335,  335,   41,
 /*   300 */    40,  335,  335,  143,  141,  139,  137,   35,   34,  127,
 /*   310 */    32,   31,  125,  168,  184,   29,  335,   28,  335,  335,
 /*   320 */   123,  335,  335,  335,  335,   26,  335,   25,  335,  209,
 /*   330 */   335,  335,  335,  335,  335,  335,   23,  335,   22,  335,
 /*   340 */   335,  208,  335,  335,   20,  335,   19,  335,  335,  335,
 /*   350 */   207,  200,   16,  335,  335,  335,   15,  199,  335,  335,
 /*   360 */   335,  335,  335,  335,  335,  335,  335,  335,  195,   12,
 /*   370 */   335,  335,  190,   92,  178,  172,  335,   13,  174,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   60,   61,   62,   63,   64,   65,    3,    4,   15,
 /*    10 */     0,    7,    8,    6,    9,   10,    9,   10,   82,   14,
 /*    20 */     2,    9,   10,    9,   10,   14,   14,   80,   81,    5,
 /*    30 */    36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
 /*    40 */    46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
 /*    50 */    56,   57,   58,   12,   14,   13,   15,   16,   17,   18,
 /*    60 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*    70 */    29,   30,   31,   32,   33,   34,   35,    6,    6,    6,
 /*    80 */    67,    9,    9,    9,    9,   69,   15,   67,   14,   14,
 /*    90 */     6,    6,   13,    6,    9,   11,    9,   14,   83,   13,
 /*   100 */    84,   88,   13,   70,   14,   13,   13,   87,   14,   14,
 /*   110 */    13,   72,   14,   13,   71,   14,   13,   79,   13,   48,
 /*   120 */    14,   14,   13,   77,   14,   14,   13,   13,   73,   13,
 /*   130 */    59,   14,   85,   14,   13,   86,   14,   14,   13,   13,
 /*   140 */    74,   14,   14,   13,   13,   75,   14,   13,    5,   14,
 /*   150 */    13,   69,   14,   13,    5,    5,   14,   13,    5,    5,
 /*   160 */     5,    5,   14,   67,   13,   89,   78,   76,    9,   67,
 /*   170 */    13,   67,   14,   13,   13,   13,   11,   78,   89,   67,
 /*   180 */    89,   89,   67,   89,   89,   89,   89,   69,   89,   69,
 /*   190 */    89,   67,   89,   89,   89,   89,   89,   89,   69,   89,
 /*   200 */    67,   89,   89,   67,   89,   89,   67,   89,   67,   89,
 /*   210 */    89,   89,   67,   67,   67,   89,   89,   89,   89,   67,
 /*   220 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   230 */    67,   67,   89,   89,   67,   67,   67,   67,   67,   67,
 /*   240 */    67,   67,   67,   67,   89,   67,   69,   89,   68,   89,
 /*   250 */    89,   68,   89,   89,   89,   89,   68,   89,   68,   89,
 /*   260 */    68,   89,   89,   89,   89,   89,   89,   68,   89,   68,
 /*   270 */    89,   89,   68,   89,   89,   68,   89,   68,   89,   89,
 /*   280 */    89,   68,   68,   68,   89,   89,   89,   89,   68,   89,
 /*   290 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   68,
 /*   300 */    68,   89,   89,   68,   68,   68,   68,   68,   68,   68,
 /*   310 */    68,   68,   68,    1,   68,   68,   89,   68,   89,   89,
 /*   320 */    68,   89,   89,   89,   89,   68,   89,   68,   89,   68,
 /*   330 */    89,   89,   89,   89,   89,   89,   68,   89,   68,   89,
 /*   340 */    89,   68,   89,   89,   68,   89,   68,   89,   89,   89,
 /*   350 */    68,   68,   68,   89,   89,   89,   68,   68,   89,   89,
 /*   360 */    89,   89,   89,   89,   89,   89,   89,   89,   68,   68,
 /*   370 */    89,   89,   68,   67,   67,   67,   89,   68,   68,
};
#define YY_SHIFT_USE_DFLT (-60)
#define YY_SHIFT_COUNT (169)
#define YY_SHIFT_MIN   (-59)
#define YY_SHIFT_MAX   (312)
static const short yy_shift_ofst[] = {
 /*     0 */   312,   87,   85,   84,   12,    5,    7,   75,   74,   73,
 /*    10 */    14,   72,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    20 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    30 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    40 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    50 */    14,   14,   14,   14,   14,   14,   14,  165,  159,  159,
 /*    60 */   159,  159,  159,  159,  159,  159,  159,  159,  159,  159,
 /*    70 */   159,  159,  159,  159,  159,  159,  159,  159,  165,  159,
 /*    80 */   165,  165,  165,  159,  159,  159,  159,  159,  -60,  -60,
 /*    90 */   -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,
 /*   100 */   -60,  -60,  -60,   -6,   41,  -59,   71,    4,  162,  161,
 /*   110 */   160,  158,  157,  148,  151,  144,  156,  155,  154,  153,
 /*   120 */   150,  149,  143,  142,  140,  138,  137,  135,  134,  132,
 /*   130 */   131,  128,  130,  127,  126,  123,  125,  122,  121,  119,
 /*   140 */   116,  117,  114,  111,  113,  110,  109,  107,  105,  106,
 /*   150 */   103,  101,  100,   98,   97,   95,   93,   94,   92,   90,
 /*   160 */    89,   83,   86,   40,   79,   11,   42,   24,   18,   10,
};
#define YY_REDUCE_USE_DFLT (-65)
#define YY_REDUCE_COUNT (102)
#define YY_REDUCE_MIN   (-64)
#define YY_REDUCE_MAX   (310)
static const short yy_reduce_ofst[] = {
 /*     0 */   -53,   13,   20,   16,  310,  310,  309,  308,  307,  306,
 /*    10 */   246,  178,  304,  301,  300,  289,  288,  284,  283,  282,
 /*    20 */   278,  276,  273,  270,  268,  261,  259,  257,  252,  249,
 /*    30 */   247,  244,  243,  242,  241,  240,  239,  238,  237,  236,
 /*    40 */   235,  232,  231,  220,  215,  214,  213,  209,  207,  204,
 /*    50 */   201,  199,  192,  190,  188,  183,  180,  177,  176,  175,
 /*    60 */   174,  173,  172,  171,  170,  169,  168,  167,  164,  163,
 /*    70 */   152,  147,  146,  145,  141,  139,  136,  133,  129,  124,
 /*    80 */   120,  118,   82,  115,  112,  104,  102,   96,   99,   91,
 /*    90 */    88,   70,   66,   55,   49,   47,   46,   38,   39,   43,
 /*   100 */    33,   15,  -64,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    10 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    20 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    30 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    40 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    50 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    60 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    70 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*    80 */   333,  333,  333,  333,  333,  333,  333,  333,  332,  328,
 /*    90 */   332,  326,  324,  317,  314,  311,  330,  309,  305,  303,
 /*   100 */   278,  254,  248,  333,  255,  316,  333,  333,  333,  333,
 /*   110 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   120 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   130 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   140 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   150 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   160 */   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
 /*   170 */   247,  323,  327,  322,  331,  321,  320,  319,  325,  318,
 /*   180 */   302,  315,  313,  308,  312,  310,  307,  329,  306,  301,
 /*   190 */   304,  300,  299,  298,  297,  296,  295,  294,  293,  292,
 /*   200 */   291,  290,  289,  288,  287,  286,  285,  284,  283,  282,
 /*   210 */   281,  280,  279,  246,  277,  276,  275,  274,  273,  272,
 /*   220 */   271,  270,  269,  268,  267,  266,  265,  264,  263,  262,
 /*   230 */   261,  260,  251,  250,  259,  258,  257,  256,  249,  253,
 /*   240 */   252,  245,  244,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "TAG_MetasequoiaDocument",  "TAG_FormatTextVer11",  "TAG_Eof",     
  "TAG_Material",  "BR1",           "BR2",           "TAG_Object",  
  "TAG_IncludeXml",  "INTVAL",        "DBLVAL",        "STRVAL",      
  "TAG_shader",    "BR3",           "BR4",           "TAG_uid",     
  "TAG_vcol",      "TAG_dbls",      "TAG_col",       "TAG_dif",     
  "TAG_amb",       "TAG_emi",       "TAG_spc",       "TAG_amb_col", 
  "TAG_emi_col",   "TAG_spc_col",   "TAG_power",     "TAG_reflect", 
  "TAG_refract",   "TAG_tex",       "TAG_aplane",    "TAG_bump",    
  "TAG_proj_type",  "TAG_proj_pos",  "TAG_proj_scale",  "TAG_proj_angle",
  "TAG_depth",     "TAG_folding",   "TAG_scale",     "TAG_rotation",
  "TAG_translation",  "TAG_patch",     "TAG_patchtri",  "TAG_segment", 
  "TAG_visible",   "TAG_locking",   "TAG_shading",   "TAG_facet",   
  "TAG_color",     "TAG_color_type",  "TAG_mirror",    "TAG_mirror_axis",
  "TAG_mirror_dis",  "TAG_lathe",     "TAG_lathe_axis",  "TAG_lathe_seg",
  "TAG_vertex",    "TAG_vertexattr",  "TAG_face",      "TAG_weit",    
  "TAG_V",         "TAG_M",         "TAG_UID",       "TAG_UV",      
  "TAG_COL",       "TAG_CRS",       "error",         "intval",      
  "dblval",        "strval",        "matparamexpr2",  "objexpr",     
  "vertexexpr",    "faceexpr",      "faceattrexpr",  "uintarr",     
  "colorrefarr",   "intarr",        "dblarr",        "vertexattrexpr2",
  "program",       "expr3",         "expr",          "matexpr",     
  "matexpr2",      "weitexpr",      "colorexpr",     "weitexpr2",   
  "colorexpr2",  
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= expr3",
 /*   1 */ "expr3 ::= TAG_MetasequoiaDocument TAG_FormatTextVer11 expr TAG_Eof",
 /*   2 */ "expr ::= expr TAG_Material intval BR1 matexpr BR2",
 /*   3 */ "expr ::= expr TAG_Object strval BR1 objexpr BR2",
 /*   4 */ "expr ::= expr TAG_IncludeXml strval",
 /*   5 */ "expr ::=",
 /*   6 */ "intval ::= INTVAL",
 /*   7 */ "dblval ::= DBLVAL",
 /*   8 */ "dblval ::= INTVAL",
 /*   9 */ "strval ::= STRVAL",
 /*  10 */ "matexpr ::= matexpr matexpr2",
 /*  11 */ "matexpr ::=",
 /*  12 */ "matexpr2 ::= strval matparamexpr2",
 /*  13 */ "matparamexpr2 ::= matparamexpr2 TAG_shader BR3 intval BR4",
 /*  14 */ "matparamexpr2 ::= matparamexpr2 TAG_uid BR3 intval BR4",
 /*  15 */ "matparamexpr2 ::= matparamexpr2 TAG_vcol BR3 intval BR4",
 /*  16 */ "matparamexpr2 ::= matparamexpr2 TAG_dbls BR3 intval BR4",
 /*  17 */ "matparamexpr2 ::= matparamexpr2 TAG_col BR3 dblval dblval dblval dblval BR4",
 /*  18 */ "matparamexpr2 ::= matparamexpr2 TAG_dif BR3 dblval BR4",
 /*  19 */ "matparamexpr2 ::= matparamexpr2 TAG_amb BR3 dblval BR4",
 /*  20 */ "matparamexpr2 ::= matparamexpr2 TAG_emi BR3 dblval BR4",
 /*  21 */ "matparamexpr2 ::= matparamexpr2 TAG_spc BR3 dblval BR4",
 /*  22 */ "matparamexpr2 ::= matparamexpr2 TAG_amb_col BR3 dblval dblval dblval BR4",
 /*  23 */ "matparamexpr2 ::= matparamexpr2 TAG_emi_col BR3 dblval dblval dblval BR4",
 /*  24 */ "matparamexpr2 ::= matparamexpr2 TAG_spc_col BR3 dblval dblval dblval BR4",
 /*  25 */ "matparamexpr2 ::= matparamexpr2 TAG_power BR3 dblval BR4",
 /*  26 */ "matparamexpr2 ::= matparamexpr2 TAG_reflect BR3 dblval BR4",
 /*  27 */ "matparamexpr2 ::= matparamexpr2 TAG_refract BR3 dblval BR4",
 /*  28 */ "matparamexpr2 ::= matparamexpr2 TAG_tex BR3 strval BR4",
 /*  29 */ "matparamexpr2 ::= matparamexpr2 TAG_aplane BR3 strval BR4",
 /*  30 */ "matparamexpr2 ::= matparamexpr2 TAG_bump BR3 strval BR4",
 /*  31 */ "matparamexpr2 ::= matparamexpr2 TAG_proj_type BR3 intval BR4",
 /*  32 */ "matparamexpr2 ::= matparamexpr2 TAG_proj_pos BR3 dblval dblval dblval BR4",
 /*  33 */ "matparamexpr2 ::= matparamexpr2 TAG_proj_scale BR3 dblval dblval dblval BR4",
 /*  34 */ "matparamexpr2 ::= matparamexpr2 TAG_proj_angle BR3 dblval dblval dblval BR4",
 /*  35 */ "matparamexpr2 ::=",
 /*  36 */ "objexpr ::= objexpr TAG_uid intval",
 /*  37 */ "objexpr ::= objexpr TAG_depth intval",
 /*  38 */ "objexpr ::= objexpr TAG_folding intval",
 /*  39 */ "objexpr ::= objexpr TAG_scale dblval dblval dblval",
 /*  40 */ "objexpr ::= objexpr TAG_rotation dblval dblval dblval",
 /*  41 */ "objexpr ::= objexpr TAG_translation dblval dblval dblval",
 /*  42 */ "objexpr ::= objexpr TAG_patch intval",
 /*  43 */ "objexpr ::= objexpr TAG_patchtri intval",
 /*  44 */ "objexpr ::= objexpr TAG_segment intval",
 /*  45 */ "objexpr ::= objexpr TAG_visible intval",
 /*  46 */ "objexpr ::= objexpr TAG_locking intval",
 /*  47 */ "objexpr ::= objexpr TAG_shading intval",
 /*  48 */ "objexpr ::= objexpr TAG_facet dblval",
 /*  49 */ "objexpr ::= objexpr TAG_color dblval dblval dblval",
 /*  50 */ "objexpr ::= objexpr TAG_color_type intval",
 /*  51 */ "objexpr ::= objexpr TAG_mirror intval",
 /*  52 */ "objexpr ::= objexpr TAG_mirror_axis intval",
 /*  53 */ "objexpr ::= objexpr TAG_mirror_dis dblval",
 /*  54 */ "objexpr ::= objexpr TAG_lathe intval",
 /*  55 */ "objexpr ::= objexpr TAG_lathe_axis intval",
 /*  56 */ "objexpr ::= objexpr TAG_lathe_seg intval",
 /*  57 */ "objexpr ::= objexpr TAG_vertex intval BR1 vertexexpr BR2",
 /*  58 */ "objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr2 BR2",
 /*  59 */ "objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2",
 /*  60 */ "objexpr ::=",
 /*  61 */ "vertexexpr ::= vertexexpr dblval dblval dblval",
 /*  62 */ "vertexexpr ::=",
 /*  63 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_uid BR1 intarr BR2",
 /*  64 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_weit BR1 weitexpr BR2",
 /*  65 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_color BR1 colorexpr BR2",
 /*  66 */ "vertexattrexpr2 ::=",
 /*  67 */ "weitexpr ::= weitexpr weitexpr2",
 /*  68 */ "weitexpr ::=",
 /*  69 */ "weitexpr2 ::= intval dblval",
 /*  70 */ "colorexpr ::= colorexpr colorexpr2",
 /*  71 */ "colorexpr ::=",
 /*  72 */ "colorexpr2 ::= intval intval",
 /*  73 */ "faceexpr ::= faceexpr intval faceattrexpr",
 /*  74 */ "faceexpr ::=",
 /*  75 */ "faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4",
 /*  76 */ "faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4",
 /*  77 */ "faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4",
 /*  78 */ "faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4",
 /*  79 */ "faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4",
 /*  80 */ "faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4",
 /*  81 */ "faceattrexpr ::=",
 /*  82 */ "uintarr ::= uintarr intval",
 /*  83 */ "uintarr ::=",
 /*  84 */ "colorrefarr ::= colorrefarr intval",
 /*  85 */ "colorrefarr ::=",
 /*  86 */ "intarr ::= intarr intval",
 /*  87 */ "intarr ::=",
 /*  88 */ "dblarr ::= dblarr dblval",
 /*  89 */ "dblarr ::=",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 69: /* strval */
{
#line 8 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
delete (yypminor->yy117);
#line 601 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
}
      break;
    case 70: /* matparamexpr2 */
{
#line 11 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
if((yypminor->yy3))delete (yypminor->yy3);
#line 608 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
}
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 80, 1 },
  { 81, 4 },
  { 82, 6 },
  { 82, 6 },
  { 82, 3 },
  { 82, 0 },
  { 67, 1 },
  { 68, 1 },
  { 68, 1 },
  { 69, 1 },
  { 83, 2 },
  { 83, 0 },
  { 84, 2 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 8 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 7 },
  { 70, 7 },
  { 70, 7 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 5 },
  { 70, 7 },
  { 70, 7 },
  { 70, 7 },
  { 70, 0 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 5 },
  { 71, 5 },
  { 71, 5 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 5 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 3 },
  { 71, 6 },
  { 71, 5 },
  { 71, 6 },
  { 71, 0 },
  { 72, 4 },
  { 72, 0 },
  { 79, 5 },
  { 79, 5 },
  { 79, 5 },
  { 79, 0 },
  { 85, 2 },
  { 85, 0 },
  { 87, 2 },
  { 86, 2 },
  { 86, 0 },
  { 88, 2 },
  { 73, 3 },
  { 73, 0 },
  { 74, 5 },
  { 74, 5 },
  { 74, 5 },
  { 74, 5 },
  { 74, 5 },
  { 74, 5 },
  { 74, 0 },
  { 75, 2 },
  { 75, 0 },
  { 76, 2 },
  { 76, 0 },
  { 77, 2 },
  { 77, 0 },
  { 78, 2 },
  { 78, 0 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 3: /* expr ::= expr TAG_Object strval BR1 objexpr BR2 */
#line 42 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-1].minor.yy61->name = *yymsp[-3].minor.yy117; pMqo->m_objects.Add(yymsp[-1].minor.yy61); yymsp[-1].minor.yy61 = NULL;}
#line 993 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 4: /* expr ::= expr TAG_IncludeXml strval */
#line 43 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{
  yy_destructor(yypParser,69,&yymsp[0].minor);
}
#line 1000 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 6: /* intval ::= INTVAL */
#line 46 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy12 = yymsp[0].minor.yy0.i; }
#line 1005 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 7: /* dblval ::= DBLVAL */
#line 48 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy116 = yymsp[0].minor.yy0.dbl; }
#line 1010 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 8: /* dblval ::= INTVAL */
#line 49 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy116 = (double)(yymsp[0].minor.yy0.i); }
#line 1015 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 9: /* strval ::= STRVAL */
#line 51 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy117 = yymsp[0].minor.yy0.str; yymsp[0].minor.yy0.str = NULL; }
#line 1020 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 12: /* matexpr2 ::= strval matparamexpr2 */
#line 55 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[0].minor.yy3->name = *yymsp[-1].minor.yy117; pMqo->AddMaterial(yymsp[0].minor.yy3); yymsp[0].minor.yy3=NULL;}
#line 1025 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 13: /* matparamexpr2 ::= matparamexpr2 TAG_shader BR3 intval BR4 */
#line 57 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->shader = (CMYMaterial::SHADER)yymsp[-1].minor.yy12;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1030 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 14: /* matparamexpr2 ::= matparamexpr2 TAG_uid BR3 intval BR4 */
#line 58 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->uid = (uint)yymsp[-1].minor.yy12;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1035 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 15: /* matparamexpr2 ::= matparamexpr2 TAG_vcol BR3 intval BR4 */
#line 59 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->vcol = yymsp[-1].minor.yy12 ? true : false;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1040 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 16: /* matparamexpr2 ::= matparamexpr2 TAG_dbls BR3 intval BR4 */
#line 60 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->dbls = yymsp[-1].minor.yy12 ? true : false;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1045 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 17: /* matparamexpr2 ::= matparamexpr2 TAG_col BR3 dblval dblval dblval dblval BR4 */
#line 61 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pCol = yymsp[-7].minor.yy3->col; pCol[0] = yymsp[-4].minor.yy116; pCol[1] = yymsp[-3].minor.yy116; pCol[2] = yymsp[-2].minor.yy116; pCol[3] = yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-7].minor.yy3;}
#line 1050 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 18: /* matparamexpr2 ::= matparamexpr2 TAG_dif BR3 dblval BR4 */
#line 62 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->dif = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1055 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 19: /* matparamexpr2 ::= matparamexpr2 TAG_amb BR3 dblval BR4 */
#line 63 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->amb = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1060 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 20: /* matparamexpr2 ::= matparamexpr2 TAG_emi BR3 dblval BR4 */
#line 64 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->emi = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1065 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 21: /* matparamexpr2 ::= matparamexpr2 TAG_spc BR3 dblval BR4 */
#line 65 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->spc = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1070 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 22: /* matparamexpr2 ::= matparamexpr2 TAG_amb_col BR3 dblval dblval dblval BR4 */
#line 66 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy3->amb_col[0]=yymsp[-3].minor.yy116;yymsp[-6].minor.yy3->amb_col[1]=yymsp[-2].minor.yy116;yymsp[-6].minor.yy3->amb_col[2]=yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1075 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 23: /* matparamexpr2 ::= matparamexpr2 TAG_emi_col BR3 dblval dblval dblval BR4 */
#line 67 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy3->emi_col[0]=yymsp[-3].minor.yy116;yymsp[-6].minor.yy3->emi_col[1]=yymsp[-2].minor.yy116;yymsp[-6].minor.yy3->emi_col[2]=yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1080 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 24: /* matparamexpr2 ::= matparamexpr2 TAG_spc_col BR3 dblval dblval dblval BR4 */
#line 68 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy3->spc_col[0]=yymsp[-3].minor.yy116;yymsp[-6].minor.yy3->spc_col[1]=yymsp[-2].minor.yy116;yymsp[-6].minor.yy3->spc_col[2]=yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1085 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 25: /* matparamexpr2 ::= matparamexpr2 TAG_power BR3 dblval BR4 */
#line 69 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->power = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1090 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 26: /* matparamexpr2 ::= matparamexpr2 TAG_reflect BR3 dblval BR4 */
#line 70 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->reflect = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1095 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 27: /* matparamexpr2 ::= matparamexpr2 TAG_refract BR3 dblval BR4 */
#line 71 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->refract = yymsp[-1].minor.yy116;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1100 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 28: /* matparamexpr2 ::= matparamexpr2 TAG_tex BR3 strval BR4 */
#line 72 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->tex = *yymsp[-1].minor.yy117;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1105 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 29: /* matparamexpr2 ::= matparamexpr2 TAG_aplane BR3 strval BR4 */
#line 73 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->aplane = *yymsp[-1].minor.yy117;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1110 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 30: /* matparamexpr2 ::= matparamexpr2 TAG_bump BR3 strval BR4 */
#line 74 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->bump = *yymsp[-1].minor.yy117;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1115 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 31: /* matparamexpr2 ::= matparamexpr2 TAG_proj_type BR3 intval BR4 */
#line 75 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy3->proj_type = (CMYMaterial::PROJTYPE)yymsp[-1].minor.yy12;yygotominor.yy3=yymsp[-4].minor.yy3;}
#line 1120 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 32: /* matparamexpr2 ::= matparamexpr2 TAG_proj_pos BR3 dblval dblval dblval BR4 */
#line 76 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_pos = yymsp[-6].minor.yy3->proj_pos; pProj_pos[0] = yymsp[-3].minor.yy116; pProj_pos[1] = yymsp[-2].minor.yy116; pProj_pos[2] = yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1125 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 33: /* matparamexpr2 ::= matparamexpr2 TAG_proj_scale BR3 dblval dblval dblval BR4 */
#line 77 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_scale = yymsp[-6].minor.yy3->proj_scale; pProj_scale[0] = yymsp[-3].minor.yy116; pProj_scale[1] = yymsp[-2].minor.yy116; pProj_scale[2] = yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1130 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 34: /* matparamexpr2 ::= matparamexpr2 TAG_proj_angle BR3 dblval dblval dblval BR4 */
#line 78 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_angle = yymsp[-6].minor.yy3->proj_angle; pProj_angle[0] = yymsp[-3].minor.yy116; pProj_angle[1] = yymsp[-2].minor.yy116; pProj_angle[2] = yymsp[-1].minor.yy116; yygotominor.yy3=yymsp[-6].minor.yy3;}
#line 1135 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 35: /* matparamexpr2 ::= */
#line 79 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy3 = new CMYMaterial();}
#line 1140 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 36: /* objexpr ::= objexpr TAG_uid intval */
#line 81 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; yygotominor.yy61->uid = yymsp[0].minor.yy12;}
#line 1145 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 37: /* objexpr ::= objexpr TAG_depth intval */
#line 82 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; yygotominor.yy61->depth = yymsp[0].minor.yy12;}
#line 1150 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 38: /* objexpr ::= objexpr TAG_folding intval */
#line 83 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; yygotominor.yy61->folding = yymsp[0].minor.yy12?true:false;}
#line 1155 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 39: /* objexpr ::= objexpr TAG_scale dblval dblval dblval */
#line 84 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-4].minor.yy61; yygotominor.yy61->scale[0] = yymsp[-2].minor.yy116; yygotominor.yy61->scale[1] = yymsp[-1].minor.yy116; yygotominor.yy61->scale[2] = yymsp[0].minor.yy116;}
#line 1160 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 40: /* objexpr ::= objexpr TAG_rotation dblval dblval dblval */
#line 85 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-4].minor.yy61; yygotominor.yy61->rotation[0] = yymsp[-2].minor.yy116; yygotominor.yy61->rotation[1] = yymsp[-1].minor.yy116; yygotominor.yy61->rotation[2] = yymsp[0].minor.yy116;}
#line 1165 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 41: /* objexpr ::= objexpr TAG_translation dblval dblval dblval */
#line 86 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-4].minor.yy61; yygotominor.yy61->translation[0] = yymsp[-2].minor.yy116; yygotominor.yy61->translation[1] = yymsp[-1].minor.yy116; yygotominor.yy61->translation[2] = yymsp[0].minor.yy116;}
#line 1170 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 42: /* objexpr ::= objexpr TAG_patch intval */
#line 87 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->patch = C;*/}
#line 1175 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 43: /* objexpr ::= objexpr TAG_patchtri intval */
#line 88 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->patchtri = C;*/}
#line 1180 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 44: /* objexpr ::= objexpr TAG_segment intval */
#line 89 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->segment = C;*/}
#line 1185 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 45: /* objexpr ::= objexpr TAG_visible intval */
#line 90 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->visible = C;*/}
#line 1190 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 46: /* objexpr ::= objexpr TAG_locking intval */
#line 91 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->locking = C;*/}
#line 1195 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 47: /* objexpr ::= objexpr TAG_shading intval */
#line 92 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; yygotominor.yy61->shading = (CMYObject::SHADING)yymsp[0].minor.yy12;}
#line 1200 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 48: /* objexpr ::= objexpr TAG_facet dblval */
#line 93 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->facet = C;*/}
#line 1205 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 49: /* objexpr ::= objexpr TAG_color dblval dblval dblval */
#line 94 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-4].minor.yy61; yygotominor.yy61->color[0] = yymsp[-2].minor.yy116; yygotominor.yy61->color[1] = yymsp[-1].minor.yy116; yygotominor.yy61->color[2] = yymsp[0].minor.yy116;}
#line 1210 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 50: /* objexpr ::= objexpr TAG_color_type intval */
#line 95 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; yygotominor.yy61->color_type = yymsp[0].minor.yy12?true:false;}
#line 1215 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 51: /* objexpr ::= objexpr TAG_mirror intval */
#line 96 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->mirror = (CMYObject::MIRROR)C;*/}
#line 1220 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 52: /* objexpr ::= objexpr TAG_mirror_axis intval */
#line 97 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->mirror_axis = (CMYObject::MIRRORAXIS)C;*/}
#line 1225 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 53: /* objexpr ::= objexpr TAG_mirror_dis dblval */
#line 98 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->mirror_dis = C;*/}
#line 1230 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 54: /* objexpr ::= objexpr TAG_lathe intval */
#line 99 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->lathe = C?true:false;*/}
#line 1235 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 55: /* objexpr ::= objexpr TAG_lathe_axis intval */
#line 100 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->lathe_axis = (CMYObject::LATHEAXIS)C;*/}
#line 1240 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 56: /* objexpr ::= objexpr TAG_lathe_seg intval */
#line 101 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-2].minor.yy61; /*yygotominor.yy61->lathe_seg = C;*/}
#line 1245 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 57: /* objexpr ::= objexpr TAG_vertex intval BR1 vertexexpr BR2 */
#line 102 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-5].minor.yy61; yygotominor.yy61->vertex = yymsp[-1].minor.yy17;}
#line 1250 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 58: /* objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr2 BR2 */
#line 103 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-4].minor.yy61; yygotominor.yy61->vertexattrUID = yymsp[-1].minor.yy31->uid;}
#line 1255 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 59: /* objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2 */
#line 105 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-5].minor.yy61; yygotominor.yy61->face = yymsp[-1].minor.yy8;}
#line 1260 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 60: /* objexpr ::= */
#line 106 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61 = new CMYObject();}
#line 1265 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 61: /* vertexexpr ::= vertexexpr dblval dblval dblval */
#line 108 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy17=yymsp[-3].minor.yy17; yygotominor.yy17->Add(new CMYVertex(yymsp[-2].minor.yy116,yymsp[-1].minor.yy116,yymsp[0].minor.yy116)); }
#line 1270 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 62: /* vertexexpr ::= */
#line 109 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy17 = new CAtlArray<CMYVertex*>();}
#line 1275 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 63: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_uid BR1 intarr BR2 */
#line 111 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy31=yymsp[-4].minor.yy31; yygotominor.yy31->uid = yymsp[-1].minor.yy13;}
#line 1280 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 64: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_weit BR1 weitexpr BR2 */
      case 65: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_color BR1 colorexpr BR2 */ yytestcase(yyruleno==65);
#line 112 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy31=yymsp[-4].minor.yy31;}
#line 1286 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 66: /* vertexattrexpr2 ::= */
#line 114 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy31 = new __CMyVertexAttr();}
#line 1291 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 73: /* faceexpr ::= faceexpr intval faceattrexpr */
#line 125 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy8=yymsp[-2].minor.yy8; yygotominor.yy8->Add(yymsp[0].minor.yy145);}
#line 1296 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 74: /* faceexpr ::= */
#line 126 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy8 = new CAtlArray<CMYFace*>();}
#line 1301 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 75: /* faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4 */
#line 128 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; yygotominor.yy145->V = yymsp[-1].minor.yy164;}
#line 1306 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 76: /* faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4 */
#line 129 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; yygotominor.yy145->M = yymsp[-1].minor.yy12;}
#line 1311 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 77: /* faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4 */
#line 130 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; /*yygotominor.yy145->UID = C;*/}
#line 1316 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 78: /* faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4 */
#line 131 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; yygotominor.yy145->UV = yymsp[-1].minor.yy29;}
#line 1321 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 79: /* faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4 */
#line 132 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; yygotominor.yy145->COL = yymsp[-1].minor.yy56;}
#line 1326 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 80: /* faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4 */
#line 133 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145=yymsp[-4].minor.yy145; /*yygotominor.yy145->CRS = C;*/}
#line 1331 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 81: /* faceattrexpr ::= */
#line 134 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy145 = new CMYFace();}
#line 1336 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 82: /* uintarr ::= uintarr intval */
#line 136 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy164=yymsp[-1].minor.yy164; yygotominor.yy164->Add((uint)yymsp[0].minor.yy12);}
#line 1341 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 83: /* uintarr ::= */
#line 137 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy164 = new CAtlArray<uint>();}
#line 1346 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 84: /* colorrefarr ::= colorrefarr intval */
#line 139 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy56=yymsp[-1].minor.yy56; yygotominor.yy56->Add((COLORREF)yymsp[0].minor.yy12);}
#line 1351 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 85: /* colorrefarr ::= */
#line 140 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy56 = new CAtlArray<COLORREF>();}
#line 1356 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 86: /* intarr ::= intarr intval */
#line 142 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy13=yymsp[-1].minor.yy13; yygotominor.yy13->Add(yymsp[0].minor.yy12);}
#line 1361 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 87: /* intarr ::= */
#line 143 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy13 = new CAtlArray<int>();}
#line 1366 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 88: /* dblarr ::= dblarr dblval */
#line 145 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-1].minor.yy29; yygotominor.yy29->Add(yymsp[0].minor.yy116);}
#line 1371 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 89: /* dblarr ::= */
#line 146 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29 = new CAtlArray<double>();}
#line 1376 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      default:
      /* (0) program ::= expr3 */ yytestcase(yyruleno==0);
      /* (1) expr3 ::= TAG_MetasequoiaDocument TAG_FormatTextVer11 expr TAG_Eof */ yytestcase(yyruleno==1);
      /* (2) expr ::= expr TAG_Material intval BR1 matexpr BR2 */ yytestcase(yyruleno==2);
      /* (5) expr ::= */ yytestcase(yyruleno==5);
      /* (10) matexpr ::= matexpr matexpr2 */ yytestcase(yyruleno==10);
      /* (11) matexpr ::= */ yytestcase(yyruleno==11);
      /* (67) weitexpr ::= weitexpr weitexpr2 */ yytestcase(yyruleno==67);
      /* (68) weitexpr ::= */ yytestcase(yyruleno==68);
      /* (69) weitexpr2 ::= intval dblval */ yytestcase(yyruleno==69);
      /* (70) colorexpr ::= colorexpr colorexpr2 */ yytestcase(yyruleno==70);
      /* (71) colorexpr ::= */ yytestcase(yyruleno==71);
      /* (72) colorexpr2 ::= intval intval */ yytestcase(yyruleno==72);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 30 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"

  ATLTRACE(_T("Syntax Error!\n"));
#line 1453 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
