/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "QSDL92.y" /* yacc.c:339  */

/******************************************************************************
 *  Modul: $RCSfile: QSDL92.y,v $
 *
 *  $Author: md $
 *  $Date: 1997/10/22 16:09:04 $
 *  $Revision: 1.2 $
 *
 *  Copyright 1994-1997: University of Essen / Germany. All rights reserved.
 *
 *  WICHTIG:
 *    Die erste Zeile dieses Moduls muss (!) mit %{ beginnen!!!
 *    Sonst kann yacc/bison die Grammatik nicht bearbeiten!!!
 *
 *  Aufgabe:
 *    Der Modul enthaelt die yacc-/bison-Grammatik fuer QSDL. Aus dieser
 *    Grammatik wird mit Hilfe von yacc/bison automatisch C-Code fuer
 *    einen Parser generiert. In die Grammatik sind aktive Teile (C-Code)
 *    eingebunden, die mit in den generierten C-Code kopiert werden und den
 *    Parser zu einem Compiler vervollstaendigen.
 *    Naeheres siehe
 *      Z100 (SDL)
 *    und
 *      Levine, John R. and Mason, Tony and Brown, Doug: lex & yacc.
 *      2nd Edition, Sebastopol, California/U.S.A: O'Reilly & Associates, 1992.
 *    sowie
 *      Bison-Documentation (bison.ps), verfuegbar per anonymous ftp.
 *
 *  Hinweise:
 *    + Bei Nonterminals, die in der Z100 mit "textual" beginnen, z.B.
 *      <textual process reference>, wurde das "textual" weggelassen, d.h.
 *      <textual process reference> wird zu process_reference.
 *    + Leere Symbole werden durch ein kommentiertes "empty" dargestellt, da
 *      "empty" als eigenstaendige Regel zu shift/reduce-Konflikten fuehrt.
 *    + "QSDL" als Kommentar markiert QSDL-spezifische Teile der Grammatik.
 *    + "HERE" als Kommentar markiert unfertige oder fehlerhafte Teile der
 *      Grammatik, und darf in der Endversion nicht mehr auftauchen.
 *    + Nicht implementierte Teile sind auskommentiert.
 *    + Verschachtelte Kommentare sind in yacc/bison NICHT erlaubt!!!
 *    + Der Lexer liefert alle lexikalischen Werte in Kleinschrift!
 *
 ******************************************************************************/          

#include <string.h>                              /* DO NOT CONFUSE THIS WITH
                                                    <String.h>, which is a
                                                    GNU-specific library NOT
                                                    in the ANSI-standard!!! */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define YYERROR_VERBOSE 1                        /* Makes parser issue verbose
                                                    error messages indicating
                                                    the token that lead to the
                                                    parse error. */
                                                    
#define YYDEBUG 1                                /* Enable debugging code. */

#include <DS/DSBasicTypes.h>

#include "QPAction.h"
#include "QPActual.h"
#include "QPBind.h"
#include "QPBlock.h"
#include "QPBlockSubstructure.h"
#include "QPChannel.h"
#include "QPConnection.h"
#include "QPData.h"
#include "QPExpression.h"
#include "QPIdentifier.h"
#include "QPInput.h"
#include "QPLink.h"
#include "QPLiteral.h"
#include "QPMachine.h"
#include "QPMachineService.h"
#include "QPName.h"
#include "QPPipe.h"
#include "QPProcedure.h"
#include "QPProcess.h"
#include "QPSensor.h"
#include "QPSignal.h"
#include "QPSignalItem.h"
#include "QPSignalList.h"
#include "QPSignalRoute.h"
#include "QPSort.h"
#include "QPState.h"
#include "QPSystem.h"
#include "QPTimer.h"
#include "QPVariable.h"

extern int yylex(void);
extern void yyerror (const char* s);


#line 161 "QSDL92.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "QSDL92.tab.h".  */
#ifndef YY_YY_QSDL92_TAB_H_INCLUDED
# define YY_YY_QSDL92_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ACTIVEtoken = 258,
    ADDINGtoken = 259,
    ALLtoken = 260,
    ALTERNATIVEtoken = 261,
    ANYtoken = 262,
    AStoken = 263,
    ATLEASTtoken = 264,
    AXIOMStoken = 265,
    BLOCKtoken = 266,
    CALLtoken = 267,
    CHANNELtoken = 268,
    COMMENTtoken = 269,
    CONNECTtoken = 270,
    CONNECTIONtoken = 271,
    CONSTANTtoken = 272,
    CONSTANTStoken = 273,
    CREATEtoken = 274,
    DCLtoken = 275,
    DECISIONtoken = 276,
    DEFAULTtoken = 277,
    DELAYtoken = 278,
    ELSEtoken = 279,
    ENDALTERNATIVEtoken = 280,
    ENDBLOCKtoken = 281,
    ENDCHANNELtoken = 282,
    ENDCONNECTIONtoken = 283,
    ENDDECISIONtoken = 284,
    ENDGENERATORtoken = 285,
    ENDMACROtoken = 286,
    ENDNEWTYPEtoken = 287,
    ENDOPERATORtoken = 288,
    ENDPACKAGEtoken = 289,
    ENDPROCEDUREtoken = 290,
    ENDPROCESStoken = 291,
    ENDREFINEMENTtoken = 292,
    ENDSELECTtoken = 293,
    ENDSERVICEtoken = 294,
    ENDSTATEtoken = 295,
    ENDSUBSTRUCTUREtoken = 296,
    ENDSYNTYPEtoken = 297,
    ENDSYSTEMtoken = 298,
    ENVtoken = 299,
    ERRORtoken = 300,
    EXPORTtoken = 301,
    EXPORTEDtoken = 302,
    EXTERNALtoken = 303,
    FItoken = 304,
    FINALIZEDtoken = 305,
    FORtoken = 306,
    FPARtoken = 307,
    FROMtoken = 308,
    GATEtoken = 309,
    GENERATORtoken = 310,
    IFtoken = 311,
    IMPORTtoken = 312,
    IMPORTEDtoken = 313,
    INtoken = 314,
    INHERITStoken = 315,
    INPUTtoken = 316,
    INTERFACEtoken = 317,
    JOINtoken = 318,
    LITERALtoken = 319,
    LITERALStoken = 320,
    MACROtoken = 321,
    MACRODEFINITIONtoken = 322,
    MACROIDtoken = 323,
    MAPtoken = 324,
    NAMECLASStoken = 325,
    NEWTYPEtoken = 326,
    NEXTSTATEtoken = 327,
    NODELAYtoken = 328,
    NOEQUALITYtoken = 329,
    NONEtoken = 330,
    NOWtoken = 331,
    OFFSPRINGtoken = 332,
    OPERATORtoken = 333,
    OPERATORStoken = 334,
    ORDERINGtoken = 335,
    OUTtoken = 336,
    OUTPUTtoken = 337,
    PACKAGEtoken = 338,
    PARENTtoken = 339,
    PRIORITYtoken = 340,
    PROCEDUREtoken = 341,
    PROCESStoken = 342,
    PROVIDEDtoken = 343,
    REDEFINEDtoken = 344,
    REFERENCEDtoken = 345,
    REFINEMENTtoken = 346,
    REMOTEtoken = 347,
    RESETtoken = 348,
    RETURNtoken = 349,
    RETURNStoken = 350,
    REVEALEDtoken = 351,
    REVERSEtoken = 352,
    SAVEtoken = 353,
    SELECTtoken = 354,
    SELFtoken = 355,
    SENDERtoken = 356,
    SERVICEtoken = 357,
    SETtoken = 358,
    SIGNALtoken = 359,
    SIGNALLISTtoken = 360,
    SIGNALROUTEtoken = 361,
    SIGNALSETtoken = 362,
    SPELLINGtoken = 363,
    STARTtoken = 364,
    STATEtoken = 365,
    STOPtoken = 366,
    STRUCTtoken = 367,
    SUBSTRUCTUREtoken = 368,
    SYNONYMtoken = 369,
    SYNTYPEtoken = 370,
    SYSTEMtoken = 371,
    TASKtoken = 372,
    THENtoken = 373,
    THIStoken = 374,
    TIMERtoken = 375,
    TOtoken = 376,
    TYPEtoken = 377,
    USEtoken = 378,
    VIAtoken = 379,
    VIEWtoken = 380,
    VIEWEDtoken = 381,
    VIRTUALtoken = 382,
    WITHtoken = 383,
    ANDtoken = 384,
    MODtoken = 385,
    NOTtoken = 386,
    ORtoken = 387,
    REMtoken = 388,
    XORtoken = 389,
    LTLTtoken = 390,
    GTGTtoken = 391,
    OTHER_CHARtoken = 392,
    APOSTROPHEtoken = 393,
    SPACEtoken = 394,
    LINEBREAKtoken = 395,
    TABULATORtoken = 396,
    COMMAtoken = 397,
    PLUStoken = 398,
    MINUStoken = 399,
    EXCLAMATIONtoken = 400,
    GREATERtoken = 401,
    ASTERISKtoken = 402,
    LEFTPARtoken = 403,
    RIGHTPARtoken = 404,
    QUOTEtoken = 405,
    SEMICOLONtoken = 406,
    LESStoken = 407,
    EQUALtoken = 408,
    COLONtoken = 409,
    FULLSTOPtoken = 410,
    DOUBLEEQUALtoken = 411,
    LONGTHICKARROWtoken = 412,
    NOTEQUALtoken = 413,
    LESSEQUALtoken = 414,
    GREATEREQUALtoken = 415,
    CONCATENATIONtoken = 416,
    ASSIGNMENTtoken = 417,
    THICKARROWtoken = 418,
    THINARROWtoken = 419,
    LEFTPARPERIODtoken = 420,
    RIGHTPARPERIODtoken = 421,
    NATURAL_NUMBERtoken = 422,
    CHARSTRINGtoken = 423,
    WORDtoken = 424,
    SLASHtoken = 425,
    UNDERLINEtoken = 426,
    HISTtoken = 427,
    PIPEtoken = 428,
    ENDPIPEtoken = 429,
    MACHINEtoken = 430,
    ENDMACHINEtoken = 431,
    SERVERtoken = 432,
    DISCIPLINEtoken = 433,
    OFFERStoken = 434,
    MACHINESERVICEtoken = 435,
    AWAKEtoken = 436,
    LINKtoken = 437,
    BINDtoken = 438,
    REQUESTtoken = 439,
    CLEARtoken = 440,
    UPDATEtoken = 441,
    ASSERTtoken = 442,
    BASECOUNTERtoken = 443,
    BASEFREQUENCYtoken = 444,
    BASETALLYtoken = 445,
    BASETIMEtoken = 446,
    FREQPROCESSCREATEtoken = 447,
    FREQPROCESSSTOPtoken = 448,
    FREQREQUESTtoken = 449,
    FREQSIGNALCONSUMEtoken = 450,
    FREQSIGNALDROPtoken = 451,
    FREQSIGNALRECEIVEtoken = 452,
    FREQSIGNALLOSEtoken = 453,
    FREQSIGNALSAVEtoken = 454,
    FREQSIGNALSENDtoken = 455,
    FREQSIGNALtoken = 456,
    FREQSTATEtoken = 457,
    FREQTRANSITIONtoken = 458,
    COUNTPROCESSCREATEtoken = 459,
    COUNTPROCESSSTOPtoken = 460,
    COUNTREQUESTtoken = 461,
    COUNTSIGNALCONSUMEtoken = 462,
    COUNTSIGNALDROPtoken = 463,
    COUNTSIGNALRECEIVEtoken = 464,
    COUNTSIGNALLOSEtoken = 465,
    COUNTSIGNALSAVEtoken = 466,
    COUNTSIGNALSENDtoken = 467,
    COUNTSIGNALtoken = 468,
    COUNTSTATEtoken = 469,
    COUNTTRANSITIONtoken = 470,
    LIFETIMEPROCESStoken = 471,
    QUEUECONTENTtoken = 472,
    QUEUELENGTHtoken = 473,
    RESPONSETIMEREQUESTtoken = 474,
    SENSORtoken = 475,
    SERVICETIMEREQUESTtoken = 476,
    THROUGHPUTtoken = 477,
    UTILIZATIONtoken = 478,
    WAITTIMEREQUESTtoken = 479,
    WAITTIMESIGNALtoken = 480,
    TRANSMISSIONTIMESIGNALtoken = 481,
    WAITTIMESTATEtoken = 482,
    ATOMtoken = 483,
    unary_minus = 484
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "QSDL92.y" /* yacc.c:355  */
 char *symval;
         int oprtr; 

#line 435 "QSDL92.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_QSDL92_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 452 "QSDL92.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  483
/* YYNRULES -- Number of rules.  */
#define YYNRULES  836
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   484

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   764,   764,   767,   768,   771,   774,   777,   782,   783,
     787,   791,   792,   795,   798,   802,   803,   806,   807,   810,
     816,   819,   820,   825,   826,   830,   831,   832,   833,   834,
     835,   836,   837,   838,   839,   840,   844,   848,   851,   852,
     856,   857,   860,   864,   867,   868,   871,   876,   877,   880,
     881,   885,   886,   889,   890,   896,   900,   911,   912,   915,
     917,   920,   921,   924,   926,   931,   932,   933,   934,   935,
     953,   956,   957,   961,   963,   967,   971,   972,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   989,
     990,   993,   997,  1001,  1005,  1006,  1007,  1008,  1009,  1010,
    1023,  1027,  1026,  1039,  1040,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1071,  1072,  1075,  1076,
    1079,  1086,  1085,  1095,  1096,  1099,  1100,  1101,  1105,  1110,
    1113,  1116,  1118,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1132,  1133,  1134,  1135,  1136,  1141,  1149,  1148,  1158,  1159,
    1162,  1163,  1166,  1167,  1168,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1204,  1201,
    1212,  1209,  1222,  1223,  1226,  1229,  1230,  1233,  1234,  1237,
    1238,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,
    1267,  1272,  1275,  1278,  1280,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1300,  1301,
    1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1318,  1326,  1327,  1326,  1331,  1332,  1336,  1340,
    1341,  1344,  1345,  1348,  1350,  1353,  1354,  1358,  1358,  1362,
    1365,  1369,  1373,  1380,  1381,  1384,  1385,  1388,  1392,  1393,
    1396,  1401,  1404,  1405,  1409,  1412,  1413,  1417,  1420,  1421,
    1425,  1432,  1433,  1436,  1438,  1442,  1443,  1444,  1445,  1446,
    1457,  1463,  1461,  1473,  1474,  1477,  1480,  1481,  1484,  1487,
    1488,  1491,  1492,  1495,  1503,  1503,  1507,  1508,  1511,  1514,
    1518,  1522,  1523,  1526,  1527,  1531,  1537,  1538,  1539,  1540,
    1544,  1545,  1548,  1549,  1554,  1553,  1564,  1565,  1570,  1572,
    1573,  1574,  1569,  1578,  1579,  1583,  1586,  1587,  1592,  1591,
    1599,  1601,  1602,  1603,  1598,  1607,  1608,  1612,  1616,  1617,
    1616,  1624,  1625,  1624,  1632,  1640,  1640,  1645,  1648,  1652,
    1652,  1660,  1665,  1666,  1669,  1671,  1676,  1677,  1678,  1675,
    1683,  1684,  1689,  1690,  1694,  1696,  1695,  1701,  1701,  1708,
    1709,  1712,  1713,  1716,  1717,  1718,  1719,  1724,  1723,  1728,
    1730,  1733,  1737,  1738,  1741,  1745,  1747,  1751,  1754,  1755,
    1772,  1772,  1779,  1780,  1781,  1779,  1788,  1789,  1792,  1793,
    1796,  1797,  1798,  1799,  1800,  1803,  1804,  1807,  1811,  1812,
    1816,  1824,  1827,  1823,  1832,  1833,  1837,  1837,  1841,  1842,
    1845,  1848,  1849,  1852,  1853,  1857,  1865,  1864,  1871,  1872,
    1878,  1880,  1876,  1885,  1889,  1892,  1893,  1897,  1902,  1903,
    1906,  1912,  1914,  1917,  1918,  1922,  1924,  1928,  1928,  1934,
    1935,  1936,  1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,
    1953,  1953,  1958,  1959,  1963,  1964,  1965,  1966,  1970,  1974,
    1975,  1979,  1983,  1987,  1991,  1991,  1994,  1995,  1999,  1998,
    2001,  2005,  2004,  2007,  2011,  2015,  2019,  2024,  2027,  2028,
    2032,  2037,  2037,  2042,  2042,  2048,  2049,  2047,  2053,  2055,
    2058,  2062,  2063,  2066,  2069,  2070,  2073,  2076,  2077,  2082,
    2083,  2086,  2090,  2092,  2096,  2100,  2101,  2100,  2108,  2109,
    2116,  2113,  2120,  2121,  2125,  2126,  2129,  2130,  2135,  2134,
    2139,  2140,  2144,  2145,  2146,  2150,  2156,  2156,  2161,  2162,
    2165,  2168,  2170,  2174,  2177,  2182,  2186,  2187,  2191,  2195,
    2202,  2205,  2207,  2211,  2215,  2215,  2220,  2224,  2228,  2234,
    2236,  2232,  2241,  2246,  2247,  2245,  2253,  2254,  2257,  2261,
    2264,  2265,  2270,  2269,  2279,  2285,  2289,  2289,  2294,  2295,
    2299,  2302,  2305,  2309,  2314,  2316,  2319,  2320,  2325,  2324,
    2329,  2330,  2334,  2341,  2345,  2352,  2356,  2357,  2364,  2365,
    2371,  2372,  2377,  2378,  2382,  2386,  2387,  2388,  2389,  2390,
    2391,  2392,  2393,  2394,  2395,  2396,  2397,  2398,  2399,  2400,
    2401,  2402,  2403,  2407,  2413,  2418,  2427,  2429,  2426,  2445,
    2449,  2450,  2454,  2458,  2459,  2462,  2463,  2467,  2471,  2472,
    2475,  2476,  2477,  2478,  2479,  2480,  2484,  2488,  2488,  2494,
    2495,  2499,  2500,  2504,  2509,  2512,  2514,  2517,  2524,  2523,
    2530,  2533,  2537,  2546,  2551,  2556,  2557,  2556,  2562,  2564,
    2568,  2573,  2574,  2577,  2578,  2582,  2583,  2589,  2590,  2595,
    2596,  2600,  2601,  2607,  2608,  2613,  2614,  2615,  2616,  2617,
    2618,  2619,  2623,  2624,  2627,  2628,  2629,  2633,  2634,  2637,
    2638,  2639,  2640,  2644,  2648,  2649,  2652,  2653,  2658,  2659,
    2660,  2661,  2662,  2663,  2675,  2674,  2679,  2678,  2685,  2690,
    2695,  2698,  2699,  2700,  2707,  2708,  2711,  2714,  2715,  2718,
    2719,  2722,  2726,  2730,  2731,  2732,  2735,  2736,  2740,  2747,
    2752,  2755,  2756,  2760,  2761,  2762,  2772,  2776,  2777,  2778,
    2779,  2783,  2790,  2791,  2792,  2795,  2796,  2801,  2806,  2809,
    2812,  2812,  2817,  2826,  2824,  2834,  2836,  2839,  2840,  2841,
    2843,  2846,  2850,  2854,  2857,  2860,  2865,  2868,  2871,  2874,
    2876,  2881,  2882,  2883,  2884,  2887,  2888,  2889,  2890,  2894,
    2893,  2903,  2905,  2907,  2902,  2911,  2912,  2916,  2920,  2919,
    2925,  2927,  2929,  2924,  2934,  2937,  2940,  2941,  2940,  2947,
    2948,  2947,  2954,  2955,  2958,  2963,  2963,  2968,  2973,  2974,
    2975,  2979,  2983,  2986,  2989,  2996,  2997,  3000,  3005,  3009,
    3014,  3020,  3025,  3026,  3029,  3033,  3034,  3037,  3042,  3049,
    3050,  3054,  3056,  3059,  3064,  3067,  3070
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACTIVEtoken", "ADDINGtoken", "ALLtoken",
  "ALTERNATIVEtoken", "ANYtoken", "AStoken", "ATLEASTtoken", "AXIOMStoken",
  "BLOCKtoken", "CALLtoken", "CHANNELtoken", "COMMENTtoken",
  "CONNECTtoken", "CONNECTIONtoken", "CONSTANTtoken", "CONSTANTStoken",
  "CREATEtoken", "DCLtoken", "DECISIONtoken", "DEFAULTtoken", "DELAYtoken",
  "ELSEtoken", "ENDALTERNATIVEtoken", "ENDBLOCKtoken", "ENDCHANNELtoken",
  "ENDCONNECTIONtoken", "ENDDECISIONtoken", "ENDGENERATORtoken",
  "ENDMACROtoken", "ENDNEWTYPEtoken", "ENDOPERATORtoken",
  "ENDPACKAGEtoken", "ENDPROCEDUREtoken", "ENDPROCESStoken",
  "ENDREFINEMENTtoken", "ENDSELECTtoken", "ENDSERVICEtoken",
  "ENDSTATEtoken", "ENDSUBSTRUCTUREtoken", "ENDSYNTYPEtoken",
  "ENDSYSTEMtoken", "ENVtoken", "ERRORtoken", "EXPORTtoken",
  "EXPORTEDtoken", "EXTERNALtoken", "FItoken", "FINALIZEDtoken",
  "FORtoken", "FPARtoken", "FROMtoken", "GATEtoken", "GENERATORtoken",
  "IFtoken", "IMPORTtoken", "IMPORTEDtoken", "INtoken", "INHERITStoken",
  "INPUTtoken", "INTERFACEtoken", "JOINtoken", "LITERALtoken",
  "LITERALStoken", "MACROtoken", "MACRODEFINITIONtoken", "MACROIDtoken",
  "MAPtoken", "NAMECLASStoken", "NEWTYPEtoken", "NEXTSTATEtoken",
  "NODELAYtoken", "NOEQUALITYtoken", "NONEtoken", "NOWtoken",
  "OFFSPRINGtoken", "OPERATORtoken", "OPERATORStoken", "ORDERINGtoken",
  "OUTtoken", "OUTPUTtoken", "PACKAGEtoken", "PARENTtoken",
  "PRIORITYtoken", "PROCEDUREtoken", "PROCESStoken", "PROVIDEDtoken",
  "REDEFINEDtoken", "REFERENCEDtoken", "REFINEMENTtoken", "REMOTEtoken",
  "RESETtoken", "RETURNtoken", "RETURNStoken", "REVEALEDtoken",
  "REVERSEtoken", "SAVEtoken", "SELECTtoken", "SELFtoken", "SENDERtoken",
  "SERVICEtoken", "SETtoken", "SIGNALtoken", "SIGNALLISTtoken",
  "SIGNALROUTEtoken", "SIGNALSETtoken", "SPELLINGtoken", "STARTtoken",
  "STATEtoken", "STOPtoken", "STRUCTtoken", "SUBSTRUCTUREtoken",
  "SYNONYMtoken", "SYNTYPEtoken", "SYSTEMtoken", "TASKtoken", "THENtoken",
  "THIStoken", "TIMERtoken", "TOtoken", "TYPEtoken", "USEtoken",
  "VIAtoken", "VIEWtoken", "VIEWEDtoken", "VIRTUALtoken", "WITHtoken",
  "ANDtoken", "MODtoken", "NOTtoken", "ORtoken", "REMtoken", "XORtoken",
  "LTLTtoken", "GTGTtoken", "OTHER_CHARtoken", "APOSTROPHEtoken",
  "SPACEtoken", "LINEBREAKtoken", "TABULATORtoken", "COMMAtoken",
  "PLUStoken", "MINUStoken", "EXCLAMATIONtoken", "GREATERtoken",
  "ASTERISKtoken", "LEFTPARtoken", "RIGHTPARtoken", "QUOTEtoken",
  "SEMICOLONtoken", "LESStoken", "EQUALtoken", "COLONtoken",
  "FULLSTOPtoken", "DOUBLEEQUALtoken", "LONGTHICKARROWtoken",
  "NOTEQUALtoken", "LESSEQUALtoken", "GREATEREQUALtoken",
  "CONCATENATIONtoken", "ASSIGNMENTtoken", "THICKARROWtoken",
  "THINARROWtoken", "LEFTPARPERIODtoken", "RIGHTPARPERIODtoken",
  "NATURAL_NUMBERtoken", "CHARSTRINGtoken", "WORDtoken", "SLASHtoken",
  "UNDERLINEtoken", "HISTtoken", "PIPEtoken", "ENDPIPEtoken",
  "MACHINEtoken", "ENDMACHINEtoken", "SERVERtoken", "DISCIPLINEtoken",
  "OFFERStoken", "MACHINESERVICEtoken", "AWAKEtoken", "LINKtoken",
  "BINDtoken", "REQUESTtoken", "CLEARtoken", "UPDATEtoken", "ASSERTtoken",
  "BASECOUNTERtoken", "BASEFREQUENCYtoken", "BASETALLYtoken",
  "BASETIMEtoken", "FREQPROCESSCREATEtoken", "FREQPROCESSSTOPtoken",
  "FREQREQUESTtoken", "FREQSIGNALCONSUMEtoken", "FREQSIGNALDROPtoken",
  "FREQSIGNALRECEIVEtoken", "FREQSIGNALLOSEtoken", "FREQSIGNALSAVEtoken",
  "FREQSIGNALSENDtoken", "FREQSIGNALtoken", "FREQSTATEtoken",
  "FREQTRANSITIONtoken", "COUNTPROCESSCREATEtoken",
  "COUNTPROCESSSTOPtoken", "COUNTREQUESTtoken", "COUNTSIGNALCONSUMEtoken",
  "COUNTSIGNALDROPtoken", "COUNTSIGNALRECEIVEtoken",
  "COUNTSIGNALLOSEtoken", "COUNTSIGNALSAVEtoken", "COUNTSIGNALSENDtoken",
  "COUNTSIGNALtoken", "COUNTSTATEtoken", "COUNTTRANSITIONtoken",
  "LIFETIMEPROCESStoken", "QUEUECONTENTtoken", "QUEUELENGTHtoken",
  "RESPONSETIMEREQUESTtoken", "SENSORtoken", "SERVICETIMEREQUESTtoken",
  "THROUGHPUTtoken", "UTILIZATIONtoken", "WAITTIMEREQUESTtoken",
  "WAITTIMESIGNALtoken", "TRANSMISSIONTIMESIGNALtoken",
  "WAITTIMESTATEtoken", "ATOMtoken", "unary_minus", "$accept", "name",
  "opt_name", "comma_name_list", "par_comma_name_list",
  "opt_par_comma_name_list", "identifier", "opt_identifier",
  "comma_ident_list", "qualifier", "opt_qualifier", "ltlt_path_item_list",
  "path_item", "path_item_list", "name_or_quoted_operator",
  "scope_unit_kind", "informal_text", "end", "opt_end", "opt_comment",
  "comment", "sdl_specification", "opt_sdl_spec_body", "sdl_spec_body",
  "opt_referenced_def_list", "referenced_def_list", "package_list",
  "pckg_opt_ref_def_list_list", "package", "package_definition",
  "opt_packg_ref_clause_list", "packg_ref_clause_list",
  "opt_entity_in_pckg_list", "entity_in_pckg_list", "entity_in_package",
  "package_reference_clause", "opt_slash_def_sel",
  "definition_selection_list", "definition_selection", "opt_entity_kind",
  "entity_kind", "opt_interface", "interface", "referenced_definition",
  "system_definition", "definition", "textual_system_definition",
  "text_sys_def_body", "$@1", "entity_in_sys_list", "entity_in_system",
  "opt_block_substruct_def_or_ref", "block_substruct_def_or_ref",
  "block_substructure_reference", "block_substructure_definition", "$@2",
  "entity_in_substructure_list", "entity_in_substructure",
  "sys_sensor_definition", "sys_sensor_list", "sys_sensor_item",
  "sys_sensor_type", "sys_sensor_type_param", "block_reference",
  "block_definition", "$@3", "opt_block_body_list", "block_body_list",
  "block_body_list_item", "entity_in_block", "process_reference", "$@4",
  "process_definition", "$@5", "opt_fpar_end_item", "fpar_end_item",
  "opt_pcs_entity_item_list", "pcs_entity_item_list", "pcs_entity_item",
  "entity_in_process", "pcs_sensor_definition", "pcs_sensor_list",
  "pcs_sensor_item", "pcs_sensor_type", "pcs_sensor_type_param",
  "procedure_reference", "valid_input_signal_set", "$@6", "$@7",
  "opt_valid_input_signal_set", "process_body", "opt_process_body",
  "opt_state_or_free_action_list", "state_or_free_action_list",
  "state_or_free_action", "formal_parameters", "$@8",
  "comma_parameters_of_sort_list", "parameters_of_sort",
  "number_of_process_instances", "opt_number_of_process_instances",
  "opt_comma_opt_max_no", "comma_opt_max_no", "opt_comma_opt_queue_length",
  "comma_opt_queue_length", "initial_number", "opt_initial_number",
  "maximum_number", "opt_maximum_number", "queue_length",
  "opt_queue_length", "service_definition", "opt_entity_in_service_list",
  "entity_in_service_list", "entity_in_service", "service_body",
  "procedure_definition", "$@9", "opt_proc_fpar_end_item",
  "proc_fpar_end_item", "opt_proc_result_end_item", "proc_result_end_item",
  "opt_entity_in_proc_item_list", "entity_in_proc_item_list",
  "entity_in_proc_item", "procedure_formal_parameters", "$@10",
  "opt_comma_formal_var_param_list", "comma_formal_var_param_list",
  "formal_variable_parameters", "parameter_kind", "in_out",
  "procedure_result", "entity_in_procedure", "procedure_body",
  "opt_procedure_body", "channel_definition", "$@11", "opt_nodelay",
  "channel_path", "$@12", "$@13", "$@14", "$@15", "opt_channel_path",
  "channel_endpoint", "ident_or_env", "signal_route_definition", "$@16",
  "signal_route_path", "$@17", "$@18", "$@19", "$@20",
  "opt_signal_route_path", "signal_route_endpoint", "channel_connection",
  "$@21", "$@22", "channel_to_route_connection", "$@23", "$@24",
  "signal_route_to_route_connection", "signal_definition", "$@25",
  "comma_sig_def_item_list", "signal_definition_item", "$@26", "sort_list",
  "opt_sort_list", "comma_sort_list", "signallist_definition", "$@27",
  "$@28", "$@29", "signallist", "opt_signallist", "signallist_item",
  "$@30", "variable_definition", "$@31", "opt_history_item",
  "opt_revealed_exported_item", "revealed_exported_item",
  "variables_of_sort", "$@32", "comma_var_exported_list", "var_exported",
  "opt_var_init", "var_init", "variables_of_sort_list", "exported_as",
  "opt_exported_as", "start", "$@33", "state", "$@34", "$@35", "$@36",
  "opt_state_body_list", "state_body_list", "state_body_item",
  "opt_endstate_item", "endstate_item", "state_list", "input_part",
  "basic_input_part", "$@37", "$@38", "input_list", "stimulus", "$@39",
  "opt_par_comma_opt_var_list", "par_comma_opt_var_list",
  "comma_opt_var_list", "comma_stimulus_list", "save_part",
  "basic_save_part", "$@40", "save_list", "spontaneous_transition", "$@41",
  "$@42", "spontaneous_designator", "label", "opt_label", "free_action",
  "opt_endconnection_item", "endconnection_item", "transition",
  "opt_transition", "transition_string", "action_statement", "$@43",
  "action", "terminator_statement", "$@44", "opt_terminator_statement",
  "terminator", "nextstate", "nextstate_body", "join", "stop", "return",
  "task", "$@45", "task_body", "comma_assignment_statement_list", "$@46",
  "comma_informal_text_list", "$@47", "create_request", "create_body",
  "ident_or_this", "actual_parameters", "opt_actual_parameters",
  "procedure_call", "procedure_call_body", "$@48", "output", "$@49",
  "output_body", "$@50", "$@51", "comma_ident_actual_param_list",
  "ident_actual_param", "opt_to_destination", "to_destination",
  "opt_via_path_item", "via_path_item", "opt_all", "opt_delay", "delay",
  "destination", "via_path", "decision", "$@52", "$@53", "decision_body",
  "answer_part", "$@54", "answer_part_list", "answer", "opt_answer",
  "else_part", "$@55", "opt_else_part", "question", "timer_definition",
  "timer_definition_item", "$@56", "opt_timer_init", "timer_init",
  "timer_definition_item_list", "reset", "par_comma_reset_statement_list",
  "reset_statement", "comma_reset_statement_list", "set", "set_statement",
  "expr_comma", "comma_set_statement_list", "simple_expression",
  "asterisk_state_list", "$@57", "asterisk_input_list",
  "asterisk_save_list", "dash_nextstate", "priority_input", "$@58", "$@59",
  "priority_input_list", "continuous_signal", "$@60", "$@61",
  "opt_priority_name_end_item", "priority_name_end_item",
  "enabling_condition", "opt_enabling_condition",
  "partial_type_definition", "$@62", "properties_expression", "operators",
  "literal_list", "$@63", "opt_literal_list", "literal_signature",
  "comma_literal_signature_list", "operator_list",
  "operator_signature_end_list", "opt_operator_list", "operator_signature",
  "$@64", "operator_name", "result", "extended_sort", "sort", "opt_sort",
  "extended_properties", "opt_extended_properties", "quoted_operator",
  "quote", "infix_operator", "monadic_operator", "noequality", "ordering",
  "syntype_definition", "$@65", "$@66", "const_range_item",
  "opt_const_range_item", "parent_sort_identifier", "range_condition",
  "closed_open_range", "closed_range", "open_range", "range_op",
  "constant", "structure_definition", "$@67", "opt_adding", "field_list",
  "fields", "field_sort", "generator_transformations",
  "generator_trans_item", "generator_transformation", "$@68",
  "generator_actual_list", "generator_actual", "synonym_definition",
  "internal_synonym_definition", "synonym_definition_item", "$@69", "$@70",
  "comma_synonym_definition_item_list", "ground_expression", "expression",
  "opt_expression", "sub_expression", "operand0", "or_op", "operand1",
  "operand2", "equ_op", "operand3", "add_op", "operand4", "div_op",
  "operand5", "opt_unary_op", "unary_op", "primary", "indexed_primary",
  "$@71", "$@72", "field_primary", "field_selection", "data_definition",
  "def_item", "expression_list", "par_comma_opt_expr_list",
  "comma_opt_expr_list", "opt_par_expression_list", "par_expression_list",
  "assignment_statement", "variable", "opt_variable", "indexed_variable",
  "field_variable", "default_initialization", "opt_default_initialization",
  "imperative_operator", "now_expression", "PID_expression",
  "value_returning_procedure_call", "virtuality", "opt_virtuality",
  "machine_service_definition", "comma_ms_def_item_list",
  "machineservice_definition_item", "$@73", "machine_reference",
  "machine_definition", "$@74", "mach_body_list", "mach_body_list_item",
  "server_item", "discipline_item", "machservice_name_speed_list",
  "machservice_name_speed_list_item", "machineservice_speed",
  "mach_sensor_list", "mach_sensor_definition", "mach_sensor_type",
  "mach_sensor_type_param", "pipe_definition", "$@75", "pipe_path", "$@76",
  "$@77", "$@78", "opt_pipe_path", "pipe_endpoint", "link_definition",
  "$@79", "link_path", "$@80", "$@81", "$@82", "link_endpoint",
  "machineservicelist", "pipe_binding", "$@83", "$@84",
  "pipe_to_link_binding", "$@85", "$@86", "opt_awake_item", "awake_item",
  "request", "$@87", "request_body", "opt_target", "from_item",
  "request_parameter_list", "request_parameter", "opt_comma_priority",
  "comma_priority", "priority", "via_request_path", "clear", "update",
  "opt_update_body", "update_body", "opt_comma_value", "comma_value",
  "assert", "opt_atom_definition", "atom_definition",
  "atom_definition_item", "name_expr_pair_list", "name_expr_pair", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484
};
# endif

#define YYPACT_NINF -1003

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1003)))

#define YYTABLE_NINF -664

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -48,  -121,    66,   253,   -48,    68, -1003,   -12,   -19, -1003,
   -1003,   -61, -1003, -1003, -1003,     2,    68, -1003,    68,  1249,
    1249,  1249,  1249,  1249,  1249, -1003,    68, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003,  -121, -1003,  1309,   119,  -121,
   -1003,   -78, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003,  1199, -1003, -1003, -1003,  -121, -1003, -1003,
      40,   165,   119,    73,   119, -1003,   119, -1003,   154, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
      83, -1003,  -121, -1003,    77, -1003,   132, -1003, -1003,  -121,
   -1003,   -78, -1003,    90,   119, -1003,  1199, -1003, -1003, -1003,
   -1003,  1313, -1003,   126, -1003,   119,   184,   119, -1003,  1309,
     119, -1003,  1309, -1003, -1003, -1003,   119,   125,    18, -1003,
   -1003, -1003,   488, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003,   171,   171,   281,  1249, -1003, -1003, -1003,
     199, -1003, -1003, -1003, -1003,   214,   211,   276,   469,   313,
     180, -1003,   780, -1003, -1003, -1003, -1003, -1003,   299,   109,
     117,    83,   568, -1003,   286,   174,  -121, -1003, -1003,  -121,
     888,  1249, -1003,  -121,  -121,  -121,  -121,  1249,  -121,  -121,
   -1003,  1249, -1003,   302,   488, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
     119, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,   330,
   -1003,   119, -1003, -1003,   130,   294, -1003,    84, -1003, -1003,
      84,    84, -1003, -1003, -1003, -1003, -1003, -1003, -1003,    84,
   -1003, -1003, -1003,    84, -1003, -1003, -1003, -1003,    84, -1003,
   -1003, -1003, -1003, -1003, -1003,   174, -1003, -1003,   244, -1003,
   -1003, -1003, -1003, -1003,   389,   456, -1003,  -121, -1003,   340,
     299, -1003, -1003, -1003, -1003, -1003,  1249,  -121, -1003,  -121,
   -1003, -1003,    57, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003,   174,   174,  -121,
    1249,   219, -1003,   119,   119,   419,   568, -1003, -1003, -1003,
   -1003, -1003, -1003,   289, -1003, -1003, -1003,  1249, -1003,   388,
      73,  -121, -1003, -1003, -1003, -1003,   337, -1003,    29, -1003,
      49, -1003, -1003,  1249,   897,    93, -1003,  1249,   454, -1003,
   -1003, -1003, -1003, -1003,   -17,  -121,   273, -1003,   119, -1003,
     345, -1003, -1003, -1003,    87,   347, -1003,   211,   276,   469,
     313,   180, -1003,   353,   -59, -1003, -1003, -1003,   184, -1003,
     119,  1249, -1003,   363, -1003, -1003,   336, -1003, -1003,   100,
   -1003, -1003,   474,    37, -1003,   432, -1003,  1249, -1003,  1249,
    -121, -1003, -1003, -1003,   373,   102, -1003,   762,   107, -1003,
    -121, -1003, -1003, -1003,  -121, -1003,  -121, -1003, -1003,   382,
     575,   119,    35, -1003,   122, -1003,   376,   478,   701,  -121,
     379,   119,   385,  -121, -1003,   482,   382, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
     393,  1249, -1003,   446,   930,   374, -1003,   403, -1003,  -121,
   -1003, -1003,  1249, -1003, -1003,    95,   273, -1003, -1003, -1003,
   -1003, -1003,   181, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003,   174,  -121,    26, -1003, -1003,   958,   119,
   -1003,    12,   385,  -121, -1003,   161,   930,  -121, -1003, -1003,
      37, -1003, -1003, -1003,   119,   477,   382,   502,   382,   119,
     174,  -121, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003,   393,  1249, -1003,   119,   119,   119,  1249,   427,
   -1003,   413, -1003,   497, -1003,   930, -1003,    22, -1003, -1003,
     385,  -121, -1003, -1003,  1044,   478, -1003, -1003, -1003, -1003,
    1249, -1003,  1249, -1003, -1003, -1003,  1044, -1003,   442,  -121,
   -1003, -1003, -1003,   119, -1003,   119,   483,   506, -1003,  1089,
   -1003, -1003,    37, -1003,   531,    37, -1003, -1003, -1003,   114,
     174, -1003,   323,   425, -1003,  1249,  1249,   340,    26, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003,   421, -1003, -1003,   472,   524,  -121, -1003,   411, -1003,
   -1003, -1003, -1003, -1003,   119,   119,   422, -1003,   254,   549,
    1321, -1003, -1003,   205, -1003, -1003, -1003,   527,   452,  1044,
     502,   461, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003,  1249,  -121, -1003, -1003,   551,   563, -1003,   508,
   -1003, -1003,   584,   119, -1003, -1003,   958, -1003, -1003, -1003,
   -1003, -1003, -1003,   444, -1003, -1003,   346, -1003, -1003, -1003,
    1249,   348, -1003, -1003, -1003, -1003,  -121, -1003,   930, -1003,
     181, -1003,   349,   174, -1003,  -121,   209,  1307,   123, -1003,
   -1003,   564, -1003, -1003, -1003, -1003,   591, -1003,  1130, -1003,
     143,   174, -1003, -1003,  -121, -1003, -1003,   334,   339,  -121,
   -1003, -1003, -1003, -1003, -1003, -1003,   464, -1003, -1003,  1044,
     527,  1249, -1003, -1003, -1003,   433,  1249,   144,  1089,    22,
   -1003,  1249,  -121,  -121,   174, -1003, -1003,   -30, -1003, -1003,
   -1003, -1003, -1003,   363,   487,   174,   563,  1249, -1003,   489,
     144, -1003, -1003,   119, -1003, -1003, -1003, -1003,  1249, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003,   393,  1249, -1003,
     930,  1249, -1003, -1003,  -121, -1003,  -121, -1003, -1003, -1003,
    1249, -1003, -1003,   466,   468, -1003, -1003,   470,   476,   485,
     119, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003,  -121,   140,   103, -1003,   119, -1003, -1003, -1003,
   -1003,   119,   393,   445, -1003, -1003, -1003,   608,   144,   515,
    -121,   144, -1003, -1003, -1003,  -121,   584, -1003, -1003,   350,
   -1003, -1003, -1003,    25, -1003,    22, -1003, -1003, -1003,    22,
   -1003,   486, -1003, -1003,   119,  1044, -1003,   619, -1003,  1044,
   -1003, -1003,   144, -1003, -1003,   119, -1003, -1003,   479, -1003,
   -1003, -1003,   345,    33,  1249,  1249, -1003,   174, -1003,   501,
    1171,  1249,  1249,  1249,   174, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003,   174, -1003, -1003,   529,  -121,
   -1003,  1044,   119, -1003, -1003, -1003,  1249, -1003,  -121, -1003,
   -1003,   -30, -1003, -1003, -1003, -1003,   394, -1003,   603, -1003,
   -1003, -1003,   174, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003,   345, -1003,   288, -1003,   500, -1003,   352,  1249,   510,
     468, -1003, -1003, -1003,   513,   514, -1003,   315, -1003, -1003,
     509, -1003,   166, -1003,   517,   525,   520, -1003,   119,  1044,
     119, -1003, -1003, -1003, -1003, -1003,  1249,   547, -1003, -1003,
   -1003, -1003, -1003, -1003,   534, -1003, -1003, -1003,   174,   505,
   -1003,  -121,   550, -1003,   119, -1003,   136,  1249, -1003, -1003,
     174, -1003, -1003,  1249, -1003,   500, -1003, -1003, -1003, -1003,
    -121,   174,   174, -1003,   174,  1249,  1249,  1249, -1003, -1003,
   -1003, -1003,   174,   532, -1003, -1003,   370, -1003, -1003,   552,
     220, -1003,   394, -1003,   174, -1003,  1249,   536, -1003, -1003,
   -1003, -1003,   561,   362, -1003,   540,  1249,   526,   365, -1003,
     554, -1003,   382, -1003, -1003,   559, -1003,   161,   631,   161,
     161,   663,   370, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003,   576,  1249,  1249,   958, -1003, -1003,   382, -1003,   589,
     676,     1,   704, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
     174,   557, -1003,   174, -1003, -1003,   638,   161, -1003, -1003,
    -121, -1003, -1003, -1003, -1003, -1003, -1003, -1003,   363,   119,
   -1003, -1003,   566,   534, -1003,   562, -1003,     1, -1003, -1003,
    1249,   695, -1003, -1003, -1003, -1003, -1003,  1212, -1003, -1003,
     174,   787,   119,   958,   119,   119, -1003,   565, -1003, -1003,
   -1003, -1003, -1003,   174, -1003, -1003, -1003, -1003,   119, -1003,
     581, -1003,   119,  1249, -1003, -1003,   363,   119, -1003, -1003,
     363, -1003, -1003, -1003,   -10, -1003,   577,   636,  1249,   636,
     581,   119,   119, -1003,   119,    72, -1003, -1003,   930, -1003,
   -1003,   174, -1003, -1003, -1003, -1003, -1003,   644, -1003, -1003,
     368,   272, -1003,   119,  -121,  -121,  -121,  -121,  -121, -1003,
     930, -1003, -1003, -1003, -1003, -1003,   119, -1003, -1003, -1003
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      51,     0,     0,    44,    52,    47,    55,     0,    58,    60,
       2,    71,     1,    43,    45,     0,    47,    93,    47,    17,
      17,    17,    17,    17,    17,    53,    48,    49,    92,    98,
      94,    95,    96,    97,    99,     0,    59,    76,    40,     0,
     100,   829,    54,    27,    33,    25,    31,    29,    30,    32,
      28,    26,    34,     0,    35,   146,    18,     0,    16,    21,
      15,     0,    40,   243,    40,   121,    40,    50,    89,    79,
      86,    84,    83,    80,    88,    81,    82,    85,    87,    78,
      72,    74,     0,    77,     0,    70,     0,    41,   101,     0,
      46,   830,   832,     0,    40,    10,     0,   594,    23,    20,
      24,     0,   271,   694,   244,    40,   226,    40,   753,    76,
      40,    90,    76,    75,    42,    37,    40,     0,    40,   835,
     831,    19,   148,    22,   599,   598,   610,   613,   596,   611,
     597,   606,   612,   602,   608,   603,   601,   600,   604,   605,
     609,   595,   607,     0,     0,   273,    17,   697,   696,   253,
     245,   741,   251,   543,   660,   661,   665,   667,   671,   673,
     682,   687,    17,   695,   662,   170,   223,   227,   261,     0,
       0,    91,    61,    73,     0,   694,     0,   833,   331,     0,
       0,    17,   335,     0,     0,     0,     0,    17,     0,     0,
     799,    17,   167,   116,   149,   151,   154,   158,   157,   161,
     162,   159,   152,   155,   156,   711,   712,   713,   653,   160,
      40,   163,   165,   164,   166,   153,   592,   593,   284,   276,
     274,    40,   481,   480,   694,   248,   246,   694,   669,   670,
     694,   694,   681,   677,   679,   675,   676,   680,   678,   694,
     684,   685,   686,   694,   691,   692,   689,   690,   694,   735,
     736,   739,   738,   737,   740,   694,   699,   698,   693,   701,
     702,   703,   733,   734,   172,   352,   357,     0,   268,     0,
     262,   264,   267,   265,   269,   266,    17,     0,   328,     0,
     796,   125,     0,   124,   115,   106,   105,   112,   111,   107,
     126,   108,   109,   110,   113,   114,   127,   694,   694,     0,
      17,     0,   756,    40,    40,     0,    62,    64,    66,    65,
      67,    68,    69,     0,   104,   836,   834,    17,   562,     0,
     243,     0,   346,   318,   655,   659,   654,   616,    40,   750,
      40,   749,   788,    17,     0,    40,   130,    17,     0,   117,
     119,   118,   150,   710,   286,     3,   279,   277,    40,   275,
     478,   256,   247,   254,   694,     0,   249,   666,   668,   672,
     674,   683,   688,     0,     0,   704,   708,   237,   226,   173,
      40,    17,   354,   353,   224,   350,   359,   526,   532,    40,
     380,   270,     0,   231,   263,   146,   304,    17,   779,    17,
       3,   123,   761,   762,     0,    40,   764,     0,    40,   768,
       3,   755,   757,   758,     3,    63,     3,   103,    14,   332,
     590,    40,    40,   339,    40,   338,     0,     0,    17,     0,
       0,    40,   342,     0,   747,     0,   800,   133,   134,   135,
     138,   139,   137,   136,   141,   142,   144,   143,   140,   131,
       8,    17,   128,   121,    11,   294,   285,   287,   289,     0,
     292,     4,    17,   298,   299,   302,   280,   282,   283,   297,
     296,   278,   694,   479,   482,   477,   259,   250,   257,   242,
     700,   706,   709,   694,     0,   175,   174,   355,    17,    40,
     360,   361,   342,     0,   525,   745,    11,   425,   382,   228,
     232,   234,   235,   236,    40,   306,   329,     0,   797,    40,
     694,     0,   759,   771,   775,   773,   772,   778,   777,   774,
     776,   769,     8,    17,   760,    40,    40,    40,    17,     0,
     637,     0,   591,   568,   588,   589,   646,    38,   222,   168,
     342,     0,   336,   347,    17,   325,   585,   587,   656,   658,
      17,   752,    17,   343,   751,   748,    17,   789,     0,     0,
       9,   132,   129,    40,    12,    40,     0,   291,     6,    17,
     290,   295,   301,   303,     0,   231,   281,   664,   718,     0,
     694,   715,     0,   238,   240,    17,    17,   229,   176,   178,
     179,   189,   183,   184,   188,   180,   181,   182,   186,   187,
     185,     0,   351,   225,   364,   363,     0,   362,   528,   531,
     744,   743,   742,   746,    40,    40,     0,   426,   437,   428,
     425,   436,   432,     0,   233,   145,   307,     0,     0,    17,
     785,     0,   122,   766,   765,   763,   770,   767,   754,    56,
     102,    13,    17,     0,   648,   566,     0,   731,   569,   576,
     645,    39,   639,    40,   340,   337,    17,   317,   316,   327,
     320,   326,   319,     0,   622,   617,     0,   345,   794,   790,
      17,     0,   120,   147,   293,   288,     0,   241,    11,   300,
     694,   716,     0,   694,   705,     0,     0,     0,    40,   192,
     230,     0,   177,   356,   366,   365,   378,   376,    17,   370,
      40,   694,   527,   529,   425,   260,   424,     0,     0,     3,
     427,   429,   435,   453,   431,   544,   398,   383,   399,    17,
     313,    17,   787,   781,   786,     0,    17,    40,    17,    38,
     642,    17,     0,     3,   694,   732,   564,     0,   577,   565,
     640,   647,   169,   348,     0,   694,   731,    17,   341,     0,
      40,     7,     5,    40,   717,   707,   714,   239,    17,   195,
     196,   197,   204,   201,   200,   198,   203,   202,   199,   205,
     220,   214,   211,   210,   208,   213,   212,   209,   215,   221,
     207,   206,   218,   216,   219,   217,   193,     8,    17,   190,
      11,    17,   379,   371,     0,   367,     0,   358,   530,   381,
      17,   505,   483,     0,     0,   464,   805,     0,     0,     0,
      40,   440,   442,   446,   441,   443,   445,   444,   439,   448,
     447,   449,     0,     0,   694,   462,    40,   454,   455,   456,
     457,    40,     8,   802,   308,   315,   314,     0,    40,     0,
       3,    40,   333,   644,   643,    39,   639,   652,   584,     0,
     651,   570,   572,    38,   563,    38,   614,   615,   582,    38,
     575,     0,   581,   580,    40,    17,   657,   620,   344,    17,
     801,   272,    40,   194,   191,    40,   377,   369,   372,   375,
     476,   474,   478,   694,    17,    17,   533,   694,   542,   538,
      17,    17,    17,    17,   694,   438,   461,   548,   459,   458,
     460,   463,   451,   430,   545,   694,   384,   803,     0,     3,
     330,    17,    40,   798,   641,   638,    17,   649,     0,   567,
     730,    39,   573,   578,   349,   321,   694,   621,     0,   791,
     334,   171,   694,   368,   373,   475,   524,    36,   523,   506,
     522,   478,   484,   491,   489,   719,   537,     0,    17,     0,
       0,   723,   473,   465,   466,   467,   470,     0,   724,   725,
       0,   806,   808,   813,     0,   822,     0,   804,    40,    17,
      40,   782,   780,   650,   571,   574,    17,     0,   633,   632,
     630,   631,   634,   635,   619,   624,   625,   626,   694,   628,
     636,     3,     0,   374,    40,   490,   694,    17,   485,   492,
     694,   535,   720,    17,   534,   719,   540,   541,   468,   471,
       0,   694,   694,   729,   694,    17,    17,    17,   807,   810,
     809,   820,   694,     0,   823,   828,   386,   309,   305,     0,
       0,   322,   694,   629,   694,   618,    17,     0,   503,   493,
     502,   488,   494,     0,   536,     0,    17,     0,     0,   722,
     815,   811,   504,   819,   812,   825,   821,   745,     0,   745,
     745,   395,   387,   389,   390,   400,   392,   415,   393,   391,
     394,     0,    17,    17,    17,   623,   627,   795,   792,   694,
       0,     0,   497,   486,   495,   721,   539,   469,   472,   728,
     694,     0,   816,   694,   824,   826,   401,   745,   553,   416,
       3,   385,   396,   388,   310,   783,   579,   583,   323,    40,
     515,   517,     0,   514,   507,     0,   513,   520,   508,   498,
      17,   499,   818,   817,   814,   827,   423,    17,   420,   549,
     694,    17,    40,    17,    40,    40,   793,     0,   518,   512,
     521,   509,   496,   694,   487,   500,   546,   406,    40,   414,
     405,   404,    40,    17,   554,   547,   418,    40,   419,   397,
     311,   784,   324,   510,   425,   501,   408,   560,    17,   560,
     552,    40,    40,   417,    40,   425,   434,   519,   726,   407,
     409,   694,   561,   402,   413,   421,   550,   556,   312,   511,
       0,   727,   412,    40,   425,   425,   425,     0,   425,   557,
     726,   410,   559,   403,   422,   551,    40,   555,   411,   558
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1003,    -1,  -383,  -531, -1003,  -508,    71,  -474,  -304, -1003,
   -1003, -1003,   635,   679, -1003, -1003,  -847,   316,  -643, -1003,
   -1003, -1003, -1003, -1003,   436, -1003, -1003, -1003,   730, -1003,
     733, -1003, -1003, -1003,   434,   735, -1003,   637,   633, -1003,
   -1003, -1003, -1003,   726, -1003, -1003, -1003, -1003, -1003, -1003,
    -144, -1003, -1003, -1003,   560, -1003, -1003,   480,   137, -1003,
     319, -1003, -1003, -1003,  -147, -1003, -1003, -1003,   567, -1003,
   -1003, -1003,   179, -1003, -1003, -1003, -1003, -1003,   176, -1003,
   -1003, -1003,   -22, -1003, -1003,  -114, -1003, -1003, -1003,   395,
     187, -1003,   200,   317,  -281, -1003, -1003, -1003,  -468, -1003,
     448, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003,   503, -1003,  -117, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003,   314, -1003, -1003, -1003, -1003,   217,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,    61,
   -1003, -1003, -1003, -1003, -1003,  -184,  -535,  -449, -1003,   241,
   -1003, -1003, -1003, -1003, -1003,   -77, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003,  -108, -1003, -1003,   250, -1003, -1003,  -379,
    -180,   -94, -1003, -1003, -1003,  -636, -1003,   304, -1003,  -330,
   -1003, -1003, -1003, -1003,     4, -1003, -1003,     9, -1003, -1003,
   -1003, -1003, -1003,   341, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003,  -258, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
    -361, -1003, -1003, -1003, -1003,  -344, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,  -486,
    -365, -1003,   191, -1003, -1003,   192, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003,  -825,   110, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003,  -183, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003,  -301, -1003, -1003, -1003, -1003, -1002,
   -1003, -1003, -1003, -1003,  -294, -1003, -1003, -1003,  -444,   333,
   -1003, -1003, -1003, -1003, -1003, -1003,  -187, -1003, -1003,  -122,
   -1003, -1003,  -151, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,  -340, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003,   -88, -1003, -1003, -1003,
   -1003,   -89, -1003, -1003, -1003,  -239,  -415, -1003, -1003, -1003,
   -1003,   332, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003,  -244,  -196, -1003, -1003, -1003,  -911, -1003, -1003,
      -9, -1003,    -6, -1003, -1003,   305, -1003, -1003, -1003,   -71,
   -1003, -1003,   418, -1003, -1003, -1003,  -101,  -235,  -646, -1003,
     611, -1003,   609,   610, -1003,   601, -1003,   599, -1003,   595,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003,   586,  -107, -1003,
    -561, -1003, -1003,  -149, -1003,  -189,  -804,  -337, -1003, -1003,
   -1003,   124, -1003, -1003, -1003, -1003, -1003,  -604,   185, -1003,
     439, -1003, -1003,   189, -1003, -1003,   558, -1003, -1003, -1003,
     354, -1003, -1003,   355, -1003, -1003, -1003, -1003,   230, -1003,
   -1003, -1003, -1003,   -29, -1003, -1003, -1003, -1003, -1003, -1003,
      16,  -185, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003,  -129, -1003, -1003, -1003,
   -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003, -1003,
     788, -1003,   707
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   451,   452,   559,   550,   551,   408,   555,  1042,    56,
      57,    58,    59,    60,    99,    61,   928,   641,   642,    86,
      87,     2,    13,    14,    25,    26,     3,     4,     5,     6,
       7,     8,   305,   306,   307,     9,    38,    80,    81,    82,
      83,   110,   111,    27,    16,    28,    17,    40,   116,   313,
     281,   338,   339,   340,    29,   107,   282,   283,   284,   335,
     336,   439,   440,   285,    30,    94,   193,   194,   195,   196,
     197,   643,    31,   264,   368,   369,   577,   578,   579,   580,
     581,   678,   679,   776,   777,   287,   167,   265,   479,   168,
     381,   681,   489,   490,   491,   370,   474,   573,   560,   104,
     105,   225,   226,   355,   356,   149,   150,   351,   352,   466,
     467,    32,   269,   270,   271,   382,    33,   145,   219,   220,
     346,   347,   455,   456,   457,   221,   344,   446,   447,   448,
     449,   450,   348,   458,   563,   564,   289,   495,   617,   710,
     898,  1061,  1123,  1164,   827,   824,   649,   201,   417,   535,
     734,   967,  1064,  1125,   652,   650,   290,   387,   618,   202,
     317,   519,   585,   291,   321,   414,   415,   530,   543,   544,
     656,   292,   416,   646,   854,   373,   374,   375,   591,   273,
     376,   481,   596,   597,   687,   868,   688,   689,   923,   924,
     690,   782,   783,   383,   485,   492,   613,   823,   958,  1051,
    1052,  1053,  1091,  1092,   707,  1054,  1055,  1117,  1184,  1138,
    1139,  1156,  1169,  1170,  1180,  1140,  1056,  1057,  1121,  1147,
    1058,  1142,  1185,  1118,   607,   608,   493,   700,   701,  1166,
    1167,   610,   611,   697,   800,   612,   698,   704,   816,   817,
     889,   818,   819,   820,   801,   880,   943,   944,  1036,   945,
    1037,   802,   871,   872,   463,   464,   151,   223,   350,   804,
     874,   932,  1032,  1111,   933,   934,   988,   989,  1073,  1074,
    1110,  1134,  1135,  1029,  1043,   805,   873,   984,  1070,  1071,
    1165,  1107,  1101,  1102,  1108,  1154,  1131,   929,   274,   378,
     482,   692,   693,   379,   806,   876,   936,   937,   807,   878,
     938,   879,   152,   708,   822,  1141,  1148,   890,  1059,  1143,
    1186,  1161,  1060,  1120,  1162,  1188,  1189,  1172,  1173,   205,
     410,   636,   637,   638,   722,   639,   842,   843,   728,   849,
     729,   850,   966,   851,  1096,   837,   838,   538,   522,   523,
     100,   101,   143,   144,   852,   853,   206,   420,   736,   917,
     918,   655,   974,   975,   976,   977,   978,   979,   524,   633,
     731,   719,   720,   834,   525,   526,   527,   721,   839,   840,
     207,   208,   325,   418,   653,   326,   980,   154,   568,   155,
     156,   230,   157,   158,   239,   159,   243,   160,   248,   161,
     162,   163,   258,   259,   473,   570,   260,  1003,   293,   210,
     572,   465,   569,   991,   992,   946,   947,  1182,   948,   949,
     725,   726,   261,   262,   263,   164,   603,   604,   294,   330,
     331,   422,   212,    34,   170,   301,   302,   303,   304,   395,
     396,   624,   398,   399,   511,   512,   295,   497,   620,   829,
    1019,  1124,   715,   713,   214,   425,   547,   739,   982,  1099,
     659,  1068,   296,   389,   621,   215,   333,   548,   896,   897,
     808,   881,   951,  1008,  1009,   952,   953,  1081,  1082,  1113,
    1010,   809,   810,  1013,  1014,  1084,  1085,   811,    90,    91,
      92,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   609,   153,   537,   626,   200,   574,   499,   199,   672,
     733,   658,   605,   409,   203,   209,   459,   515,   661,  -433,
     363,   516,   286,   517,   744,  1105,   584,   286,   204,   426,
     314,   589,    84,   942,    68,   -57,    84,   561,    88,    84,
     926,   575,   445,    84,   846,   146,   266,   925,    10,    84,
     847,   272,   288,   487,   268,   309,    95,   288,   308,   594,
      98,   275,   392,    84,   310,   312,    12,  1023,   276,  1106,
     277,    35,   278,   353,   315,     1,   836,   200,   311,    19,
     199,   113,   706,   496,   712,   498,   203,   209,   117,   471,
      55,    62,    63,    64,    65,    66,  -433,   179,   390,   146,
     204,  -433,   718,   598,     1,  1129,   985,    84,   595,    37,
      10,   487,   180,  1066,    84,   146,    84,  -663,    39,   421,
     276,    84,   277,   153,   278,   529,   459,   657,   179,   584,
     182,   183,   184,    84,   589,   286,    84,    84,   146,    10,
     185,   186,   146,   180,   667,   588,   267,   488,   146,  1069,
      89,   644,  -291,   272,    20,    21,   268,    84,    84,    10,
     176,   182,   183,   275,   147,   288,   286,   908,   891,   407,
      22,   185,   186,   -40,   825,   117,   -40,   148,   318,   319,
     179,    23,   322,   323,   324,   327,   146,   329,   332,   309,
    1078,   423,   308,   146,   743,   180,   288,   393,   310,   312,
     909,   927,   910,   468,   380,   488,   912,   747,   789,   614,
      96,   600,   311,   182,   183,   147,   109,   222,   147,  1005,
    -433,   103,  1100,   185,   186,   112,   121,   567,   148,   454,
     279,   148,   453,   257,   147,   441,  -258,   188,   571,   460,
     280,    10,   483,    24,   501,   114,   576,   148,   588,   513,
     601,    62,   320,   153,  -663,  1028,   670,   147,   328,   192,
      96,   147,   334,   671,   531,   778,   377,   147,  -252,   863,
     148,   676,  -255,   785,   148,  -252,   386,   191,   388,  -255,
     148,   614,   279,   115,   887,   786,   518,   175,   602,   188,
    1006,   166,   280,   266,   297,   298,   299,   276,   394,   277,
     276,   198,   277,   833,   718,   147,   865,   211,  1007,    10,
     244,   213,   147,   245,   894,    97,   821,  -450,   148,   266,
     413,    97,   858,  -663,   658,   148,  -450,   246,   717,   191,
    -663,   192,   406,   218,    10,   571,   372,   300,   748,   454,
     844,   224,   453,   228,   179,   229,   146,   385,  -450,   460,
     247,   518,   705,   790,    85,   791,   740,   179,   583,   180,
     179,   582,   737,   472,  1181,  -450,   712,   586,   590,   -57,
     179,   397,   180,   198,    10,   180,     1,   227,   102,   211,
     106,   587,   108,   213,  1063,   180,  1181,   185,   186,   364,
     182,   183,   365,   182,   183,   400,   297,   298,   299,   623,
     185,   186,   812,   185,   186,   231,   146,   828,   443,   986,
     122,   813,   831,   185,   186,   337,   792,  1000,   324,   267,
    1001,   165,   329,   169,   825,   345,   172,   793,  1098,  1033,
     987,  1047,   174,   814,   177,   567,   354,   794,   746,   300,
    1038,   367,   477,  1086,   862,  1088,  1089,   902,   558,   380,
     815,   795,    41,   404,    42,  1048,   240,   241,  1049,   279,
    1000,   583,   279,  1001,   582,   673,   188,    43,  1050,   188,
     586,   590,   674,   558,   242,   216,   217,  1002,   411,   419,
     444,   521,   377,  1119,   587,  1146,   606,  1150,   737,   536,
     666,   673,   906,   462,   993,   738,   469,   741,   745,   907,
     394,   994,   470,   178,   673,   478,   191,   673,   480,   191,
    1190,  1075,   334,   486,  1079,   554,   960,  1191,   796,   797,
     798,   799,   494,   536,   518,   147,   343,   500,   232,   533,
     413,   534,   540,   542,    44,   546,   553,   349,   148,    45,
     968,   549,    46,    47,   556,   557,   969,   970,   558,   372,
     616,   657,   971,   972,   973,   619,   632,   554,    48,   179,
      49,   634,   635,   660,   664,   445,   668,   675,   684,    50,
     683,   685,    51,   691,   180,   181,   696,   699,    52,   567,
     709,   711,   716,   723,   397,   724,    43,   727,   730,   631,
     788,    53,   182,   183,   184,   686,   521,   735,  1025,   781,
     780,   146,   185,   186,   371,   648,   666,   830,   855,   606,
     859,   654,   558,   536,   875,   233,   877,   648,   882,   402,
     403,   234,   235,   845,   883,   -17,   895,   236,   237,   238,
     536,    54,   558,   884,   856,   899,   901,   916,   930,   179,
     913,   922,   939,   940,   108,   981,   424,   677,   990,   956,
     959,   442,   996,    44,   180,   998,   999,  1004,    45,  1024,
     957,    46,    47,   187,   461,   742,  1011,  1012,   188,  1015,
     189,   190,   182,   183,   558,  1021,  1022,    48,  1026,    49,
    1062,  1046,   185,   186,  1069,  1072,   476,   520,    50,  1076,
     648,    51,  1087,   606,   927,   484,  1080,    52,  1193,  1194,
    1195,  1083,  1197,  1090,  1094,  1104,  1114,  1122,   191,  1109,
      53,   502,    43,  1116,   514,  1127,  1128,   372,  1133,  1153,
     147,   841,  1067,  1158,  1171,  1168,   848,   528,   165,  1187,
     532,   123,    93,   148,    18,   968,    15,   541,  -516,   554,
     405,   969,   970,    36,   -17,   173,   171,   971,   972,   973,
      54,  1030,    67,   341,   682,   571,   864,   927,  1067,   536,
     552,   342,   391,   475,   680,   669,   571,  1039,   412,  1040,
     566,   826,   562,   384,   665,  1017,   651,  1045,   915,    44,
     648,   645,   592,   686,    45,   686,  1020,    46,    47,   536,
     869,    43,   536,   867,  1093,   593,   565,  1174,    43,  1160,
    1179,   702,   703,    48,  1031,    49,  1034,   803,   536,  1132,
     615,   886,   888,  1130,    50,   622,   599,    51,   997,  1175,
     964,   983,   965,    52,  1097,  1103,  1065,   905,   249,   904,
     640,   628,   629,   630,   558,   963,    53,   539,   357,   358,
     360,   359,   361,   362,   366,  1112,  1035,  1077,  1115,   677,
     714,   554,   866,  1198,  -586,   625,   250,   251,    44,   401,
     857,   870,   545,    45,   252,    44,    46,    47,   627,   662,
      45,   663,   961,    46,    47,   919,    54,  1095,  1044,   120,
     253,   254,    48,   316,    49,  1144,     0,     0,     0,    48,
       0,    49,     0,    50,     0,     0,    51,     0,  1155,    43,
      50,     0,    52,    51,     0,     0,     0,   841,     0,    52,
     848,     0,     0,     0,     0,    53,     0,     0,     0,     0,
     694,   695,    53,     0,     0,     0,   648,     0,   255,     0,
     648,     0,     0,     0,  1145,   371,  1183,     0,     0,     0,
       0,    43,     0,     0,     0,   931,   935,     0,   256,     0,
       0,   941,   950,   954,   955,    54,   503,     0,     0,   732,
       0,     0,    54,     0,     0,     0,    44,     0,   504,    43,
       0,    45,   648,     0,    46,    47,     0,   536,     0,   505,
     506,     0,     0,   507,   508,   509,   510,     0,     0,     0,
      48,     0,    49,     0,   779,     0,     0,     0,     0,   472,
       0,    50,     0,     0,    51,     0,   787,     0,    44,   995,
      52,     0,     0,    45,     0,     0,    46,    47,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
     648,     0,    48,   832,    49,   835,    44,   536,     0,     0,
       0,    45,     0,    50,    46,    47,    51,     0,     0,     0,
       0,     0,    52,     0,     0,    43,   860,    10,   931,   861,
      48,     0,    49,    54,   935,    53,     0,     0,     0,     0,
       0,    50,     0,     0,    51,     0,  1041,     0,   950,     0,
      52,     0,     0,     0,     0,   427,   428,   429,   647,   430,
     431,   432,     0,    53,     0,     0,     0,     0,   433,   -17,
      43,   434,   435,   436,     0,    54,   371,   941,     0,     0,
     437,     0,     0,   438,     0,     0,   885,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,    45,     0,     0,
      46,    47,   892,    54,   536,   372,     0,   893,     0,     0,
       0,    43,     0,     0,   900,     0,    48,   903,    49,     0,
       0,     0,     0,   606,     0,     0,     0,    50,     0,     0,
      51,     0,     0,     0,   606,   911,    52,    44,     0,     0,
     914,     0,    45,     0,     0,    46,    47,     0,   920,    53,
       0,   921,    43,   606,   606,   606,  1196,   606,  1137,     0,
       0,    48,   372,    49,   372,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,    51,     0,     0,    44,     0,
      43,    52,     0,    45,  1137,     0,    46,    47,   962,    54,
       0,     0,     0,    43,    53,     0,     0,     0,     0,  1137,
       0,   666,    48,     0,    49,     0,     0,     0,     0,   941,
       0,     0,     0,    50,     0,     0,    51,     0,     0,    44,
       0,     0,    52,     0,    45,     0,     0,    46,    47,     0,
      43,   941,     0,     0,    54,    53,     0,     0,     0,     0,
       0,     0,   784,    48,  1016,    49,  1018,    44,     0,     0,
       0,     0,    45,     0,    50,    46,    47,    51,     0,     0,
      44,     0,     0,    52,     0,    45,     0,     0,    46,    47,
    1027,    48,     0,    49,     0,    54,    53,     0,     0,     0,
       0,     0,    50,     0,    48,    51,    49,     0,     0,     0,
      69,    52,     0,     0,     0,    50,     0,    44,    51,     0,
       0,     0,    45,     0,    52,    46,    47,  -452,     0,   927,
       0,     0,     0,     0,     0,  -452,    54,    53,     0,  -452,
    -452,    48,     0,    49,     0,     0,  -452,  -452,     0,  1136,
    -452,  -452,    50,     0,    70,    51,     0,     0,     0,     0,
       0,    52,   124,     0,    54,     0,     0,     0,     0,     0,
      71,     0,  -452,     0,    53,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,    74,     0,     0,     0,     0,  -452,     0,     0,  -452,
       0,    75,     0,    76,    77,  1126,     0,     0,     0,  -452,
       0,     0,     0,    78,    54,    79,     0,     0,     0,     0,
       0,  -452,     0,     0,     0,     0,     0,     0,  1149,     0,
    1151,  1152,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,  1157,     0,   131,   132,  1159,   133,
     134,     0,     0,  1163,     0,   135,   136,     0,     0,  -452,
       0,   137,   138,   139,   140,     0,   141,  1176,  1177,     0,
    1178,     0,     0,   142,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,   749,   750,   751,     0,  1192,
       0,   752,   753,   754,   755,   756,   757,   758,     0,   759,
     760,     0,  1199,   761,   762,   763,   764,   765,   766,   767,
       0,   768,   769,     0,   770,   771,   772,     0,     0,     0,
       0,     0,   773,   774,   775
};

static const yytype_int16 yycheck[] =
{
       1,   487,   103,   418,   512,   122,   474,   390,   122,   570,
     646,   546,   486,   317,   122,   122,   346,   400,   549,    29,
     255,   404,   169,   406,   670,    24,   475,   174,   122,   333,
     174,   475,    14,   880,    35,    83,    14,   452,    39,    14,
       7,    15,    59,    14,    74,    12,    20,   872,   169,    14,
      80,   168,   169,    16,   168,   172,    57,   174,   172,    47,
      61,   168,   297,    14,   172,   172,     0,   978,    11,  1071,
      13,    83,    15,   224,   175,   123,   719,   194,   172,    11,
     194,    82,   613,   387,   619,   389,   194,   194,    89,   148,
      19,    20,    21,    22,    23,    24,    24,    71,    41,    12,
     194,    29,   633,   482,   123,  1107,   931,    14,    96,   170,
     169,    16,    86,  1024,    14,    12,    14,    14,   116,    90,
      11,    14,    13,   224,    15,    90,   456,   542,    71,   578,
     104,   105,   106,    14,   578,   282,    14,    14,    12,   169,
     114,   115,    12,    86,   559,   475,   120,   110,    12,   148,
     228,   530,   169,   270,    86,    87,   270,    14,    14,   169,
     142,   104,   105,   270,   131,   282,   313,   142,   814,   313,
     102,   114,   115,   151,   709,   176,   151,   144,   179,   180,
      71,   113,   183,   184,   185,   186,    12,   188,   189,   306,
    1037,   142,   306,    12,   668,    86,   313,   298,   306,   306,
     843,   168,   845,   354,   109,   110,   849,   675,   694,   490,
     170,    50,   306,   104,   105,   131,    62,   146,   131,    53,
     148,   148,  1069,   114,   115,   142,   136,   462,   144,   346,
     173,   144,   346,   162,   131,   142,   149,   180,   473,   346,
     183,   169,   142,   175,   142,   168,   220,   144,   578,   142,
      89,   180,   181,   354,   151,   119,   142,   131,   187,   122,
     170,   131,   191,   149,   142,   142,   267,   131,   142,   777,
     144,   575,   142,   688,   144,   149,   277,   220,   279,   149,
     144,   562,   173,   151,   144,   142,   142,   162,   127,   180,
     124,   107,   183,    20,   177,   178,   179,    11,   299,    13,
      11,   122,    13,   718,   835,   131,   780,   122,   142,   169,
     130,   122,   131,   133,   822,   150,   699,    63,   144,    20,
     321,   150,   737,   142,   859,   144,    72,   147,   632,   220,
     149,   194,    43,    52,   169,   570,   265,   220,   129,   456,
     723,   142,   456,   132,    71,   134,    12,   276,    94,   456,
     170,   142,   147,    19,    38,    21,   660,    71,   475,    86,
      71,   475,   142,   364,  1168,   111,   901,   475,   475,   116,
      71,   300,    86,   194,   169,    86,   123,   163,    62,   194,
      64,   475,    66,   194,   164,    86,  1190,   114,   115,   145,
     104,   105,   148,   104,   105,   176,   177,   178,   179,   500,
     114,   115,    63,   114,   115,   129,    12,   711,   337,   121,
      94,    72,   716,   114,   115,   113,    82,   145,   419,   120,
     148,   105,   423,   107,   959,    95,   110,    93,  1064,   990,
     142,    61,   116,    94,   118,   670,   142,   103,   673,   220,
    1001,    52,   371,  1047,   748,  1049,  1050,   830,   449,   109,
     111,   117,    16,    34,    18,    85,   143,   144,    88,   173,
     145,   578,   173,   148,   578,   142,   180,    11,    98,   180,
     578,   578,   149,   474,   161,   143,   144,   162,    90,   142,
      26,   410,   483,  1087,   578,  1121,   487,  1123,   142,   418,
     142,   142,   142,   148,   142,   149,   149,   149,   149,   149,
     501,   149,   149,    15,   142,   142,   220,   142,   172,   220,
     142,   149,   441,    39,   149,   444,   899,   149,   184,   185,
     186,   187,    90,   452,   142,   131,   210,   154,    59,   153,
     531,    53,   153,   148,    78,    53,    90,   221,   144,    83,
     146,   148,    86,    87,   170,   142,   152,   153,   549,   478,
      73,   966,   158,   159,   160,    53,   129,   486,   102,    71,
     104,   148,    65,   121,    81,    59,    35,   142,    96,   113,
     149,    47,   116,   162,    86,    87,   154,    28,   122,   814,
      53,   129,   121,    32,   513,    22,    11,    79,     4,   518,
     691,   135,   104,   105,   106,   596,   525,   153,   981,     8,
      36,    12,   114,   115,   148,   534,   142,   174,   121,   610,
     121,   540,   613,   542,   148,   146,   148,   546,   148,   303,
     304,   152,   153,   724,   148,   169,   181,   158,   159,   160,
     559,   175,   633,   148,   735,    27,   121,    18,   873,    71,
     154,   162,   877,   142,   328,    42,   330,   576,   148,   884,
     121,   335,   142,    78,    86,   142,   142,   148,    83,   154,
     895,    86,    87,   175,   348,   666,   149,   142,   180,   149,
     182,   183,   104,   105,   675,   128,   142,   102,   128,   104,
     128,   149,   114,   115,   148,   124,   370,   112,   113,   149,
     619,   116,    61,   694,   168,   379,   142,   122,  1184,  1185,
    1186,   142,  1188,    40,   128,    29,   149,  1090,   220,     5,
     135,   395,    11,    75,   398,   149,   154,   646,    23,   154,
     131,   722,  1026,   142,    88,   148,   727,   411,   412,    85,
     414,    96,    53,   144,     4,   146,     3,   421,   149,   668,
     306,   152,   153,     8,   169,   112,   109,   158,   159,   160,
     175,   986,    26,   193,   578,   990,   778,   168,  1062,   688,
     441,   194,   282,   368,   577,   565,  1001,  1002,   320,  1004,
     456,   710,   455,   270,   557,   959,   535,  1012,   855,    78,
     709,   531,   478,   784,    83,   786,   966,    86,    87,   718,
     786,    11,   721,   784,  1052,   479,   455,  1158,    11,  1143,
    1165,   610,   610,   102,   987,   104,   993,   697,   737,  1110,
     494,   812,   813,  1107,   113,   499,   483,   116,   940,  1159,
     908,   922,   911,   122,  1063,  1069,  1022,   836,    48,   835,
     525,   515,   516,   517,   835,   906,   135,   419,   227,   230,
     239,   231,   243,   248,   258,  1080,   995,  1036,  1083,   778,
     620,   780,   781,  1190,   153,   501,    76,    77,    78,   301,
     736,   790,   423,    83,    84,    78,    86,    87,   513,   553,
      83,   555,   901,    86,    87,   859,   175,  1062,  1007,    91,
     100,   101,   102,   176,   104,  1120,    -1,    -1,    -1,   102,
      -1,   104,    -1,   113,    -1,    -1,   116,    -1,  1133,    11,
     113,    -1,   122,   116,    -1,    -1,    -1,   908,    -1,   122,
     911,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
     604,   605,   135,    -1,    -1,    -1,   855,    -1,   148,    -1,
     859,    -1,    -1,    -1,   147,   148,  1171,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,   874,   875,    -1,   168,    -1,
      -1,   880,   881,   882,   883,   175,   194,    -1,    -1,   643,
      -1,    -1,   175,    -1,    -1,    -1,    78,    -1,   206,    11,
      -1,    83,   901,    -1,    86,    87,    -1,   906,    -1,   217,
     218,    -1,    -1,   221,   222,   223,   224,    -1,    -1,    -1,
     102,    -1,   104,    -1,   678,    -1,    -1,    -1,    -1,  1000,
      -1,   113,    -1,    -1,   116,    -1,   690,    -1,    78,   938,
     122,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
     959,    -1,   102,   717,   104,   719,    78,   966,    -1,    -1,
      -1,    83,    -1,   113,    86,    87,   116,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    11,   740,   169,   987,   743,
     102,    -1,   104,   175,   993,   135,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,   116,    -1,  1005,    -1,  1007,    -1,
     122,    -1,    -1,    -1,    -1,   188,   189,   190,    44,   192,
     193,   194,    -1,   135,    -1,    -1,    -1,    -1,   201,   169,
      11,   204,   205,   206,    -1,   175,   148,  1036,    -1,    -1,
     213,    -1,    -1,   216,    -1,    -1,   800,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      86,    87,   816,   175,  1063,  1064,    -1,   821,    -1,    -1,
      -1,    11,    -1,    -1,   828,    -1,   102,   831,   104,    -1,
      -1,    -1,    -1,  1154,    -1,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,  1165,   849,   122,    78,    -1,    -1,
     854,    -1,    83,    -1,    -1,    86,    87,    -1,   862,   135,
      -1,   865,    11,  1184,  1185,  1186,  1187,  1188,  1117,    -1,
      -1,   102,  1121,   104,  1123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    78,    -1,
      11,   122,    -1,    83,  1143,    -1,    86,    87,   902,   175,
      -1,    -1,    -1,    11,   135,    -1,    -1,    -1,    -1,  1158,
      -1,   142,   102,    -1,   104,    -1,    -1,    -1,    -1,  1168,
      -1,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    78,
      -1,    -1,   122,    -1,    83,    -1,    -1,    86,    87,    -1,
      11,  1190,    -1,    -1,   175,   135,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   102,   958,   104,   960,    78,    -1,    -1,
      -1,    -1,    83,    -1,   113,    86,    87,   116,    -1,    -1,
      78,    -1,    -1,   122,    -1,    83,    -1,    -1,    86,    87,
     984,   102,    -1,   104,    -1,   175,   135,    -1,    -1,    -1,
      -1,    -1,   113,    -1,   102,   116,   104,    -1,    -1,    -1,
      11,   122,    -1,    -1,    -1,   113,    -1,    78,   116,    -1,
      -1,    -1,    83,    -1,   122,    86,    87,    16,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    24,   175,   135,    -1,    28,
      29,   102,    -1,   104,    -1,    -1,    35,    36,    -1,   147,
      39,    40,   113,    -1,    55,   116,    -1,    -1,    -1,    -1,
      -1,   122,    59,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    61,    -1,   135,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,   102,    -1,   104,   105,  1099,    -1,    -1,    -1,    98,
      -1,    -1,    -1,   114,   175,   116,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,  1122,    -1,
    1124,  1125,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,  1138,    -1,   143,   144,  1142,   146,
     147,    -1,    -1,  1147,    -1,   152,   153,    -1,    -1,   148,
      -1,   158,   159,   160,   161,    -1,   163,  1161,  1162,    -1,
    1164,    -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,   188,   189,   190,    -1,  1183,
      -1,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,    -1,  1196,   206,   207,   208,   209,   210,   211,   212,
      -1,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   123,   251,   256,   257,   258,   259,   260,   261,   265,
     169,   231,     0,   252,   253,   260,   274,   276,   258,    11,
      86,    87,   102,   113,   175,   254,   255,   273,   275,   284,
     294,   302,   341,   346,   653,    83,   265,   170,   266,   116,
     277,   254,   254,    11,    78,    83,    86,    87,   102,   104,
     113,   116,   122,   135,   175,   236,   239,   240,   241,   242,
     243,   245,   236,   236,   236,   236,   236,   273,   231,    11,
      55,    71,    86,    87,    92,   102,   104,   105,   114,   116,
     267,   268,   269,   270,    14,   247,   249,   250,   231,   228,
     708,   709,   710,   243,   295,   231,   170,   150,   231,   244,
     570,   571,   247,   148,   329,   330,   247,   285,   247,    62,
     271,   272,   142,   231,   168,   151,   278,   231,   711,   712,
     710,   136,   247,   242,    59,   129,   130,   131,   132,   133,
     134,   143,   144,   146,   147,   152,   153,   158,   159,   160,
     161,   163,   170,   572,   573,   347,    12,   131,   144,   335,
     336,   486,   532,   606,   607,   609,   610,   612,   613,   615,
     617,   619,   620,   621,   645,   247,   107,   316,   319,   247,
     654,   267,   247,   268,   247,   162,   142,   247,    15,    71,
      86,    87,   104,   105,   106,   114,   115,   175,   180,   182,
     183,   220,   288,   296,   297,   298,   299,   300,   302,   315,
     346,   377,   389,   393,   401,   549,   576,   600,   601,   628,
     629,   648,   652,   653,   674,   685,   571,   571,    52,   348,
     349,   355,   236,   487,   142,   331,   332,   163,   132,   134,
     611,   129,    59,   146,   152,   153,   158,   159,   160,   614,
     143,   144,   161,   616,   130,   133,   147,   170,   618,    48,
      76,    77,    84,   100,   101,   148,   168,   236,   622,   623,
     626,   642,   643,   644,   303,   317,    20,   120,   315,   342,
     343,   344,   346,   409,   518,   628,    11,    13,    15,   173,
     183,   280,   286,   287,   288,   293,   294,   315,   346,   366,
     386,   393,   401,   628,   648,   666,   682,   177,   178,   179,
     220,   655,   656,   657,   658,   262,   263,   264,   315,   346,
     393,   401,   628,   279,   280,   606,   712,   390,   231,   231,
     236,   394,   231,   231,   231,   602,   605,   231,   236,   231,
     649,   650,   231,   686,   236,   289,   290,   113,   281,   282,
     283,   284,   298,   247,   356,    95,   350,   351,   362,   247,
     488,   337,   338,   532,   142,   333,   334,   610,   612,   613,
     615,   617,   619,   607,   145,   148,   627,    52,   304,   305,
     325,   148,   236,   405,   406,   407,   410,   231,   519,   523,
     109,   320,   345,   423,   344,   236,   231,   387,   231,   683,
      41,   287,   607,   606,   231,   659,   660,   236,   662,   663,
     176,   656,   247,   247,    34,   264,    43,   280,   236,   238,
     550,    90,   330,   231,   395,   396,   402,   378,   603,   142,
     577,    90,   651,   142,   247,   675,   238,   188,   189,   190,
     192,   193,   194,   201,   204,   205,   206,   213,   216,   291,
     292,   142,   247,   236,    26,    59,   357,   358,   359,   360,
     361,   231,   232,   315,   346,   352,   353,   354,   363,   409,
     628,   247,   148,   484,   485,   631,   339,   340,   532,   149,
     149,   148,   231,   624,   326,   319,   247,   236,   142,   318,
     172,   411,   520,   142,   247,   424,    39,    16,   110,   322,
     323,   324,   425,   456,    90,   367,   238,   667,   238,   232,
     154,   142,   247,   194,   206,   217,   218,   221,   222,   223,
     224,   664,   665,   142,   247,   232,   232,   232,   142,   391,
     112,   236,   568,   569,   588,   594,   595,   596,   247,    90,
     397,   142,   247,   153,    53,   379,   236,   566,   567,   602,
     153,   247,   148,   398,   399,   650,    53,   676,   687,   148,
     234,   235,   290,    90,   236,   237,   170,   142,   231,   233,
     328,   566,   323,   364,   365,   423,   354,   607,   608,   632,
     625,   607,   630,   327,   328,    15,   220,   306,   307,   308,
     309,   310,   315,   346,   377,   392,   393,   401,   409,   518,
     628,   408,   407,   247,    47,    96,   412,   413,   399,   519,
      50,    89,   127,   646,   647,   237,   231,   454,   455,   459,
     461,   462,   465,   426,   324,   247,    73,   368,   388,    53,
     668,   684,   247,   606,   661,   660,   235,   663,   247,   247,
     247,   236,   129,   589,   148,    65,   551,   552,   553,   555,
     595,   247,   248,   301,   399,   396,   403,    44,   236,   376,
     385,   379,   384,   604,   236,   581,   400,   566,   376,   680,
     121,   233,   247,   247,    81,   359,   142,   566,    35,   322,
     142,   149,   630,   142,   149,   142,   238,   236,   311,   312,
     320,   321,   308,   149,    96,    47,   231,   414,   416,   417,
     420,   162,   521,   522,   247,   247,   154,   463,   466,    28,
     457,   458,   462,   465,   467,   147,   233,   434,   533,    53,
     369,   129,   376,   673,   668,   672,   121,   238,   233,   591,
     592,   597,   554,    32,    22,   640,   641,    79,   558,   560,
       4,   590,   247,   405,   380,   153,   578,   142,   149,   677,
     238,   149,   231,   237,   608,   149,   607,   328,   129,   188,
     189,   190,   194,   195,   196,   197,   198,   199,   200,   202,
     203,   206,   207,   208,   209,   210,   211,   212,   214,   215,
     217,   218,   219,   225,   226,   227,   313,   314,   142,   247,
      36,     8,   421,   422,   142,   566,   142,   247,   606,   459,
      19,    21,    82,    93,   103,   117,   184,   185,   186,   187,
     464,   474,   481,   486,   489,   505,   524,   528,   690,   701,
     702,   707,    63,    72,    94,   111,   468,   469,   471,   472,
     473,   232,   534,   427,   375,   376,   369,   374,   238,   669,
     174,   238,   247,   566,   593,   247,   248,   565,   566,   598,
     599,   231,   556,   557,   232,   606,    74,    80,   231,   559,
     561,   563,   574,   575,   404,   121,   606,   641,   566,   121,
     247,   247,   238,   235,   312,   237,   236,   417,   415,   414,
     236,   482,   483,   506,   490,   148,   525,   148,   529,   531,
     475,   691,   148,   148,   148,   247,   231,   144,   231,   470,
     537,   608,   247,   247,   235,   181,   688,   689,   370,    27,
     247,   121,   232,   247,   592,   590,   142,   149,   142,   248,
     248,   247,   248,   154,   247,   385,    18,   579,   580,   680,
     247,   247,   162,   418,   419,   485,     7,   168,   246,   517,
     607,   236,   491,   494,   495,   236,   526,   527,   530,   607,
     142,   236,   246,   476,   477,   479,   635,   636,   638,   639,
     236,   692,   695,   696,   236,   236,   607,   607,   428,   121,
     232,   673,   247,   599,   556,   561,   562,   381,   146,   152,
     153,   158,   159,   160,   582,   583,   584,   585,   586,   587,
     606,    42,   678,   606,   507,   485,   121,   142,   496,   497,
     148,   633,   634,   142,   149,   236,   142,   529,   142,   142,
     145,   148,   162,   627,   148,    53,   124,   142,   693,   694,
     700,   149,   142,   703,   704,   149,   247,   375,   247,   670,
     400,   128,   142,   587,   154,   232,   128,   247,   119,   503,
     607,   495,   492,   630,   526,   633,   478,   480,   630,   607,
     607,   236,   238,   504,   696,   607,   149,    61,    85,    88,
      98,   429,   430,   431,   435,   436,   446,   447,   450,   538,
     542,   371,   128,   164,   382,   583,   587,   238,   681,   148,
     508,   509,   124,   498,   499,   149,   149,   635,   246,   149,
     142,   697,   698,   142,   705,   706,   647,    61,   647,   647,
      40,   432,   433,   431,   128,   681,   564,   565,   405,   679,
     246,   512,   513,   582,    29,    24,   509,   511,   514,     5,
     500,   493,   607,   699,   149,   607,    75,   437,   453,   647,
     543,   448,   232,   372,   671,   383,   247,   149,   154,   509,
     514,   516,   504,    23,   501,   502,   147,   236,   439,   440,
     445,   535,   451,   539,   607,   147,   405,   449,   536,   247,
     405,   247,   247,   154,   515,   607,   441,   247,   142,   247,
     445,   541,   544,   247,   373,   510,   459,   460,   148,   442,
     443,    88,   547,   548,   440,   548,   247,   247,   247,   460,
     444,   636,   637,   607,   438,   452,   540,    85,   545,   546,
     142,   149,   247,   459,   459,   459,   231,   459,   637,   247
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   230,   231,   232,   232,   233,   233,   234,   235,   235,
     236,   237,   237,   238,   238,   239,   239,   240,   240,   241,
     242,   243,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   246,   247,   248,   248,
     249,   249,   250,   251,   252,   252,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   259,   260,   260,   261,
     261,   262,   262,   263,   263,   264,   264,   264,   264,   264,
     265,   266,   266,   267,   267,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   271,
     271,   272,   273,   274,   275,   275,   275,   275,   275,   275,
     276,   278,   277,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   281,   281,   282,   282,
     283,   285,   284,   286,   286,   287,   287,   287,   288,   289,
     289,   290,   290,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   292,   292,   292,   293,   295,   294,   296,   296,
     297,   297,   298,   298,   298,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   301,   300,
     303,   302,   304,   304,   305,   306,   306,   307,   307,   308,
     308,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     310,   311,   311,   312,   312,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   315,   317,   318,   316,   319,   319,   320,   321,
     321,   322,   322,   323,   323,   324,   324,   326,   325,   327,
     327,   328,   329,   330,   330,   331,   331,   332,   333,   333,
     334,   335,   336,   336,   337,   338,   338,   339,   340,   340,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   344,
     345,   347,   346,   348,   348,   349,   350,   350,   351,   352,
     352,   353,   353,   354,   356,   355,   357,   357,   358,   358,
     359,   360,   360,   361,   361,   362,   363,   363,   363,   363,
     364,   364,   365,   365,   367,   366,   368,   368,   370,   371,
     372,   373,   369,   374,   374,   375,   376,   376,   378,   377,
     380,   381,   382,   383,   379,   384,   384,   385,   387,   388,
     386,   390,   391,   389,   392,   394,   393,   395,   395,   397,
     396,   398,   399,   399,   400,   400,   402,   403,   404,   401,
     405,   405,   406,   406,   407,   408,   407,   410,   409,   411,
     411,   412,   412,   413,   413,   413,   413,   415,   414,   416,
     416,   417,   418,   418,   419,   420,   420,   421,   422,   422,
     424,   423,   426,   427,   428,   425,   429,   429,   430,   430,
     431,   431,   431,   431,   431,   432,   432,   433,   434,   434,
     435,   437,   438,   436,   439,   439,   441,   440,   442,   442,
     443,   444,   444,   445,   445,   446,   448,   447,   449,   449,
     451,   452,   450,   453,   454,   455,   455,   456,   457,   457,
     458,   459,   459,   460,   460,   461,   461,   463,   462,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     466,   465,   467,   467,   468,   468,   468,   468,   469,   470,
     470,   471,   472,   473,   475,   474,   476,   476,   478,   477,
     477,   480,   479,   479,   481,   482,   483,   484,   485,   485,
     486,   488,   487,   490,   489,   492,   493,   491,   494,   494,
     495,   496,   496,   497,   498,   498,   499,   500,   500,   501,
     501,   502,   503,   503,   504,   506,   507,   505,   508,   508,
     510,   509,   511,   511,   512,   512,   513,   513,   515,   514,
     516,   516,   517,   517,   517,   518,   520,   519,   521,   521,
     522,   523,   523,   524,   525,   526,   527,   527,   528,   529,
     530,   531,   531,   532,   534,   533,   535,   536,   537,   539,
     540,   538,   541,   543,   544,   542,   545,   545,   546,   547,
     548,   548,   550,   549,   551,   552,   554,   553,   555,   555,
     556,   557,   557,   558,   559,   559,   560,   560,   562,   561,
     561,   561,   563,   564,   565,   566,   567,   567,   568,   568,
     569,   569,   570,   570,   571,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   573,   574,   575,   577,   578,   576,   579,
     580,   580,   581,   582,   582,   583,   583,   584,   585,   585,
     586,   586,   586,   586,   586,   586,   587,   589,   588,   590,
     590,   591,   591,   592,   593,   594,   594,   595,   597,   596,
     598,   598,   599,   600,   601,   603,   604,   602,   605,   605,
     606,   607,   607,   608,   608,   609,   609,   610,   610,   611,
     611,   612,   612,   613,   613,   614,   614,   614,   614,   614,
     614,   614,   615,   615,   616,   616,   616,   617,   617,   618,
     618,   618,   618,   619,   620,   620,   621,   621,   622,   622,
     622,   622,   622,   622,   624,   623,   625,   623,   626,   627,
     628,   629,   629,   629,   630,   630,   631,   632,   632,   633,
     633,   634,   635,   636,   636,   636,   637,   637,   638,   639,
     640,   641,   641,   642,   642,   642,   643,   644,   644,   644,
     644,   645,   646,   646,   646,   647,   647,   648,   649,   649,
     651,   650,   652,   654,   653,   655,   655,   656,   656,   656,
     656,   657,   658,   659,   659,   660,   661,   662,   662,   663,
     663,   664,   664,   664,   664,   665,   665,   665,   665,   667,
     666,   669,   670,   671,   668,   672,   672,   673,   675,   674,
     677,   678,   679,   676,   680,   681,   683,   684,   682,   686,
     687,   685,   688,   688,   689,   691,   690,   692,   693,   693,
     693,   694,   695,   695,   696,   697,   697,   698,   699,   700,
     701,   702,   703,   703,   704,   705,   705,   706,   707,   708,
     708,   709,   709,   710,   711,   711,   712
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     3,     1,     3,     0,     1,
       2,     0,     1,     3,     1,     1,     1,     0,     1,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       0,     1,     2,     2,     0,     1,     3,     0,     1,     1,
       2,     0,     1,     2,     3,     1,     9,     0,     1,     2,
       1,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       4,     0,     2,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     8,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       4,     0,     8,     2,     1,     1,     1,     1,     3,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     9,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       0,    12,     0,     1,     2,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     0,     5,     0,     1,     2,     0,
       1,     0,     1,     2,     1,     1,     1,     0,     3,     3,
       1,     2,     5,     0,     1,     0,     1,     2,     0,     1,
       2,     1,     0,     1,     1,     0,     1,     1,     0,     1,
       9,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     0,    11,     0,     1,     2,     0,     1,     2,     0,
       1,     2,     1,     1,     0,     3,     0,     1,     3,     1,
       2,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     0,     1,     0,     9,     0,     1,     0,     0,
       0,     0,    11,     0,     1,     1,     1,     1,     0,     5,
       0,     0,     0,     0,    11,     0,     1,     1,     0,     0,
       7,     0,     0,     7,     5,     0,     4,     3,     1,     0,
       3,     3,     0,     1,     3,     1,     0,     0,     0,     8,
       1,     3,     0,     1,     1,     0,     4,     0,     6,     0,
       1,     0,     1,     1,     1,     2,     2,     0,     4,     3,
       1,     2,     0,     1,     2,     3,     1,     2,     0,     1,
       0,     5,     0,     0,     0,     9,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     1,     1,
       1,     0,     0,     8,     1,     1,     0,     3,     0,     1,
       3,     3,     1,     3,     1,     1,     0,     5,     1,     1,
       0,     0,     8,     1,     2,     0,     1,     3,     0,     1,
       3,     2,     1,     0,     1,     2,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     0,     3,     1,     1,     0,     4,
       1,     0,     4,     1,     2,     2,     1,     1,     0,     1,
       2,     0,     3,     0,     3,     0,     0,     6,     3,     1,
       2,     0,     1,     2,     0,     1,     3,     0,     1,     0,
       1,     2,     1,     1,     1,     0,     0,     7,     2,     3,
       0,     6,     2,     1,     1,     1,     0,     1,     0,     4,
       0,     1,     1,     1,     1,     3,     0,     4,     0,     1,
       2,     3,     1,     2,     3,     2,     3,     1,     2,     5,
       2,     3,     1,     1,     0,     3,     1,     1,     1,     0,
       0,     8,     1,     0,     0,     8,     0,     1,     3,     3,
       0,     1,     0,     7,     2,     2,     0,     4,     0,     1,
       1,     3,     1,     3,     3,     1,     0,     1,     0,     6,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       0,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,    10,     2,
       0,     1,     1,     3,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     0,
       1,     3,     1,     2,     1,     2,     1,     3,     0,     5,
       3,     1,     1,     1,     2,     0,     0,     6,     3,     1,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     0,     5,     0,     6,     2,     2,
       2,     1,     1,     1,     3,     1,     3,     3,     1,     0,
       1,     3,     3,     1,     1,     1,     0,     1,     4,     2,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     3,     1,
       0,     3,     4,     0,     8,     2,     1,     2,     2,     3,
       3,     2,     2,     3,     1,     3,     1,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       8,     0,     0,     0,    10,     0,     1,     1,     0,     4,
       0,     0,     0,    10,     1,     1,     0,     0,     7,     0,
       0,     7,     0,     1,     2,     0,     3,     2,     0,     1,
       1,     2,     3,     1,     5,     0,     1,     2,     1,     2,
       4,     5,     0,     1,     3,     0,     1,     2,     4,     0,
       1,     2,     1,     3,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 764 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 2761 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 767 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2767 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 768 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 2773 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 773 "QSDL92.y" /* yacc.c:1646  */
    {comma_name_list_1((yyvsp[0].symval));}
#line 2779 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 774 "QSDL92.y" /* yacc.c:1646  */
    {comma_name_list_1((yyvsp[0].symval));}
#line 2785 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 782 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2791 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 788 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 2797 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 791 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2803 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 792 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 2809 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 797 "QSDL92.y" /* yacc.c:1646  */
    {comma_ident_list_1((yyvsp[0].symval));}
#line 2815 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 798 "QSDL92.y" /* yacc.c:1646  */
    {comma_ident_list_1((yyvsp[0].symval));}
#line 2821 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 806 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; opt_qualifier_1(); }
#line 2827 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 825 "QSDL92.y" /* yacc.c:1646  */
    { name_or_quoted_operator_1((yyvsp[0].symval)); }
#line 2833 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 831 "QSDL92.y" /* yacc.c:1646  */
    {scope_unit_kind_1( DS_SYSTEM ); }
#line 2839 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 832 "QSDL92.y" /* yacc.c:1646  */
    {scope_unit_kind_1( DS_BLOCK ); }
#line 2845 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 834 "QSDL92.y" /* yacc.c:1646  */
    {scope_unit_kind_1( DS_PROCESS ); }
#line 2851 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 840 "QSDL92.y" /* yacc.c:1646  */
    {scope_unit_kind_1( DS_MACHINE ); }
#line 2857 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 851 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2863 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 856 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2869 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 867 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2875 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 876 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2881 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 885 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2887 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 911 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2893 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 920 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2899 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 956 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2905 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 971 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2911 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 989 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2917 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1027 "QSDL92.y" /* yacc.c:1646  */
    {text_sys_def_body_1((yyvsp[0].symval));}
#line 2923 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1032 "QSDL92.y" /* yacc.c:1646  */
    {text_sys_def_body_2((yyvsp[-1].symval));}
#line 2929 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1071 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 2935 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1082 "QSDL92.y" /* yacc.c:1646  */
    {block_substructure_reference_1((yyvsp[-2].symval));}
#line 2941 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1086 "QSDL92.y" /* yacc.c:1646  */
    {block_substructure_definition_1((yyvsp[0].symval));}
#line 2947 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1091 "QSDL92.y" /* yacc.c:1646  */
    {block_substructure_definition_2((yyvsp[-1].symval));}
#line 2953 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1117 "QSDL92.y" /* yacc.c:1646  */
    { sys_sensor_definition_1 ((yyvsp[-1].symval), (yyvsp[0].oprtr)); }
#line 2959 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1120 "QSDL92.y" /* yacc.c:1646  */
    { sys_sensor_definition_2 ((yyvsp[-2].symval), (yyvsp[-1].oprtr)); }
#line 2965 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1123 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_COUNTER; }
#line 2971 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1124 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_FREQUENCY; }
#line 2977 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1125 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_TALLY; }
#line 2983 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1126 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_FREQ_SIGNAL; }
#line 2989 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1127 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_FREQ_REQUEST; }
#line 2995 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1128 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_FREQ_PROCESS_CREATE; }
#line 3001 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1129 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_FREQ_PROCESS_STOP; }
#line 3007 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1132 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_LIFETIME_PROCESS; }
#line 3013 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1133 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_COUNT_PROCESS_CREATE; }
#line 3019 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1134 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_COUNT_PROCESS_STOP; }
#line 3025 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1135 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_COUNT_SIGNAL; }
#line 3031 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1136 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_SYS_COUNT_REQUEST; }
#line 3037 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1144 "QSDL92.y" /* yacc.c:1646  */
    {block_reference_1((yyvsp[-2].symval));}
#line 3043 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1149 "QSDL92.y" /* yacc.c:1646  */
    {block_definition_1((yyvsp[0].symval));}
#line 3049 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1155 "QSDL92.y" /* yacc.c:1646  */
    {block_definition_2((yyvsp[-1].symval));}
#line 3055 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1158 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3061 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1204 "QSDL92.y" /* yacc.c:1646  */
    {process_reference_1((yyvsp[-2].symval));}
#line 3067 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1212 "QSDL92.y" /* yacc.c:1646  */
    {process_definition_1((yyvsp[-2].symval));}
#line 3073 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1219 "QSDL92.y" /* yacc.c:1646  */
    {process_definition_2((yyvsp[-1].symval));}
#line 3079 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1222 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3085 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1229 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3091 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1279 "QSDL92.y" /* yacc.c:1646  */
    { pcs_sensor_definition_1 ((yyvsp[-1].symval), (yyvsp[0].oprtr)); }
#line 3097 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1282 "QSDL92.y" /* yacc.c:1646  */
    { pcs_sensor_definition_2 ((yyvsp[-2].symval), (yyvsp[-1].oprtr)); }
#line 3103 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1285 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_COUNTER; }
#line 3109 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1286 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_FREQUENCY; }
#line 3115 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1287 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_TALLY; }
#line 3121 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1288 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_RECEIVE; }
#line 3127 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1289 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_SEND; }
#line 3133 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1290 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_DROP; }
#line 3139 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1291 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_CONSUME; }
#line 3145 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1292 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_SAVE; }
#line 3151 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1293 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_SIGNAL_LOSE; }
#line 3157 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1294 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_REQUEST; }
#line 3163 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1295 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_STATE; }
#line 3169 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1296 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_QUEUE_LENGTH; }
#line 3175 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1297 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_QUEUE_CONTENT; }
#line 3181 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1300 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_RECEIVE; }
#line 3187 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1301 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_SEND; }
#line 3193 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1302 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_DROP; }
#line 3199 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1303 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_CONSUME; }
#line 3205 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1304 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_SAVE; }
#line 3211 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1305 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_SIGNAL_LOSE; }
#line 3217 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1306 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_REQUEST; }
#line 3223 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1307 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_STATE; }
#line 3229 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1308 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_WAITTIME_SIGNAL; }
#line 3235 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1309 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_WAITTIME_STATE; }
#line 3241 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1310 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_RESPONSETIME_REQUEST; }
#line 3247 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1311 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_TRANSMISSIONTIME_SIGNAL; }
#line 3253 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1312 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_FREQ_TRANSITION; }
#line 3259 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1313 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_PCS_COUNT_TRANSITION; }
#line 3265 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1321 "QSDL92.y" /* yacc.c:1646  */
    {procedure_reference_1((yyvsp[-2].symval));}
#line 3271 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1326 "QSDL92.y" /* yacc.c:1646  */
    {valid_input_signal_set_1();}
#line 3277 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1327 "QSDL92.y" /* yacc.c:1646  */
    {valid_input_signal_set_2();}
#line 3283 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1331 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3289 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1340 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3295 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1344 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3301 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1358 "QSDL92.y" /* yacc.c:1646  */
    {formal_parameters_1();}
#line 3307 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1359 "QSDL92.y" /* yacc.c:1646  */
    {formal_parameters_2();}
#line 3313 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1364 "QSDL92.y" /* yacc.c:1646  */
    {comma_parameters_of_sort_list_1((yyvsp[0].symval));}
#line 3319 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1365 "QSDL92.y" /* yacc.c:1646  */
    {comma_parameters_of_sort_list_1((yyvsp[0].symval));}
#line 3325 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1369 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 3331 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1380 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3337 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1384 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3343 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1392 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3349 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1404 "QSDL92.y" /* yacc.c:1646  */
    {opt_expression_1();}
#line 3355 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1412 "QSDL92.y" /* yacc.c:1646  */
    {opt_expression_1();}
#line 3361 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1420 "QSDL92.y" /* yacc.c:1646  */
    {opt_expression_1();}
#line 3367 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1432 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3373 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1463 "QSDL92.y" /* yacc.c:1646  */
    {procedure_definition_1((yyvsp[-1].symval));}
#line 3379 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1470 "QSDL92.y" /* yacc.c:1646  */
    {procedure_definition_2((yyvsp[-1].symval));}
#line 3385 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1473 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3391 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1480 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3397 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1487 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3403 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1503 "QSDL92.y" /* yacc.c:1646  */
    {procedure_formal_parameters_1();}
#line 3409 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1504 "QSDL92.y" /* yacc.c:1646  */
    {procedure_formal_parameters_2();}
#line 3415 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1507 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3421 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1518 "QSDL92.y" /* yacc.c:1646  */
    {formal_variable_parameters_1((yyvsp[-1].symval), (yyvsp[0].symval));}
#line 3427 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1522 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = "IN"; }
#line 3433 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1523 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 3439 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1526 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = "IN/OUT";}
#line 3445 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1527 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = "IN";}
#line 3451 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1533 "QSDL92.y" /* yacc.c:1646  */
    {procedure_result_1((yyvsp[-1].symval), (yyvsp[0].symval));}
#line 3457 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1548 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3463 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1554 "QSDL92.y" /* yacc.c:1646  */
    {channel_definition_1((yyvsp[0].symval));}
#line 3469 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1561 "QSDL92.y" /* yacc.c:1646  */
    {channel_definition_2((yyvsp[-1].symval));}
#line 3475 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1564 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3481 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1565 "QSDL92.y" /* yacc.c:1646  */
    {opt_nodelay_1();}
#line 3487 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1570 "QSDL92.y" /* yacc.c:1646  */
    {channel_path_1((yyvsp[0].symval));}
#line 3493 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1572 "QSDL92.y" /* yacc.c:1646  */
    {channel_path_2((yyvsp[0].symval));}
#line 3499 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1573 "QSDL92.y" /* yacc.c:1646  */
    {channel_path_3();}
#line 3505 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1574 "QSDL92.y" /* yacc.c:1646  */
    {channel_path_4();}
#line 3511 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1578 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3517 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1579 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 3523 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1583 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 3529 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1586 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 3535 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1587 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = DS_NAME_ENV; }
#line 3541 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1592 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_definition_1((yyvsp[0].symval));}
#line 3547 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1594 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_definition_2();}
#line 3553 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1599 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_path_1((yyvsp[0].symval));}
#line 3559 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1601 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_path_2((yyvsp[0].symval));}
#line 3565 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1602 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_path_3();}
#line 3571 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1603 "QSDL92.y" /* yacc.c:1646  */
    {signal_route_path_4();}
#line 3577 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1607 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3583 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1612 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 3589 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1616 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_channel_connection_1();}
#line 3595 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1617 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_channel_connection_2();}
#line 3601 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1620 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_channel_connection_3();}
#line 3607 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1624 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_route_connection_1();}
#line 3613 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1625 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_route_connection_2();}
#line 3619 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1628 "QSDL92.y" /* yacc.c:1646  */
    {channel_to_route_connection_3();}
#line 3625 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1640 "QSDL92.y" /* yacc.c:1646  */
    {/* nichts tun s.u. */}
#line 3631 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1652 "QSDL92.y" /* yacc.c:1646  */
    {signal_definition_item_1((yyvsp[0].symval));}
#line 3637 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1655 "QSDL92.y" /* yacc.c:1646  */
    {signal_definition_item_2();}
#line 3643 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1665 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3649 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1670 "QSDL92.y" /* yacc.c:1646  */
    {comma_sort_list_1((yyvsp[0].symval));}
#line 3655 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1671 "QSDL92.y" /* yacc.c:1646  */
    {comma_sort_list_1((yyvsp[0].symval));}
#line 3661 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1676 "QSDL92.y" /* yacc.c:1646  */
    {signallist_definition_1((yyvsp[0].symval));}
#line 3667 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1677 "QSDL92.y" /* yacc.c:1646  */
    {signallist_definition_2();}
#line 3673 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1678 "QSDL92.y" /* yacc.c:1646  */
    {signallist_definition_3();}
#line 3679 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1679 "QSDL92.y" /* yacc.c:1646  */
    {signallist_definition_4();}
#line 3685 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1689 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3691 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1694 "QSDL92.y" /* yacc.c:1646  */
    {signallist_item_1((yyvsp[0].symval));}
#line 3697 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1696 "QSDL92.y" /* yacc.c:1646  */
    {signallist_item_2((yyvsp[0].symval));}
#line 3703 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1701 "QSDL92.y" /* yacc.c:1646  */
    {variable_definition_1();}
#line 3709 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1705 "QSDL92.y" /* yacc.c:1646  */
    {variable_definition_2();}
#line 3715 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1708 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3721 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1709 "QSDL92.y" /* yacc.c:1646  */
    {opt_history_item_1();}
#line 3727 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1712 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3733 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1716 "QSDL92.y" /* yacc.c:1646  */
    {revealed_exported_item_1();}
#line 3739 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1717 "QSDL92.y" /* yacc.c:1646  */
    {revealed_exported_item_2();}
#line 3745 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1718 "QSDL92.y" /* yacc.c:1646  */
    {revealed_exported_item_3();}
#line 3751 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1719 "QSDL92.y" /* yacc.c:1646  */
    {revealed_exported_item_3();}
#line 3757 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1724 "QSDL92.y" /* yacc.c:1646  */
    {variables_of_sort_1((yyvsp[0].symval));}
#line 3763 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1725 "QSDL92.y" /* yacc.c:1646  */
    {variables_of_sort_2();}
#line 3769 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1734 "QSDL92.y" /* yacc.c:1646  */
    {var_exported_1((yyvsp[-1].symval), (yyvsp[0].symval));}
#line 3775 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1737 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3781 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1751 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 3787 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1754 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3793 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1755 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 3799 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1772 "QSDL92.y" /* yacc.c:1646  */
    {start_1();}
#line 3805 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1775 "QSDL92.y" /* yacc.c:1646  */
    {start_2();}
#line 3811 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1779 "QSDL92.y" /* yacc.c:1646  */
    {state_1();}
#line 3817 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1780 "QSDL92.y" /* yacc.c:1646  */
    {state_2();}
#line 3823 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1781 "QSDL92.y" /* yacc.c:1646  */
    {state_3();}
#line 3829 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1784 "QSDL92.y" /* yacc.c:1646  */
    {state_4((yyvsp[0].symval));}
#line 3835 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1788 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3841 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1803 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3847 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1807 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[-1].symval);}
#line 3853 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1824 "QSDL92.y" /* yacc.c:1646  */
    {basic_input_part_1();}
#line 3859 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1827 "QSDL92.y" /* yacc.c:1646  */
    {basic_input_part_2();}
#line 3865 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1828 "QSDL92.y" /* yacc.c:1646  */
    {basic_input_part_3();}
#line 3871 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1837 "QSDL92.y" /* yacc.c:1646  */
    {stimulus_1((yyvsp[0].symval));}
#line 3877 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1838 "QSDL92.y" /* yacc.c:1646  */
    {stimulus_2();}
#line 3883 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1841 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3889 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1865 "QSDL92.y" /* yacc.c:1646  */
    {basic_save_part_1();}
#line 3895 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1867 "QSDL92.y" /* yacc.c:1646  */
    {basic_save_part_2();}
#line 3901 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1878 "QSDL92.y" /* yacc.c:1646  */
    {spontaneous_transition_1();}
#line 3907 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1880 "QSDL92.y" /* yacc.c:1646  */
    {spontaneous_transition_2();}
#line 3913 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1881 "QSDL92.y" /* yacc.c:1646  */
    {spontaneous_transition_3();}
#line 3919 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1889 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[-1].symval);}
#line 3925 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1892 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3931 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1902 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3937 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1908 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[-1].symval);}
#line 3943 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1917 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3949 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1928 "QSDL92.y" /* yacc.c:1646  */
    {action_statement_1((yyvsp[0].symval));}
#line 3955 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1930 "QSDL92.y" /* yacc.c:1646  */
    {action_statement_2();}
#line 3961 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1953 "QSDL92.y" /* yacc.c:1646  */
    {terminator_statement_1((yyvsp[0].symval));}
#line 3967 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1955 "QSDL92.y" /* yacc.c:1646  */
    {terminator_statement_2();}
#line 3973 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1958 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 3979 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1971 "QSDL92.y" /* yacc.c:1646  */
    {nextstate_1((yyvsp[0].symval));}
#line 3985 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1974 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 3991 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1975 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = "-";}
#line 3997 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1979 "QSDL92.y" /* yacc.c:1646  */
    {join_1((yyvsp[0].symval));}
#line 4003 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1983 "QSDL92.y" /* yacc.c:1646  */
    {stop_1();}
#line 4009 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1987 "QSDL92.y" /* yacc.c:1646  */
    {return_1();}
#line 4015 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1991 "QSDL92.y" /* yacc.c:1646  */
    {task_1();}
#line 4021 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1999 "QSDL92.y" /* yacc.c:1646  */
    {task_1();}
#line 4027 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2000 "QSDL92.y" /* yacc.c:1646  */
    {comma_assignment_statement_list_1();}
#line 4033 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2001 "QSDL92.y" /* yacc.c:1646  */
    {comma_assignment_statement_list_1();}
#line 4039 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2005 "QSDL92.y" /* yacc.c:1646  */
    {task_1();}
#line 4045 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2006 "QSDL92.y" /* yacc.c:1646  */
    {comma_informal_text_list_1((yyvsp[-3].symval));}
#line 4051 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2007 "QSDL92.y" /* yacc.c:1646  */
    {comma_informal_text_list_1((yyvsp[0].symval));}
#line 4057 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2016 "QSDL92.y" /* yacc.c:1646  */
    {create_body_1((yyvsp[-1].symval));}
#line 4063 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2027 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4069 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2037 "QSDL92.y" /* yacc.c:1646  */
    {procedure_call_body_1((yyvsp[0].symval));}
#line 4075 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2038 "QSDL92.y" /* yacc.c:1646  */
    {procedure_call_body_2();}
#line 4081 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2042 "QSDL92.y" /* yacc.c:1646  */
    {output_1();}
#line 4087 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 2048 "QSDL92.y" /* yacc.c:1646  */
    {output_body_1();}
#line 4093 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 2049 "QSDL92.y" /* yacc.c:1646  */
    {output_body_2();}
#line 4099 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2050 "QSDL92.y" /* yacc.c:1646  */
    {output_body_3();}
#line 4105 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2059 "QSDL92.y" /* yacc.c:1646  */
    {ident_actual_param_1((yyvsp[-1].symval));}
#line 4111 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2062 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4117 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2069 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4123 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2076 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4129 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2082 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4135 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 2092 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_THIS);}
#line 4141 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 2100 "QSDL92.y" /* yacc.c:1646  */
    {decision_1();}
#line 4147 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2101 "QSDL92.y" /* yacc.c:1646  */
    {decision_2();}
#line 4153 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2104 "QSDL92.y" /* yacc.c:1646  */
    {decision_3();}
#line 4159 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2116 "QSDL92.y" /* yacc.c:1646  */
    {answer_part_1();}
#line 4165 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2117 "QSDL92.y" /* yacc.c:1646  */
    {answer_part_2();}
#line 4171 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2129 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4177 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2135 "QSDL92.y" /* yacc.c:1646  */
    {else_part_1();}
#line 4183 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2136 "QSDL92.y" /* yacc.c:1646  */
    {else_part_2();}
#line 4189 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2139 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4195 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2156 "QSDL92.y" /* yacc.c:1646  */
    {timer_definition_item_1((yyvsp[0].symval));}
#line 4201 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2158 "QSDL92.y" /* yacc.c:1646  */
    {timer_definition_item_2();}
#line 4207 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2161 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4213 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2183 "QSDL92.y" /* yacc.c:1646  */
    {reset_statement_1((yyvsp[-1].symval));}
#line 4219 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2199 "QSDL92.y" /* yacc.c:1646  */
    {set_statement_1((yyvsp[-2].symval));}
#line 4225 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2215 "QSDL92.y" /* yacc.c:1646  */
    {asterisk_state_list_1();}
#line 4231 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2234 "QSDL92.y" /* yacc.c:1646  */
    {priority_input_1();}
#line 4237 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2236 "QSDL92.y" /* yacc.c:1646  */
    {priority_input_2();}
#line 4243 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2237 "QSDL92.y" /* yacc.c:1646  */
    {priority_input_3();}
#line 4249 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2246 "QSDL92.y" /* yacc.c:1646  */
    {continuous_signal_1();}
#line 4255 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2247 "QSDL92.y" /* yacc.c:1646  */
    {continuous_signal_2();}
#line 4261 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2250 "QSDL92.y" /* yacc.c:1646  */
    {continuous_signal_3((yyvsp[-1].symval));}
#line 4267 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2253 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4273 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2257 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[-1].symval);}
#line 4279 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2264 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4285 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2270 "QSDL92.y" /* yacc.c:1646  */
    {partial_type_definition_1((yyvsp[0].symval));}
#line 4291 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2275 "QSDL92.y" /* yacc.c:1646  */
    {partial_type_definition_2((yyvsp[0].symval));}
#line 4297 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2289 "QSDL92.y" /* yacc.c:1646  */
    {literal_list_1();}
#line 4303 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2291 "QSDL92.y" /* yacc.c:1646  */
    {literal_list_2();}
#line 4309 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2294 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4315 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2304 "QSDL92.y" /* yacc.c:1646  */
    {comma_literal_signature_list_1((yyvsp[0].symval));}
#line 4321 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2305 "QSDL92.y" /* yacc.c:1646  */
    {comma_literal_signature_list_1((yyvsp[0].symval));}
#line 4327 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2319 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4333 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2325 "QSDL92.y" /* yacc.c:1646  */
    {operator_signature_1();}
#line 4339 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2328 "QSDL92.y" /* yacc.c:1646  */
    {operator_signature_2((yyvsp[-5].symval), (yyvsp[-1].symval));}
#line 4345 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2352 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 4351 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2356 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4357 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2357 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 4363 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2371 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4369 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2427 "QSDL92.y" /* yacc.c:1646  */
    {syntype_definition_1((yyvsp[0].symval));}
#line 4375 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2429 "QSDL92.y" /* yacc.c:1646  */
    {syntype_definition_2((yyvsp[0].symval));}
#line 4381 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2433 "QSDL92.y" /* yacc.c:1646  */
    {syntype_definition_3((yyvsp[0].symval));}
#line 4387 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2449 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4393 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2467 "QSDL92.y" /* yacc.c:1646  */
    {closed_range_1();}
#line 4399 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2471 "QSDL92.y" /* yacc.c:1646  */
    {open_range_1();}
#line 4405 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2472 "QSDL92.y" /* yacc.c:1646  */
    {open_range_2((yyvsp[-1].oprtr));}
#line 4411 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2475 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_EQUAL;}
#line 4417 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2476 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_NOT_EQUAL;}
#line 4423 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2477 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_LESS;}
#line 4429 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2478 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_GREATER;}
#line 4435 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2479 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_LESS_EQUAL;}
#line 4441 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2480 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_RANGE_OPT_GREATER_EQUAL;}
#line 4447 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2488 "QSDL92.y" /* yacc.c:1646  */
    {structure_definition_1();}
#line 4453 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2491 "QSDL92.y" /* yacc.c:1646  */
    {structure_definition_2();}
#line 4459 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2494 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4465 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2505 "QSDL92.y" /* yacc.c:1646  */
    {fields_1((yyvsp[0].symval));}
#line 4471 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2509 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 4477 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2524 "QSDL92.y" /* yacc.c:1646  */
    {generator_transformation_1((yyvsp[-1].symval));}
#line 4483 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2526 "QSDL92.y" /* yacc.c:1646  */
    {generator_transformation_2();}
#line 4489 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2532 "QSDL92.y" /* yacc.c:1646  */
    {generator_actual_list_1((yyvsp[0].symval));}
#line 4495 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2533 "QSDL92.y" /* yacc.c:1646  */
    {generator_actual_list_1((yyvsp[0].symval));}
#line 4501 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2537 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 4507 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2556 "QSDL92.y" /* yacc.c:1646  */
    {synonym_definition_item_1((yyvsp[0].symval));}
#line 4513 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2557 "QSDL92.y" /* yacc.c:1646  */
    {synonym_definition_item_2((yyvsp[0].symval));}
#line 4519 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2559 "QSDL92.y" /* yacc.c:1646  */
    {synonym_definition_item_3();}
#line 4525 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2577 "QSDL92.y" /* yacc.c:1646  */
    {opt_expression_1(); }
#line 4531 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2585 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary(DS_OPT_THICKARROW);}
#line 4537 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2592 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary((yyvsp[-1].oprtr));}
#line 4543 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2595 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_OR;}
#line 4549 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2596 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_XOR;}
#line 4555 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2603 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary(DS_OPT_AND);}
#line 4561 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2610 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary((yyvsp[-1].oprtr));}
#line 4567 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 675:
#line 2613 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_EQUAL;}
#line 4573 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 676:
#line 2614 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_NOT_EQUAL;}
#line 4579 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 677:
#line 2615 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_GREATER;}
#line 4585 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 678:
#line 2616 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_GREATER_EQUAL;}
#line 4591 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 679:
#line 2617 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_LESS;}
#line 4597 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 680:
#line 2618 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_LESS_EQUAL;}
#line 4603 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 681:
#line 2619 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_IN;}
#line 4609 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 683:
#line 2624 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary((yyvsp[-1].oprtr));}
#line 4615 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 684:
#line 2627 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_ADDITION;}
#line 4621 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 685:
#line 2628 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_SUBTRACTION;}
#line 4627 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 686:
#line 2629 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_CONCATENATION;}
#line 4633 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 688:
#line 2634 "QSDL92.y" /* yacc.c:1646  */
    {operand_binary((yyvsp[-1].oprtr));}
#line 4639 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 689:
#line 2637 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_MULTIPLICATION;}
#line 4645 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 690:
#line 2638 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_DIVISION;}
#line 4651 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 691:
#line 2639 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_MOD;}
#line 4657 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 692:
#line 2640 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_REM;}
#line 4663 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 693:
#line 2645 "QSDL92.y" /* yacc.c:1646  */
    {operand_unary((yyvsp[-1].oprtr));}
#line 4669 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 694:
#line 2648 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_NONE;}
#line 4675 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 695:
#line 2649 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = (yyvsp[0].oprtr);}
#line 4681 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 696:
#line 2652 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_MINUS;}
#line 4687 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 697:
#line 2653 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.oprtr) = DS_OPT_NOT;}
#line 4693 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 698:
#line 2658 "QSDL92.y" /* yacc.c:1646  */
    {primary_1((yyvsp[0].symval));}
#line 4699 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 699:
#line 2659 "QSDL92.y" /* yacc.c:1646  */
    {primary_2((yyvsp[0].symval));}
#line 4705 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 704:
#line 2675 "QSDL92.y" /* yacc.c:1646  */
    {indexed_primary_1();}
#line 4711 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 705:
#line 2677 "QSDL92.y" /* yacc.c:1646  */
    {indexed_primary_2();}
#line 4717 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 706:
#line 2679 "QSDL92.y" /* yacc.c:1646  */
    {indexed_primary_1();}
#line 4723 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 707:
#line 2681 "QSDL92.y" /* yacc.c:1646  */
    {indexed_primary_2();}
#line 4729 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 708:
#line 2686 "QSDL92.y" /* yacc.c:1646  */
    {field_primary_1((yyvsp[0].symval));}
#line 4735 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 709:
#line 2690 "QSDL92.y" /* yacc.c:1646  */
    {(yyval.symval) = (yyvsp[0].symval);}
#line 4741 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 719:
#line 2718 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4747 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 723:
#line 2730 "QSDL92.y" /* yacc.c:1646  */
    {variable_1((yyvsp[0].symval));}
#line 4753 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 726:
#line 2735 "QSDL92.y" /* yacc.c:1646  */
    {opt_variable_1(); }
#line 4759 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 728:
#line 2743 "QSDL92.y" /* yacc.c:1646  */
    {indexed_variable_1();}
#line 4765 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 729:
#line 2748 "QSDL92.y" /* yacc.c:1646  */
    {field_variable_1((yyvsp[0].symval));}
#line 4771 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 731:
#line 2755 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4777 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 735:
#line 2762 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_NAME_EXTERNAL);}
#line 4783 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 736:
#line 2772 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_NOW);}
#line 4789 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 737:
#line 2776 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_SELF);}
#line 4795 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 738:
#line 2777 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_PARENT);}
#line 4801 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 739:
#line 2778 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_OFFSPRING);}
#line 4807 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 740:
#line 2779 "QSDL92.y" /* yacc.c:1646  */
    {constant_expression(DS_SORT_OPERATOR_NAME_SENDER);}
#line 4813 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 745:
#line 2795 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4819 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 750:
#line 2812 "QSDL92.y" /* yacc.c:1646  */
    {machineservice_definition_item_1((yyvsp[0].symval));}
#line 4825 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 751:
#line 2813 "QSDL92.y" /* yacc.c:1646  */
    {machineservice_definition_item_2();}
#line 4831 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 752:
#line 2820 "QSDL92.y" /* yacc.c:1646  */
    {machine_reference_1((yyvsp[-2].symval));}
#line 4837 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 753:
#line 2826 "QSDL92.y" /* yacc.c:1646  */
    {machine_definition_1((yyvsp[-1].symval));}
#line 4843 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 754:
#line 2830 "QSDL92.y" /* yacc.c:1646  */
    {machine_definition_4((yyvsp[-1].symval));}
#line 4849 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 757:
#line 2839 "QSDL92.y" /* yacc.c:1646  */
    {machine_definition_2();}
#line 4855 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 758:
#line 2840 "QSDL92.y" /* yacc.c:1646  */
    {machine_definition_3();}
#line 4861 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 765:
#line 2862 "QSDL92.y" /* yacc.c:1646  */
    {machservice_name_speed_list_item_1((yyvsp[-2].symval));}
#line 4867 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 769:
#line 2875 "QSDL92.y" /* yacc.c:1646  */
    { mach_sensor_definition_1 ((yyvsp[-1].symval), (yyvsp[0].oprtr)); }
#line 4873 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 770:
#line 2878 "QSDL92.y" /* yacc.c:1646  */
    { mach_sensor_definition_2 ((yyvsp[-2].symval), (yyvsp[-1].oprtr)); }
#line 4879 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 771:
#line 2881 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_FREQ_REQUEST; }
#line 4885 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 772:
#line 2882 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_QUEUE_LENGTH; }
#line 4891 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 773:
#line 2883 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_QUEUE_CONTENT; }
#line 4897 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 774:
#line 2884 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_UTILIZATION; }
#line 4903 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 775:
#line 2887 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_COUNT_REQUEST; }
#line 4909 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 776:
#line 2888 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_WAITTIME_REQUEST; }
#line 4915 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 777:
#line 2889 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_THROUGHPUT;}
#line 4921 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 778:
#line 2890 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.oprtr) = DS_SENSOR_MACH_SERVICETIME_REQUEST; }
#line 4927 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 779:
#line 2894 "QSDL92.y" /* yacc.c:1646  */
    {pipe_definition_1((yyvsp[0].symval));}
#line 4933 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 780:
#line 2899 "QSDL92.y" /* yacc.c:1646  */
    {pipe_definition_2((yyvsp[-2].symval));}
#line 4939 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 781:
#line 2903 "QSDL92.y" /* yacc.c:1646  */
    {pipe_path_1((yyvsp[0].symval));}
#line 4945 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 782:
#line 2905 "QSDL92.y" /* yacc.c:1646  */
    {pipe_path_2((yyvsp[0].symval));}
#line 4951 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 783:
#line 2907 "QSDL92.y" /* yacc.c:1646  */
    {pipe_path_3();}
#line 4957 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 785:
#line 2911 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 4963 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 786:
#line 2912 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 4969 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 787:
#line 2916 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 4975 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 788:
#line 2920 "QSDL92.y" /* yacc.c:1646  */
    {link_definition_1((yyvsp[0].symval));}
#line 4981 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 789:
#line 2921 "QSDL92.y" /* yacc.c:1646  */
    {link_definition_2();}
#line 4987 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 790:
#line 2925 "QSDL92.y" /* yacc.c:1646  */
    {link_path_1((yyvsp[0].symval));}
#line 4993 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 791:
#line 2927 "QSDL92.y" /* yacc.c:1646  */
    {link_path_2((yyvsp[0].symval));}
#line 4999 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 792:
#line 2929 "QSDL92.y" /* yacc.c:1646  */
    {link_path_3();}
#line 5005 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 794:
#line 2934 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 5011 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 796:
#line 2940 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_pipe_binding_1();}
#line 5017 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 797:
#line 2941 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_pipe_binding_2();}
#line 5023 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 798:
#line 2944 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_pipe_binding_3();}
#line 5029 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 799:
#line 2947 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_link_binding_1();}
#line 5035 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 800:
#line 2948 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_link_binding_2();}
#line 5041 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 801:
#line 2951 "QSDL92.y" /* yacc.c:1646  */
    {pipe_to_link_binding_3();}
#line 5047 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 802:
#line 2954 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5053 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 805:
#line 2963 "QSDL92.y" /* yacc.c:1646  */
    {request_1();}
#line 5059 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 808:
#line 2973 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5065 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 809:
#line 2974 "QSDL92.y" /* yacc.c:1646  */
    { request_body_1(); }
#line 5071 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 810:
#line 2975 "QSDL92.y" /* yacc.c:1646  */
    { request_body_2((yyvsp[0].symval)); }
#line 5077 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 811:
#line 2979 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = (yyvsp[0].symval); }
#line 5083 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 814:
#line 2993 "QSDL92.y" /* yacc.c:1646  */
    {request_parameter_1((yyvsp[-4].symval));}
#line 5089 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 815:
#line 2996 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5095 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 820:
#line 3016 "QSDL92.y" /* yacc.c:1646  */
    {clear_1((yyvsp[-1].symval));}
#line 5101 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 821:
#line 3022 "QSDL92.y" /* yacc.c:1646  */
    {update_1((yyvsp[-2].symval));}
#line 5107 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 822:
#line 3025 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5113 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 825:
#line 3033 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5119 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 828:
#line 3044 "QSDL92.y" /* yacc.c:1646  */
    {assert_1();}
#line 5125 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 829:
#line 3049 "QSDL92.y" /* yacc.c:1646  */
    { (yyval.symval) = NULL; }
#line 5131 "QSDL92.tab.c" /* yacc.c:1646  */
    break;

  case 836:
#line 3072 "QSDL92.y" /* yacc.c:1646  */
    { atom_1((yyvsp[-2].symval)); }
#line 5137 "QSDL92.tab.c" /* yacc.c:1646  */
    break;


#line 5141 "QSDL92.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 3074 "QSDL92.y" /* yacc.c:1906  */

