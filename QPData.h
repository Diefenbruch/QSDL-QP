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
| QPData        |   QPData.h        | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERDATA_H_
#define _PARSERDATA_H_

void synonym_definition_item_1(const char *symbol);
void synonym_definition_item_2(const char *symbol);
void synonym_definition_item_3(void);
void syntype_definition_1(const char *symbol);
void syntype_definition_2(const char *symbol);
void syntype_definition_3(const char *symbol);
void closed_range_1(void);
void open_range_1(void);
void open_range_2(int op);
void partial_type_definition_1(const char *symbol);
void partial_type_definition_2(const char *symbol);
void structure_definition_1(void);
void structure_definition_2(void);
void fields_1(const char *symbol);
void generator_transformation_1(const char *symbol);
void generator_transformation_2(void);
void literal_list_1(void);
void literal_list_2(void);
void operator_signature_1(void);
void operator_signature_2(const char *name, const char *result);

#endif
