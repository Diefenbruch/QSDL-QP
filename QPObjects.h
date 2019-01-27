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
| QPObjects     |   QPObjects.h     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

/* #include <CG/CGAction.h> */
#include <CG/CGActualParam.h>
#include <CG/CGAssert.h>
#include <CG/CGAtom.h>
#include <CG/CGBasicTypes.h>
#include <CG/CGBlock.h>
#include <CG/CGBlockSubstructure.h>
#include <CG/CGCall.h>
#include <CG/CGClear.h>
#include <CG/CGCreate.h>
#include <CG/CGDecision.h>
#include <CG/CGExpression.h>
#include <CG/CGFormalParam.h>
#include <CG/CGGenerator.h>
#include <CG/CGInput.h>
#include <CG/CGInputSignal.h>
#include <CG/CGInputTimerSignal.h>
#include <CG/CGJoin.h>
#include <CG/CGMachine.h>
#include <CG/CGMachineService.h>
#include <CG/CGMachineServiceSpeed.h>
#include <CG/CGNextState.h>
#include <CG/CGOperandConstant.h>
#include <CG/CGOperandExpression.h>
#include <CG/CGOperandLiteral.h>
#include <CG/CGOperandMachineService.h>
#include <CG/CGOperandOperator.h>
#include <CG/CGOperandProcedureCall.h>
#include <CG/CGOperandProcessAccess.h>
#include <CG/CGOperandSensor.h>
#include <CG/CGOperandSignal.h>
#include <CG/CGOperandState.h>
#include <CG/CGOperandSynonym.h>
#include <CG/CGOperandVariableAccess.h>
#include <CG/CGOperator.h>
#include <CG/CGOutput.h>
#include <CG/CGProcedure.h>
#include <CG/CGProcess.h>
#include <CG/CGProcessAccess.h>
#include <CG/CGRequest.h>
#include <CG/CGReset.h>
#include <CG/CGReturn.h>
#include <CG/CGSet.h>
#include <CG/CGSensor.h>
#include <CG/CGSensorProcess.h>
#include <CG/CGSensorMachineService.h>
#include <CG/CGSensorSignal.h>
#include <CG/CGSensorState.h>
#include <CG/CGSignal.h>
#include <CG/CGSort.h>
#include <CG/CGSortExtended.h>
#include <CG/CGState.h>
#include <CG/CGStop.h>
#include <CG/CGStruct.h>
#include <CG/CGSynonym.h>
#include <CG/CGSyntype.h>
#include <CG/CGSystem.h>
#include <CG/CGTask.h>
#include <CG/CGTimer.h>
#include <CG/CGTransition.h>
#include <CG/CGUpdate.h>
#include <CG/CGVariable.h>
#include <CG/CGVariableAccess.h>
#include <CG/CGVariableAccessField.h>
#include <CG/CGVariableAccessIndex.h>
#include <CG/CGWriter.h>

#define NewAssert new CGAssert
#define NewAtom new CGAtom
#define NewActualParam new CGActualParam
#define NewBlock new CGBlock
#define NewBlockSubstructure new CGBlockSubstructure
#define NewCall new CGCall
#define NewClear new CGClear
#define NewCreate new CGCreate
#define NewDecision new CGDecision
#define NewExpression new CGExpression
#define NewFormalParam new CGFormalParam
#define NewGenerator new CGGenerator
#define NewInput new CGInput
#define NewInputSignal new CGInputSignal
#define NewInputTimerSignal new CGInputTimerSignal
#define NewJoin new CGJoin
#define NewMachine new CGMachine
#define NewMachineService new CGMachineService
#define NewMachineServiceSpeed new CGMachineServiceSpeed
#define NewNextState new CGNextState
#define NewOperandConstant new CGOperandConstant
#define NewOperandExpression new CGOperandExpression
#define NewOperandLiteral new CGOperandLiteral
#define NewOperandMachineService new CGOperandMachineService
#define NewOperandOperator new CGOperandOperator
#define NewOperandProcedureCall new CGOperandProcedureCall
#define NewOperandProcessAccess new CGOperandProcessAccess
#define NewOperandSignal new CGOperandSignal
#define NewOperandState new CGOperandState
#define NewOperandSensor new CGOperandSensor
#define NewOperandSynonym new CGOperandSynonym
#define NewOperandVariableAccess new CGOperandVariableAccess
#define NewOperator new CGOperator
#define NewOutput new CGOutput
#define NewProcedure new CGProcedure
#define NewProcess new CGProcess
#define NewProcessAccess new CGProcessAccess
#define NewRequest new CGRequest
#define NewReset new CGReset
#define NewReturn new CGReturn
#define NewSet new CGSet
#define NewSensor new CGSensor
#define NewSensorProcess new CGSensorProcess
#define NewSensorMachineService new CGSensorMachineService
#define NewSensorSignal new CGSensorSignal
#define NewSensorState new CGSensorState
#define NewSignal new CGSignal
#define NewSort new CGSort
#define NewSortExtended new CGSortExtended
#define NewState new CGState
#define NewStop new CGStop
#define NewStruct new CGStruct
#define NewSynonym new CGSynonym
#define NewSyntype new CGSyntype
#define NewSystem new CGSystem
#define NewTask new CGTask
#define NewTimer new CGTimer
#define NewTransition new CGTransition
#define NewUpdate new CGUpdate
#define NewVariable new CGVariable
#define NewVariableAccess new CGVariableAccess
#define NewVariableAccessField new CGVariableAccessField
#define NewVariableAccessIndex new CGVariableAccessIndex
