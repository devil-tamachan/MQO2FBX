/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 24 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"

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
#define YYNOCODE 92
#define YYACTIONTYPE unsigned short int
#define ParseTOKENTYPE PassData
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  CString* yy9;
  CMYMaterial* yy15;
  CMYFace* yy37;
  CMYObject* yy45;
  CAtlArray<int>* yy51;
  CAtlArray<CMYFace*>* yy54;
  CAtlArray<uint>* yy84;
  CAtlArray<COLORREF>* yy98;
  double yy102;
  __int64 yy130;
  CAtlArray<double>* yy163;
  CAtlArray<CMYVertex*>* yy179;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  CMYMQO *pMqo ;
#define ParseARG_PDECL , CMYMQO *pMqo 
#define ParseARG_FETCH  CMYMQO *pMqo  = yypParser->pMqo 
#define ParseARG_STORE yypParser->pMqo  = pMqo 
#define YYNSTATE 244
#define YYNRULE 91
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
#define YY_ACTTAB_COUNT (388)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   214,  115,  114,  112,  110,  109,  108,  243,   88,   78,
 /*    10 */   244,   79,   58,  192,  233,  234,  233,  234,  107,  175,
 /*    20 */   103,  233,  234,  233,  234,  238,  171,  336,  169,  102,
 /*    30 */    77,   76,   28,   25,   22,   75,   74,   73,   72,   71,
 /*    40 */    70,   19,   18,   69,   68,   67,   15,   66,   65,   64,
 /*    50 */    63,  120,   61,  166,  237,   87,  164,  162,  160,  158,
 /*    60 */   156,  154,  152,  150,  148,  146,  144,  142,  140,  138,
 /*    70 */   136,  134,  132,  130,  128,  126,  124,  190,  188,  180,
 /*    80 */    11,  239,  239,  239,  239,  101,  119,   62,  179,  173,
 /*    90 */   242,  186,   86,  183,  239,  241,  239,  236,  100,  240,
 /*   100 */   235,   85,  185,   84,   57,    3,  232,   53,  105,  231,
 /*   110 */   182,   52,   92,    4,  230,   51,  104,  229,   50,  117,
 /*   120 */     7,  228,  227,   49,   46,   12,  226,  177,   43,   40,
 /*   130 */   118,    2,  225,  224,  223,   39,   38,    1,  222,  221,
 /*   140 */    83,   99,   82,   10,  220,  219,   81,   80,  167,  218,
 /*   150 */    37,  106,   98,  217,   34,   97,   96,  216,   31,   95,
 /*   160 */   215,   94,  176,  241,    9,  189,   60,  168,   59,  239,
 /*   170 */    91,   90,   89,    8,    6,  135,  165,  337,  337,    5,
 /*   180 */   337,  163,  337,  337,  161,  337,  337,  337,  159,  337,
 /*   190 */   337,  337,  337,  337,  337,  133,  337,  131,  337,  129,
 /*   200 */   337,  337,  337,  337,  337,  337,  337,  122,   56,  213,
 /*   210 */   337,  212,  337,  337,  337,  337,  211,  337,  337,  337,
 /*   220 */   337,  337,  337,  337,  337,  337,  337,  337,  207,  206,
 /*   230 */   205,  204,  203,  337,  202,  337,  199,  198,  197,  195,
 /*   240 */   194,  193,  121,  181,  116,  337,  337,  113,  337,  111,
 /*   250 */   337,  337,  337,  337,  170,  337,  337,   55,  337,  337,
 /*   260 */   337,  337,  337,  337,   54,  337,  157,  337,  155,  337,
 /*   270 */   337,  337,  337,  337,  337,  337,  153,  151,  149,  337,
 /*   280 */    48,  337,  337,  337,  337,   47,  337,  337,  337,  337,
 /*   290 */   337,  337,  337,  337,  337,  337,  337,  147,   45,   44,
 /*   300 */   145,   42,  337,   41,  337,  143,  141,  139,  137,   36,
 /*   310 */    35,  127,   33,   32,  337,  337,  125,  337,   30,  337,
 /*   320 */   337,  337,  337,   29,  337,  337,  123,  337,  337,  337,
 /*   330 */   337,  337,  337,   27,  337,   26,  337,  210,  337,  337,
 /*   340 */   337,  337,  337,  337,  337,   24,   23,  209,  337,   21,
 /*   350 */   337,  337,  337,  337,   20,  337,  337,  337,  337,  337,
 /*   360 */   337,  337,  337,  337,  337,  337,  208,  201,   17,   16,
 /*   370 */   200,  337,  196,  337,   13,  191,  187,  337,  184,   93,
 /*   380 */   178,  172,  337,  337,  337,   14,  337,  174,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   60,   61,   62,   63,   64,   65,    3,    4,   15,
 /*    10 */     0,    7,    8,    6,    9,   10,    9,   10,   81,   14,
 /*    20 */     2,    9,   10,    9,   10,   14,   14,   79,   80,    5,
 /*    30 */    36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
 /*    40 */    46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
 /*    50 */    56,   57,   58,   12,   14,   13,   15,   16,   17,   18,
 /*    60 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*    70 */    29,   30,   31,   32,   33,   34,   35,    6,    6,    6,
 /*    80 */    67,    9,    9,    9,    9,   69,   15,   67,   14,   14,
 /*    90 */     6,    6,   13,    6,    9,   11,    9,   14,    5,   83,
 /*   100 */    14,   13,   89,   13,   13,   82,   14,   13,   70,   14,
 /*   110 */    90,   13,   13,   84,   14,   13,   71,   14,   13,   48,
 /*   120 */    72,   14,   14,   13,   13,   86,   14,   14,   13,   13,
 /*   130 */    59,   87,   14,   14,   14,   13,   13,   88,   14,   14,
 /*   140 */    13,    5,   13,   73,   14,   14,   13,   13,   67,   14,
 /*   150 */    13,   74,    5,   14,   13,    5,    5,   14,   13,    5,
 /*   160 */    14,    5,   14,   11,   75,   85,   13,    1,   13,    9,
 /*   170 */    13,   13,   13,   76,   78,   69,   67,   91,   91,   78,
 /*   180 */    91,   67,   91,   91,   67,   91,   91,   91,   67,   91,
 /*   190 */    91,   91,   91,   91,   91,   69,   91,   69,   91,   67,
 /*   200 */    91,   91,   91,   91,   91,   91,   91,   69,   68,   67,
 /*   210 */    91,   67,   91,   91,   91,   91,   67,   91,   91,   91,
 /*   220 */    91,   91,   91,   91,   91,   91,   91,   91,   67,   67,
 /*   230 */    67,   67,   67,   91,   67,   91,   67,   67,   67,   67,
 /*   240 */    67,   67,   67,   67,   67,   91,   91,   67,   91,   67,
 /*   250 */    91,   91,   91,   91,   69,   91,   91,   68,   91,   91,
 /*   260 */    91,   91,   91,   91,   68,   91,   68,   91,   68,   91,
 /*   270 */    91,   91,   91,   91,   91,   91,   68,   68,   68,   91,
 /*   280 */    68,   91,   91,   91,   91,   68,   91,   91,   91,   91,
 /*   290 */    91,   91,   91,   91,   91,   91,   91,   68,   68,   68,
 /*   300 */    68,   68,   91,   68,   91,   68,   68,   68,   68,   68,
 /*   310 */    68,   68,   68,   68,   91,   91,   68,   91,   68,   91,
 /*   320 */    91,   91,   91,   68,   91,   91,   68,   91,   91,   91,
 /*   330 */    91,   91,   91,   68,   91,   68,   91,   68,   91,   91,
 /*   340 */    91,   91,   91,   91,   91,   68,   68,   68,   91,   68,
 /*   350 */    91,   91,   91,   91,   68,   91,   91,   91,   91,   91,
 /*   360 */    91,   91,   91,   91,   91,   91,   68,   68,   68,   68,
 /*   370 */    68,   91,   68,   91,   68,   68,   67,   91,   68,   67,
 /*   380 */    67,   67,   91,   91,   91,   68,   91,   68,
};
#define YY_SHIFT_USE_DFLT (-60)
#define YY_SHIFT_COUNT (169)
#define YY_SHIFT_MIN   (-59)
#define YY_SHIFT_MAX   (166)
static const short yy_shift_ofst[] = {
 /*     0 */   166,   87,   85,   84,   71,   12,    5,    7,   75,   74,
 /*    10 */    73,   14,   72,   14,   14,   14,   14,   14,   14,   14,
 /*    20 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    30 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    40 */    14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
 /*    50 */    14,   14,   14,   14,   14,   14,   14,   14,  152,  160,
 /*    60 */   160,  160,  160,  160,  160,  160,  160,  160,  160,  160,
 /*    70 */   160,  160,  160,  160,  160,  160,  160,  160,  160,  152,
 /*    80 */   160,  152,  152,  152,  160,  160,  160,  160,  160,  -60,
 /*    90 */   -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,
 /*   100 */   -60,  -60,  -60,  -60,   -6,   41,  -59,    4,  159,  158,
 /*   110 */   157,  148,  155,  113,  153,   99,  156,  154,  151,  150,
 /*   120 */   147,  136,   93,  146,  145,  143,  141,  139,  137,  135,
 /*   130 */   134,  131,  133,  130,  129,  125,  127,  124,  123,  120,
 /*   140 */   122,  119,  116,  118,  115,  112,  111,  108,  110,  107,
 /*   150 */   105,  103,  102,  100,   98,   95,   94,   92,   91,   86,
 /*   160 */    90,   83,   88,   40,   79,   11,   42,   24,   18,   10,
};
#define YY_REDUCE_USE_DFLT (-64)
#define YY_REDUCE_COUNT (103)
#define YY_REDUCE_MIN   (-63)
#define YY_REDUCE_MAX   (319)
static const short yy_reduce_ofst[] = {
 /*     0 */   -52,   20,   13,   16,   80,  319,  319,  317,  314,  313,
 /*    10 */   312,  310,  309,  307,  306,  304,  302,  301,  300,  299,
 /*    20 */   298,  286,  281,  279,  278,  277,  269,  267,  265,  258,
 /*    30 */   255,  250,  248,  245,  244,  243,  242,  241,  240,  239,
 /*    40 */   238,  237,  235,  233,  232,  231,  230,  229,  217,  212,
 /*    50 */   210,  209,  208,  200,  198,  196,  189,  140,  185,  182,
 /*    60 */   180,  177,  176,  175,  174,  173,  172,  171,  170,  169,
 /*    70 */   167,  165,  164,  163,  162,  161,  149,  144,  142,  138,
 /*    80 */   132,  128,  126,  106,  121,  117,  114,  109,   81,  101,
 /*    90 */    97,   96,   89,   77,   70,   49,   44,   39,   29,   48,
 /*   100 */    45,   38,   23,  -63,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    10 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    20 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    30 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    40 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    50 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    60 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    70 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*    80 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  334,
 /*    90 */   332,  334,  330,  328,  321,  318,  315,  313,  308,  306,
 /*   100 */   304,  279,  255,  249,  335,  256,  320,  335,  335,  335,
 /*   110 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   120 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   130 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   140 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   150 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   160 */   335,  335,  335,  335,  335,  335,  335,  335,  335,  335,
 /*   170 */   248,  327,  331,  326,  333,  325,  324,  323,  329,  322,
 /*   180 */   303,  319,  317,  311,  316,  314,  310,  312,  309,  307,
 /*   190 */   302,  305,  301,  300,  299,  298,  297,  296,  295,  294,
 /*   200 */   293,  292,  291,  290,  289,  288,  287,  286,  285,  284,
 /*   210 */   283,  282,  281,  280,  247,  278,  277,  276,  275,  274,
 /*   220 */   273,  272,  271,  270,  269,  268,  267,  266,  265,  264,
 /*   230 */   263,  262,  261,  252,  251,  260,  259,  258,  257,  250,
 /*   240 */   254,  253,  246,  245,
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
  "colorrefarr",   "intarr",        "dblarr",        "program",     
  "expr3",         "expr",          "matexpr",       "matexpr2",    
  "vertexattrexpr",  "vertexattrexpr2",  "uidexpr",       "weitexpr",    
  "colorexpr",     "weitexpr2",     "colorexpr2",  
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
 /*  58 */ "objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr BR2",
 /*  59 */ "objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2",
 /*  60 */ "objexpr ::=",
 /*  61 */ "vertexexpr ::= vertexexpr dblval dblval dblval",
 /*  62 */ "vertexexpr ::=",
 /*  63 */ "vertexattrexpr ::= vertexattrexpr vertexattrexpr2",
 /*  64 */ "vertexattrexpr ::=",
 /*  65 */ "vertexattrexpr2 ::= TAG_uid BR1 uidexpr BR2",
 /*  66 */ "vertexattrexpr2 ::= TAG_weit BR1 weitexpr BR2",
 /*  67 */ "vertexattrexpr2 ::= TAG_color BR1 colorexpr BR2",
 /*  68 */ "uidexpr ::= uidexpr intval",
 /*  69 */ "uidexpr ::=",
 /*  70 */ "weitexpr ::= weitexpr weitexpr2",
 /*  71 */ "weitexpr ::=",
 /*  72 */ "weitexpr2 ::= intval dblval",
 /*  73 */ "colorexpr ::= colorexpr colorexpr2",
 /*  74 */ "colorexpr ::=",
 /*  75 */ "colorexpr2 ::= intval intval",
 /*  76 */ "faceexpr ::= faceexpr intval faceattrexpr",
 /*  77 */ "faceexpr ::=",
 /*  78 */ "faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4",
 /*  79 */ "faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4",
 /*  80 */ "faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4",
 /*  81 */ "faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4",
 /*  82 */ "faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4",
 /*  83 */ "faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4",
 /*  84 */ "faceattrexpr ::=",
 /*  85 */ "uintarr ::= uintarr intval",
 /*  86 */ "uintarr ::=",
 /*  87 */ "colorrefarr ::= colorrefarr intval",
 /*  88 */ "colorrefarr ::=",
 /*  89 */ "dblarr ::= dblarr dblval",
 /*  90 */ "dblarr ::=",
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
delete (yypminor->yy9);
#line 603 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
}
      break;
    case 70: /* matparamexpr2 */
{
#line 11 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
if((yypminor->yy15))delete (yypminor->yy15);
#line 610 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
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
  { 79, 1 },
  { 80, 4 },
  { 81, 6 },
  { 81, 6 },
  { 81, 3 },
  { 81, 0 },
  { 67, 1 },
  { 68, 1 },
  { 68, 1 },
  { 69, 1 },
  { 82, 2 },
  { 82, 0 },
  { 83, 2 },
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
  { 84, 2 },
  { 84, 0 },
  { 85, 4 },
  { 85, 4 },
  { 85, 4 },
  { 86, 2 },
  { 86, 0 },
  { 87, 2 },
  { 87, 0 },
  { 89, 2 },
  { 88, 2 },
  { 88, 0 },
  { 90, 2 },
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
#line 41 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-1].minor.yy45->name = *yymsp[-3].minor.yy9; pMqo->m_objects.Add(yymsp[-1].minor.yy45); yymsp[-1].minor.yy45 = NULL;}
#line 996 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 4: /* expr ::= expr TAG_IncludeXml strval */
#line 42 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{
  yy_destructor(yypParser,69,&yymsp[0].minor);
}
#line 1003 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 6: /* intval ::= INTVAL */
#line 45 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy130 = yymsp[0].minor.yy0.i; }
#line 1008 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 7: /* dblval ::= DBLVAL */
#line 47 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy102 = yymsp[0].minor.yy0.dbl; }
#line 1013 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 8: /* dblval ::= INTVAL */
#line 48 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy102 = (double)(yymsp[0].minor.yy0.i); }
#line 1018 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 9: /* strval ::= STRVAL */
#line 50 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy9 = yymsp[0].minor.yy0.str; yymsp[0].minor.yy0.str = NULL; }
#line 1023 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 12: /* matexpr2 ::= strval matparamexpr2 */
#line 54 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[0].minor.yy15->name = *yymsp[-1].minor.yy9; pMqo->AddMaterial(yymsp[0].minor.yy15); yymsp[0].minor.yy15=NULL;}
#line 1028 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 13: /* matparamexpr2 ::= matparamexpr2 TAG_shader BR3 intval BR4 */
#line 56 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->shader = (CMYMaterial::SHADER)yymsp[-1].minor.yy130;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1033 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 14: /* matparamexpr2 ::= matparamexpr2 TAG_uid BR3 intval BR4 */
#line 57 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->uid = (uint)yymsp[-1].minor.yy130;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1038 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 15: /* matparamexpr2 ::= matparamexpr2 TAG_vcol BR3 intval BR4 */
#line 58 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->vcol = yymsp[-1].minor.yy130 ? true : false;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1043 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 16: /* matparamexpr2 ::= matparamexpr2 TAG_dbls BR3 intval BR4 */
#line 59 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->dbls = yymsp[-1].minor.yy130 ? true : false;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1048 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 17: /* matparamexpr2 ::= matparamexpr2 TAG_col BR3 dblval dblval dblval dblval BR4 */
#line 60 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pCol = yymsp[-7].minor.yy15->col; pCol[0] = yymsp[-4].minor.yy102; pCol[1] = yymsp[-3].minor.yy102; pCol[2] = yymsp[-2].minor.yy102; pCol[3] = yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-7].minor.yy15;}
#line 1053 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 18: /* matparamexpr2 ::= matparamexpr2 TAG_dif BR3 dblval BR4 */
#line 61 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->dif = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1058 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 19: /* matparamexpr2 ::= matparamexpr2 TAG_amb BR3 dblval BR4 */
#line 62 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->amb = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1063 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 20: /* matparamexpr2 ::= matparamexpr2 TAG_emi BR3 dblval BR4 */
#line 63 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->emi = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1068 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 21: /* matparamexpr2 ::= matparamexpr2 TAG_spc BR3 dblval BR4 */
#line 64 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->spc = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1073 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 22: /* matparamexpr2 ::= matparamexpr2 TAG_amb_col BR3 dblval dblval dblval BR4 */
#line 65 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy15->amb_col[0]=yymsp[-3].minor.yy102;yymsp[-6].minor.yy15->amb_col[1]=yymsp[-2].minor.yy102;yymsp[-6].minor.yy15->amb_col[2]=yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1078 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 23: /* matparamexpr2 ::= matparamexpr2 TAG_emi_col BR3 dblval dblval dblval BR4 */
#line 66 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy15->emi_col[0]=yymsp[-3].minor.yy102;yymsp[-6].minor.yy15->emi_col[1]=yymsp[-2].minor.yy102;yymsp[-6].minor.yy15->emi_col[2]=yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1083 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 24: /* matparamexpr2 ::= matparamexpr2 TAG_spc_col BR3 dblval dblval dblval BR4 */
#line 67 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy15->spc_col[0]=yymsp[-3].minor.yy102;yymsp[-6].minor.yy15->spc_col[1]=yymsp[-2].minor.yy102;yymsp[-6].minor.yy15->spc_col[2]=yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1088 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 25: /* matparamexpr2 ::= matparamexpr2 TAG_power BR3 dblval BR4 */
#line 68 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->power = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1093 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 26: /* matparamexpr2 ::= matparamexpr2 TAG_reflect BR3 dblval BR4 */
#line 69 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->reflect = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1098 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 27: /* matparamexpr2 ::= matparamexpr2 TAG_refract BR3 dblval BR4 */
#line 70 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->refract = yymsp[-1].minor.yy102;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1103 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 28: /* matparamexpr2 ::= matparamexpr2 TAG_tex BR3 strval BR4 */
#line 71 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->tex = *yymsp[-1].minor.yy9;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1108 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 29: /* matparamexpr2 ::= matparamexpr2 TAG_aplane BR3 strval BR4 */
#line 72 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->aplane = *yymsp[-1].minor.yy9;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1113 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 30: /* matparamexpr2 ::= matparamexpr2 TAG_bump BR3 strval BR4 */
#line 73 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->bump = *yymsp[-1].minor.yy9;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1118 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 31: /* matparamexpr2 ::= matparamexpr2 TAG_proj_type BR3 intval BR4 */
#line 74 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy15->proj_type = (CMYMaterial::PROJTYPE)yymsp[-1].minor.yy130;yygotominor.yy15=yymsp[-4].minor.yy15;}
#line 1123 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 32: /* matparamexpr2 ::= matparamexpr2 TAG_proj_pos BR3 dblval dblval dblval BR4 */
#line 75 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_pos = yymsp[-6].minor.yy15->proj_pos; pProj_pos[0] = yymsp[-3].minor.yy102; pProj_pos[1] = yymsp[-2].minor.yy102; pProj_pos[2] = yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1128 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 33: /* matparamexpr2 ::= matparamexpr2 TAG_proj_scale BR3 dblval dblval dblval BR4 */
#line 76 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_scale = yymsp[-6].minor.yy15->proj_scale; pProj_scale[0] = yymsp[-3].minor.yy102; pProj_scale[1] = yymsp[-2].minor.yy102; pProj_scale[2] = yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1133 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 34: /* matparamexpr2 ::= matparamexpr2 TAG_proj_angle BR3 dblval dblval dblval BR4 */
#line 77 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_angle = yymsp[-6].minor.yy15->proj_angle; pProj_angle[0] = yymsp[-3].minor.yy102; pProj_angle[1] = yymsp[-2].minor.yy102; pProj_angle[2] = yymsp[-1].minor.yy102; yygotominor.yy15=yymsp[-6].minor.yy15;}
#line 1138 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 35: /* matparamexpr2 ::= */
#line 78 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy15 = new CMYMaterial();}
#line 1143 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 36: /* objexpr ::= objexpr TAG_uid intval */
#line 80 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; yygotominor.yy45->uid = yymsp[0].minor.yy130;}
#line 1148 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 37: /* objexpr ::= objexpr TAG_depth intval */
#line 81 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; yygotominor.yy45->depth = yymsp[0].minor.yy130;}
#line 1153 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 38: /* objexpr ::= objexpr TAG_folding intval */
#line 82 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; yygotominor.yy45->folding = yymsp[0].minor.yy130?true:false;}
#line 1158 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 39: /* objexpr ::= objexpr TAG_scale dblval dblval dblval */
#line 83 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-4].minor.yy45; yygotominor.yy45->scale[0] = yymsp[-2].minor.yy102; yygotominor.yy45->scale[1] = yymsp[-1].minor.yy102; yygotominor.yy45->scale[2] = yymsp[0].minor.yy102;}
#line 1163 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 40: /* objexpr ::= objexpr TAG_rotation dblval dblval dblval */
#line 84 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-4].minor.yy45; yygotominor.yy45->rotation[0] = yymsp[-2].minor.yy102; yygotominor.yy45->rotation[1] = yymsp[-1].minor.yy102; yygotominor.yy45->rotation[2] = yymsp[0].minor.yy102;}
#line 1168 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 41: /* objexpr ::= objexpr TAG_translation dblval dblval dblval */
#line 85 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-4].minor.yy45; yygotominor.yy45->translation[0] = yymsp[-2].minor.yy102; yygotominor.yy45->translation[1] = yymsp[-1].minor.yy102; yygotominor.yy45->translation[2] = yymsp[0].minor.yy102;}
#line 1173 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 42: /* objexpr ::= objexpr TAG_patch intval */
#line 86 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->patch = C;*/}
#line 1178 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 43: /* objexpr ::= objexpr TAG_patchtri intval */
#line 87 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->patchtri = C;*/}
#line 1183 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 44: /* objexpr ::= objexpr TAG_segment intval */
#line 88 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->segment = C;*/}
#line 1188 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 45: /* objexpr ::= objexpr TAG_visible intval */
#line 89 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->visible = C;*/}
#line 1193 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 46: /* objexpr ::= objexpr TAG_locking intval */
#line 90 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->locking = C;*/}
#line 1198 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 47: /* objexpr ::= objexpr TAG_shading intval */
#line 91 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; yygotominor.yy45->shading = (CMYObject::SHADING)yymsp[0].minor.yy130;}
#line 1203 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 48: /* objexpr ::= objexpr TAG_facet dblval */
#line 92 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->facet = C;*/}
#line 1208 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 49: /* objexpr ::= objexpr TAG_color dblval dblval dblval */
#line 93 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-4].minor.yy45; yygotominor.yy45->color[0] = yymsp[-2].minor.yy102; yygotominor.yy45->color[1] = yymsp[-1].minor.yy102; yygotominor.yy45->color[2] = yymsp[0].minor.yy102;}
#line 1213 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 50: /* objexpr ::= objexpr TAG_color_type intval */
#line 94 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; yygotominor.yy45->color_type = yymsp[0].minor.yy130?true:false;}
#line 1218 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 51: /* objexpr ::= objexpr TAG_mirror intval */
#line 95 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->mirror = (CMYObject::MIRROR)C;*/}
#line 1223 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 52: /* objexpr ::= objexpr TAG_mirror_axis intval */
#line 96 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->mirror_axis = (CMYObject::MIRRORAXIS)C;*/}
#line 1228 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 53: /* objexpr ::= objexpr TAG_mirror_dis dblval */
#line 97 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->mirror_dis = C;*/}
#line 1233 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 54: /* objexpr ::= objexpr TAG_lathe intval */
#line 98 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->lathe = C?true:false;*/}
#line 1238 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 55: /* objexpr ::= objexpr TAG_lathe_axis intval */
#line 99 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->lathe_axis = (CMYObject::LATHEAXIS)C;*/}
#line 1243 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 56: /* objexpr ::= objexpr TAG_lathe_seg intval */
#line 100 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-2].minor.yy45; /*yygotominor.yy45->lathe_seg = C;*/}
#line 1248 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 57: /* objexpr ::= objexpr TAG_vertex intval BR1 vertexexpr BR2 */
#line 101 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-5].minor.yy45; yygotominor.yy45->vertex = yymsp[-1].minor.yy179;}
#line 1253 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 58: /* objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr BR2 */
#line 102 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-4].minor.yy45; }
#line 1258 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 59: /* objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2 */
#line 104 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45=yymsp[-5].minor.yy45; yygotominor.yy45->face = yymsp[-1].minor.yy54;}
#line 1263 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 60: /* objexpr ::= */
#line 105 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy45 = new CMYObject();}
#line 1268 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 61: /* vertexexpr ::= vertexexpr dblval dblval dblval */
#line 107 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy179=yymsp[-3].minor.yy179; yygotominor.yy179->Add(new CMYVertex(yymsp[-2].minor.yy102,yymsp[-1].minor.yy102,yymsp[0].minor.yy102)); }
#line 1273 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 62: /* vertexexpr ::= */
#line 108 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy179 = new CAtlArray<CMYVertex*>();}
#line 1278 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 76: /* faceexpr ::= faceexpr intval faceattrexpr */
#line 128 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy54=yymsp[-2].minor.yy54; yygotominor.yy54->Add(yymsp[0].minor.yy37);}
#line 1283 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 77: /* faceexpr ::= */
#line 129 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy54 = new CAtlArray<CMYFace*>();}
#line 1288 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 78: /* faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4 */
#line 131 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; yygotominor.yy37->V = yymsp[-1].minor.yy84;}
#line 1293 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 79: /* faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4 */
#line 132 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; yygotominor.yy37->M = yymsp[-1].minor.yy130;}
#line 1298 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 80: /* faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4 */
#line 133 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; /*yygotominor.yy37->UID = C;*/}
#line 1303 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 81: /* faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4 */
#line 134 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; yygotominor.yy37->UV = yymsp[-1].minor.yy163;}
#line 1308 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 82: /* faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4 */
#line 135 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; yygotominor.yy37->COL = yymsp[-1].minor.yy98;}
#line 1313 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 83: /* faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4 */
#line 136 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37=yymsp[-4].minor.yy37; /*yygotominor.yy37->CRS = C;*/}
#line 1318 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 84: /* faceattrexpr ::= */
#line 137 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy37 = new CMYFace();}
#line 1323 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 85: /* uintarr ::= uintarr intval */
#line 139 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy84=yymsp[-1].minor.yy84; yygotominor.yy84->Add((uint)yymsp[0].minor.yy130);}
#line 1328 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 86: /* uintarr ::= */
#line 140 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy84 = new CAtlArray<uint>();}
#line 1333 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 87: /* colorrefarr ::= colorrefarr intval */
#line 142 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy98=yymsp[-1].minor.yy98; yygotominor.yy98->Add((COLORREF)yymsp[0].minor.yy130);}
#line 1338 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 88: /* colorrefarr ::= */
#line 143 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy98 = new CAtlArray<COLORREF>();}
#line 1343 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 89: /* dblarr ::= dblarr dblval */
#line 148 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy163=yymsp[-1].minor.yy163; yygotominor.yy163->Add(yymsp[0].minor.yy102);}
#line 1348 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 90: /* dblarr ::= */
#line 149 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy163 = new CAtlArray<double>();}
#line 1353 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      default:
      /* (0) program ::= expr3 */ yytestcase(yyruleno==0);
      /* (1) expr3 ::= TAG_MetasequoiaDocument TAG_FormatTextVer11 expr TAG_Eof */ yytestcase(yyruleno==1);
      /* (2) expr ::= expr TAG_Material intval BR1 matexpr BR2 */ yytestcase(yyruleno==2);
      /* (5) expr ::= */ yytestcase(yyruleno==5);
      /* (10) matexpr ::= matexpr matexpr2 */ yytestcase(yyruleno==10);
      /* (11) matexpr ::= */ yytestcase(yyruleno==11);
      /* (63) vertexattrexpr ::= vertexattrexpr vertexattrexpr2 */ yytestcase(yyruleno==63);
      /* (64) vertexattrexpr ::= */ yytestcase(yyruleno==64);
      /* (65) vertexattrexpr2 ::= TAG_uid BR1 uidexpr BR2 */ yytestcase(yyruleno==65);
      /* (66) vertexattrexpr2 ::= TAG_weit BR1 weitexpr BR2 */ yytestcase(yyruleno==66);
      /* (67) vertexattrexpr2 ::= TAG_color BR1 colorexpr BR2 */ yytestcase(yyruleno==67);
      /* (68) uidexpr ::= uidexpr intval */ yytestcase(yyruleno==68);
      /* (69) uidexpr ::= */ yytestcase(yyruleno==69);
      /* (70) weitexpr ::= weitexpr weitexpr2 */ yytestcase(yyruleno==70);
      /* (71) weitexpr ::= */ yytestcase(yyruleno==71);
      /* (72) weitexpr2 ::= intval dblval */ yytestcase(yyruleno==72);
      /* (73) colorexpr ::= colorexpr colorexpr2 */ yytestcase(yyruleno==73);
      /* (74) colorexpr ::= */ yytestcase(yyruleno==74);
      /* (75) colorexpr2 ::= intval intval */ yytestcase(yyruleno==75);
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
#line 29 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"

  ATLTRACE(_T("Syntax Error!\n"));
#line 1437 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
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
