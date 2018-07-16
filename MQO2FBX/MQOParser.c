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
#define YYNOCODE 96
#define YYACTIONTYPE unsigned short int
#define ParseTOKENTYPE PassData
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  CMYObject* yy25;
  CMYFace* yy29;
  CAtlArray<CMYVertex*>* yy33;
  CAtlArray<double>* yy61;
  __CMyVertexAttr* yy67;
  CAtlArray<COLORREF>* yy76;
  CAtlArray<int>* yy101;
  CString* yy133;
  CAtlArray<CMYFace*>* yy134;
  double yy136;
  CMYMaterial* yy143;
  CAtlArray<uint>* yy150;
  __int64 yy182;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  CMYMQO *pMqo ;
#define ParseARG_PDECL , CMYMQO *pMqo 
#define ParseARG_FETCH  CMYMQO *pMqo  = yypParser->pMqo 
#define ParseARG_STORE yypParser->pMqo  = pMqo 
#define YYNSTATE 257
#define YYNRULE 96
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
#define YY_ACTTAB_COUNT (404)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */   227,  123,  122,  120,  118,  117,  116,  115,   63,   83,
 /*    10 */   256,   93,  246,  247,   84,   59,  200,  184,  257,  246,
 /*    20 */   247,  246,  247,  246,  247,  108,  180,  109,  179,  191,
 /*    30 */    82,   81,   29,   26,   23,   80,   79,   78,   77,   76,
 /*    40 */    75,   74,   73,   72,   71,   20,   19,   18,   70,   69,
 /*    50 */    68,   15,   67,   66,   65,   64,  128,   62,  174,  246,
 /*    60 */   247,  172,  170,  168,  166,  164,  162,  160,  158,  156,
 /*    70 */   154,  152,  150,  148,  146,  144,  142,  140,  138,  136,
 /*    80 */   134,  132,  198,  197,  189,   92,  252,  252,  252,  252,
 /*    90 */   107,  127,  106,  188,  182,  255,   11,  251,  195,   91,
 /*   100 */   254,  252,  250,  192,   90,  253,  252,  354,  177,  249,
 /*   110 */   248,   89,   58,    3,  245,   54,  194,  244,   53,  114,
 /*   120 */   243,   52,  110,  242,   51,  111,  241,  240,   50,  125,
 /*   130 */    47,    7,  239,  238,   44,   41,  113,   12,  237,  236,
 /*   140 */   126,   40,   39,    2,  235,  234,   88,   87,    1,  233,
 /*   150 */   232,  105,   86,   85,   10,  231,   38,  104,  103,  230,
 /*   160 */    35,  102,  229,   32,  101,  228,  100,   98,    6,    5,
 /*   170 */    61,    9,  186,   60,  112,    8,  185,   97,   96,   95,
 /*   180 */    94,  252,  143,  175,  254,    4,  355,  173,  355,  171,
 /*   190 */   355,  355,  355,  169,  355,  355,  167,  355,  355,  355,
 /*   200 */   355,  141,  139,  355,  355,  137,  355,  355,  355,  355,
 /*   210 */   355,  226,  130,  355,  355,  225,  355,  224,  355,  355,
 /*   220 */   355,  355,  220,  355,  355,  355,  355,  355,  219,  355,
 /*   230 */   355,  355,  355,  355,  355,  355,  218,  355,  355,  355,
 /*   240 */   355,  217,  216,  215,  214,  355,  355,  213,  212,  211,
 /*   250 */   207,  206,  205,  203,  202,  201,  129,  190,  124,  121,
 /*   260 */   355,  119,  355,  355,  355,  178,  355,  355,   57,  355,
 /*   270 */   355,   56,  355,  355,  355,  355,   55,  165,  355,  355,
 /*   280 */   163,  355,  355,  355,  355,  355,  161,  159,  355,  355,
 /*   290 */   157,  355,   49,  355,  355,  355,  355,   48,  355,  355,
 /*   300 */   355,  355,  355,  155,  355,  355,  355,  355,  355,  355,
 /*   310 */   355,   46,  355,  355,  355,  355,   45,  153,   43,   42,
 /*   320 */   176,  355,  151,  149,  147,  145,   37,   36,  135,   34,
 /*   330 */    33,  133,   31,   30,  131,  355,   28,  355,  355,  355,
 /*   340 */    27,  355,  355,  223,  355,  355,   25,  355,  355,  355,
 /*   350 */   355,   24,  222,  355,  355,   22,  355,  355,  355,  355,
 /*   360 */   355,   21,  221,  355,  355,  210,  355,  209,  355,  355,
 /*   370 */   355,  355,   17,  355,  355,  355,   16,  355,  208,  355,
 /*   380 */   355,  355,  355,  355,  355,  355,  204,  355,  355,  355,
 /*   390 */   355,   13,  199,  196,  355,  355,  355,  193,   99,  187,
 /*   400 */   181,  355,   14,  183,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     6,   65,   66,   67,   68,   69,   70,   71,   73,   15,
 /*    10 */     3,    4,    9,   10,    7,    8,    6,   14,    0,    9,
 /*    20 */    10,    9,   10,    9,   10,    5,   14,    2,   14,   94,
 /*    30 */    36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
 /*    40 */    46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
 /*    50 */    56,   57,   58,   59,   60,   61,   62,   63,   12,    9,
 /*    60 */    10,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    70 */    24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
 /*    80 */    34,   35,    6,    6,    6,   13,    9,    9,    9,    9,
 /*    90 */    75,   15,    5,   14,   14,    6,   73,   14,    6,   13,
 /*   100 */    11,    9,   14,    6,   13,   90,    9,   86,   87,   14,
 /*   110 */    14,   13,   13,   89,   14,   13,   93,   14,   13,   88,
 /*   120 */    14,   13,   77,   14,   13,   76,   14,   14,   13,   53,
 /*   130 */    13,   78,   14,   14,   13,   13,   85,   83,   14,   14,
 /*   140 */    64,   13,   13,   91,   14,   14,   13,   13,   92,   14,
 /*   150 */    14,    5,   13,   13,   79,   14,   13,    5,    5,   14,
 /*   160 */    13,    5,   14,   13,    5,   14,    5,   13,   84,   84,
 /*   170 */    13,   81,   14,   13,   80,   82,   14,   13,   13,   13,
 /*   180 */    13,    9,   75,   73,   11,   84,   95,   73,   95,   73,
 /*   190 */    95,   95,   95,   73,   95,   95,   73,   95,   95,   95,
 /*   200 */    95,   75,   75,   95,   95,   73,   95,   95,   95,   95,
 /*   210 */    95,   73,   75,   95,   95,   73,   95,   73,   95,   95,
 /*   220 */    95,   95,   73,   95,   95,   95,   95,   95,   73,   95,
 /*   230 */    95,   95,   95,   95,   95,   95,   73,   95,   95,   95,
 /*   240 */    95,   73,   73,   73,   73,   95,   95,   73,   73,   73,
 /*   250 */    73,   73,   73,   73,   73,   73,   73,   73,   73,   73,
 /*   260 */    95,   73,   95,   95,   95,   75,   95,   95,   74,   95,
 /*   270 */    95,   74,   95,   95,   95,   95,   74,   74,   95,   95,
 /*   280 */    74,   95,   95,   95,   95,   95,   74,   74,   95,   95,
 /*   290 */    74,   95,   74,   95,   95,   95,   95,   74,   95,   95,
 /*   300 */    95,   95,   95,   74,   95,   95,   95,   95,   95,   95,
 /*   310 */    95,   74,   95,   95,   95,   95,   74,   74,   74,   74,
 /*   320 */     1,   95,   74,   74,   74,   74,   74,   74,   74,   74,
 /*   330 */    74,   74,   74,   74,   74,   95,   74,   95,   95,   95,
 /*   340 */    74,   95,   95,   74,   95,   95,   74,   95,   95,   95,
 /*   350 */    95,   74,   74,   95,   95,   74,   95,   95,   95,   95,
 /*   360 */    95,   74,   74,   95,   95,   74,   95,   74,   95,   95,
 /*   370 */    95,   95,   74,   95,   95,   95,   74,   95,   74,   95,
 /*   380 */    95,   95,   95,   95,   95,   95,   74,   95,   95,   95,
 /*   390 */    95,   74,   74,   73,   95,   95,   95,   74,   73,   73,
 /*   400 */    73,   95,   74,   74,
};
#define YY_SHIFT_USE_DFLT (-65)
#define YY_SHIFT_COUNT (177)
#define YY_SHIFT_MIN   (-64)
#define YY_SHIFT_MAX   (319)
static const short yy_shift_ofst[] = {
 /*     0 */   319,   97,   92,   89,   14,   12,    3,   10,   80,   79,
 /*    10 */    78,   50,   77,   50,   50,   50,   50,   50,   50,   50,
 /*    20 */    50,   50,   50,   50,   50,   50,   50,   50,   50,   50,
 /*    30 */    50,   50,   50,   50,   50,   50,   50,   50,   50,   50,
 /*    40 */    50,   50,   50,   50,   50,   50,   50,   50,   50,   50,
 /*    50 */    50,   50,   50,   50,   50,   50,   50,   50,   50,  173,
 /*    60 */   172,  172,  172,  172,  172,  172,  172,  172,  172,  172,
 /*    70 */   172,  172,  172,  172,  172,  172,  172,  172,  172,  172,
 /*    80 */   172,  172,  172,  172,  173,  172,  173,  173,  173,  172,
 /*    90 */   172,  172,  172,  172,  -65,  -65,  -65,  -65,  -65,  -65,
 /*   100 */   -65,  -65,  -65,  -65,  -65,  -65,  -65,  -65,  -65,  -65,
 /*   110 */    -6,   46,  -64,   76,    7,  167,  166,  165,  164,  162,
 /*   120 */   160,  158,  157,  154,  161,  159,  156,  153,  152,  146,
 /*   130 */    87,  151,  150,  148,  147,  145,  143,  141,  140,  136,
 /*   140 */   139,  135,  134,  131,  133,  130,  129,  125,  128,  124,
 /*   150 */   122,  119,  121,  118,  117,  113,  115,  112,  111,  109,
 /*   160 */   108,  106,  105,  103,  102,  100,   99,   96,   98,   95,
 /*   170 */    91,   88,   86,   83,   72,   20,   25,   18,
};
#define YY_REDUCE_USE_DFLT (-66)
#define YY_REDUCE_COUNT (109)
#define YY_REDUCE_MIN   (-65)
#define YY_REDUCE_MAX   (329)
static const short yy_reduce_ofst[] = {
 /*     0 */    21,  -65,   23,   15,  329,  329,  329,  328,  327,  326,
 /*    10 */   325,  323,  320,  318,  317,  312,  304,  302,  298,  293,
 /*    20 */   291,  288,  287,  281,  278,  277,  272,  269,  266,  262,
 /*    30 */   260,  259,  258,  257,  256,  255,  254,  253,  252,  251,
 /*    40 */   250,  249,  248,  245,  244,  243,  242,  237,  229,  223,
 /*    50 */   218,  216,  213,  212,  206,  203,  202,  197,  194,  190,
 /*    60 */   188,  186,  185,  184,  183,  182,  181,  180,  179,  178,
 /*    70 */   177,  176,  175,  174,  171,  170,  169,  168,  163,  155,
 /*    80 */   149,  144,  142,  138,  137,  132,  127,  126,  107,  123,
 /*    90 */   120,  116,  114,  110,  101,   85,   93,   84,   90,   94,
 /*   100 */    75,   56,   52,   54,   51,   53,   45,   49,   24,   31,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    10 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    20 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    30 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    40 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    50 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    60 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    70 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    80 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*    90 */   353,  353,  353,  353,  352,  352,  348,  352,  346,  344,
 /*   100 */   336,  333,  330,  350,  328,  324,  322,  292,  268,  262,
 /*   110 */   353,  269,  335,  353,  353,  353,  353,  353,  353,  353,
 /*   120 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*   130 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*   140 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*   150 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*   160 */   353,  353,  353,  353,  353,  353,  353,  353,  353,  353,
 /*   170 */   353,  353,  353,  353,  353,  353,  353,  353,  261,  343,
 /*   180 */   342,  347,  341,  351,  340,  339,  338,  345,  337,  321,
 /*   190 */   334,  332,  327,  331,  329,  326,  349,  325,  320,  323,
 /*   200 */   319,  318,  317,  316,  315,  314,  313,  312,  311,  310,
 /*   210 */   309,  308,  307,  306,  305,  304,  303,  302,  301,  300,
 /*   220 */   299,  298,  297,  296,  295,  294,  293,  260,  291,  290,
 /*   230 */   289,  288,  287,  286,  285,  284,  283,  282,  281,  280,
 /*   240 */   279,  278,  277,  276,  275,  274,  265,  264,  273,  272,
 /*   250 */   271,  270,  263,  267,  266,  259,  258,
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
  "TAG_translation",  "TAG_patch",     "TAG_patchtri",  "TAG_patchsmoothtri",
  "TAG_patchlimitsurface",  "TAG_patchmeshinterp",  "TAG_patchuvinterp",  "TAG_segment", 
  "TAG_visible",   "TAG_locking",   "TAG_shading",   "TAG_facet",   
  "TAG_normal_weight",  "TAG_color",     "TAG_color_type",  "TAG_mirror",  
  "TAG_mirror_axis",  "TAG_mirror_dis",  "TAG_lathe",     "TAG_lathe_axis",
  "TAG_lathe_seg",  "TAG_vertex",    "TAG_vertexattr",  "TAG_face",    
  "TAG_weit",      "TAG_V",         "TAG_M",         "TAG_UID",     
  "TAG_UV",        "TAG_COL",       "TAG_CRS",       "TAG_N",       
  "error",         "intval",        "dblval",        "strval",      
  "matparamexpr2",  "objexpr",       "vertexexpr",    "faceexpr",    
  "faceattrexpr",  "uintarr",       "colorrefarr",   "intarr",      
  "dblarr",        "vertexattrexpr2",  "program",       "expr3",       
  "expr",          "matexpr",       "matexpr2",      "weitexpr",    
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
 /*  44 */ "objexpr ::= objexpr TAG_patchsmoothtri intval",
 /*  45 */ "objexpr ::= objexpr TAG_patchlimitsurface intval",
 /*  46 */ "objexpr ::= objexpr TAG_patchmeshinterp intval",
 /*  47 */ "objexpr ::= objexpr TAG_patchuvinterp intval",
 /*  48 */ "objexpr ::= objexpr TAG_segment intval",
 /*  49 */ "objexpr ::= objexpr TAG_visible intval",
 /*  50 */ "objexpr ::= objexpr TAG_locking intval",
 /*  51 */ "objexpr ::= objexpr TAG_shading intval",
 /*  52 */ "objexpr ::= objexpr TAG_facet dblval",
 /*  53 */ "objexpr ::= objexpr TAG_normal_weight dblval",
 /*  54 */ "objexpr ::= objexpr TAG_color dblval dblval dblval",
 /*  55 */ "objexpr ::= objexpr TAG_color_type intval",
 /*  56 */ "objexpr ::= objexpr TAG_mirror intval",
 /*  57 */ "objexpr ::= objexpr TAG_mirror_axis intval",
 /*  58 */ "objexpr ::= objexpr TAG_mirror_dis dblval",
 /*  59 */ "objexpr ::= objexpr TAG_lathe intval",
 /*  60 */ "objexpr ::= objexpr TAG_lathe_axis intval",
 /*  61 */ "objexpr ::= objexpr TAG_lathe_seg intval",
 /*  62 */ "objexpr ::= objexpr TAG_vertex intval BR1 vertexexpr BR2",
 /*  63 */ "objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr2 BR2",
 /*  64 */ "objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2",
 /*  65 */ "objexpr ::=",
 /*  66 */ "vertexexpr ::= vertexexpr dblval dblval dblval",
 /*  67 */ "vertexexpr ::=",
 /*  68 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_uid BR1 intarr BR2",
 /*  69 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_weit BR1 weitexpr BR2",
 /*  70 */ "vertexattrexpr2 ::= vertexattrexpr2 TAG_color BR1 colorexpr BR2",
 /*  71 */ "vertexattrexpr2 ::=",
 /*  72 */ "weitexpr ::= weitexpr weitexpr2",
 /*  73 */ "weitexpr ::=",
 /*  74 */ "weitexpr2 ::= intval dblval",
 /*  75 */ "colorexpr ::= colorexpr colorexpr2",
 /*  76 */ "colorexpr ::=",
 /*  77 */ "colorexpr2 ::= intval intval",
 /*  78 */ "faceexpr ::= faceexpr intval faceattrexpr",
 /*  79 */ "faceexpr ::=",
 /*  80 */ "faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4",
 /*  81 */ "faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4",
 /*  82 */ "faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4",
 /*  83 */ "faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4",
 /*  84 */ "faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4",
 /*  85 */ "faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4",
 /*  86 */ "faceattrexpr ::= faceattrexpr TAG_N BR3 dblarr BR4",
 /*  87 */ "faceattrexpr ::=",
 /*  88 */ "uintarr ::= uintarr intval",
 /*  89 */ "uintarr ::=",
 /*  90 */ "colorrefarr ::= colorrefarr intval",
 /*  91 */ "colorrefarr ::=",
 /*  92 */ "intarr ::= intarr intval",
 /*  93 */ "intarr ::=",
 /*  94 */ "dblarr ::= dblarr dblval",
 /*  95 */ "dblarr ::=",
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
    case 75: /* strval */
{
#line 8 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
delete (yypminor->yy133);
#line 616 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
}
      break;
    case 76: /* matparamexpr2 */
{
#line 11 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
if((yypminor->yy143))delete (yypminor->yy143);
#line 623 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
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
  { 86, 1 },
  { 87, 4 },
  { 88, 6 },
  { 88, 6 },
  { 88, 3 },
  { 88, 0 },
  { 73, 1 },
  { 74, 1 },
  { 74, 1 },
  { 75, 1 },
  { 89, 2 },
  { 89, 0 },
  { 90, 2 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 8 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 7 },
  { 76, 7 },
  { 76, 7 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 5 },
  { 76, 7 },
  { 76, 7 },
  { 76, 7 },
  { 76, 0 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 5 },
  { 77, 5 },
  { 77, 5 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 5 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 3 },
  { 77, 6 },
  { 77, 5 },
  { 77, 6 },
  { 77, 0 },
  { 78, 4 },
  { 78, 0 },
  { 85, 5 },
  { 85, 5 },
  { 85, 5 },
  { 85, 0 },
  { 91, 2 },
  { 91, 0 },
  { 93, 2 },
  { 92, 2 },
  { 92, 0 },
  { 94, 2 },
  { 79, 3 },
  { 79, 0 },
  { 80, 5 },
  { 80, 5 },
  { 80, 5 },
  { 80, 5 },
  { 80, 5 },
  { 80, 5 },
  { 80, 5 },
  { 80, 0 },
  { 81, 2 },
  { 81, 0 },
  { 82, 2 },
  { 82, 0 },
  { 83, 2 },
  { 83, 0 },
  { 84, 2 },
  { 84, 0 },
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
{yymsp[-1].minor.yy25->name = *yymsp[-3].minor.yy133; pMqo->m_objects.Add(yymsp[-1].minor.yy25); yymsp[-1].minor.yy25 = NULL;}
#line 1014 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 4: /* expr ::= expr TAG_IncludeXml strval */
#line 43 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{
  yy_destructor(yypParser,75,&yymsp[0].minor);
}
#line 1021 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 6: /* intval ::= INTVAL */
#line 46 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy182 = yymsp[0].minor.yy0.i; }
#line 1026 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 7: /* dblval ::= DBLVAL */
#line 48 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy136 = yymsp[0].minor.yy0.dbl; }
#line 1031 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 8: /* dblval ::= INTVAL */
#line 49 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy136 = (double)(yymsp[0].minor.yy0.i); }
#line 1036 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 9: /* strval ::= STRVAL */
#line 51 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{ yygotominor.yy133 = yymsp[0].minor.yy0.str; yymsp[0].minor.yy0.str = NULL; }
#line 1041 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 12: /* matexpr2 ::= strval matparamexpr2 */
#line 55 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[0].minor.yy143->name = *yymsp[-1].minor.yy133; pMqo->AddMaterial(yymsp[0].minor.yy143); yymsp[0].minor.yy143=NULL;}
#line 1046 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 13: /* matparamexpr2 ::= matparamexpr2 TAG_shader BR3 intval BR4 */
#line 57 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->shader = (CMYMaterial::SHADER)yymsp[-1].minor.yy182;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1051 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 14: /* matparamexpr2 ::= matparamexpr2 TAG_uid BR3 intval BR4 */
#line 58 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->uid = (uint)yymsp[-1].minor.yy182;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1056 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 15: /* matparamexpr2 ::= matparamexpr2 TAG_vcol BR3 intval BR4 */
#line 59 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->vcol = yymsp[-1].minor.yy182 ? true : false;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1061 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 16: /* matparamexpr2 ::= matparamexpr2 TAG_dbls BR3 intval BR4 */
#line 60 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->dbls = yymsp[-1].minor.yy182 ? true : false;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1066 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 17: /* matparamexpr2 ::= matparamexpr2 TAG_col BR3 dblval dblval dblval dblval BR4 */
#line 61 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pCol = yymsp[-7].minor.yy143->col; pCol[0] = yymsp[-4].minor.yy136; pCol[1] = yymsp[-3].minor.yy136; pCol[2] = yymsp[-2].minor.yy136; pCol[3] = yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-7].minor.yy143;}
#line 1071 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 18: /* matparamexpr2 ::= matparamexpr2 TAG_dif BR3 dblval BR4 */
#line 62 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->dif = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1076 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 19: /* matparamexpr2 ::= matparamexpr2 TAG_amb BR3 dblval BR4 */
#line 63 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->amb = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1081 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 20: /* matparamexpr2 ::= matparamexpr2 TAG_emi BR3 dblval BR4 */
#line 64 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->emi = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1086 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 21: /* matparamexpr2 ::= matparamexpr2 TAG_spc BR3 dblval BR4 */
#line 65 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->spc = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1091 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 22: /* matparamexpr2 ::= matparamexpr2 TAG_amb_col BR3 dblval dblval dblval BR4 */
#line 66 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy143->amb_col[0]=yymsp[-3].minor.yy136;yymsp[-6].minor.yy143->amb_col[1]=yymsp[-2].minor.yy136;yymsp[-6].minor.yy143->amb_col[2]=yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1096 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 23: /* matparamexpr2 ::= matparamexpr2 TAG_emi_col BR3 dblval dblval dblval BR4 */
#line 67 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy143->emi_col[0]=yymsp[-3].minor.yy136;yymsp[-6].minor.yy143->emi_col[1]=yymsp[-2].minor.yy136;yymsp[-6].minor.yy143->emi_col[2]=yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1101 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 24: /* matparamexpr2 ::= matparamexpr2 TAG_spc_col BR3 dblval dblval dblval BR4 */
#line 68 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-6].minor.yy143->spc_col[0]=yymsp[-3].minor.yy136;yymsp[-6].minor.yy143->spc_col[1]=yymsp[-2].minor.yy136;yymsp[-6].minor.yy143->spc_col[2]=yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1106 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 25: /* matparamexpr2 ::= matparamexpr2 TAG_power BR3 dblval BR4 */
#line 69 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->power = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1111 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 26: /* matparamexpr2 ::= matparamexpr2 TAG_reflect BR3 dblval BR4 */
#line 70 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->reflect = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1116 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 27: /* matparamexpr2 ::= matparamexpr2 TAG_refract BR3 dblval BR4 */
#line 71 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->refract = yymsp[-1].minor.yy136;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1121 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 28: /* matparamexpr2 ::= matparamexpr2 TAG_tex BR3 strval BR4 */
#line 72 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->tex = *yymsp[-1].minor.yy133;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1126 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 29: /* matparamexpr2 ::= matparamexpr2 TAG_aplane BR3 strval BR4 */
#line 73 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->aplane = *yymsp[-1].minor.yy133;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1131 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 30: /* matparamexpr2 ::= matparamexpr2 TAG_bump BR3 strval BR4 */
#line 74 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->bump = *yymsp[-1].minor.yy133;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1136 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 31: /* matparamexpr2 ::= matparamexpr2 TAG_proj_type BR3 intval BR4 */
#line 75 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yymsp[-4].minor.yy143->proj_type = (CMYMaterial::PROJTYPE)yymsp[-1].minor.yy182;yygotominor.yy143=yymsp[-4].minor.yy143;}
#line 1141 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 32: /* matparamexpr2 ::= matparamexpr2 TAG_proj_pos BR3 dblval dblval dblval BR4 */
#line 76 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_pos = yymsp[-6].minor.yy143->proj_pos; pProj_pos[0] = yymsp[-3].minor.yy136; pProj_pos[1] = yymsp[-2].minor.yy136; pProj_pos[2] = yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1146 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 33: /* matparamexpr2 ::= matparamexpr2 TAG_proj_scale BR3 dblval dblval dblval BR4 */
#line 77 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_scale = yymsp[-6].minor.yy143->proj_scale; pProj_scale[0] = yymsp[-3].minor.yy136; pProj_scale[1] = yymsp[-2].minor.yy136; pProj_scale[2] = yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1151 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 34: /* matparamexpr2 ::= matparamexpr2 TAG_proj_angle BR3 dblval dblval dblval BR4 */
#line 78 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{double* pProj_angle = yymsp[-6].minor.yy143->proj_angle; pProj_angle[0] = yymsp[-3].minor.yy136; pProj_angle[1] = yymsp[-2].minor.yy136; pProj_angle[2] = yymsp[-1].minor.yy136; yygotominor.yy143=yymsp[-6].minor.yy143;}
#line 1156 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 35: /* matparamexpr2 ::= */
#line 79 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy143 = new CMYMaterial();}
#line 1161 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 36: /* objexpr ::= objexpr TAG_uid intval */
#line 81 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->uid = yymsp[0].minor.yy182;}
#line 1166 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 37: /* objexpr ::= objexpr TAG_depth intval */
#line 82 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->depth = yymsp[0].minor.yy182;}
#line 1171 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 38: /* objexpr ::= objexpr TAG_folding intval */
#line 83 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->folding = yymsp[0].minor.yy182?true:false;}
#line 1176 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 39: /* objexpr ::= objexpr TAG_scale dblval dblval dblval */
#line 84 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-4].minor.yy25; yygotominor.yy25->scale[0] = yymsp[-2].minor.yy136; yygotominor.yy25->scale[1] = yymsp[-1].minor.yy136; yygotominor.yy25->scale[2] = yymsp[0].minor.yy136;}
#line 1181 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 40: /* objexpr ::= objexpr TAG_rotation dblval dblval dblval */
#line 85 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-4].minor.yy25; yygotominor.yy25->rotation[0] = yymsp[-2].minor.yy136; yygotominor.yy25->rotation[1] = yymsp[-1].minor.yy136; yygotominor.yy25->rotation[2] = yymsp[0].minor.yy136;}
#line 1186 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 41: /* objexpr ::= objexpr TAG_translation dblval dblval dblval */
#line 86 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-4].minor.yy25; yygotominor.yy25->translation[0] = yymsp[-2].minor.yy136; yygotominor.yy25->translation[1] = yymsp[-1].minor.yy136; yygotominor.yy25->translation[2] = yymsp[0].minor.yy136;}
#line 1191 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 42: /* objexpr ::= objexpr TAG_patch intval */
#line 87 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patch = C;*/}
#line 1196 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 43: /* objexpr ::= objexpr TAG_patchtri intval */
#line 88 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patchtri = C;*/}
#line 1201 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 44: /* objexpr ::= objexpr TAG_patchsmoothtri intval */
#line 89 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patchsmoothtri = C;*/}
#line 1206 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 45: /* objexpr ::= objexpr TAG_patchlimitsurface intval */
#line 90 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patchlimitsurface = C;*/}
#line 1211 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 46: /* objexpr ::= objexpr TAG_patchmeshinterp intval */
#line 91 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patchmeshinterp = C;*/}
#line 1216 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 47: /* objexpr ::= objexpr TAG_patchuvinterp intval */
#line 92 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->patchuvinterp = C;*/}
#line 1221 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 48: /* objexpr ::= objexpr TAG_segment intval */
#line 93 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->segment = C;*/}
#line 1226 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 49: /* objexpr ::= objexpr TAG_visible intval */
#line 94 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->visible = yymsp[0].minor.yy182!=0;}
#line 1231 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 50: /* objexpr ::= objexpr TAG_locking intval */
#line 95 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->locking = C;*/}
#line 1236 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 51: /* objexpr ::= objexpr TAG_shading intval */
#line 96 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->shading = (CMYObject::SHADING)yymsp[0].minor.yy182;}
#line 1241 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 52: /* objexpr ::= objexpr TAG_facet dblval */
#line 97 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->facet = C;*/}
#line 1246 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 53: /* objexpr ::= objexpr TAG_normal_weight dblval */
#line 98 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->normal_weight = C;*/}
#line 1251 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 54: /* objexpr ::= objexpr TAG_color dblval dblval dblval */
#line 99 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-4].minor.yy25; yygotominor.yy25->color[0] = yymsp[-2].minor.yy136; yygotominor.yy25->color[1] = yymsp[-1].minor.yy136; yygotominor.yy25->color[2] = yymsp[0].minor.yy136;}
#line 1256 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 55: /* objexpr ::= objexpr TAG_color_type intval */
#line 100 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; yygotominor.yy25->color_type = yymsp[0].minor.yy182?true:false;}
#line 1261 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 56: /* objexpr ::= objexpr TAG_mirror intval */
#line 101 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->mirror = (CMYObject::MIRROR)C;*/}
#line 1266 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 57: /* objexpr ::= objexpr TAG_mirror_axis intval */
#line 102 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->mirror_axis = (CMYObject::MIRRORAXIS)C;*/}
#line 1271 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 58: /* objexpr ::= objexpr TAG_mirror_dis dblval */
#line 103 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->mirror_dis = C;*/}
#line 1276 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 59: /* objexpr ::= objexpr TAG_lathe intval */
#line 104 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->lathe = C?true:false;*/}
#line 1281 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 60: /* objexpr ::= objexpr TAG_lathe_axis intval */
#line 105 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->lathe_axis = (CMYObject::LATHEAXIS)C;*/}
#line 1286 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 61: /* objexpr ::= objexpr TAG_lathe_seg intval */
#line 106 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-2].minor.yy25; /*yygotominor.yy25->lathe_seg = C;*/}
#line 1291 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 62: /* objexpr ::= objexpr TAG_vertex intval BR1 vertexexpr BR2 */
#line 107 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-5].minor.yy25; yygotominor.yy25->vertex = yymsp[-1].minor.yy33;}
#line 1296 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 63: /* objexpr ::= objexpr TAG_vertexattr BR1 vertexattrexpr2 BR2 */
#line 108 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-4].minor.yy25; yygotominor.yy25->vertexattrUID = yymsp[-1].minor.yy67->uid;}
#line 1301 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 64: /* objexpr ::= objexpr TAG_face intval BR1 faceexpr BR2 */
#line 110 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25=yymsp[-5].minor.yy25; yygotominor.yy25->face = yymsp[-1].minor.yy134;}
#line 1306 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 65: /* objexpr ::= */
#line 111 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy25 = new CMYObject();}
#line 1311 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 66: /* vertexexpr ::= vertexexpr dblval dblval dblval */
#line 113 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy33=yymsp[-3].minor.yy33; yygotominor.yy33->Add(new CMYVertex(yymsp[-2].minor.yy136,yymsp[-1].minor.yy136,yymsp[0].minor.yy136)); }
#line 1316 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 67: /* vertexexpr ::= */
#line 114 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy33 = new CAtlArray<CMYVertex*>();}
#line 1321 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 68: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_uid BR1 intarr BR2 */
#line 116 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy67=yymsp[-4].minor.yy67; yygotominor.yy67->uid = yymsp[-1].minor.yy101;}
#line 1326 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 69: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_weit BR1 weitexpr BR2 */
      case 70: /* vertexattrexpr2 ::= vertexattrexpr2 TAG_color BR1 colorexpr BR2 */ yytestcase(yyruleno==70);
#line 117 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy67=yymsp[-4].minor.yy67;}
#line 1332 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 71: /* vertexattrexpr2 ::= */
#line 119 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy67 = new __CMyVertexAttr();}
#line 1337 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 78: /* faceexpr ::= faceexpr intval faceattrexpr */
#line 130 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy134=yymsp[-2].minor.yy134; yygotominor.yy134->Add(yymsp[0].minor.yy29);}
#line 1342 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 79: /* faceexpr ::= */
#line 131 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy134 = new CAtlArray<CMYFace*>();}
#line 1347 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 80: /* faceattrexpr ::= faceattrexpr TAG_V BR3 uintarr BR4 */
#line 133 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; yygotominor.yy29->V = yymsp[-1].minor.yy150;}
#line 1352 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 81: /* faceattrexpr ::= faceattrexpr TAG_M BR3 intval BR4 */
#line 134 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; yygotominor.yy29->M = yymsp[-1].minor.yy182;}
#line 1357 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 82: /* faceattrexpr ::= faceattrexpr TAG_UID BR3 intval BR4 */
#line 135 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; /*yygotominor.yy29->UID = C;*/}
#line 1362 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 83: /* faceattrexpr ::= faceattrexpr TAG_UV BR3 dblarr BR4 */
#line 136 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; yygotominor.yy29->UV = yymsp[-1].minor.yy61;}
#line 1367 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 84: /* faceattrexpr ::= faceattrexpr TAG_COL BR3 colorrefarr BR4 */
#line 137 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; yygotominor.yy29->COL = yymsp[-1].minor.yy76;}
#line 1372 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 85: /* faceattrexpr ::= faceattrexpr TAG_CRS BR3 dblarr BR4 */
#line 138 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; /*yygotominor.yy29->CRS = C;*/}
#line 1377 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 86: /* faceattrexpr ::= faceattrexpr TAG_N BR3 dblarr BR4 */
#line 139 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29=yymsp[-4].minor.yy29; /*yygotominor.yy29->N = C;*/}
#line 1382 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 87: /* faceattrexpr ::= */
#line 140 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy29 = new CMYFace();}
#line 1387 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 88: /* uintarr ::= uintarr intval */
#line 142 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy150=yymsp[-1].minor.yy150; yygotominor.yy150->Add((uint)yymsp[0].minor.yy182);}
#line 1392 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 89: /* uintarr ::= */
#line 143 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy150 = new CAtlArray<uint>();}
#line 1397 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 90: /* colorrefarr ::= colorrefarr intval */
#line 145 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy76=yymsp[-1].minor.yy76; yygotominor.yy76->Add((COLORREF)yymsp[0].minor.yy182);}
#line 1402 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 91: /* colorrefarr ::= */
#line 146 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy76 = new CAtlArray<COLORREF>();}
#line 1407 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 92: /* intarr ::= intarr intval */
#line 148 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy101=yymsp[-1].minor.yy101; yygotominor.yy101->Add(yymsp[0].minor.yy182);}
#line 1412 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 93: /* intarr ::= */
#line 149 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy101 = new CAtlArray<int>();}
#line 1417 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 94: /* dblarr ::= dblarr dblval */
#line 151 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61=yymsp[-1].minor.yy61; yygotominor.yy61->Add(yymsp[0].minor.yy136);}
#line 1422 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      case 95: /* dblarr ::= */
#line 152 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.lemon"
{yygotominor.yy61 = new CAtlArray<double>();}
#line 1427 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
        break;
      default:
      /* (0) program ::= expr3 */ yytestcase(yyruleno==0);
      /* (1) expr3 ::= TAG_MetasequoiaDocument TAG_FormatTextVer11 expr TAG_Eof */ yytestcase(yyruleno==1);
      /* (2) expr ::= expr TAG_Material intval BR1 matexpr BR2 */ yytestcase(yyruleno==2);
      /* (5) expr ::= */ yytestcase(yyruleno==5);
      /* (10) matexpr ::= matexpr matexpr2 */ yytestcase(yyruleno==10);
      /* (11) matexpr ::= */ yytestcase(yyruleno==11);
      /* (72) weitexpr ::= weitexpr weitexpr2 */ yytestcase(yyruleno==72);
      /* (73) weitexpr ::= */ yytestcase(yyruleno==73);
      /* (74) weitexpr2 ::= intval dblval */ yytestcase(yyruleno==74);
      /* (75) colorexpr ::= colorexpr colorexpr2 */ yytestcase(yyruleno==75);
      /* (76) colorexpr ::= */ yytestcase(yyruleno==76);
      /* (77) colorexpr2 ::= intval intval */ yytestcase(yyruleno==77);
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
#line 1504 "C:\\Projects\\MQO2FBX\\MQO2FBX\\MQOParser.c"
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
