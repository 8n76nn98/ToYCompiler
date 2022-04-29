/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

  ///////////////////////////////////////////////
  // Authors: Mingwei Shi & Eligijus Skersonas //
  ///////////////////////////////////////////////
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "banner.h"
  #include "globals.h"
  extern FILE *yyin;
  FILE *yyout;
  extern int lineno;
  extern int yylex();
  void yyerror();
  #define myMalloc  malloc
  #define myCalloc  calloc
  #define myFree    free
  #define myHash    hash
  // extra header here
  #include "CacheNode.h"
  #include "CacheNode.c"
  // function stack
  #include "FunctionStack.h"
  #include "FunctionStack.c"
  // Record type
  #include "StructureRecord.h"
  #include "StructureRecord.c"
  // Stack structure
  #include "Stack.h"
  #include "Stack.c"
  #include "VariableScopeCollection.h"
  #include "VariableScopeCollection.c"
  // Hashmap for type cherk
  #include "hashUtil.h"
  #include "hashMap.h"
  #include "hashUtil.c"
  #include "LexpressionLinkList.h"
  #include "LexpressionLinkList.c"
  #include "ArrayFunctionStack.h"
  #include "ArrayFunctionStack.c"

  #define GLOBAL_UNDEFINED_TYPE 0
  #define GLOBAL_INT_TYPE 1
  #define GLBOAL_BOOLEAN_TYPE 2
  #define GLOBAL_STRING_TYPE 3
  #define GL0BAL_FUNCTION_VOID_RETURN_TYPE 4

  int globalType= GLOBAL_UNDEFINED_TYPE;
  char globalFunctionNameRecord[1024];

  #define GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED 0
  #define GLOBAL_ASSIGNMENT_TRAKER_INVAILD 1
  #define GLOBAL_ASSIGNMENT_TRAKER_VAILD 2

  int assignmentTracker =GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;

  int grammarError =1;
  int semanticsError =1;
  int lexicalSpeficError;

  #include"ConditionalExpressionList.h"
  #include"ConditionalExpressionList.c"
  // Expressionlist
  #include "ExpressionCollectionList.h"
  #include "ExpressionCollectionList.c"

  #include "TypeDefaultVauleFileter.h"
  #include "TypeDefaultVauleFileter.c"

  struct  TypeDefultValueFilter *myTypeTransder;
  #include"FunctionHeaderInformationCollector.h"
  #include"FunctionHeaderInformationCollector.c"
  struct  FunctionHeaderInformationList *myFunctionInfoHeaderList;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  //  1 for left ID we need to scope undelcard checking firstly and tpe checking and prerver the word  //
  //  2 is for right part we need to undeclard checking firstly and then do semantice checking         //
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  #define LEFT_PART_EQUATION_FOR_LEFT_EXPRESSION 1
  #define RIGHT_PART_EQUATION_FOR_LEFT_EXPRESSION 2

  int globalFunctionParameterNumber = 0;
  int IDPositionSwithcer=LEFT_PART_EQUATION_FOR_LEFT_EXPRESSION;

  //////////////////////////////////////////////////
  // Scope Checking data structures and variables //
  //////////////////////////////////////////////////
  struct VariableScopeArray* myVariableLinklist;
  int globalScope = 0;
  struct FunctionList *myFunctionList;
  struct strucureList *myStructureList;
  struct ArrayFunctionStackList *myArrayFunctionList;
  List* functionNameList;
  List* structureNameList;
  List* functionDeclarationList;
  PNode LexpressionCollectionList;
  PNode LexpressionTypeCollectionList;
  PNode LFunctionParameterCollectionList;

  #define UNDEFINT_LEFTEXPRESSION_TYPE 0
  #define SWITCH_TO_PURE_ID 1
  #define SWITCH_TO_STRUCURE_DOT 2
  int assignmentLexpressionType =UNDEFINT_LEFTEXPRESSION_TYPE;

  // Type checking variable
  int globalVariableAssignmentType;
  int lastTypeOFLexpressionFiled;
  struct ExpressionTypeSystem *myType;

  ///////////////////////////////////
  // Type checking data structures //
  ///////////////////////////////////
  HashMap* functionNameCheckerhashMap;
  HashMap* structureNameCheckerhashMap;
  HashMap* filedBelongWhichStctureCheckerMap;
  HashMap* globalStrucureVaildAssignment;
  //For function call used;
  HashMap *Vaild_DeclrationWithReturnTypeFunctionChecker;
  //for quicly mapping:condition
  HashMap *functionDeclrationTypeChecker;

  //////////////////////////////////////////////////////////////////////////////////
  // First hashing last file -> strucure name eg: first_name->em1 in test1One.txt //
  // Since well-defined strucure only last filed is basic type:                   //
  // Bool int string                                                              //
  // Second hashing em1 -> Assignment                                             //
  //////////////////////////////////////////////////////////////////////////////////

  HashMap* lastFiledMapStructureTypeVariableName;
  HashMap* StrucureTypeNameAassignmentChecker;

  struct stack_t *stackForLexpression;

  //HashMap Function global
  HashMap* CreateHashMap(int n);
  int InsertHashMap(HashMap* hashMap, char* key, char* value);
  char* GetHashMap(HashMap* hashMap, char* key);
  void DeleteHashMap(HashMap* hashMap);
  void PrintHashMap(HashMap* hashMap);
  void functionSizeChecker();
  char globalFunctionCallName[1024];
  char lastStructureDotVariableGlobalRecorder[1024];
  char lastestPureIdGlobalRecorder[1024];

  int globalFunctionParameterNumberForFunctionItself = 0;

#line 218 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_THEN = 4,                       /* THEN  */
  YYSYMBOL_STRING_TYPE = 5,                /* STRING_TYPE  */
  YYSYMBOL_GREATER_THAN = 6,               /* GREATER_THAN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_PRINTF = 9,                     /* PRINTF  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_STRUCT = 13,                    /* STRUCT  */
  YYSYMBOL_LESS_THAN = 14,                 /* LESS_THAN  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 17,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 18,                    /* RPAREN  */
  YYSYMBOL_DOT = 19,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 20,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_NOT_EQUAL = 23,                 /* NOT_EQUAL  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_TRUE = 25,                      /* TRUE  */
  YYSYMBOL_FALSE = 26,                     /* FALSE  */
  YYSYMBOL_STRING_CONSTANT = 27,           /* STRING_CONSTANT  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_SUB = 29,                       /* SUB  */
  YYSYMBOL_ADD = 30,                       /* ADD  */
  YYSYMBOL_MUL = 31,                       /* MUL  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_EQUALITY = 37,                  /* EQUALITY  */
  YYSYMBOL_GREATER_OR_EQUAL = 38,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 39,             /* LESS_OR_EQUAL  */
  YYSYMBOL_ICONST = 40,                    /* ICONST  */
  YYSYMBOL_UMINUS = 41,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_toypgm = 43,                    /* toypgm  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_pgm = 45,                       /* pgm  */
  YYSYMBOL_proc = 46,                      /* proc  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_51_6 = 51,                      /* $@6  */
  YYSYMBOL_52_7 = 52,                      /* $@7  */
  YYSYMBOL_53_8 = 53,                      /* $@8  */
  YYSYMBOL_54_9 = 54,                      /* $@9  */
  YYSYMBOL_55_10 = 55,                     /* $@10  */
  YYSYMBOL_56_11 = 56,                     /* $@11  */
  YYSYMBOL_funcDeclarParameterlist = 57,   /* funcDeclarParameterlist  */
  YYSYMBOL_parameterDeclar = 58,           /* parameterDeclar  */
  YYSYMBOL_structdecl = 59,                /* structdecl  */
  YYSYMBOL_60_12 = 60,                     /* $@12  */
  YYSYMBOL_strucDeclarationList = 61,      /* strucDeclarationList  */
  YYSYMBOL_singleStructdecl = 62,          /* singleStructdecl  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_64_13 = 64,                     /* $@13  */
  YYSYMBOL_65_14 = 65,                     /* $@14  */
  YYSYMBOL_66_15 = 66,                     /* $@15  */
  YYSYMBOL_67_16 = 67,                     /* $@16  */
  YYSYMBOL_68_17 = 68,                     /* $@17  */
  YYSYMBOL_69_18 = 69,                     /* $@18  */
  YYSYMBOL_70_19 = 70,                     /* $@19  */
  YYSYMBOL_71_20 = 71,                     /* $@20  */
  YYSYMBOL_72_21 = 72,                     /* $@21  */
  YYSYMBOL_73_22 = 73,                     /* $@22  */
  YYSYMBOL_74_23 = 74,                     /* $@23  */
  YYSYMBOL_75_24 = 75,                     /* $@24  */
  YYSYMBOL_76_25 = 76,                     /* $@25  */
  YYSYMBOL_77_26 = 77,                     /* $@26  */
  YYSYMBOL_78_27 = 78,                     /* $@27  */
  YYSYMBOL_exprlist = 79,                  /* exprlist  */
  YYSYMBOL_80_28 = 80,                     /* $@28  */
  YYSYMBOL_lexprLHS = 81,                  /* lexprLHS  */
  YYSYMBOL_Stucture_LHS = 82,              /* Stucture_LHS  */
  YYSYMBOL_83_29 = 83,                     /* $@29  */
  YYSYMBOL_IFClause = 84,                  /* IFClause  */
  YYSYMBOL_IFCondition = 85,               /* IFCondition  */
  YYSYMBOL_86_30 = 86,                     /* $@30  */
  YYSYMBOL_THENCALUSE = 87,                /* THENCALUSE  */
  YYSYMBOL_IFTailer = 88,                  /* IFTailer  */
  YYSYMBOL_stmt = 89,                      /* stmt  */
  YYSYMBOL_90_31 = 90,                     /* $@31  */
  YYSYMBOL_91_32 = 91,                     /* $@32  */
  YYSYMBOL_92_33 = 92,                     /* $@33  */
  YYSYMBOL_93_34 = 93,                     /* $@34  */
  YYSYMBOL_94_35 = 94,                     /* $@35  */
  YYSYMBOL_95_36 = 95,                     /* $@36  */
  YYSYMBOL_96_37 = 96,                     /* $@37  */
  YYSYMBOL_stmtlist = 97,                  /* stmtlist  */
  YYSYMBOL_decl = 98                       /* decl  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   193,   193,   193,   238,   240,   241,   248,   275,   248,
     287,   311,   287,   322,   345,   322,   357,   380,   357,   392,
     424,   392,   443,   444,   445,   452,   474,   495,   516,   555,
     555,   576,   577,   581,   597,   613,   629,   662,   662,   663,
     663,   664,   664,   665,   665,   666,   666,   667,   667,   668,
     668,   669,   669,   670,   670,   671,   671,   672,   672,   673,
     673,   674,   674,   675,   675,   676,   676,   677,   678,   679,
     719,   720,   721,   734,   736,   775,   775,   821,   849,   853,
     853,   857,  1005,  1007,  1007,  1027,  1029,  1031,  1038,  1066,
    1102,  1038,  1128,  1129,  1130,  1130,  1203,  1203,  1217,  1218,
    1287,  1287,  1325,  1329,  1329,  1403,  1404,  1412,  1432,  1451,
    1469
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "THEN",
  "STRING_TYPE", "GREATER_THAN", "INT", "BOOL", "PRINTF", "VOID", "FOR",
  "RETURN", "STRUCT", "LESS_THAN", "LBRACE", "RBRACE", "LPAREN", "RPAREN",
  "DOT", "SEMICOLON", "COMMA", "ELSE", "NOT_EQUAL", "ID", "TRUE", "FALSE",
  "STRING_CONSTANT", "EQ", "SUB", "ADD", "MUL", "DIV", "MOD", "AND", "OR",
  "NOT", "EQUALITY", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "ICONST",
  "UMINUS", "$accept", "toypgm", "$@1", "pgm", "proc", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "funcDeclarParameterlist", "parameterDeclar", "structdecl", "$@12",
  "strucDeclarationList", "singleStructdecl", "expr", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "exprlist", "$@28", "lexprLHS",
  "Stucture_LHS", "$@29", "IFClause", "IFCondition", "$@30", "THENCALUSE",
  "IFTailer", "stmt", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36",
  "$@37", "stmtlist", "decl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-104)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -189,     3,   275,  -189,   -10,    -6,     2,    26,    42,    45,
    -189,   275,   275,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,     8,    10,    53,    70,    73,    74,  -189,  -189,  -189,
    -189,    97,  -189,   127,   127,   127,   127,    66,    68,    69,
      71,    81,    75,   127,    77,    82,    96,    98,   105,    78,
     107,   108,   109,  -189,  -189,  -189,  -189,  -189,    97,   111,
    -189,  -189,  -189,  -189,    83,   127,   113,   116,   121,  -189,
     122,   266,  -189,   266,   266,   266,   266,  -189,   128,   129,
     130,   139,   140,  -189,  -189,   -11,   131,  -189,  -189,   169,
     266,   142,   -16,   158,   159,   160,   162,   163,  -189,  -189,
    -189,   152,   157,   230,   266,  -189,  -189,   177,   236,   266,
     173,  -189,  -189,  -189,   230,  -189,  -189,  -189,  -189,   230,
     178,  -189,   230,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
       1,   182,   179,   230,   183,    80,  -189,   266,  -189,   110,
     132,   181,   174,   154,   230,   230,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,   197,  -189,   176,   201,   203,  -189,  -189,  -189,  -189,
    -189,   230,  -189,  -189,  -189,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   202,   204,
     230,    14,   211,   211,   211,  -189,  -189,   -20,   -20,   -20,
      32,    32,   211,   211,   211,   230,  -189,   208,   218,  -189,
     219,   230,  -189,   198,  -189,   266,   233,  -189
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     0,     0,     0,     0,     0,     0,
       3,     4,     4,    16,    10,    13,     7,    29,    19,     5,
       6,     0,     0,     0,     0,     0,     0,    17,    11,    14,
       8,     0,    20,    22,    22,    22,    22,     0,     0,     0,
       0,     0,    31,    22,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    35,    33,    34,    36,    30,     0,     0,
      27,    25,    26,    28,     0,    22,     0,     0,     0,    32,
       0,   105,    24,   105,   105,   105,   105,    83,     0,     0,
       0,     0,     0,    94,    96,    77,     0,    78,    92,     0,
     105,     0,     0,     0,     0,     0,     0,     0,   109,   107,
     108,     0,     0,     0,   105,    79,   110,     0,     0,     0,
      86,   106,    18,    98,     0,    12,    15,     9,    21,     0,
       0,    88,     0,    69,    71,    70,    68,    65,    63,    67,
       0,     0,     0,    73,    69,     0,    85,     0,    82,     0,
       0,     0,     0,     0,     0,     0,    59,    61,    95,    53,
      39,    37,    41,    43,    45,    47,    49,    51,    55,    57,
      97,    81,    80,    74,     0,     0,    99,    87,   102,    84,
      93,     0,    72,    66,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    89,    60,    62,    54,    40,    38,    42,    44,    46,
      48,    50,    52,    56,    58,    73,   101,     0,     0,    76,
       0,     0,   104,     0,    90,     0,     0,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,    11,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,    24,  -189,  -189,  -189,   164,
    -189,  -103,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -188,  -189,  -189,
     120,  -189,  -189,  -189,  -189,  -189,  -189,  -108,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,   -19,  -189
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    24,    36,    22,    34,    23,
      35,    21,    33,    26,    43,    48,    49,    12,    25,    41,
      42,   163,   179,   178,   180,   181,   182,   183,   184,   185,
     177,   186,   187,   175,   176,   145,   144,   164,   188,    86,
      87,   132,    88,    89,    97,   110,   138,    90,   142,   208,
     215,   103,   104,   107,   165,    91,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   136,   207,     3,   113,   135,  -100,   146,   105,   150,
     151,   139,   114,   106,    13,   147,   140,   209,    14,   143,
     146,   148,    19,    20,   149,    27,    15,    28,   147,   167,
     150,   151,   152,   153,   154,   155,   156,   149,   157,   158,
     159,   173,   174,   150,   151,   152,   153,   154,   155,   156,
      16,   157,   158,   159,    93,    94,    95,    96,    50,    51,
      52,   150,   151,   152,   153,   154,    17,    59,   191,    18,
      29,   111,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   131,   146,    30,    31,    72,
      53,    32,    54,    55,   147,    56,    58,    57,    71,    65,
     166,    60,    37,   149,    38,    39,    61,   216,   213,   150,
     151,   152,   153,   154,   155,   156,   146,   157,   158,   159,
      62,    40,    63,    64,   147,    66,    67,    68,    73,    70,
     168,    74,    44,   149,    45,    46,    75,    76,   146,   150,
     151,   152,   153,   154,   155,   156,   147,   157,   158,   159,
     169,    47,    98,    99,   100,   149,   101,   102,   112,   108,
     146,   150,   151,   152,   153,   154,   155,   156,   147,   157,
     158,   159,   172,   109,   115,   116,   117,   149,   118,   120,
     119,   121,   146,   150,   151,   152,   153,   154,   155,   156,
     147,   157,   158,   159,   133,   137,   141,   -75,   160,   149,
    -103,   170,   171,   161,   146,   150,   151,   152,   153,   154,
     155,   156,   147,   157,   158,   159,   105,  -104,   214,   189,
     190,   149,    69,   205,   206,  -104,   210,   150,   151,   152,
     153,   154,   155,   156,  -104,   157,   158,   159,   211,   212,
     150,   151,   152,   153,   154,   155,   156,   122,  -104,  -104,
    -104,   217,   162,   122,   123,   124,   125,   126,     0,   127,
     134,   124,   125,   126,     0,   127,   128,     0,     0,    77,
     129,    78,   128,    79,    80,    81,   129,    82,    83,     0,
       4,    84,     5,     6,     0,     7,     0,     0,     8,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     9
};

static const yytype_int16 yycheck[] =
{
     103,   109,   190,     0,    20,   108,    17,     6,    19,    29,
      30,   114,    28,    24,    24,    14,   119,   205,    24,   122,
       6,    20,    11,    12,    23,    17,    24,    17,    14,   137,
      29,    30,    31,    32,    33,    34,    35,    23,    37,    38,
      39,   144,   145,    29,    30,    31,    32,    33,    34,    35,
      24,    37,    38,    39,    73,    74,    75,    76,    34,    35,
      36,    29,    30,    31,    32,    33,    24,    43,   171,    24,
      17,    90,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   104,     6,    17,    15,    65,
      24,    17,    24,    24,    14,    24,    21,    16,    15,    21,
      20,    24,     5,    23,     7,     8,    24,   215,   211,    29,
      30,    31,    32,    33,    34,    35,     6,    37,    38,    39,
      24,    24,    24,    18,    14,    18,    18,    18,    15,    18,
      20,    15,     5,    23,     7,     8,    15,    15,     6,    29,
      30,    31,    32,    33,    34,    35,    14,    37,    38,    39,
      18,    24,    24,    24,    24,    23,    17,    17,    16,    28,
       6,    29,    30,    31,    32,    33,    34,    35,    14,    37,
      38,    39,    18,     4,    16,    16,    16,    23,    16,    27,
      17,    24,     6,    29,    30,    31,    32,    33,    34,    35,
      14,    37,    38,    39,    17,    22,    18,    21,    16,    23,
      17,    20,    28,    24,     6,    29,    30,    31,    32,    33,
      34,    35,    14,    37,    38,    39,    19,     6,    20,    18,
      17,    23,    58,    21,    20,    14,    18,    29,    30,    31,
      32,    33,    34,    35,    23,    37,    38,    39,    20,    20,
      29,    30,    31,    32,    33,    34,    35,    17,    37,    38,
      39,    18,   132,    17,    24,    25,    26,    27,    -1,    29,
      24,    25,    26,    27,    -1,    29,    36,    -1,    -1,     3,
      40,     5,    36,     7,     8,     9,    40,    11,    12,    -1,
       5,    15,     7,     8,    -1,    10,    -1,    -1,    13,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     5,     7,     8,    10,    13,    24,
      45,    46,    59,    24,    24,    24,    24,    24,    24,    45,
      45,    53,    49,    51,    47,    60,    55,    17,    17,    17,
      17,    15,    17,    54,    50,    52,    48,     5,     7,     8,
      24,    61,    62,    56,     5,     7,     8,    24,    57,    58,
      57,    57,    57,    24,    24,    24,    24,    16,    21,    57,
      24,    24,    24,    24,    18,    21,    18,    18,    18,    61,
      18,    15,    57,    15,    15,    15,    15,     3,     5,     7,
       8,     9,    11,    12,    15,    24,    81,    82,    84,    85,
      89,    97,    98,    97,    97,    97,    97,    86,    24,    24,
      24,    17,    17,    93,    94,    19,    24,    95,    28,     4,
      87,    97,    16,    20,    28,    16,    16,    16,    16,    17,
      27,    24,    17,    24,    25,    26,    27,    29,    36,    40,
      63,    97,    83,    17,    24,    63,    89,    22,    88,    63,
      63,    18,    90,    63,    78,    77,     6,    14,    20,    23,
      29,    30,    31,    32,    33,    34,    35,    37,    38,    39,
      16,    24,    82,    63,    79,    96,    20,    89,    20,    18,
      20,    28,    18,    63,    63,    75,    76,    72,    65,    64,
      66,    67,    68,    69,    70,    71,    73,    74,    80,    18,
      17,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    21,    20,    79,    91,    79,
      18,    20,    20,    63,    20,    92,    89,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    43,    45,    45,    45,    47,    48,    46,
      49,    50,    46,    51,    52,    46,    53,    54,    46,    55,
      56,    46,    57,    57,    57,    58,    58,    58,    58,    60,
      59,    61,    61,    62,    62,    62,    62,    64,    63,    65,
      63,    66,    63,    67,    63,    68,    63,    69,    63,    70,
      63,    71,    63,    72,    63,    73,    63,    74,    63,    75,
      63,    76,    63,    77,    63,    78,    63,    63,    63,    63,
      63,    63,    63,    79,    79,    80,    79,    81,    81,    83,
      82,    82,    84,    86,    85,    87,    88,    88,    90,    91,
      92,    89,    89,    89,    93,    89,    94,    89,    89,    89,
      95,    89,    89,    96,    89,    97,    97,    98,    98,    98,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     0,    10,
       0,     0,    10,     0,     0,    10,     0,     0,    10,     0,
       0,    10,     0,     1,     3,     2,     2,     2,     2,     0,
       6,     1,     3,     2,     2,     2,     2,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     3,     0,     1,     0,     4,     1,     1,     0,
       4,     1,     3,     0,     5,     2,     0,     2,     0,     0,
       0,    13,     1,     5,     0,     4,     0,     4,     2,     4,
       0,     6,     4,     0,     8,     0,     2,     2,     2,     2,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 193 "parser.y"
        {
        printBanner();
        assignmentLexpressionType=0;
        IDPositionSwithcer=LEFT_PART_EQUATION_FOR_LEFT_EXPRESSION;
        myTypeTransder = initilization_typeDefaultFilter(myTypeTransder);

        stackForLexpression= newStack();
        myFunctionList =init_FunctionList(myFunctionList); // Function linklist initilization;
        myStructureList = init_strucure_list(myStructureList);
        myArrayFunctionList =Arrayinit_FunctionList(myArrayFunctionList);
        functionNameCheckerhashMap = CreateHashMap(1024);
        structureNameCheckerhashMap =CreateHashMap(1024);
        globalStrucureVaildAssignment =CreateHashMap(1024); 

        lastFiledMapStructureTypeVariableName  =CreateHashMap(1024);
        StrucureTypeNameAassignmentChecker= CreateHashMap(1024);

        filedBelongWhichStctureCheckerMap = CreateHashMap(1024);
        Vaild_DeclrationWithReturnTypeFunctionChecker= CreateHashMap(1024);
        functionDeclrationTypeChecker= CreateHashMap(1024);

        functionNameList =(List*)malloc(sizeof(List)); // Linklist initlization
        initList(functionNameList);
        myFunctionInfoHeaderList = initilizaion_functionHeaderinformation(myFunctionInfoHeaderList);

        structureNameList=(List*)malloc(sizeof(List));
        initList(structureNameList);

        functionDeclarationList=(List*)malloc(sizeof(List));
        initList(functionDeclarationList);

        LexpressionList_initilization(&LexpressionCollectionList);
        LexpressionList_initilization(&LexpressionTypeCollectionList);

        LexpressionList_initilization(&LFunctionParameterCollectionList);
        IDPositionSwithcer =LEFT_PART_EQUATION_FOR_LEFT_EXPRESSION;
        myType = InitilizationAndResetOfTypeSystem(myType);
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);   
      }
#line 1508 "parser.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 248 "parser.y"
          {
        char *tempIDname = (yyvsp[0].str_val);
        char *functionNameCheckFlag = GetHashMap(functionNameCheckerhashMap,tempIDname);

        if(functionNameCheckFlag){
          printf("GRAMMAR ERROR: procedure %s() already in use\n",(yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if(functionNameCheckFlag == NULL){
          char *tempType = "void";
          insertFuncttionName(myFunctionList,(yyvsp[0].str_val),tempType);
          ArrayInsertFunctionName(myArrayFunctionList,(yyvsp[0].str_val),tempType);
          addAtHeadCacheNode(functionDeclarationList,"void");
          addAtHeadCacheNode(functionNameList,(yyvsp[0].str_val));

          char *temp1 = acquireHeadOfListCache(functionNameList);
          InsertHashMap(functionNameCheckerhashMap,tempIDname, "used"); // We need to insert stackMap here
          myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist); // Initlize when in the new function
          InsertHashMap(functionDeclrationTypeChecker,tempIDname,tempType);
          // Function header info
          addFunctionDeclartionType_ID_InFunctionHeaderList(myFunctionInfoHeaderList,tempType,tempIDname);
          // For void function we did a special trick            
          InsertHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,tempIDname,"vaild");
          InsertHashMap(functionDeclrationTypeChecker,tempIDname,"void");
          
        } // end if
  }
#line 1541 "parser.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 275 "parser.y"
            {
        globalScope += 1; // increase scope
        char *tempName = (yyvsp[-2].str_val); 
        bracketControlAdd(myFunctionList,tempName);
        ArraybracketControlAdd(myArrayFunctionList,tempName);

  }
#line 1553 "parser.tab.c"
    break;

  case 9: /* proc: VOID ID $@2 LPAREN $@3 funcDeclarParameterlist RPAREN LBRACE stmtlist RBRACE  */
#line 281 "parser.y"
                                                          {
        // reset globalscope and variablelist
        globalScope = 0;
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);

  }
#line 1564 "parser.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 287 "parser.y"
         {
        char *tempIDname = (yyvsp[0].str_val);
        char *functionNameCheckFlag = GetHashMap(functionNameCheckerhashMap,tempIDname);

        if(functionNameCheckFlag){
          printf("GRAMMAR ERROR: procedure %s() already in use\n",(yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if(functionNameCheckFlag == NULL){
          char *tempType = "int";
          insertFuncttionName(myFunctionList,(yyvsp[0].str_val),tempType);
          ArrayInsertFunctionName(myArrayFunctionList,(yyvsp[0].str_val),tempType);
          addAtHeadCacheNode(functionDeclarationList,"int");
          addAtHeadCacheNode(functionNameList,(yyvsp[0].str_val));

          char *temp1 = acquireHeadOfListCache(functionNameList);
          InsertHashMap(functionNameCheckerhashMap,tempIDname, "used"); // We need to insert stackMap here
          myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
         
          InsertHashMap(functionDeclrationTypeChecker,tempIDname,tempType);
          addFunctionDeclartionType_ID_InFunctionHeaderList(myFunctionInfoHeaderList,tempType,tempIDname);

        } // end if
  }
#line 1594 "parser.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 311 "parser.y"
            {
        char *tempName = (yyvsp[-2].str_val);
        bracketControlAdd(myFunctionList,tempName);
        ArraybracketControlAdd(myArrayFunctionList,tempName);
        globalScope+=1; // increase scope

  }
#line 1606 "parser.tab.c"
    break;

  case 12: /* proc: INT ID $@4 LPAREN $@5 funcDeclarParameterlist RPAREN LBRACE stmtlist RBRACE  */
#line 317 "parser.y"
                                                           {
        // reset globalscope and variablelist
        globalScope=0;
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
  }
#line 1616 "parser.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 322 "parser.y"
          {
        char *tempIDname = (yyvsp[0].str_val);
        char *functionNameCheckFlag = GetHashMap(functionNameCheckerhashMap,tempIDname);
    
        if(functionNameCheckFlag){
          printf("GRAMMAR ERROR: procedure %s() already in use\n",(yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if(functionNameCheckFlag  == NULL){
          char *tempType = "bool";
          insertFuncttionName(myFunctionList,(yyvsp[0].str_val),tempType);
          ArrayInsertFunctionName(myArrayFunctionList,(yyvsp[0].str_val),tempType);
          addAtHeadCacheNode(functionDeclarationList,"bool");
          addAtHeadCacheNode(functionNameList,(yyvsp[0].str_val));

          char *temp1 = acquireHeadOfListCache(functionNameList);
          InsertHashMap(functionNameCheckerhashMap,tempIDname, "used"); // We need to insert stackMap here
          myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
          addFunctionDeclartionType_ID_InFunctionHeaderList(myFunctionInfoHeaderList,tempType,tempIDname);
          InsertHashMap(functionDeclrationTypeChecker,tempIDname,tempType);
        
        } // end if
  }
#line 1645 "parser.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 345 "parser.y"
           {
        char *tempName = (yyvsp[-2].str_val);
        bracketControlAdd(myFunctionList,tempName);
        ArraybracketControlAdd(myArrayFunctionList,tempName);
        globalScope += 1; // increase scope

  }
#line 1657 "parser.tab.c"
    break;

  case 15: /* proc: BOOL ID $@6 LPAREN $@7 funcDeclarParameterlist RPAREN LBRACE stmtlist RBRACE  */
#line 351 "parser.y"
                                                          {
        // reset globalscope and variablelist
        globalScope = 0;
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);

  }
#line 1668 "parser.tab.c"
    break;

  case 16: /* $@8: %empty  */
#line 357 "parser.y"
                 {
        char *tempIDname = (yyvsp[0].str_val);
        char *functionNameCheckFlag = GetHashMap(functionNameCheckerhashMap,tempIDname);

        if(functionNameCheckFlag){
          printf("GRAMMAR ERROR: procedure %s() already in use\n",(yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if(functionNameCheckFlag  == NULL){
          char *tempType = "string";
          insertFuncttionName(myFunctionList,(yyvsp[0].str_val),tempType);
          ArrayInsertFunctionName(myArrayFunctionList,(yyvsp[0].str_val),tempType);
          addAtHeadCacheNode(functionDeclarationList,"string");
          addAtHeadCacheNode(functionNameList,(yyvsp[0].str_val));

          char *temp1 = acquireHeadOfListCache(functionNameList);
          InsertHashMap(functionNameCheckerhashMap,tempIDname, "used"); // We need to insert stackMap here
          myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
          addFunctionDeclartionType_ID_InFunctionHeaderList(myFunctionInfoHeaderList,tempType,tempIDname);
          InsertHashMap(functionDeclrationTypeChecker,tempIDname,tempType);
        
        } // end if
  }
#line 1697 "parser.tab.c"
    break;

  case 17: /* $@9: %empty  */
#line 380 "parser.y"
           {
        char *tempName = (yyvsp[-2].str_val);
        bracketControlAdd(myFunctionList,tempName);
        ArraybracketControlAdd(myArrayFunctionList,tempName);
        globalScope += 1; // increase scope

  }
#line 1709 "parser.tab.c"
    break;

  case 18: /* proc: STRING_TYPE ID $@8 LPAREN $@9 funcDeclarParameterlist RPAREN LBRACE stmtlist RBRACE  */
#line 386 "parser.y"
                                                          {
        // reset globalscope and variablelist
        globalScope = 0;
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);

  }
#line 1720 "parser.tab.c"
    break;

  case 19: /* $@10: %empty  */
#line 392 "parser.y"
        {
        char * structureName = (yyvsp[-1].str_val);
        char * strctureNameCheckerFlag = GetHashMap(structureNameCheckerhashMap,structureName);

        if(strctureNameCheckerFlag == NULL){
          printf("GRAMMAR ERROR: Structure %s has not been declared\n", structureName);
          grammarError = 0;
        } // end if

        if (structureNameCheckerhashMap) {
          char * tempIDname = (yyvsp[0].str_val);
          char * functionNameCheckFlag = GetHashMap(functionNameCheckerhashMap, tempIDname);

          if (functionNameCheckFlag) {
            printf("GRAMMAR ERROR: procedure %s() already in use\n",(yyvsp[0].str_val));
            grammarError = 0;
          } // end if

          if (functionNameCheckFlag == NULL) {
            char * tempType = (yyvsp[-1].str_val);
            insertFuncttionName(myFunctionList, (yyvsp[0].str_val), tempType);
            ArrayInsertFunctionName(myArrayFunctionList,(yyvsp[0].str_val),tempType);
            addAtHeadCacheNode(functionDeclarationList, tempType);
            addAtHeadCacheNode(functionNameList, (yyvsp[0].str_val));

            char * temp1 = acquireHeadOfListCache(functionNameList);
            InsertHashMap(functionNameCheckerhashMap, tempIDname, "used"); // We need to insert stackMap here
            myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
            InsertHashMap(functionDeclrationTypeChecker,tempIDname,structureName);
            addFunctionDeclartionType_ID_InFunctionHeaderList(myFunctionInfoHeaderList,tempType,tempIDname);
          } // end if
        } // end if
}
#line 1758 "parser.tab.c"
    break;

  case 20: /* $@11: %empty  */
#line 424 "parser.y"
         {
        char *tempName = (yyvsp[-2].str_val);
        bracketControlAdd(myFunctionList,tempName);
        ArraybracketControlAdd(myArrayFunctionList,tempName);
        globalScope += 1; // increase scope

}
#line 1770 "parser.tab.c"
    break;

  case 21: /* proc: ID ID $@10 LPAREN $@11 funcDeclarParameterlist RPAREN LBRACE stmtlist RBRACE  */
#line 430 "parser.y"
                                                        {
        globalScope = 0;
        myVariableLinklist = initilization_And_Reset_variableScopearray(myVariableLinklist);
}
#line 1779 "parser.tab.c"
    break;

  case 22: /* funcDeclarParameterlist: %empty  */
#line 443 "parser.y"
  {/*Empty Parameter List*/}
#line 1785 "parser.tab.c"
    break;

  case 25: /* parameterDeclar: INT ID  */
#line 452 "parser.y"
          {
        char *variableName =(yyvsp[0].str_val);
        char *variableType = "int";
     
        char *latestFunctionName = acquireHeadOfListCache(functionNameList);
        char *latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
        if(redeclatedCheck == RECLRATED) { // check if redeclared
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if(redeclatedCheck == NOT_RECLARED){ // if not redeclared
          insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          // adding function parameter in the header list
          addFunctionFunctionParameterInFunctionHeaderList(myFunctionInfoHeaderList,latestFunctionName,variableType,variableName);

        } // end if
  }
#line 1812 "parser.tab.c"
    break;

  case 26: /* parameterDeclar: BOOL ID  */
#line 474 "parser.y"
          {
        char *variableName =(yyvsp[0].str_val);
        char *variableType = "bool";
        char *latestFunctionName = acquireHeadOfListCache(functionNameList);
        char *latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck = checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
        if(redeclatedCheck == RECLRATED){ // check if redeclared
            printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
            grammarError = 0;
        }

        if(redeclatedCheck == NOT_RECLARED){ // if not redeclared
          inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
          insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          // adding function parameter in the header list
          addFunctionFunctionParameterInFunctionHeaderList(myFunctionInfoHeaderList,latestFunctionName,variableType,variableName);
        
       }    
  }
#line 1838 "parser.tab.c"
    break;

  case 27: /* parameterDeclar: STRING_TYPE ID  */
#line 495 "parser.y"
                 {
        char * variableName = (yyvsp[0].str_val);
        char * variableType = "string";
        char * latestFunctionName = acquireHeadOfListCache(functionNameList);
        char * latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
        if (redeclatedCheck == RECLRATED) { // check if redeclared
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if (redeclatedCheck == NOT_RECLARED) { // if not redeclared
          insertVariableDeclarationforSpecificFunction(myFunctionList, latestFunctionName, latestFunctionType, variableType, variableName);
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
          // adding function parameter in the header list
          addFunctionFunctionParameterInFunctionHeaderList(myFunctionInfoHeaderList,latestFunctionName,variableType,variableName);
        
        } // end if
  }
#line 1864 "parser.tab.c"
    break;

  case 28: /* parameterDeclar: ID ID  */
#line 516 "parser.y"
        {
        char * structureName = (yyvsp[-1].str_val);
        char * strctureNameCheckerFlag = GetHashMap(structureNameCheckerhashMap, structureName);

        if (strctureNameCheckerFlag == NULL) {
          printf("GRAMMAR ERROR: Structure %s has not been declared \n", structureName);
          grammarError = 0;
        }

        if(strctureNameCheckerFlag) {           
          char *variableName =(yyvsp[0].str_val);
          char *variableType = (yyvsp[-1].str_val);
          char *latestFunctionName = acquireHeadOfListCache(functionNameList);
          char *latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

          int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
          if(redeclatedCheck == RECLRATED){ // check if redeclared
            printf("GRAMMAR ERROR: %s %s is already in use \n", (yyvsp[-1].str_val), (yyvsp[0].str_val));
            grammarError = 0;
          } // end if

          if(redeclatedCheck == NOT_RECLARED){ // if not redeclared
            insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
            ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
            inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
            // adding function parameter in the header list
            addFunctionFunctionParameterInFunctionHeaderList(myFunctionInfoHeaderList,latestFunctionName,variableType,variableName);
        
          } // end if  
        } // end if

  }
#line 1901 "parser.tab.c"
    break;

  case 29: /* $@12: %empty  */
#line 555 "parser.y"
            {
        char *tempStrctureName = (yyvsp[0].str_val);
        char *structureNameChecker =  GetHashMap(structureNameCheckerhashMap,tempStrctureName);
        
        if(structureNameChecker){
          printf("GRAMMAR ERROR: Structure already in use \n");
          grammarError = 0;
        }

        if(structureNameChecker == NULL){
          add_strucure_name(myStructureList,tempStrctureName);
          addAtHeadCacheNode(structureNameList,tempStrctureName);
          InsertHashMap(structureNameCheckerhashMap,tempStrctureName, "used");
        }

}
#line 1922 "parser.tab.c"
    break;

  case 33: /* singleStructdecl: INT ID  */
#line 581 "parser.y"
         {
        char *tempFiledID = (yyvsp[0].str_val);
        char *latesutStuctureName = acquireHeadOfListCache(structureNameList);

        int filedCheck = checker_structureFiled(myStructureList,latesutStuctureName,tempFiledID);
        if(filedCheck == 1){
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0;  
        } // end if

        if(filedCheck == 0){
          char *tempType = "int";
          add_structureFiled(myStructureList,latesutStuctureName,tempType,tempFiledID);
          char *lastStcureNamsssss = acquireHeadOfListCache(structureNameList);
        } // end if
  }
#line 1943 "parser.tab.c"
    break;

  case 34: /* singleStructdecl: BOOL ID  */
#line 597 "parser.y"
          {
        char *tempFiledID = (yyvsp[0].str_val);
        char *latesutStuctureName = acquireHeadOfListCache(structureNameList);
      
        int filedCheck = checker_structureFiled(myStructureList,latesutStuctureName,tempFiledID);
        if(filedCheck == 1){
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0; 
        } // end if

        if(filedCheck == 0){
          char *tempType = "bool"; 
          add_structureFiled(myStructureList,latesutStuctureName,tempType,tempFiledID);
          char *lastStcureNamsssss = acquireHeadOfListCache(structureNameList);
        }        
  }
#line 1964 "parser.tab.c"
    break;

  case 35: /* singleStructdecl: STRING_TYPE ID  */
#line 613 "parser.y"
                  {
        char *tempFiledID = (yyvsp[0].str_val);
        char *latesutStuctureName = acquireHeadOfListCache(structureNameList);

        int filedCheck = checker_structureFiled(myStructureList,latesutStuctureName,tempFiledID);
        if(filedCheck == 1){
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0;
        }

        if(filedCheck ==0){
          char *tempType = "string";
          add_structureFiled(myStructureList,latesutStuctureName,tempType,tempFiledID);
          char *lastStcureNamsssss = acquireHeadOfListCache(structureNameList);
        }        
    }
#line 1985 "parser.tab.c"
    break;

  case 36: /* singleStructdecl: ID ID  */
#line 629 "parser.y"
        {
        char * structureName = (yyvsp[-1].str_val);
        char * strctureNameCheckerFlag = GetHashMap(structureNameCheckerhashMap, structureName);
        if (strctureNameCheckerFlag == NULL) {
          printf("GRAMMAR ERROR: Structure %s has not been declared \n", structureName);
          grammarError = 0;
        }
        if (structureNameCheckerhashMap) {
          char *tempFiledID = (yyvsp[0].str_val);
          char *latesutStuctureName = acquireHeadOfListCache(structureNameList);
        
          int filedCheck = checker_structureFiled(myStructureList,latesutStuctureName,tempFiledID);
          if(filedCheck == 1){
            printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
            grammarError = 0;
          }

          if(filedCheck == 0){
            char *tempType = (yyvsp[-1].str_val);
            add_structureFiled(myStructureList,latesutStuctureName,tempType,tempFiledID);
            char *lastStcureNamsssss = acquireHeadOfListCache(structureNameList);
          } // end if   
        } // end if
  }
#line 2014 "parser.tab.c"
    break;

  case 37: /* $@13: %empty  */
#line 662 "parser.y"
                        {typeSystem_tailInsert(myType,"+");}
#line 2020 "parser.tab.c"
    break;

  case 39: /* $@14: %empty  */
#line 663 "parser.y"
                        {typeSystem_tailInsert(myType,"-");}
#line 2026 "parser.tab.c"
    break;

  case 41: /* $@15: %empty  */
#line 664 "parser.y"
                        {typeSystem_tailInsert(myType,"*");}
#line 2032 "parser.tab.c"
    break;

  case 43: /* $@16: %empty  */
#line 665 "parser.y"
                        {typeSystem_tailInsert(myType,"/");}
#line 2038 "parser.tab.c"
    break;

  case 45: /* $@17: %empty  */
#line 666 "parser.y"
                        {typeSystem_tailInsert(myType,"mod");}
#line 2044 "parser.tab.c"
    break;

  case 47: /* $@18: %empty  */
#line 667 "parser.y"
                        {typeSystem_tailInsert(myType,"and");}
#line 2050 "parser.tab.c"
    break;

  case 49: /* $@19: %empty  */
#line 668 "parser.y"
                        {typeSystem_tailInsert(myType,"or");}
#line 2056 "parser.tab.c"
    break;

  case 51: /* $@20: %empty  */
#line 669 "parser.y"
                        {typeSystem_tailInsert(myType,"==");}
#line 2062 "parser.tab.c"
    break;

  case 53: /* $@21: %empty  */
#line 670 "parser.y"
                        {typeSystem_tailInsert(myType,"!=");}
#line 2068 "parser.tab.c"
    break;

  case 55: /* $@22: %empty  */
#line 671 "parser.y"
                        {typeSystem_tailInsert(myType,">=");}
#line 2074 "parser.tab.c"
    break;

  case 57: /* $@23: %empty  */
#line 672 "parser.y"
                        {typeSystem_tailInsert(myType,"<=");}
#line 2080 "parser.tab.c"
    break;

  case 59: /* $@24: %empty  */
#line 673 "parser.y"
                        {typeSystem_tailInsert(myType,">");}
#line 2086 "parser.tab.c"
    break;

  case 61: /* $@25: %empty  */
#line 674 "parser.y"
                        {typeSystem_tailInsert(myType,"<");}
#line 2092 "parser.tab.c"
    break;

  case 63: /* $@26: %empty  */
#line 675 "parser.y"
                        {typeSystem_tailInsert(myType,"not");}
#line 2098 "parser.tab.c"
    break;

  case 65: /* $@27: %empty  */
#line 676 "parser.y"
                        {typeSystem_tailInsert(myType,"-");}
#line 2104 "parser.tab.c"
    break;

  case 67: /* expr: ICONST  */
#line 677 "parser.y"
                        {typeSystem_tailInsert(myType,(yyvsp[0].str_val));}
#line 2110 "parser.tab.c"
    break;

  case 68: /* expr: STRING_CONSTANT  */
#line 678 "parser.y"
                        {typeSystem_tailInsert(myType,(yyvsp[0].str_val));}
#line 2116 "parser.tab.c"
    break;

  case 69: /* expr: ID  */
#line 679 "parser.y"
       {
        char *latestfUNCTIOnmae = acquireHeadOfListCache(functionNameList);
        char *tempId = (yyvsp[0].str_val);
        int undelclaredCheck = checkVariableUndeclarationVariableScopeArray(myVariableLinklist,tempId,globalScope);

        if(undelclaredCheck == UNDELCARED){
          printf("GRAMMAR ERROR: %s is undeclared in variable assignment \n", (yyvsp[0].str_val));
          grammarError =0;
          assignmentTracker =GLOBAL_ASSIGNMENT_TRAKER_INVAILD;
        }
        if(undelclaredCheck== NOT_UNCLEATION){
          int AssignmentAlradyChcker = checkAssignedAlreadyVariableInVariabelScopeArray(myVariableLinklist,tempId,globalScope);

          if(AssignmentAlradyChcker == 0){
            semanticsError = 0;
            printf("SEMANTICS ERROR: variable in expression is not initialised \n");
          }
          else{
            char *returnTypeOfThisID = returnTypeOfVaribleInVaribaleScopeArray(myVariableLinklist,tempId,globalScope);
            if (strcmp(returnTypeOfThisID, "int") == 0){
              adding_abstructureTypeInDefaultFileter(myTypeTransder, "int");
              char * returnVaule = acquireFilterVaule(myTypeTransder);
              typeSystem_tailInsert(myType, returnVaule);
              myTypeTransder = initilization_typeDefaultFilter(myTypeTransder);
            } 
            else if (strcmp(returnTypeOfThisID, "bool") == 0){
                adding_abstructureTypeInDefaultFileter(myTypeTransder, "bool");
                char * returnVaule = acquireFilterVaule(myTypeTransder);
                typeSystem_tailInsert(myType, returnVaule);
                myTypeTransder = initilization_typeDefaultFilter(myTypeTransder);
            } 
            else if (strcmp(returnTypeOfThisID, "string") == 0){
                adding_abstructureTypeInDefaultFileter(myTypeTransder, "string");
                char * returnVaule = acquireFilterVaule(myTypeTransder);
                typeSystem_tailInsert(myType, returnVaule);
                myTypeTransder = initilization_typeDefaultFilter(myTypeTransder);
            }
          }
        }  
}
#line 2161 "parser.tab.c"
    break;

  case 70: /* expr: FALSE  */
#line 719 "parser.y"
                {typeSystem_tailInsert(myType,"false");}
#line 2167 "parser.tab.c"
    break;

  case 71: /* expr: TRUE  */
#line 720 "parser.y"
                {typeSystem_tailInsert(myType,"true");}
#line 2173 "parser.tab.c"
    break;

  case 74: /* exprlist: expr  */
#line 736 "parser.y"
       {
        globalFunctionParameterNumber+=1;
        int emptyCheck = isEmptyLexpressionList(LFunctionParameterCollectionList);

        if(globalFunctionParameterNumber>globalFunctionParameterNumberForFunctionItself){
            semanticsError=0;
            printf("SEMANTIC ERROR: Expression number > function parameter number \n");
        }
        else{
          char *TopElementType = acquireFirstElementOfLexpressionList(&LFunctionParameterCollectionList);
          if (strcmp(TopElementType, "int") == 0) 
              globalType = GLOBAL_INT_TYPE;
          else if (strcmp(TopElementType, "bool") == 0)
              globalType = GLBOAL_BOOLEAN_TYPE;
          else if (strcmp(TopElementType, "string") == 0) 
            globalType = GLOBAL_STRING_TYPE;

          int temp = globalType;
          modifyEnvironmentTypeSystemInExpressionList(myType, temp);

          // clear expression list here
          typeSystem_Print(myType);
          int result;
          int ExpressionNumber = myType -> expressionNumber;

          result = typeSystemSelectionAndJudgeSystem(myType);

          if (result == 0) {
              semanticsError = 0;
              printf("SEMANTICS ERROR: type checking error occurred \n");
          } 

          // FOR NEXT iteration
          globalType = GLOBAL_UNDEFINED_TYPE;
          myType = InitilizationAndResetOfTypeSystem(myType);

          LexpressionList_headDelete( & LFunctionParameterCollectionList);
       }
}
#line 2217 "parser.tab.c"
    break;

  case 75: /* $@28: %empty  */
#line 775 "parser.y"
       {
        globalFunctionParameterNumber += 1;
        if (globalFunctionParameterNumber > globalFunctionParameterNumberForFunctionItself){
          semanticsError = 0;
          printf("SEMANTICS ERROR: Expression number > function parameter number\n");
        } 
        else {
          char * TopElementType = acquireFirstElementOfLexpressionList( & LFunctionParameterCollectionList);

          if (strcmp(TopElementType, "int") == 0)
            globalType = GLOBAL_INT_TYPE;
          else if (strcmp(TopElementType, "bool") == 0)
            globalType = GLBOAL_BOOLEAN_TYPE;
          else if (strcmp(TopElementType, "string") == 0) 
            globalType = GLOBAL_STRING_TYPE;
    
          int temp = globalType;
          modifyEnvironmentTypeSystemInExpressionList(myType, temp);

          // clear expression list here
          typeSystem_Print(myType);
          int result;
          int ExpressionNumber = myType -> expressionNumber;
          result = typeSystemSelectionAndJudgeSystem(myType);

          if (result == 0) {
              semanticsError = 0;
              printf("SEMANTICS ERROR: Type checking error occurred \n");
          } 

          // FOR NEXT iteration
          globalType = GLOBAL_UNDEFINED_TYPE;
          myType = InitilizationAndResetOfTypeSystem(myType);

          LexpressionList_headDelete( & LFunctionParameterCollectionList);

        }

}
#line 2261 "parser.tab.c"
    break;

  case 77: /* lexprLHS: ID  */
#line 821 "parser.y"
     {
        char *latestfUNCTIOnmae = acquireHeadOfListCache(functionNameList);
        char *tempId = (yyvsp[0].str_val);
        int undelclaredCheck = checkVariableUndeclarationVariableScopeArray(myVariableLinklist,tempId,globalScope);

        if(undelclaredCheck == UNDELCARED){
          printf("GRAMMAR ERROR: %s is undeclared in variable assignment \n", (yyvsp[0].str_val));
          grammarError = 0;
          assignmentTracker = GLOBAL_ASSIGNMENT_TRAKER_INVAILD;
        }
        if(undelclaredCheck == NOT_UNCLEATION){
          char *returnTypeOfThisId = returnTypeOfVaribleInVaribaleScopeArray(myVariableLinklist,tempId,globalScope);

          if(strcmp(returnTypeOfThisId,"int")==0)
            globalType = GLOBAL_INT_TYPE;
          else if(strcmp(returnTypeOfThisId,"bool")==0)
            globalType = GLBOAL_BOOLEAN_TYPE;
          else if(strcmp(returnTypeOfThisId,"string")==0)
            globalType = GLOBAL_STRING_TYPE;

          assignmentCheckerOpenForVariableScopeArray(myVariableLinklist,tempId,globalScope);
          assignmentTracker = GLOBAL_ASSIGNMENT_TRAKER_VAILD;
          strcpy(lastestPureIdGlobalRecorder,tempId);
          assignmentLexpressionType = SWITCH_TO_PURE_ID;
          myType = InitilizationAndResetOfTypeSystem(myType);
          modifyEnvironmentTypeSystemInExpressionList(myType,globalType);
        }    
  }
#line 2294 "parser.tab.c"
    break;

  case 79: /* $@29: %empty  */
#line 853 "parser.y"
        {
        char *tempId = (yyvsp[-1].str_val);
        LexpressionList_tailInsert(&LexpressionCollectionList, tempId);
  }
#line 2303 "parser.tab.c"
    break;

  case 81: /* Stucture_LHS: ID  */
#line 857 "parser.y"
     {
        char *tempId =(yyvsp[0].str_val);
        LexpressionList_tailInsert(&LexpressionCollectionList, tempId);

        char fullDotName[1024];
        PNode axcuilaryList;
        LexpressionList_initilization(&axcuilaryList);

        char *relativeStrcutureName = acquireFirstElementOfLexpressionList(&LexpressionCollectionList);
        strcpy(fullDotName,relativeStrcutureName);
        char *latestFunctionName = acquireHeadOfListCache(functionNameList);
        int checkID = checkUndeclaratedVaraible(myFunctionList,latestFunctionName,relativeStrcutureName);
    
        
        int checkIDTwo = checkVariableUndeclarationVariableScopeArray(myVariableLinklist,relativeStrcutureName,globalScope);
        int newCheckID = ArraycheckUndeclaratedVaraible(myArrayFunctionList,latestFunctionName,relativeStrcutureName);
        if(checkIDTwo == 0){
          printf("GRAMMAR ERROR: %s has not been declared \n",relativeStrcutureName);
          grammarError = 0;
          assignmentTracker =GLOBAL_ASSIGNMENT_TRAKER_INVAILD;
        }

        if (checkIDTwo == 1){
          char * tempType = ArrayreturnStructureTypeofVariable(myArrayFunctionList, latestFunctionName, relativeStrcutureName);
          //  delete the top one
          char * newType = returnTypeOfVaribleInVaribaleScopeArray(myVariableLinklist, relativeStrcutureName, globalScope);
          LexpressionList_headDelete( & LexpressionCollectionList);
          LexpressionList_headInsert( & LexpressionTypeCollectionList, newType);
          LexpressionList_headInsert( & LexpressionCollectionList, newType);
          LexpressionList_headInsert( & axcuilaryList,newType);
          
         // Lexpression_print(LexpressionCollectionList);

          char lastFiled[MAX_SIZE];
          char RelativeStrucure[1024];
          char relativeFiled[1024];

          int length;
          int counter = 0;
         
          do {
            counter++;
            char * temp1 = acquireFirstElementOfLexpressionList( & LexpressionCollectionList);
            char *temp2_ssss= acquireFirstElementOfLexpressionList( & axcuilaryList);
            strcpy(RelativeStrucure, temp2_ssss);
            LexpressionList_headDelete( & LexpressionCollectionList);
            char * temp2 = acquireFirstElementOfLexpressionList( & LexpressionCollectionList);
            strcpy(relativeFiled, temp2);
            length = Lexpression_length(LexpressionCollectionList);
            
            if (length != 1) {
              int flagCC = checker_structureFiled(myStructureList, RelativeStrucure, relativeFiled);

            
              
              if (flagCC == 0) {
                grammarError = 0;
                printf("GRAMMAR ERROR: The structure field %s does not exist\n", relativeFiled);
              } 
              else {
                // Preseving the type eachly
                char * returnTypeOFfILED = returnFiledTypeForSpecificStrucure(myStructureList, RelativeStrucure, relativeFiled);
               // printf("The return type of file is %s\n",returnTypeOFfILED);
                strcat(fullDotName,".");
                strcat(fullDotName,relativeFiled);
                LexpressionList_headInsert( & LexpressionTypeCollectionList, returnTypeOFfILED);
                LexpressionList_headInsert(& axcuilaryList,returnTypeOFfILED);
              }

              if (length == 2) {
                char * HeadOfTypeLexpression = acquireFirstElementOfLexpressionList( & LexpressionTypeCollectionList);
                LexpressionList_headInsert(&axcuilaryList,HeadOfTypeLexpression);
                Lexpression_print(axcuilaryList);
              }
            }

            if (length == 1) {
          
              
           
              // Preseving the type eachl
              strcat(fullDotName,".");
           
              strcat(fullDotName,relativeFiled);
              char * HeadOfTypeLexpressionLengthOne = acquireFirstElementOfLexpressionList( & LexpressionTypeCollectionList);
            
              char *tempStrcure =RelativeStrucure;
              char *tempFiled =relativeFiled;
            

             
              char *newReturn = returnFiledTypeForSpecificStrucure(myStructureList,tempStrcure,tempFiled);
             


              char * returnTypeOFfILED = returnFiledTypeForSpecificStrucure(myStructureList, RelativeStrucure, relativeFiled);
            
              if(returnTypeOFfILED == NULL){
                  grammarError = 0;
                  printf("GRAMMAR ERROR: structure field is not valid \n");
              }
              else
                LexpressionList_headInsert( & LexpressionTypeCollectionList, returnTypeOFfILED);
            

              
            }
          } while (length > 1 && grammarError != 0);

           
          if(grammarError == 0){
            assignmentTracker = GLOBAL_ASSIGNMENT_TRAKER_INVAILD;
            LexpressionList_initilization( & LexpressionCollectionList);
            LexpressionList_initilization( & LexpressionTypeCollectionList);
          

            myType = InitilizationAndResetOfTypeSystem(myType);
            modifyEnvironmentTypeSystemInExpressionList(myType,BOOL_TYPE);
          }
          else{
            Lexpression_print(LexpressionTypeCollectionList);
            char * TypeOfLastOne = acquireFirstElementOfLexpressionList( & LexpressionTypeCollectionList);
            Lexpression_print(LexpressionTypeCollectionList);

           

            if (strcmp(TypeOfLastOne, "int") == 0)
              globalType = GLOBAL_INT_TYPE;
            else if (strcmp(TypeOfLastOne, "bool") == 0)
              globalType = GLBOAL_BOOLEAN_TYPE;
            else if (strcmp(TypeOfLastOne, "string") == 0)
              globalType = GLOBAL_STRING_TYPE;

            assignmentTracker = GLOBAL_ASSIGNMENT_TRAKER_VAILD;
            assignmentLexpressionType = SWITCH_TO_STRUCURE_DOT;

            // After finishing computer intilization
            strcpy(lastStructureDotVariableGlobalRecorder,fullDotName);
            LexpressionList_initilization( & LexpressionCollectionList);
            LexpressionList_initilization( & LexpressionTypeCollectionList);
          
            myType = InitilizationAndResetOfTypeSystem(myType);
            modifyEnvironmentTypeSystemInExpressionList(myType,globalType);

          }
       }             
}
#line 2455 "parser.tab.c"
    break;

  case 83: /* $@30: %empty  */
#line 1007 "parser.y"
                {
        globalType = BOOL_TYPE;
        myType = InitilizationAndResetOfTypeSystem(myType);
        modifyEnvironmentTypeSystemInExpressionList(myType,BOOL_TYPE);
}
#line 2465 "parser.tab.c"
    break;

  case 84: /* IFCondition: IF $@30 LPAREN expr RPAREN  */
#line 1011 "parser.y"
                     {
        typeSystem_Print(myType);
        int result = 0;
        int ExpressionNumber = myType -> expressionNumber;
        result = typeSystemSelectionAndJudgeSystem(myType);

        if (result == 0) {
          semanticsError = 0;
          assignmentCheckerCloseForVariableScopeArray(myVariableLinklist, lastestPureIdGlobalRecorder, globalScope);
          printf("SEMANTIC ERROR: Type checking error occurred \n");
        } 

        myType = InitilizationAndResetOfTypeSystem(myType);
  
}
#line 2485 "parser.tab.c"
    break;

  case 88: /* $@31: %empty  */
#line 1038 "parser.y"
               {  
        char *latesfFunctioName = acquireHeadOfListCache(functionNameList);
        char *tempId = (yyvsp[0].str_val);
        int undelclaredCheck = checkVariableUndeclarationVariableScopeArray(myVariableLinklist,tempId,globalScope);

        if(undelclaredCheck == UNDELCARED){
          grammarError = 0;
          printf("GRAMMAR ERROR: for loop identifier %s\n is not declared\n",tempId);
        }
        else if(undelclaredCheck == NOT_UNCLEATION){
          char *returnTypeOfThisId = returnTypeOfVaribleInVaribaleScopeArray(myVariableLinklist,tempId,globalScope);
          
          if(strcmp(returnTypeOfThisId,"int")==0)
            globalType =GLOBAL_INT_TYPE;
          else if(strcmp(returnTypeOfThisId,"bool")==0)
            globalType =GLBOAL_BOOLEAN_TYPE;
          else if(strcmp(returnTypeOfThisId,"string")==0)
            globalType =GLOBAL_STRING_TYPE;

          assignmentCheckerOpenForVariableScopeArray(myVariableLinklist,tempId,globalScope);
          assignmentTracker = GLOBAL_ASSIGNMENT_TRAKER_VAILD;
          strcpy(lastestPureIdGlobalRecorder,tempId);
          assignmentLexpressionType = SWITCH_TO_PURE_ID;
          myType = InitilizationAndResetOfTypeSystem(myType);
          modifyEnvironmentTypeSystemInExpressionList(myType,globalType);

        }

  }
#line 2519 "parser.tab.c"
    break;

  case 89: /* $@32: %empty  */
#line 1066 "parser.y"
           {
        if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_VAILD){
          int temp = globalType;
          modifyEnvironmentTypeSystemInExpressionList(myType,temp);

          // clear expression list here
          typeSystem_Print(myType);
          int result=0;
          int ExpressionNumber = myType -> expressionNumber;
          result = typeSystemSelectionAndJudgeSystem(myType);

          if (result == 0){
            semanticsError = 0;
            assignmentCheckerCloseForVariableScopeArray(myVariableLinklist,lastestPureIdGlobalRecorder,globalScope);
            printf("SEMANTICS ERROR: type checking error occurred \n");
          }
          else if(result==1)
            assignmentCheckerOpenForVariableScopeArray(myVariableLinklist,lastestPureIdGlobalRecorder,globalScope);
        }
        else if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_INVAILD) {
          grammarError = 0;
          printf("GRAMMAR ERROR: cannot assign to an undeclared variable \n");
        }

        assignmentTracker = GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;
        myType = InitilizationAndResetOfTypeSystem(myType);

        // Clearing the type system 
        globalType = GLOBAL_UNDEFINED_TYPE;
        assignmentLexpressionType=UNDEFINT_LEFTEXPRESSION_TYPE;

        // Cleaning for next boolean expression
        myType = InitilizationAndResetOfTypeSystem(myType);
        globalType= BOOL_TYPE;
        modifyEnvironmentTypeSystemInExpressionList(myType,globalType);

  }
#line 2561 "parser.tab.c"
    break;

  case 90: /* $@33: %empty  */
#line 1102 "parser.y"
                             {

        int temp = globalType;
        modifyEnvironmentTypeSystemInExpressionList(myType, temp);

        // clear expression list here
        typeSystem_Print(myType);
        int result = 0;
        int ExpressionNumber = myType -> expressionNumber;
        result = typeSystemSelectionAndJudgeSystem(myType);
        if (result == 0) {
          semanticsError = 0;
          assignmentCheckerCloseForVariableScopeArray(myVariableLinklist, lastestPureIdGlobalRecorder, globalScope);
        } 
        else if (result == 1)
          assignmentCheckerOpenForVariableScopeArray(myVariableLinklist, lastestPureIdGlobalRecorder, globalScope);

        assignmentTracker = GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;
        myType = InitilizationAndResetOfTypeSystem(myType);

        // Clearing the type system agsi
        globalType = GLOBAL_UNDEFINED_TYPE;
        assignmentLexpressionType=UNDEFINT_LEFTEXPRESSION_TYPE;

  }
#line 2591 "parser.tab.c"
    break;

  case 94: /* $@34: %empty  */
#line 1130 "parser.y"
         {
        char * tempFunctionDeclrationType = acquireHeadOfListCache(functionDeclarationList);
        char * trueFunctionName = acquireHeadOfListCache(functionNameList);
        if (strcmp(tempFunctionDeclrationType, "int") == 0)
          globalType = GLOBAL_INT_TYPE;
        else if (strcmp(tempFunctionDeclrationType, "bool") == 0)
          globalType = GLBOAL_BOOLEAN_TYPE;
        else if (strcmp(tempFunctionDeclrationType, "string") == 0)
          globalType = GLOBAL_STRING_TYPE;
        else if(strcmp(tempFunctionDeclrationType, "void")==0)
          globalType = GL0BAL_FUNCTION_VOID_RETURN_TYPE;

        if(globalType == GL0BAL_FUNCTION_VOID_RETURN_TYPE){
          myType=InitilizationAndResetOfTypeSystem(myType);
          // Selecting random one ;
          modifyEnvironmentTypeSystemInExpressionList(myType,STRING_TYPE);
        }
        else{
            myType = InitilizationAndResetOfTypeSystem(myType);
            modifyEnvironmentTypeSystemInExpressionList(myType, globalType);
        }

}
#line 2619 "parser.tab.c"
    break;

  case 95: /* stmt: RETURN $@34 expr SEMICOLON  */
#line 1152 "parser.y"
                  {

        char *trueFunctionName = acquireHeadOfListCache(functionNameList);
        int temp =globalType;

        if(globalType== GL0BAL_FUNCTION_VOID_RETURN_TYPE){
          // clear expression list here
          typeSystem_Print(myType);
          int result;
          int ExpressionNumberForVoidFunction =myType->expressionNumber;

          if(ExpressionNumberForVoidFunction==0){
            InsertHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,trueFunctionName,"vaild");
            InsertHashMap(functionDeclrationTypeChecker,trueFunctionName,"void");
          }
          else
              semanticsError=0;

          globalType = GLOBAL_UNDEFINED_TYPE;
          myType=InitilizationAndResetOfTypeSystem(myType);
        }
        else{
          // clear expression list here
          typeSystem_Print(myType);
          int result;
          int ExpressionNumber =myType->expressionNumber;
          result = typeSystemSelectionAndJudgeSystem(myType);

          if(result == 0)
            semanticsError = 0;
          else if(result == 1){
            char *tempFunctionName = acquireHeadOfListCache(functionNameList);
            InsertHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,tempFunctionName,"vaild");
            char gloablTypeMapping[1024];

            if(globalType==INT_TYPE)
              strcpy(gloablTypeMapping,"int");
            else if(globalType==BOOL_TYPE)
              strcpy(gloablTypeMapping,"bool");
            else if(globalType==STRING_TYPE)
              strcpy(gloablTypeMapping,"string");
                    
            InsertHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,tempFunctionName,"vaild");
            InsertHashMap(functionDeclrationTypeChecker,tempFunctionName,gloablTypeMapping);
          }

          globalType = GLOBAL_UNDEFINED_TYPE;
          myType=InitilizationAndResetOfTypeSystem(myType);

      }
}
#line 2675 "parser.tab.c"
    break;

  case 96: /* $@35: %empty  */
#line 1203 "parser.y"
        {
        globalScope += 1; // increase scope
        char *lastesfFunctionName = acquireHeadOfListCache(functionNameList);
        bracketControlAdd(myFunctionList,lastesfFunctionName);
        ArraybracketControlAdd(myArrayFunctionList,lastesfFunctionName);
  }
#line 2686 "parser.tab.c"
    break;

  case 97: /* stmt: LBRACE $@35 stmtlist RBRACE  */
#line 1208 "parser.y"
                    {
        char *lastesfFunctionName = acquireHeadOfListCache(functionNameList);
        ArraycloseScopeOfVariable(myArrayFunctionList,lastesfFunctionName);
        closeScopeOfVariable(myFunctionList,lastesfFunctionName);
        bracketControlSub(myFunctionList,lastesfFunctionName);
        ArraybracketControlSub(myArrayFunctionList,lastesfFunctionName);      
        globalScope-=1; // decrease scope

  }
#line 2700 "parser.tab.c"
    break;

  case 99: /* stmt: lexprLHS EQ expr SEMICOLON  */
#line 1218 "parser.y"
                              {
        if(assignmentLexpressionType == SWITCH_TO_PURE_ID){
          if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_VAILD) {
            int temp = globalType;
            modifyEnvironmentTypeSystemInExpressionList(myType,temp);

            // clear expression list here
            typeSystem_Print(myType);
            int result=0;
            int ExpressionNumber = myType -> expressionNumber;
            result = typeSystemSelectionAndJudgeSystem(myType);

            if (result == 0) {
              semanticsError = 0;
              assignmentCheckerCloseForVariableScopeArray(myVariableLinklist,lastestPureIdGlobalRecorder,globalScope);
              printf("SEMANTIC ERROR: Type checking error occurred \n");
            }
            else if(result==1)
              assignmentCheckerOpenForVariableScopeArray(myVariableLinklist,lastestPureIdGlobalRecorder,globalScope);

          }
          else if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_INVAILD) {
            grammarError = 0;
            printf("GRAMMAR ERROR: cannot assign to an undeclared variable \n");
          }

          assignmentTracker = GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;
          myType = InitilizationAndResetOfTypeSystem(myType);
          // Clearing the type system agsi
          globalType = GLOBAL_UNDEFINED_TYPE;
          assignmentLexpressionType=UNDEFINT_LEFTEXPRESSION_TYPE;

        } //end if

        if(assignmentLexpressionType== SWITCH_TO_STRUCURE_DOT){
          if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_VAILD) {
            int temp = globalType;
            // clear expression list here
            typeSystem_Print(myType);
            int result=0;
            int ExpressionNumber = myType -> expressionNumber;
            result = typeSystemSelectionAndJudgeSystem(myType);

            if (result == 0) {
              semanticsError = 0;
              assignmentCheckerCloseForVariableScopeArray(myVariableLinklist,lastestPureIdGlobalRecorder,globalScope);
              printf("SEMANTIC ERROR: Type checking error occurred \n");
            }
            else if(result==1)
                InsertHashMap(globalStrucureVaildAssignment,lastStructureDotVariableGlobalRecorder,"vaild");
          }
          else if (assignmentTracker == GLOBAL_ASSIGNMENT_TRAKER_INVAILD) {
            grammarError = 0;
            printf("GRAMMAR ERROR: cannot assign to an undeclared variable \n");
          }

          assignmentTracker = GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;
          myType = InitilizationAndResetOfTypeSystem(myType);
          // Clearing the type system agsi
          globalType = GLOBAL_UNDEFINED_TYPE;
          assignmentLexpressionType=UNDEFINT_LEFTEXPRESSION_TYPE;
        } //end if

        assignmentTracker = GLOBAL_ASSIGNMENT_TRACKER_UNDEFINED;
        myType = InitilizationAndResetOfTypeSystem(myType);
        // Clearing the type system agsi
        globalType = GLOBAL_UNDEFINED_TYPE;
        assignmentLexpressionType=UNDEFINT_LEFTEXPRESSION_TYPE;
}
#line 2774 "parser.tab.c"
    break;

  case 100: /* $@36: %empty  */
#line 1287 "parser.y"
     {
        strcpy(globalFunctionCallName,(yyvsp[0].str_val));
        char *tempFunctionName = (yyvsp[0].str_val);
        char* flagWellDefinedFunctionChekcker = GetHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,tempFunctionName);

        if(flagWellDefinedFunctionChekcker == NULL){
          semanticsError = 0;
          printf("SEMANTICS ERROR: function is not well defined and could not be called\n");
        }
        else{
          struct functionHeaderParameterNode * myNode = getFunctionParameterList(myFunctionInfoHeaderList, tempFunctionName);
          int parameterIteratiion = getSpecifificFunctionParameterCount(myFunctionInfoHeaderList, tempFunctionName);
          struct functionHeaderParameterNode * indexFunctionParamet;
          
          globalFunctionParameterNumberForFunctionItself=0;
          for (indexFunctionParamet = myNode; indexFunctionParamet < myNode + parameterIteratiion; indexFunctionParamet++){
            char * Type = indexFunctionParamet -> parameterType;
            globalFunctionParameterNumberForFunctionItself+=1;
            LexpressionList_tailInsert( & LFunctionParameterCollectionList, Type);
          }

          // reseting for functionlist
          myType =InitilizationAndResetOfTypeSystem(myType);
        }
}
#line 2804 "parser.tab.c"
    break;

  case 101: /* stmt: ID $@36 LPAREN exprlist RPAREN SEMICOLON  */
#line 1311 "parser.y"
                                   {
        char *tempFucntionName = (yyvsp[-5].str_val);   
        int checkFlagMatching = checkingFunctionParameterSizeCounter(myFunctionInfoHeaderList,tempFucntionName,globalFunctionParameterNumber);
        
        if(checkFlagMatching == Missing_Match_function_Parameter_count){
          semanticsError = 0;
          printf("SEMANTICS ERROR: number of arguments passed does not match function signature \n");
        }

        globalFunctionParameterNumber=0;
        globalFunctionParameterNumberForFunctionItself=0;
        LexpressionList_initilization(&LFunctionParameterCollectionList);
        myType = InitilizationAndResetOfTypeSystem(myType);
}
#line 2823 "parser.tab.c"
    break;

  case 102: /* stmt: decl EQ expr SEMICOLON  */
#line 1325 "parser.y"
                          {
        semanticsError =0;
        printf("SEMANTICS ERROR: declaration and assignment is on the same line\n");
  }
#line 2832 "parser.tab.c"
    break;

  case 103: /* $@37: %empty  */
#line 1329 "parser.y"
                 {
        strcpy(globalFunctionCallName,(yyvsp[0].str_val));

        //Checking well defined function here 
        char *tempFunctionName = (yyvsp[0].str_val);
        char* flagWellDefinedFunctionChekcker = GetHashMap(Vaild_DeclrationWithReturnTypeFunctionChecker,tempFunctionName);

        if(flagWellDefinedFunctionChekcker == NULL){
          semanticsError = 0;
          printf("SEMANTICS ERROR: function is not well defined and could not be called\n");
        }
        else{
          char *functionReturnType =GetHashMap(functionDeclrationTypeChecker,tempFunctionName);
          if(strcmp(functionReturnType,"void") == 0){
              semanticsError = 0;
              printf("SEMANTIC ERROR: void function cannot be assigned to a variable \n");
          }
          else{
            char gloablTypeMapping[1024];

            if(globalType==INT_TYPE)
                strcpy(gloablTypeMapping,"int");
            else if(globalType==BOOL_TYPE)
              strcpy(gloablTypeMapping,"bool");
            else if(globalType==STRING_TYPE)
                strcpy(gloablTypeMapping,"string");

            if(strcmp(functionReturnType,gloablTypeMapping)==0){
              // doing function list here
              struct functionHeaderParameterNode * myNode = getFunctionParameterList(myFunctionInfoHeaderList, tempFunctionName);
              int parameterIteratiion = getSpecifificFunctionParameterCount(myFunctionInfoHeaderList, tempFunctionName);

              struct functionHeaderParameterNode * indexFunctionParamet;
              globalFunctionParameterNumberForFunctionItself=0;
              for (indexFunctionParamet = myNode; indexFunctionParamet < myNode + parameterIteratiion; indexFunctionParamet++){
                char * Type = indexFunctionParamet -> parameterType;
                globalFunctionParameterNumberForFunctionItself+=1;
                LexpressionList_tailInsert( & LFunctionParameterCollectionList, Type);
              }

              // reseting for functionlist
              myType =InitilizationAndResetOfTypeSystem(myType);
            }
            else{
              semanticsError=0;
              char * idd = (yyvsp[0].str_val);
              printf("SEMANTICS ERROR: The  type is not equal to fucntin declation type \n");
            }
          } // end if

        }// end if
}
#line 2889 "parser.tab.c"
    break;

  case 104: /* stmt: lexprLHS EQ ID $@37 LPAREN exprlist RPAREN SEMICOLON  */
#line 1380 "parser.y"
                                  {
        int checkFlagMatching = checkingFunctionParameterSizeCounter(myFunctionInfoHeaderList,(yyvsp[-5].str_val),globalFunctionParameterNumber);

        if(checkFlagMatching == Missing_Match_function_Parameter_count){
          semanticsError = 0;
          printf("SEMANTICS ERROR: number of arguments passed does not match function signature \n");
        }

      
        if((semanticsError != 0)&&(grammarError != 0))
        {
          //printf("assign this function to a varaible!\n");
           assignmentCheckerOpenForVariableScopeArray(myVariableLinklist, lastestPureIdGlobalRecorder, globalScope); 
        }
        

        globalFunctionParameterNumber=0;
        myType=InitilizationAndResetOfTypeSystem(myType);
        LexpressionList_initilization(&LFunctionParameterCollectionList);

}
#line 2915 "parser.tab.c"
    break;

  case 107: /* decl: INT ID  */
#line 1412 "parser.y"
         {
        char *variableName = (yyvsp[0].str_val);
        char *variableType = "int";
        char *latestFunctionName = acquireHeadOfListCache(functionNameList);
        char *latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
        
        if(redeclatedCheck == RECLRATED){ // check if redeclared
            printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
            grammarError = 0;
        } // end if

        if(redeclatedCheck == NOT_RECLARED){ // if not redeclared
          insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);  
          inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
         
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
        } // end if
}
#line 2940 "parser.tab.c"
    break;

  case 108: /* decl: BOOL ID  */
#line 1432 "parser.y"
          {
        char *variableName = (yyvsp[0].str_val);
        char *variableType = "bool";
        char *latestFunctionName = acquireHeadOfListCache(functionNameList);
        char *latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
       
        if(redeclatedCheck == RECLRATED){ // check if redeclared
            printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
            grammarError = 0;
        } // end if

        if(redeclatedCheck == NOT_RECLARED){ // if not redeclared
          inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
          insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
        } // end if
  }
#line 2964 "parser.tab.c"
    break;

  case 109: /* decl: STRING_TYPE ID  */
#line 1451 "parser.y"
                 {
        char * variableName = (yyvsp[0].str_val);
        char * variableType = "string";
        char * latestFunctionName = acquireHeadOfListCache(functionNameList);
        char * latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

        int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
        if (redeclatedCheck == RECLRATED) { // check if redeclared
          printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
          grammarError = 0;
        } // end if

        if (redeclatedCheck == NOT_RECLARED) { // if not redeclared
          insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
          insertVariableDeclarationforSpecificFunction(myFunctionList, latestFunctionName, latestFunctionType, variableType, variableName);
          ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
        } // end if
  }
#line 2987 "parser.tab.c"
    break;

  case 110: /* decl: ID ID  */
#line 1469 "parser.y"
        {
          char * structureName = (yyvsp[-1].str_val);
          char * strctureNameCheckerFlag = GetHashMap(structureNameCheckerhashMap, structureName);
          if (strctureNameCheckerFlag == NULL) {
            printf("GRAMMAR ERROR: Structure %s has not been declared\n", structureName);
            grammarError = 0;
          }

          if (strctureNameCheckerFlag) {
            char * variableName = (yyvsp[0].str_val);
            char * variableType = (yyvsp[-1].str_val);
            char * latestFunctionName = acquireHeadOfListCache(functionNameList);
            char * latestFunctionType = acquireHeadOfListCache(functionDeclarationList);

            int redeclatedCheck =checkVariableRecelarationVariableScopeArray(myVariableLinklist,variableName,globalScope);
            if(redeclatedCheck == RECLRATED) { // check if redeclared
              printf("GRAMMAR ERROR: %s is already in use \n", (yyvsp[0].str_val));
              grammarError = 0;
            } // end if
            
            if (redeclatedCheck == NOT_RECLARED ) { // if not redeclared
              ArrayinsertVariableDeclarationforSpecificFunction(myArrayFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
              insertVariableDeclarationforSpecificFunction(myFunctionList,latestFunctionName,latestFunctionType,variableType,variableName);
              inserionOfVaraibelScopeArray(myVariableLinklist,variableType,variableName,globalScope);
            } // end if
          }
      }
#line 3019 "parser.tab.c"
    break;


#line 3023 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1500 "parser.y"


void yyerror (){
   printf("Exception Thrown! \n");
}

HashMap* CreateHashMap(int n){
    HashMap* hashMap = (HashMap*)myCalloc(1, sizeof(HashMap));
    hashMap->hashArr = (HashNode**)myCalloc(n, sizeof(HashNode*));
    if (hashMap == NULL || hashMap->hashArr == NULL)
        return NULL;

    hashMap->size = n;
    return hashMap;
};

int InsertHashMap(HashMap* hashMap, char* key, char* value){
    HashNode* node = (HashNode*)myCalloc(1, sizeof(HashNode));
    if (node == NULL)
        return 0;

    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;

    int index = myHash(key) % hashMap->size;
    if (hashMap->hashArr[index] == NULL)
        hashMap->hashArr[index] = node;
    else {
        HashNode *temp = hashMap->hashArr[index];
        HashNode *prev = temp;

        while (temp != NULL) {
          if (strcmp(temp->key, node->key) == 0) {
              myFree(temp->value);
              temp->value = strdup(node->value);
              return 1;
          }
          prev = temp;
          temp = temp->next;
        }
        prev->next = node;
    }
    return 1;
}

char* GetHashMap(HashMap* hashMap, char* key){
    int index = myHash(key) % hashMap->size;
    HashNode *temp = hashMap->hashArr[index];

    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) 
            return temp->value;

        temp = temp->next;
    }
    return NULL;
}

void DeleteHashMap(HashMap* hashMap){
    for (int i = 0; i < hashMap->size; i++){
        HashNode *temp = hashMap->hashArr[i];
        HashNode *prev = temp;

        while (temp != NULL) {
            prev = temp;
            temp = temp->next;
            myFree(prev->key);
            myFree(prev->value);
            myFree(prev);
        }
    }
    myFree(hashMap->hashArr);
    myFree(hashMap);
    hashMap->hashArr = NULL;
    hashMap = NULL;
}

void PrintHashMap(HashMap* hashMap){
    HashNode* node = NULL;
    for (int i = 0; i < hashMap->size; i++){
        node = hashMap->hashArr[i];
        if (node != NULL) {
            HashNode* temp = node;
            while (temp != NULL) {
                temp = temp->next;
            }
            fprintf(yyout,"\n");
        }
    }
}

// Semantics function 
 void functionSizeChecker()
 {
        int lengthOfFunction = lengthOfCacheNodeForFunctionLengthChecking(functionNameList);
        if(lengthOfFunction ==0)
        {
           semanticsError = 0;
           printf("Semantics error ,function number is zero \n");
        }
 }
int main (int argc, char *argv[]){
  // parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
  functionSizeChecker();
    
    if((flag != 0) || (grammarError == 0) || (semanticsError == 0)){
        if(flag !=0)
          printf("LEXICAL ERROR!\n");

        if(grammarError ==0) 
          printf("GRAMMAR ERROR!\n");

        if(semanticsError==0)
          printf("SEMANTIC ERROR!\n");

        printf("\n                      ❌ FAILED TO COMPILE ❌\n");
    }
    else
      printf("\n                    ✅ COMPILED SUCCESSFULLY ✅\n");

    printf("________________________,--.___________,--._______________________\n");
    printf("                        `--'           `--'\n\n");

	return flag;
}
