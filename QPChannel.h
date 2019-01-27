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
| QPChannel     |   QPChannel.h     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _PARSERCHANNEL_H_
#define _PARSERCHANNEL_H_

void channel_definition_1(const char *name);
void channel_definition_2(const char *name);
void channel_path_1(const char* symbol);
void channel_path_2(const char* symbol);
void channel_path_3(void);
void channel_path_4(void);
void opt_nodelay_1(void);

#endif
