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
| QPExpression  |   QPExpression.h  | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSEREXPRESSION_H_
#define _PARSEREXPRESSION_H_

void opt_expression_1(void);
void operand_binary(int opt);
void operand_unary(int opt);
void primary_1(const char *name);
void primary_2(const char *name);
void indexed_primary_1(void);
void indexed_primary_2(void);
void field_primary_1(const char *field);
void constant_expression(const char *token);

#endif
