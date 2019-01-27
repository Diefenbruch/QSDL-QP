/*------------------------------------------------------------------------------+
|                                                                               |
|   QP - QSDL Parser                                                            |
|                                                                               |
|   (C) 1994-98 Marc Diefenbruch                                                |
|       University of Essen, Germany                                            |
|                                                                               |
+---------------+-------------------+---------------+-------------------+-------+
|   Module      |   File            |   Created     |   Project         |       |
+---------------+-------------------+---------------+-------------------+-------+
| QPError       |   QPError.h       | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#include "QPLexYacc.h"


#ifdef __cplusplus

#ifdef DEBUG

#include <fstream>

extern ofstream qpDebugLog;

#endif

extern "C" {
#endif

void yyerror(const char* );
void yywarning(const char* );

#ifdef __cplusplus
} // extern "C"
#endif
