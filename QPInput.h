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
| QPInput       |   QPInput.h       | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERINPUT_H_
#define _PARSERINPUT_H_

void basic_input_part_1(void);
void basic_input_part_2(void);
void basic_input_part_3(void);
void basic_save_part_1(void);
void basic_save_part_2(void);
void spontaneous_transition_1(void);
void spontaneous_transition_2(void);
void spontaneous_transition_3(void);
void priority_input_1(void);
void priority_input_2(void);
void priority_input_3(void);
void continuous_signal_1(void);
void continuous_signal_2(void);
void continuous_signal_3(const char *symbol);
void stimulus_1(const char *symbol);
void stimulus_2(void);

#endif
