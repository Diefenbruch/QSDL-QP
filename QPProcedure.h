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
| QPProcedure   |   QPProcedure.h   | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERPROCEDURE_H_
#define _PARSERPROCEDURE_H_

void procedure_reference_1(const char* symbol);
void procedure_definition_1(const char* symbol);
void procedure_definition_2(const char* symbol);
void procedure_formal_parameters_1(void);
void procedure_formal_parameters_2(void);
void formal_variable_parameters_1(const char *kind, const char *sort);
void procedure_result_1(const char *name, const char *sort);

#endif
