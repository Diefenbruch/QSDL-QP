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
| QPProcess     |   QPProcess.h     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERPROCESS_H_
#define _PARSERPROCESS_H_

void process_reference_1(const char *symbol);
void process_definition_1(const char *symbol);
void process_definition_2(const char *symbol);
void valid_input_signal_set_1(void);
void valid_input_signal_set_2(void);
void number_of_process_instances_1(void);
void number_of_process_instances_2(void);
void formal_parameters_1(void);
void formal_parameters_2(void);
void comma_parameters_of_sort_list_1(const char *symbol);
#endif
