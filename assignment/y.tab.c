
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 19 "scan_yac.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "linkedlist.h"
	int yyerror(char *s);
	int error_check;
	int yylex();
	int line_co=0;
	char * Vtitle = NULL;
	LinkedList * Vfields = NULL;
	LinkedList * Vbuttons = NULL;
	FILE * error;
	extern int yylineno;
	extern char * yytext;



/* Line 189 of yacc.c  */
#line 92 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN = 258,
     TITLE = 259,
     FIELDS = 260,
     BUTTONS = 261,
     QUOATATION = 262,
     LEFTBRACE = 263,
     RIGHTBRACE = 264,
     EQUALS = 265,
     SEMICOLON = 266,
     ERRORMSG = 267,
     COMMA = 268
   };
#endif
/* Tokens.  */
#define TOKEN 258
#define TITLE 259
#define FIELDS 260
#define BUTTONS 261
#define QUOATATION 262
#define LEFTBRACE 263
#define RIGHTBRACE 264
#define EQUALS 265
#define SEMICOLON 266
#define ERRORMSG 267
#define COMMA 268




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "scan_yac.y"

	int int_val;
	char *string_val;



/* Line 214 of yacc.c  */
#line 161 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 173 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   44

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  14
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  22
/* YYNRULES -- Number of states.  */
#define YYNSTATES  50

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   268

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    27,    34,    36,    40,    47,    49,    53,    57,    61,
      68,    70,    72
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      15,     0,    -1,    16,    -1,    15,    16,    -1,    17,    -1,
      18,    -1,    20,    -1,    24,    -1,    26,    -1,    25,    -1,
       4,    10,     7,     3,     7,    11,    -1,     5,    10,     8,
      19,     9,    11,    -1,    22,    -1,    19,    13,    22,    -1,
       6,    10,     8,    21,     9,    11,    -1,    23,    -1,    21,
      13,    23,    -1,     7,     3,     7,    -1,     7,     3,     7,
      -1,     3,    10,     7,     3,     7,    11,    -1,    12,    -1,
       6,    -1,     5,    10,     8,     9,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    59,    61,    62,    63,    64,    65,    66,
      70,    79,    81,    82,    86,    88,    89,    92,    99,   105,
     169,   179,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN", "TITLE", "FIELDS", "BUTTONS",
  "QUOATATION", "LEFTBRACE", "RIGHTBRACE", "EQUALS", "SEMICOLON",
  "ERRORMSG", "COMMA", "$accept", "statements", "expression", "title",
  "fields", "f_values", "buttons", "b_values", "fitem", "bitem",
  "string_value", "parseerror", "emptylist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    14,    15,    15,    16,    16,    16,    16,    16,    16,
      17,    18,    19,    19,    20,    21,    21,    22,    23,    24,
      25,    26,    26
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       6,     6,     1,     3,     6,     1,     3,     3,     3,     6,
       1,     1,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    21,    20,     0,     2,     4,     5,
       6,     7,     9,     8,     0,     0,     0,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    15,     0,     0,     0,    22,     0,     0,     0,
       0,     0,    19,    10,    17,    11,    13,    18,    14,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    28,    10,    31,    29,    32,
      11,    12,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -12
static const yytype_int8 yypact[] =
{
       4,    -9,    -8,     3,    11,   -12,     0,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,    13,    15,    16,    17,   -12,   -12,
      20,    23,    10,    21,    22,    24,    27,    25,     2,   -12,
      29,     5,   -12,    26,    28,    31,   -12,    30,    33,    35,
      32,    21,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -12,   -12,    38,   -12,   -12,   -12,   -12,   -12,   -11,    -7,
     -12,   -12,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    14,    15,     1,     2,     3,     4,     1,     2,     3,
       4,    37,     5,    16,    40,    38,     5,    26,    41,    27,
      20,    17,    21,    24,    22,    23,    25,    46,    30,    33,
      35,    34,    39,     0,    49,     0,    36,    42,    44,    43,
      26,    45,    47,    48,    19
};

static const yytype_int8 yycheck[] =
{
       0,    10,    10,     3,     4,     5,     6,     3,     4,     5,
       6,     9,    12,    10,     9,    13,    12,     7,    13,     9,
       7,    10,     7,     3,     8,     8,     3,    38,     7,     7,
       3,     7,     3,    -1,    41,    -1,    11,    11,     7,    11,
       7,    11,     7,    11,     6
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    12,    15,    16,    17,    18,
      20,    24,    25,    26,    10,    10,    10,    10,     0,    16,
       7,     7,     8,     8,     3,     3,     7,     9,    19,    22,
       7,    21,    23,     7,     7,     3,    11,     9,    13,     3,
       9,    13,    11,    11,     7,    11,    22,     7,    11,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:

/* Line 1455 of yacc.c  */
#line 70 "scan_yac.y"
    {
	Vtitle = malloc(sizeof(char *)*strlen((yyvsp[(4) - (6)].string_val))*1);
	strcpy(Vtitle, (yyvsp[(4) - (6)].string_val));
	printf("The title is set to %s\n", Vtitle);
	free((yyvsp[(4) - (6)].string_val));
	

}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 92 "scan_yac.y"
    {
	printf("Found for Fields item: %s\n", (yyvsp[(2) - (3)].string_val)); 
	add_List(Vfields, (yyvsp[(2) - (3)].string_val)); 
	free((yyvsp[(2) - (3)].string_val));

}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 99 "scan_yac.y"
    {
	printf("Found For Buttons item: %s\n", (yyvsp[(2) - (3)].string_val));
	add_List(Vbuttons, (yyvsp[(2) - (3)].string_val));
	free((yyvsp[(2) - (3)].string_val)); 
}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "scan_yac.y"
    {
	printf("Left side: %s Right Side %s \n",(yyvsp[(1) - (6)].string_val),(yyvsp[(4) - (6)].string_val));
	node * tempF = Vfields->head;
	node * tempB = Vbuttons->head;
	int check =0;
	
	/*check for fields*/
		while(tempF!=NULL){
			/*Checking the Type of if Values of Field matches*/
			if((strcmp(tempF->string,(yyvsp[(1) - (6)].string_val)))==0){
				printf("The String -> %s matches the string -> %s \n",tempF->string,(yyvsp[(1) - (6)].string_val));
				if(tempF->value==NULL){	
					/****Checking the Value of Field****/
					if((strcmp((yyvsp[(4) - (6)].string_val),"string"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen((yyvsp[(4) - (6)].string_val)) + 1)))!=NULL){
							strcpy(tempF->value,(yyvsp[(4) - (6)].string_val));
							printf("The value record:-> %s\n",tempF->value);
							free((yyvsp[(4) - (6)].string_val));	
						}
					}else if((strcmp((yyvsp[(4) - (6)].string_val),"integer"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen((yyvsp[(4) - (6)].string_val)) + 1)))!=NULL){
							strcpy(tempF->value,(yyvsp[(4) - (6)].string_val));
							printf("The value record:-> %s\n",tempF->value);
							free((yyvsp[(4) - (6)].string_val));	
						}
					}else if ((strcmp((yyvsp[(4) - (6)].string_val),"float"))==0){
						if ((tempF->value = malloc(sizeof(char) * (strlen((yyvsp[(4) - (6)].string_val)) + 1)))!=NULL){
							strcpy(tempF->value,(yyvsp[(4) - (6)].string_val));
							printf("The value record:-> %s\n",tempF->value);
							free((yyvsp[(4) - (6)].string_val));	
						}
					}else{
					/*The Value did not match either string, float or integer*/
						printf("\nPARSE ERROR: The %s value: %s did not match  either string, float or integer\n",(yyvsp[(1) - (6)].string_val),tempF->value);
						return line_co;
					}
				}else{
					printf("\nDuplicate String for %s found at line %d ",tempF->value,line_co);
					return line_co;
				}
				check =1;
			}
		tempF = tempF->next;
		}
	

	/*checking for buttons*/
		if(check == 0){
			while(tempB!=NULL){
				/*comparing the value button with button name*/
				if((strcmp(tempB->string,(yyvsp[(1) - (6)].string_val)))==0){
					printf("The String -> %s matches the string -> %s \n",tempB->string,(yyvsp[(1) - (6)].string_val));
						/*if matched*/
					if((tempB->value = malloc(sizeof(char) * (strlen((yyvsp[(4) - (6)].string_val)) + 1)))!=NULL){
						strcpy(tempB->value,(yyvsp[(4) - (6)].string_val));
						printf("The value record:-> %s\n",tempB->value);
						free((yyvsp[(4) - (6)].string_val));
					}
				}
			tempB = tempB->next;
			}
		}
}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 169 "scan_yac.y"
    {
	
	fprintf(error,"Error Occured On Char: %s on line %d \n",yytext,line_co);
	fprintf(stderr, "Error Occured On Char: %s on line %d \n",yytext,line_co);
	return line_co;

}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 179 "scan_yac.y"
    {
	fprintf(error, "\nEmpty List\n");
	fprintf(stderr,"\nEmpty List\n");
	return line_co;
}
    break;



/* Line 1455 of yacc.c  */
#line 1522 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 184 "scan_yac.y"

/*exter variable*/

extern FILE *yyin;
extern FILE * yyout;
extern FILE * error;
extern int yyparse();
extern int line_co;
/*Main function*/
int main(int argc, const char *argv[])
{	
	/*Variable Declaration*/
	
	char * filename;
	int eCheck = 0;
	error = fopen("error.txt","w");
	/* create the field and buttons list that will be used for parsing */
	Vfields = list_create();
	Vbuttons = list_create();

	/*check for if list got created properly*/
	if ((Vfields==NULL)&&(Vbuttons==NULL)) {
		fprintf(error,"\nFields list and Buttons List creation Error\n");
		fclose(yyin);
		exit(-1);
	}
	/*checking command line arguments*/
	if (argc < 2){
		fprintf(error,"\nNeed Proper Command Line Arguments\n");
		fprintf(error,"./yadc [input file name] [output file name]\n");
		printf("\nNeed Proper Command Line Arguments\n");
		printf("./yadc [input file name] [output file name]\n");
		fclose(yyin);
		
		exit(-1);
	}else{
		/*valid arguement*/
		printf("The Input file : %s\n",argv[1]);
		yyin = fopen(argv[1],"r");
		filename = malloc(sizeof(char)*strlen(argv[1])+1);
		filename = strtok((char*)argv[1],".");
	}
	
	/*check for open and close streams*/
	if (yyin==NULL){
		fprintf(error,"\nFile Stream Parameters not Set.\nPlease check command line arguements\n");
		printf("\nFile Stream Parameters not Set.\nPlease check command line arguements\n");
	
		exit(-1);
	}

	/*Parsing the Lex info*/
	 while (!feof(yyin)){
	 	eCheck =  yyparse();
	 }
	 /*check to see parse was successful*/
	 if (eCheck==0){
	 		printf("\n\nARG 2 IS %s\n",argv[2]);
			yyout = fopen(argv[2],"w");
			/*checking if output stream is empty or not*/
			if(yyout==NULL){
				fprintf(error,"\nerror in opening and creating write file\n\n");
				
				exit(-1);
			}

	 }else{
	 	/*parse error occured*/
	 	fprintf(error,"Error Occured Parsing .Config File on Line %d\n",line_co);
	 	
	 	return line_co;
	 }
	/*pointers to head of lists*/
	 node * temp_F = Vfields->head;
	 node * temp_B = Vbuttons->head;
	 /*checking for whether all field and buttons have been asssigned a value*/
	  /*checking fields*/
	  if(temp_F!=NULL){

		 while(temp_F!=NULL){
			if (temp_F->string!=NULL){
				if(temp_F->value == NULL){
					eCheck = 1;
				}
			}
			temp_F = temp_F->next;
			}
		}else{
			fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			eCheck =1;
		}
		/*checking buttons*/
		if(temp_B!=NULL){
			while(temp_B!=NULL){
				if (temp_B->string!=NULL){
					if(temp_B->value == NULL){
						eCheck = 1;
					}
				}
				temp_B = temp_B->next;
			}
		}else{
			fprintf(error,"\n\n\nNULL TEMP Buttons\n\n\n");
			eCheck =1;
		}

	 /*if successful parse, generate file*/
	 if(eCheck == 0){

	 	/*variable declaration*/
		 int count=0;
		 /*Writing to main file */
		 fprintf(yyout,"import java.awt.*;\nimport java.awt.event.*;\nimport javax.swing.*;\nimport java.io.*;\nimport java.util.Scanner;\nimport javax.swing.border.*;\nimport java.util.ArrayList;\nimport java.lang.*;");
		 fprintf(yyout, "\n\npublic class %s extends JFrame implements %sFieldEdit {\n",filename,filename);
		 fprintf(yyout,"\n\n\t/*GUI STuff*/\n\n");
		 fprintf(yyout,"\tJPanel buttons_GUI = new JPanel();\n");
		 fprintf(yyout,"\t JPanel compile_panel_text = new JPanel();\n");
		 fprintf(yyout,"\t JPanel compile_panel = new JPanel();\n");
		 fprintf(yyout,"\t JPanel split = new JPanel();\n");
		 fprintf(yyout,"\t JTextArea message_GUI = new JTextArea();\n");
		 fprintf(yyout,"\t JScrollPane message_GUI_scroll = new JScrollPane(message_GUI);\n\n");
		 fprintf(yyout,"\t /*Layout stuff*/\n\n");
		 fprintf(yyout,"\t Box left = Box.createVerticalBox();\n");
		 fprintf(yyout,"\t Box right = Box.createVerticalBox();\n");
		 fprintf(yyout,"\t Box horizontal = Box.createHorizontalBox();\n");
		 fprintf(yyout,"\t TitledBorder status_GUI = new TitledBorder(BorderFactory.createEmptyBorder());\n");
			 /*writing generic textfields*/
			 temp_F = Vfields->head;
			 if(temp_F!=NULL){

				 while(temp_F!=NULL){
					fprintf(yyout, "\n\tJTextField text_field%d = new JTextField();\n",count);
					fprintf(yyout, "\tJLabel field_label%d = new JLabel();\n",count);
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
			/*writing generic buttons*/
			temp_B = Vbuttons->head;
			 if(temp_B!=NULL){
			 	count=0;
				 while(temp_B!=NULL){
					fprintf(yyout, "\n\tJButton button%d =  new JButton(\"%s\");",count,temp_B->string);
					count++;
					temp_B = temp_B->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
		/*constructor*/
		fprintf(yyout, "\n\n\tpublic %s (){\n\n\tsuper();",filename);	 
		fprintf(yyout, "\n\n\tsplit.setLayout(new BorderLayout());\n");
		fprintf(yyout," \tthis.setTitle(\"%s\");\n",Vtitle);
		fprintf(yyout," \t this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);\n");
		fprintf(yyout," \t this.setSize(600,600);\n");
		fprintf(yyout," \t this.setLocationRelativeTo(null);\n");
		fprintf(yyout," \t this.setLayout(new BorderLayout());\n");
		fprintf(yyout," \t message_GUI.setEditable(false);\n");
		fprintf(yyout," \t status_GUI.setTitle(\"----Status----\");\n");
		fprintf(yyout," \t message_GUI_scroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);\n");
		fprintf(yyout," \t message_GUI_scroll.setBorder(BorderFactory.createEtchedBorder());\n");
		fprintf(yyout," \t message_GUI_scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);\n");
		fprintf(yyout," \t message_GUI_scroll.setBorder(status_GUI);\n");
		fprintf(yyout," \t buttons_GUI.setLayout(new BoxLayout(buttons_GUI,BoxLayout.LINE_AXIS));\n");
			/*Setting Field Values*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tfield_label%d.setBorder(BorderFactory.createEtchedBorder());\n",count);
					fprintf(yyout,"\tfield_label%d.setFont(new Font(\"Times\", Font.BOLD, 16));\n",count);
					fprintf(yyout,"\tfield_label%d.setSize(text_field%d.getPreferredSize());\n",count,count);
					fprintf(yyout,"\tfield_label%d.setText(\"%s\");\n",count,temp_F->string);
					fprintf(yyout,"\tleft.add(field_label%d);\n",count);
					fprintf(yyout,"\t right.add(text_field%d);\n",count);
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field setting\n\n\n");
			}

			/*Setting buttons values*/
			temp_B = Vbuttons->head;
			 if(temp_B!=NULL){
			 	count=0;
				 while(temp_B!=NULL){
					fprintf(yyout, "\n\t button%d.addActionListener(new %s (this) );",count,temp_B->value);
					fprintf(yyout, "\n\tbuttons_GUI.add(button%d);\n",count);
					count++;
					temp_B = temp_B->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field\n\n\n");
			}
		/*setting things in place*/
		fprintf(yyout,"\thorizontal.add(left);\n\thorizontal.add(right);\n\tadd(horizontal,BorderLayout.NORTH);");
		fprintf(yyout,"\n\tsplit.add(buttons_GUI,BorderLayout.NORTH);\n");
		fprintf(yyout, "\tsplit.add(message_GUI_scroll,BorderLayout.CENTER);\n");
		fprintf(yyout,"\tadd(split,BorderLayout.CENTER);");
		fprintf(yyout,"\n\t}");
		
			/*Setters for field*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tpublic void setDC%s (String text){\n",temp_F->string);
					fprintf(yyout,"\n\t\t text_field%d.setText(text);",count);
					fprintf(yyout,"\n\t}");
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
			}

			/*Getters for Field*/
			temp_F = Vfields->head;
			if(temp_F!=NULL){
				count=0;
				 while(temp_F!=NULL){
					fprintf(yyout, "\n\n\tpublic String getDC%s (){\n\n",temp_F->string);
					fprintf(yyout,"\n\t\tString %s= null;",temp_F->string);
					fprintf(yyout,"\n\t\tint int_%s = 0;",temp_F->string);
					fprintf(yyout,"\n\t\tfloat float_%s = 0.0f;",temp_F->string);
					/*Trying to figure out which type values it is and setting appropiate generic functionality*/
					if((strcmp(temp_F->value,"float"))==0) { /*float*/
						fprintf(yyout,"\n\n\t\tif((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout,"\n\n\t\t\ttry{");
						fprintf(yyout,"\n\n\t\t\tfloat_%s =  Float.parseFloat(text_field%d.getText());",temp_F->string,count);
						fprintf(yyout,"\n\t\t}catch(Exception ef){");
						fprintf(yyout,"\n\t\t\tthrow new IllegalFieldValueException(text_field%d.getText());",count);
						fprintf(yyout,"\n\t\t}");
						fprintf(yyout,"\n\n\t\t\treturn text_field%d.getText();\n\n\t\t\t}",count);

					}else if((strcmp(temp_F->value,"integer"))==0){ /*Integers*/

						fprintf(yyout,"\n\n\t\tif((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout,"\n\n\t\t\ttry{");
						fprintf(yyout,"\n\n\t\t\tint_%s =  Integer.parseInt(text_field%d.getText());",temp_F->string,count);
						fprintf(yyout,"\n\t\t}catch(Exception ef){");
						fprintf(yyout,"\n\t\t\tthrow new IllegalFieldValueException(text_field%d.getText());",count);
						fprintf(yyout,"\n\t\t\t}");
						fprintf(yyout,"\n\n\t\t\treturn text_field%d.getText();\n\n\t\t\t}",count);
					}else{ /*string*/
						fprintf(yyout, "\n\n\t\tif ((text_field%d.getText())!= null && (text_field%d.getText().isEmpty())!=true){",count,count);
						fprintf(yyout, "\n\t\t\t %s = text_field%d.getText();",temp_F->string,count);
						fprintf(yyout, "\n\n\t\treturn %s;",temp_F->string);
						fprintf(yyout, "\n\n\t\t}");
					}
					/*finish the get methods*/
					fprintf(yyout,"\n\n\t\treturn null;");
					fprintf(yyout,"\n\n\t}");
					count++;
					temp_F = temp_F->next;
					}
			}else{
				fprintf(error,"\n\n\nNULL TEMP Field for getters\n\n\n");
			}
		/*append to status message*/
		fprintf(yyout, "\n\n\tpublic void appendToStatusArea(String message){\n");
		fprintf(yyout,"\n\t\t message_GUI.append(message+\" \\n \");"); 
		fprintf(yyout, "\n\n\t}");
		/*main function*/
		fprintf(yyout, "\n\n\n\tpublic static void main(String[] args) {\n");
		fprintf(yyout, "\n\t\t %s  %sinstance = new %s ();",filename,filename,filename);
		fprintf(yyout, "\n\t\t %sinstance.setVisible(true);\n\n",filename);
		fprintf(yyout, "\n\t}\n\n}");
		/***********Writing the interface, fieldEdit file************/
		/*variable declaration*/
		char inter[50], dest[50],dirname[50];
		/*getting exact output and destination for file*/
		strcpy(inter,filename);
		strcpy(dest,"FieldEdit");
		strcpy(dirname,"/");
		strcat(dirname,filename);
		strcat(inter,dirname);
		strcat(inter,dest);
		strcat(inter,".java");
		printf("The inter %s\n",inter );

			/*creating the interface*/
			if((yyout = fopen(inter,"w"))!=NULL){
					/*writing to the file*/
				fprintf(yyout, "import java.awt.*;\n");
				fprintf(yyout, "import java.awt.event.*;\n");
				fprintf(yyout, "import javax.swing.*;\n");
				fprintf(yyout, "import java.io.*;\n");
				fprintf(yyout, "import java.util.Scanner;\n");
				fprintf(yyout, "import javax.swing.border.*;\n");
				fprintf(yyout, "import java.util.ArrayList;\n");
				fprintf(yyout,"import java.lang.*;");
				fprintf(yyout,"\n\npublic interface %sFieldEdit  {\n",filename);
				fprintf(yyout,"\n\n/*Getter methods*/\n\n");
				
				/*Setters for field*/
				temp_F = Vfields->head;
				if(temp_F!=NULL){
					 while(temp_F!=NULL){
						fprintf(yyout, "\n\tpublic String getDC%s ();",temp_F->string);
						temp_F = temp_F->next;
						}
				}else{
					fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
				}
				fprintf(yyout,"\n\n/*Setter methods*/\n\n");
				
				/*Setters for field*/
				temp_F = Vfields->head;
				if(temp_F!=NULL){
					 while(temp_F!=NULL){
						fprintf(yyout, "\n\tpublic void setDC%s (String text);",temp_F->string);
						temp_F = temp_F->next;
						}
				}else{
					fprintf(error,"\n\n\nNULL TEMP Field setter\n\n\n");
				}

				fprintf(yyout,"\n\n\tpublic void appendToStatusArea(String message);\n");
				fprintf(yyout,"\n\n}");
			}/*closing the streams*/
		/**********Writing Illegal Field Exception class file*************************/
		
		char inter1[50], dest1[50],name1[50];
		strcpy(inter1,filename);
		strcpy(dest1,"/");
		strcpy(name1,"IllegalFieldValueException.java");
		strcat(inter1,dest1);
		strcat(inter1,name1);
		
		/*printing the exception handler*/
		if((yyout = fopen(inter1,"w"))!=NULL){
				
				fprintf(yyout,"import java.lang.*;");
				fprintf(yyout,"\n\npublic class IllegalFieldValueException extends RuntimeException  {\n");
				fprintf(yyout,"\n\n\tpublic IllegalFieldValueException(String ef){\n\n");
				fprintf(yyout, "\n\n\t\tsuper(ef);\n\n\t}\n}");
		}

		 fclose(yyin);
		 fclose(yyout);
	}else{
		fprintf(error,"Value of error_check%d\n",eCheck );
	
		return line_co;
	}
	destroyList(Vfields);
	destroyList(Vbuttons);
return 0;
}
/*Error function used by yacc*/
int yyerror(char *s) { 
	fprintf(stderr,"Error Occured On Char: %s on line %d \n",yytext,line_co); 
	fprintf(error,"Error Occured On Char: %s on line %d \n",yytext,line_co); 
	return line_co;
}







