%{
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "QSDL92.tab.h"					     		 /* header file generated
													by yacc / bison. */
#include "QPError.h"								 /* header file for general
													purpose symbols. */

int line_count = 1;								 /* counter for lines. */

int yywrap(void)       /* This function is supposed
													to be supplied by the
													library libfl.a. For some
													reason it is not. If
													problems arise during
													compilation, remove this
													function. */
{
  return 1;										 /* Verbatim copy from original
													library source. */
}

extern void yyerror (const char* s);					 /* Error reporting routine. */
%}

ACTIVEsym				"active"
ADDINGsym				"adding"
ALLsym					"all"
ALTERNATIVEsym			"alternative"
ANYsym					"any"
ASsym					"as"
ATLEASTsym				"atleast"
AXIOMSsym				"axioms"
BLOCKsym				"block"
CALLsym					"call"
CHANNELsym				"channel"
COMMENTsym				"comment" 
CONNECTsym				"connect"
CONNECTIONsym			"connection"
CONSTANTsym				"constant"
CONSTANTSsym			"constants"
CREATEsym				"create"
DCLsym					"dcl"
DECISIONsym				"decision"
DEFAULTsym				"default"
DELAYsym				"delay"
ELSEsym					"else"
ENDALTERNATIVEsym		"endalternative"
ENDBLOCKsym				"endblock"
ENDCHANNELsym			"endchannel"
ENDCONNECTIONsym		"endconnection"
ENDDECISIONsym			"enddecision"
ENDGENERATORsym			"endgenerator"
ENDMACROsym				"endmacro"
ENDNEWTYPEsym			"endnewtype"
ENDOPERATORsym			"endoperator"
ENDPACKAGEsym			"endpackage"
ENDPROCEDUREsym			"endprocedure"
ENDPROCESSsym			"endprocess"
ENDREFINEMENTsym		"endrefinement"
ENDSELECTsym			"endselect"
ENDSERVICEsym			"endservice"
ENDSTATEsym				"endstate"
ENDSUBSTRUCTUREsym		"endsubstructure"
ENDSYNTYPEsym			"endsyntype"
ENDSYSTEMsym			"endsystem"
ENVsym					"env"
ERRORsym				"error"
EXPORTsym				"export"
EXPORTEDsym				"exported"
EXTERNALsym				"external"
FIsym					"fi"
FINALIZEDsym			"finalized"
FORsym					"for"
FPARsym					"fpar"
FROMsym					"from"
GATEsym					"gate"
GENERATORsym			"generator"
IFsym					"if"
IMPORTsym				"import"
IMPORTEDsym				"imported"
INsym					"in"
INHERITSsym				"inherits"
INPUTsym				"input"
INTERFACEsym			"interface"
JOINsym					"join"
LITERALsym				"literal"
LITERALSsym				"literals"
MACROsym				"macro"
MACRODEFINITIONsym		"macrodefinition"
MACROIDsym				"macroid"
MAPsym					"map"
NAMECLASSsym			"nameclass"
NEWTYPEsym				"newtype"
NEXTSTATEsym			"nextstate"
NODELAYsym				"nodelay"
NOEQUALITYsym			"noequality"
NONEsym					"none"
NOWsym					"now"
OFFSPRINGsym			"offspring"
OPERATORsym				"operator"
OPERATORSsym			"operators"
ORDERINGsym				"ordering"
OUTsym					"out"
OUTPUTsym				"output"
PACKAGEsym				"package"
PARENTsym				"parent"
PRIORITYsym				"priority"
PROCEDUREsym			"procedure"
PROCESSsym				"process"
PROVIDEDsym				"provided"
REDEFINEDsym			"redefined"
REFERENCEDsym			"referenced"
REFINEMENTsym			"refinement"
REMOTEsym				"remote"
RESETsym				"reset"
RETURNsym				"return"
RETURNSsym				"returns"
REVEALEDsym				"revealed"
REVERSEsym				"reverse"
SAVEsym					"save"
SELECTsym				"select"
SELFsym					"self"
SENDERsym				"sender"
SERVICEsym				"service"
SETsym					"set"
SIGNALsym				"signal"
SIGNALLISTsym			"signallist"
SIGNALROUTEsym			"signalroute"
SIGNALSETsym			"signalset"
SPELLINGsym				"spelling"
STARTsym				"start"
STATEsym				"state"
STOPsym					"stop"
STRUCTsym				"struct"
SUBSTRUCTUREsym			"substructure"
SYNONYMsym				"synonym"
SYNTYPEsym				"syntype"
SYSTEMsym				"system"
TASKsym					"task"
THENsym					"then"
THISsym					"this"
TIMERsym				"timer"
TOsym					"to"
TYPEsym					"type"
USEsym					"use"
VIAsym					"via"
VIEWsym					"view"
VIEWEDsym				"viewed"
VIRTUALsym				"virtual"
WITHsym					"with"

HISTsym					"hist"

AWAKEsym				"awake"
BINDsym					"bind"
CLEARsym				"clear"
DISCIPLINEsym			"discipline"
ENDMACHINEsym			"endmachine"
ENDPIPEsym				"endpipe"
LINKsym					"link"
MACHINESERVICEsym		"machineservice"
MACHINEsym				"machine"
OFFERSsym				"offers"
PIPEsym					"pipe"
REQUESTsym				"request"
SENSORsym				"sensor"
SERVERsym				"server"
UPDATEsym 			"update"
ASSERTsym 			"assert"

BASECOUNTERsym	"basecounter"
BASEFREQUENCYsym "basefrequency"
BASETALLYsym	"basetally"

FREQSIGNALRECEIVEsym	"freqsignalreceive"
FREQSIGNALSENDsym		"freqsignalsend"
FREQSIGNALDROPsym		"freqsignaldrop"
FREQSIGNALCONSUMEsym	"freqsignalconsume"
FREQSIGNALSAVEsym		"freqsignalsave"
FREQSIGNALLOSEsym		"freqsignallose"
FREQREQUESTsym			"freqrequest"
FREQSTATEsym			"freqstate"
FREQTRANSITIONsym		"freqtransition"
COUNTSIGNALRECEIVEsym	"countsignalreceive"
COUNTSIGNALSENDsym		"countsignalsend"
COUNTSIGNALDROPsym		"countsignaldrop"
COUNTSIGNALCONSUMEsym	"countsignalconsume"
COUNTSIGNALSAVEsym		"countsignalsave"
COUNTSIGNALLOSEsym		"countsignallose"
COUNTREQUESTsym			"countrequest"
COUNTSTATEsym			"countstate"
COUNTTRANSITIONsym		"counttransition"
QUEUELENGTHsym			"queuelength"
QUEUECONTENTsym			"queuecontent"
RESPONSETIMEREQUESTsym  "responsetimerequest"
WAITTIMESIGNALsym		"waittimesignal"
WAITTIMESTATEsym		"waittimestate"
TRANSMISSIONTIMESIGNALsym   "transmissiontimesignal"

SERVICETIMEREQUESTsym   "servicetimerequest"
THROUGHPUTsym			"throughput"
UTILIZATIONsym			"utilization"
WAITTIMEREQUESTsym		"waittimerequest"

FREQSIGNALsym			"freqsignal"
FREQPROCESSCREATEsym			"freqprocesscreate"
FREQPROCESSSTOPsym			"freqprocessstop"
COUNTSIGNALsym			"countsignal"
COUNTPROCESSCREATEsym			"countprocesscreate"
COUNTPROCESSSTOPsym			"countprocessstop"
LIFETIMEPROCESSsym		"lifetimeprocess"

ATOMsym					"atom"

ANDsym					"and"
MODsym					"mod"
NOTsym					"not"
ORsym					"or"
REMsym					"rem"
XORsym					"xor"

LTLTsym					"<<"
GTGTsym					">>"

OTHER_CHARsym			"?"|"&"|"%"
APOSTROPHEsym			"'"

SPACEsym				" "
LINEBREAKsym			\n
TABULATORsym			\t

COMMAsym				","
PLUSsym					"+"
MINUSsym				"-"
EXCLAMATIONsym			"!"
GREATERsym				">"
ASTERISKsym				"*"
LEFTPARsym				"("
RIGHTPARsym				")"
QUOTEsym				\"
SEMICOLONsym			";"
LESSsym					"<"
EQUALsym				"="
COLONsym				":"
FULLSTOPsym				"."
UNDERLINEsym			"_"

DOUBLEEQUALsym			"=="
LONGTHICKARROWsym		"==>"
NOTEQUALsym				"/="
LESSEQUALsym			"<="
GREATEREQUALsym			">="
CONCATENATIONsym		"//"
ASSIGNMENTsym			":="
THICKARROWsym			"=>"
THINARROWsym			"->"
LEFTPARPERIODsym		"(."
RIGHTPARPERIODsym		".)"

white_space				({SPACEsym}|{TABULATORsym})
letter					[a-zA-Z]
decimal_digit			[0-9]

national				"#"|"`"|"@"|"["|\\|"]"|"{"|"}"|"|"|"~"|"^"
special					"+"|"-"|"!"|">"|"*"|"("|")"|\"|";"|"<"|"="|":"|\/|","
SLASHsym				\/

alphanumeric			({letter}|{decimal_digit}|{national})
word					({alphanumeric}|{FULLSTOPsym}|{UNDERLINEsym})*{alphanumeric}({alphanumeric}|{FULLSTOPsym}|{UNDERLINEsym})*
begin_comment			\/\*
character_string		{APOSTROPHEsym}({alphanumeric}|{OTHER_CHARsym}|{special}|{FULLSTOPsym}|{UNDERLINEsym}|{white_space}|{APOSTROPHEsym}{APOSTROPHEsym})*{APOSTROPHEsym}


%%
{white_space}			{  ;                    /* Do nothing. */
						}
						
{LINEBREAKsym}			{  line_count++;        /* Increment linecounter. */
						}

{begin_comment}			{  char ch = EOF;
						   int comment_flag = 0;
						   while (comment_flag == 0)
						   {
							 while ((ch = input()) != EOF
									 && ch != '*'
									 && ch != '\n')
							 {
							   ;				 /* Do nothing. */
							 };
										
							 if (ch == '\n')
							 {
							   line_count++;	 /* Increment linecounter. */
							 };
										
							 while ((ch = input()) == '*')
							 {
							   ;				 /* Consume *'s. */
							 };
										
							 if (ch == '\n')
							 {
							   line_count++;	 /* Increment linecounter. */
							 };
												
							 if (ch == EOF)
							 {
							   yyerror ("Unexpected end of file in comment.\n");
												 /* error in comment. */
							   comment_flag = 1; /* Set loop termination flag. */
							 };
										
							 if (ch == '/')      /* end of coment reached. */
							 {
							   comment_flag = 1; /* Set loop termination flag. */
							 };
										
						  };
						}


{ACTIVEsym}             {  return ACTIVEtoken;
                        }
                        
{ADDINGsym}             {  return ADDINGtoken;
                        }

{ALLsym}                {  return ALLtoken;
                        }

{ALTERNATIVEsym}        {  return ALTERNATIVEtoken;
                        }

{ANYsym}                {  return ANYtoken;
                        }

{ASsym}                 {  return AStoken;
                        }

{ATLEASTsym}            {  return ATLEASTtoken;
                        }

{AXIOMSsym}             {  return AXIOMStoken;
                        }

{BLOCKsym}              {  return BLOCKtoken;
                        }

{CALLsym}               {  return CALLtoken;
                        }

{CHANNELsym}            {  return CHANNELtoken;
                        }

{COMMENTsym}            {  return COMMENTtoken;
                        }

{CONNECTsym}            {  return CONNECTtoken;
                        }

{CONNECTIONsym}         {  return CONNECTIONtoken;
                        }

{CONSTANTsym}           {  return CONSTANTtoken;
                        }

{CONSTANTSsym}          {  return CONSTANTStoken;
                        }

{CREATEsym}             {  return CREATEtoken;
                        }

{DCLsym}                {  return DCLtoken;
                        }

{DECISIONsym}           {  return DECISIONtoken;
                        }

{DEFAULTsym}            {  return DEFAULTtoken;
                        }

{ELSEsym}               {  return ELSEtoken;
                        }

{ENDALTERNATIVEsym}     {  return ENDALTERNATIVEtoken;
                        }

{ENDBLOCKsym}           {  return ENDBLOCKtoken;
                        }

{ENDCHANNELsym}         {  return ENDCHANNELtoken;
                        }

{ENDCONNECTIONsym}      {  return ENDCONNECTIONtoken;
                        }

{ENDDECISIONsym}        {  return ENDDECISIONtoken;
                        }

{ENDGENERATORsym}       {  return ENDGENERATORtoken;
                        }

{ENDMACROsym}           {  return ENDMACROtoken;
                        }

{ENDNEWTYPEsym}         {  return ENDNEWTYPEtoken;
                        }

{ENDOPERATORsym}        {  return ENDOPERATORtoken;
                        }

{ENDPACKAGEsym}         {  return ENDPACKAGEtoken;
                        }

{ENDPROCEDUREsym}       {  return ENDPROCEDUREtoken;
                        }

{ENDPROCESSsym}         {  return ENDPROCESStoken;
                        }

{ENDREFINEMENTsym}      {  return ENDREFINEMENTtoken;
                        }

{ENDSELECTsym}          {  return ENDSELECTtoken;
                        }

{ENDSERVICEsym}         {  return ENDSERVICEtoken;
                        }

{ENDSTATEsym}           {  return ENDSTATEtoken;
                        }

{ENDSUBSTRUCTUREsym}    {  return ENDSUBSTRUCTUREtoken;
                        }

{ENDSYNTYPEsym}         {  return ENDSYNTYPEtoken;
                        }

{ENDSYSTEMsym}          {  return ENDSYSTEMtoken;
                        }

{ENVsym}                {  return ENVtoken;
                        }

{ERRORsym}              {  return ERRORtoken;
                        }

{EXPORTsym}             {  return EXPORTtoken;
                        }

{EXPORTEDsym}           {  return EXPORTEDtoken;
                        }

{EXTERNALsym}           {  return EXTERNALtoken;
                        }

{FIsym}                 {  return FItoken;
                        }

{FINALIZEDsym}          {  return FINALIZEDtoken;
                        }

{FORsym}                {  return FORtoken;
                        }

{FPARsym}               {  return FPARtoken;
                        }

{FROMsym}               {  return FROMtoken;
                        }

{GATEsym}               {  return GATEtoken;
                        }

{GENERATORsym}          {  return GENERATORtoken;
                        }

{IFsym}                 {  return IFtoken;
                        }

{IMPORTsym}             {  return IMPORTtoken;
                        }

{IMPORTEDsym}           {  return IMPORTEDtoken;
                        }

{INsym}                 {  return INtoken;
                        }

{INHERITSsym}           {  return INHERITStoken;
                        }

{INPUTsym}              {  return INPUTtoken;
                        }

{INTERFACEsym}          {  return INTERFACEtoken;
                        }

{JOINsym}               {  return JOINtoken;
                        }

{LITERALsym}            {  return LITERALtoken;
                        }

{LITERALSsym}           {  return LITERALStoken;
                        }

{MACROsym}              {  return MACROtoken;
                        }

{MACRODEFINITIONsym}	{  return MACRODEFINITIONtoken;
                        }

{MACROIDsym}            {  return MACROIDtoken;
                        }

{MAPsym}                {  return MAPtoken;
                        }

{NAMECLASSsym}          {  return NAMECLASStoken;
                        }

{NEWTYPEsym}            {  return NEWTYPEtoken;
                        }

{NEXTSTATEsym}          {  return NEXTSTATEtoken;
                        }

{NODELAYsym}            {  return NODELAYtoken;
                        }

{NOEQUALITYsym}         {  return NOEQUALITYtoken;
                        }

{NONEsym}               {  return NONEtoken;
                        }

{NOWsym}                {  return NOWtoken;
                        }

{OFFSPRINGsym}          {  return OFFSPRINGtoken;
                        }

{OPERATORsym}           {  return OPERATORtoken;
                        }

{OPERATORSsym}          {  return OPERATORStoken;
                        }

{ORDERINGsym}           {  return ORDERINGtoken;
                        }

{OUTsym}                {  return OUTtoken;
                        }

{OUTPUTsym}             {  return OUTPUTtoken;
                        }

{PACKAGEsym}            {  return PACKAGEtoken;
                        }

{PARENTsym}             {  return PARENTtoken;
                        }

{PRIORITYsym}           {  return PRIORITYtoken;
                        }

{PROCEDUREsym}          {  return PROCEDUREtoken;
                        }

{PROCESSsym}            {  return PROCESStoken;
                        }

{PROVIDEDsym}           {  return PROVIDEDtoken;
                        }

{REDEFINEDsym}          {  return REDEFINEDtoken;
                        }

{REFERENCEDsym}         {  return REFERENCEDtoken;
                        }

{REFINEMENTsym}         {  return REFINEMENTtoken;
                        }

{REMOTEsym}             {  return REMOTEtoken;
                        }

{RESETsym}              {  return RESETtoken;
                        }

{RETURNsym}             {  return RETURNtoken;
                        }

{RETURNSsym}            {  return RETURNStoken;
                        }

{REVEALEDsym}           {  return REVEALEDtoken;
                        }

{REVERSEsym}            {  return REVERSEtoken;
                        }

{SAVEsym}               {  return SAVEtoken;
                        }

{SELECTsym}             {  return SELECTtoken;
                        }

{SELFsym}               {  return SELFtoken;
                        }

{SENDERsym}             {  return SENDERtoken;
                        }

{SERVICEsym}            {  return SERVICEtoken;
                        }

{SETsym}                {  return SETtoken;
                        }

{SIGNALsym}             {  return SIGNALtoken;
                        }

{SIGNALLISTsym}         {  return SIGNALLISTtoken;
                        }

{SIGNALROUTEsym}        {  return SIGNALROUTEtoken;
                        }

{SIGNALSETsym}          {  return SIGNALSETtoken;
                        }

{SPELLINGsym}           {  return SPELLINGtoken;
                        }

{STARTsym}              {  return STARTtoken;
                        }

{STATEsym}              {  return STATEtoken;
                        }

{STOPsym}               {  return STOPtoken;
                        }

{STRUCTsym}             {  return STRUCTtoken;
                        }

{SUBSTRUCTUREsym}       {  return SUBSTRUCTUREtoken;
                        }

{SYNONYMsym}            {  return SYNONYMtoken;
                        }

{SYNTYPEsym}            {  return SYNTYPEtoken;
                        }

{SYSTEMsym}             {  return SYSTEMtoken;
                        }

{TASKsym}               {  return TASKtoken;
                        }

{THENsym}               {  return THENtoken;
                        }

{THISsym}               {  return THIStoken;
                        }

{TIMERsym}              {  return TIMERtoken;
                        }

{TOsym}                 {  return TOtoken;
                        }

{TYPEsym}               {  return TYPEtoken;
                        }

{USEsym}                {  return USEtoken;
                        }

{VIAsym}                {  return VIAtoken;
                        }

{VIEWsym}               {  return VIEWtoken;
                        }

{VIEWEDsym}             {  return VIEWEDtoken;
                        }

{VIRTUALsym}            {  return VIRTUALtoken;
                        }

{WITHsym}               {  return WITHtoken;
                        }

{HISTsym}               { return HISTtoken;
                        }

{PIPEsym}               {  return PIPEtoken;
                        }

{ENDPIPEsym}            {  return ENDPIPEtoken;
                        }

{MACHINEsym}            {  return MACHINEtoken;
                        }

{ENDMACHINEsym}         {  return ENDMACHINEtoken;
                        }

{DISCIPLINEsym}         {  return DISCIPLINEtoken;
                        }

{OFFERSsym}             {  return OFFERStoken;
                        }

{MACHINESERVICEsym}     {  return MACHINESERVICEtoken;
                        }

{AWAKEsym}              {  return AWAKEtoken;
                        }

{LINKsym}               {  return LINKtoken;
                        }

{BINDsym}               {  return BINDtoken;
                        }
                        
{SERVERsym}             {  return SERVERtoken;
                        }

{REQUESTsym}            {  return REQUESTtoken;
                        }

{CLEARsym}            {  return CLEARtoken;
                        }

{UPDATEsym}            {  return UPDATEtoken;
                        }

{ASSERTsym}            {  return ASSERTtoken;
                        }

{DELAYsym}            	{  return DELAYtoken;
                        }

{SENSORsym}				{  return SENSORtoken;
						}

{BASECOUNTERsym}	{ return BASECOUNTERtoken;
						}

{BASEFREQUENCYsym}	{ return BASEFREQUENCYtoken;
						}

{BASETALLYsym}	{ return BASETALLYtoken;
						}

{FREQSIGNALRECEIVEsym}	{ return FREQSIGNALRECEIVEtoken;
						}

{FREQSIGNALSENDsym}		{ return FREQSIGNALSENDtoken;
						}

{FREQSIGNALDROPsym}		{ return FREQSIGNALDROPtoken;
						}

{FREQSIGNALCONSUMEsym}	{ return FREQSIGNALCONSUMEtoken;
						}
					
{FREQSIGNALSAVEsym}		{ return FREQSIGNALSAVEtoken;
						}

{FREQSIGNALLOSEsym}	{ return FREQSIGNALLOSEtoken;
						}

{FREQREQUESTsym}		{ return FREQREQUESTtoken;
						}

{FREQSTATEsym}			{ return FREQSTATEtoken;
						}

{FREQTRANSITIONsym}		{ return FREQTRANSITIONtoken;
						}

{COUNTSIGNALRECEIVEsym}	{ return COUNTSIGNALRECEIVEtoken;
						}

{COUNTSIGNALSENDsym}		{ return COUNTSIGNALSENDtoken;
						}

{COUNTSIGNALDROPsym}		{ return COUNTSIGNALDROPtoken;
						}

{COUNTSIGNALCONSUMEsym}	{ return COUNTSIGNALCONSUMEtoken;
						}
					
{COUNTSIGNALSAVEsym}		{ return COUNTSIGNALSAVEtoken;
						}

{COUNTSIGNALLOSEsym}	{ return COUNTSIGNALLOSEtoken;
						}

{COUNTREQUESTsym}		{ return COUNTREQUESTtoken;
						}

{COUNTSTATEsym}			{ return COUNTSTATEtoken;
						}

{COUNTTRANSITIONsym}		{ return COUNTTRANSITIONtoken;
						}

{QUEUELENGTHsym}		{ return QUEUELENGTHtoken;
						}

{QUEUECONTENTsym}		{ return QUEUECONTENTtoken;
						}

{RESPONSETIMEREQUESTsym} { return RESPONSETIMEREQUESTtoken;
                         }

{WAITTIMESIGNALsym}		{ return WAITTIMESIGNALtoken;
						}

{WAITTIMESTATEsym}		{ return WAITTIMESTATEtoken;
						}

{TRANSMISSIONTIMESIGNALsym} { return TRANSMISSIONTIMESIGNALtoken;
            }

{WAITTIMEREQUESTsym}	{ return WAITTIMEREQUESTtoken;
						}

{SERVICETIMEREQUESTsym} { return SERVICETIMEREQUESTtoken;
                        }

{THROUGHPUTsym}			{ return THROUGHPUTtoken;
						}

{UTILIZATIONsym}		{ return UTILIZATIONtoken;
						}

{FREQSIGNALsym}			{ return FREQSIGNALtoken;
						}
						
{FREQPROCESSCREATEsym}		{ return FREQPROCESSCREATEtoken;
						}

{FREQPROCESSSTOPsym}		{ return FREQPROCESSSTOPtoken;
						}

{COUNTSIGNALsym}			{ return COUNTSIGNALtoken;
						}
						
{COUNTPROCESSCREATEsym}		{ return COUNTPROCESSCREATEtoken;
						}

{COUNTPROCESSSTOPsym}		{ return COUNTPROCESSSTOPtoken;
						}

{LIFETIMEPROCESSsym}	{ return LIFETIMEPROCESStoken;
						}

{ATOMsym}				{ return ATOMtoken;
						}

{ORsym}                 {  return ORtoken  ;
                        }

{XORsym}                {  return XORtoken ;
                        }

{ANDsym}                {  return ANDtoken ;
                        }
                        
{MODsym}                {  return MODtoken ;
                        }

{REMsym}                {  return REMtoken ;
                        }

{NOTsym}                {  return NOTtoken ;
                        }

{word}					{ unsigned int i;

                          yylval.symval = malloc((size_t) yyleng + 1);
                          for (i = 0;
                               i < yyleng;
                               i++)
                          {
                            (yylval.symval)[i] = tolower(yytext[i]);
                          }
                          yylval.symval[yyleng] = '\0';
                          return WORDtoken;
						}
						
{character_string}      {  yylval.symval = malloc((size_t)yyleng + 1);
                           yylval.symval = strncpy (yylval.symval,
                                                    yytext,
                                                    (size_t) yyleng);
                           yylval.symval[yyleng] = '\0';
                           return CHARSTRINGtoken;
                        }

{LTLTsym}				{  return LTLTtoken;
						}
						
{GTGTsym}				{  return GTGTtoken;
						}

{OTHER_CHARsym}			{  return OTHER_CHARtoken;
						}

{DOUBLEEQUALsym}		{  return DOUBLEEQUALtoken;
						}

{LONGTHICKARROWsym}		{  return LONGTHICKARROWtoken;
						}

{NOTEQUALsym}			{  return NOTEQUALtoken;
						}

{LESSEQUALsym}			{  return LESSEQUALtoken;
						}

{GREATEREQUALsym}		{  return GREATEREQUALtoken;
						}

{CONCATENATIONsym}		{  return CONCATENATIONtoken;
						}

{ASSIGNMENTsym}			{  return ASSIGNMENTtoken;
						}

{THICKARROWsym}			{  return THICKARROWtoken;
						}

{THINARROWsym}			{  return THINARROWtoken;
						}

{LEFTPARPERIODsym}		{  return LEFTPARPERIODtoken;
						}

{RIGHTPARPERIODsym}		{  return RIGHTPARPERIODtoken;
						}

{SLASHsym}				{  return SLASHtoken;
						}

{APOSTROPHEsym}			{  return APOSTROPHEtoken;
						}

{COMMAsym}				{  return COMMAtoken;
						}

{PLUSsym}				{  return PLUStoken;
						}

{MINUSsym}				{  return MINUStoken;
						}

{EXCLAMATIONsym}		{  return EXCLAMATIONtoken;
						}

{GREATERsym}			{  return GREATERtoken;
						}

{ASTERISKsym}			{  return ASTERISKtoken;
						}

{LEFTPARsym}			{  return LEFTPARtoken;
						}

{RIGHTPARsym}			{  return RIGHTPARtoken;
						}

{QUOTEsym}				{  return QUOTEtoken;
						}

{SEMICOLONsym}			{  return SEMICOLONtoken;
						}

{LESSsym}				{  return LESStoken;
						}

{EQUALsym}				{  return EQUALtoken;
						}

{COLONsym}				{  return COLONtoken;
						}

{UNDERLINEsym}			{  return UNDERLINEtoken;
						}

%%
