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
| QPVariable    |   QPVariable.h    | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERVARIABLE_H_
#define _PARSERVARIABLE_H_

void variable_definition_1 (void);
void variable_definition_2 (void);
void opt_history_item_1 (void);
void revealed_exported_item_1 (void);
void revealed_exported_item_2 (void);
void revealed_exported_item_3 (void);
void var_exported_1 (const char *name, const char *exported_as);
void variables_of_sort_1 (const char *symbol);
void variables_of_sort_2 (void);
void variable_1 (const char *name);
void opt_variable_1 (void);
void indexed_variable_1 (void);
void field_variable_1 (const char *field);

#endif
