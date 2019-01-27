/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 96 "QSDL92.y" /* yacc.c:1909  */
 char *symval;
         int oprtr; 

#line 288 "QSDL92.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_QSDL92_TAB_H_INCLUDED  */
