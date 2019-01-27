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
| QPMachine     |   QPMachine.h     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERMACHINE_H_
#define _PARSERMACHINE_H_

void machine_reference_1(const char *name);
void machine_definition_1(const char *name);
void machine_definition_2(void);
void machine_definition_3(void);
void machine_definition_4(const char *name);
void machservice_name_speed_list_item_1(const char *name);

#endif
