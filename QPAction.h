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
| QPAction      |   QPAction.h      | 9. Aug 1994   |   SCL             |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERACTION_H_
#define _PARSERACTION_H_

void action_statement_1(const char *label);
void action_statement_2(void);
void terminator_statement_1(const char *label);
void terminator_statement_2(void);
void decision_1(void);
void decision_2(void);
void decision_3(void);
void answer_part_1(void);
void answer_part_2(void);
void else_part_1(void);
void else_part_2(void);
void task_1(void);
void comma_assignment_statement_list_1(void);
void comma_informal_text_list_1(const char *text);
void nextstate_1(const char *statename);
void join_1(const char *label);
void stop_1(void);
void return_1(void);
void create_body_1(const char *processname);
void procedure_call_body_1(const char *procedurename);
void procedure_call_body_2(void);
void reset_statement_1(const char *name);
void set_statement_1(const char *name);
void output_1(void);
void ident_actual_param_1(const char *signal); /* OUTPUT ! */
void output_body_1(void);
void output_body_2(void);
void output_body_3(void);
void request_1(void);
void request_parameter_1(const char *machineservice);
void opt_target_1(void);
void request_body_1(void);
void request_body_2(const char*);
void clear_1(const char *sensor);
void update_1(const char *sensor);
void assert_1(void);

#endif
