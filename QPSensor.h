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
| QPSensor      |   QPSensor.h      | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifndef _QPSENSOR_H_
#define _QPSENSOR_H_


void sys_sensor_definition_1 (char*        sensorName,
                              DSSensorType sensorType);

void sys_sensor_definition_2 (char*        sensorName,
                              DSSensorType sensorType);

void pcs_sensor_definition_1 (char*        sensorName,
                              DSSensorType sensorType);

void pcs_sensor_definition_2 (char*        sensorName,
                              DSSensorType sensorType);

void mach_sensor_definition_1 (char*        sensorName,
                               DSSensorType sensorType);

void mach_sensor_definition_2 (char*        sensorName,
                               DSSensorType sensorType);

#endif

