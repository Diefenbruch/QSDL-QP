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
| QPIdentifier  |   QPIdentifier.h  | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERIDENTIFIER_H_
#define _PARSERIDENTIFIER_H_

#include "DS/DSBasicTypes.h"

void comma_ident_list_1(const char *);
void name_or_quoted_operator_1(const char *);
void scope_unit_kind_1(const int);
void opt_qualifier_1(void);

#endif
