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
| QPSignalRoute |   QPSignalRoute.h | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERSIGNALROUTE_H_
#define _PARSERSIGNALROUTE_H_

void signal_route_definition_1(const char* symbol);
void signal_route_definition_2(void);
void signal_route_path_1(const char* symbol);
void signal_route_path_2(const char* symbol);
void signal_route_path_3(void);
void signal_route_path_4(void);

#endif
