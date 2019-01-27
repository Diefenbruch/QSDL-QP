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
| QPExpression  |   QPExpression.cpp| 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************/
/*  Include-Dateien                                                         */
/****************************************************************************/

#include <stdio.h>
#include <string.h>

#include <DS/DSBasicTypes.h>
#include <DS/DSString.h>
#include <DS/DSSystem.h>
#include <DS/DSRef.h>
#include <DS/DSObject.h>
#include <DS/DSExpression.h>
#include <DS/DSOperandExpression.h>
#include <DS/DSOperandConstant.h>
#include <DS/DSOperandSensor.h>
#include <DS/DSOperandSynonym.h>
#include <DS/DSOperandVariableAccess.h>
#include <DS/DSOperandLiteral.h>
#include <DS/DSOperandOperator.h>  // ADT-Operatoren
#include <DS/DSVariableAccess.h>
#include <DS/DSVariableAccessElem.h>
#include <DS/DSVariableAccessIndex.h>
#include <DS/DSVariableAccessField.h>
#include <DS/DSGenerator.h>
#include <DS/DSStruct.h>
#include <DS/DSNameSort.h>
#include <DS/DSActualParam.h>
#include <DS/DSSynonym.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************/
/*  Externe Variablen                                                       */
/****************************************************************************/

extern DSObjectRefStack p_stack;
extern int line_count;
extern DSSystem *p_system;
extern DSObject *p_scope_object;

/****************************************************************************/
/*  Globale Variablen                                                       */
/****************************************************************************/

DSObjectRefStack p_indexed_expression_stack;

typedef DSOperatorIndex OperatorMatrix[DS_SORT_ILLEGAL][DS_SORT_ILLEGAL];

OperatorMatrix PlusOperator =
{
/********************************************************************************************************************/
/*   "+"            Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_INTEGER, DS_SORT_REAL,    DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_INTEGER, DS_SORT_INTEGER, DS_SORT_REAL,    DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_TIME,     DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_TIME,    DS_SORT_DURATION, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL}
};

OperatorMatrix MinusOperator =
{
/********************************************************************************************************************/
/*    "-"           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_INTEGER, DS_SORT_REAL,    DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_INTEGER, DS_SORT_INTEGER, DS_SORT_REAL,    DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_DURATION, DS_SORT_TIME,     DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_DURATION, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL}
};

OperatorMatrix MultOperator =
{
/********************************************************************************************************************/
/*    "*"           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_INTEGER, DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_INTEGER, DS_SORT_INTEGER, DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_DURATION, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_DURATION, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL}
};

OperatorMatrix DivOperator =
{
/********************************************************************************************************************/
/*    "/"           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_INTEGER, DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_INTEGER, DS_SORT_INTEGER, DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_REAL,    DS_SORT_REAL,    DS_SORT_REAL,     DS_SORT_ILLEGAL, DS_SORT_DURATION, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_DURATION, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL, DS_SORT_ILLEGAL,  DS_SORT_ILLEGAL}
};

OperatorMatrix EqualOperator =
{
/********************************************************************************************************************/
/*    "="           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix NotEqualOperator =
{
/********************************************************************************************************************/
/*    "/="          Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix GreaterOperator =
{
/********************************************************************************************************************/
/*    ">"           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix GreaterEqualOperator =
{
/********************************************************************************************************************/
/*    ">="          Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix LessOperator =
{
/********************************************************************************************************************/
/*    "<"           Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix LessEqualOperator =
{
/********************************************************************************************************************/
/*    "<="          Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_BOOLEAN, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix AndOperator =
{
/********************************************************************************************************************/
/*    "And"         Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix OrOperator =
{
/********************************************************************************************************************/
/*    "OR"          Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix XorOperator =
{
/********************************************************************************************************************/
/*    "XOR"         Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_BOOLEAN}
};

OperatorMatrix ModOperator =
{
/********************************************************************************************************************/
/*    "MOD"         Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_ILLEGAL, DS_SORT_INTEGER, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL}
};

OperatorMatrix RemOperator =
{
/********************************************************************************************************************/
/*    "REM"         Natural            Integer         Real              Time              Duration         Boolean */
/********************************************************************************************************************/
/* Natural  */  {DS_SORT_NATURAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Integer  */  {DS_SORT_ILLEGAL, DS_SORT_INTEGER, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Real     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Time     */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Duration */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL},
/* Boolean  */  {DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL, DS_SORT_ILLEGAL}
};

const char *SortNames[DS_SORT_ILLEGAL] =
{
  DS_SORT_NAME_NATURAL,
  DS_SORT_NAME_INTEGER,
  DS_SORT_NAME_REAL,
  DS_SORT_NAME_TIME,
  DS_SORT_NAME_DURATION,
  DS_SORT_NAME_BOOLEAN
};

extern "C" {

/****************************************************************************/
/*  Prototypen                                                              */
/****************************************************************************/

DSSortRef indexed_primary_variable(DSOperand *, DSExpressionRefList *);
DSSortRef indexed_primary_process(DSOperand *, DSExpressionRefList *);
void indexed_primary_operator(DSOperand *, DSExpressionRefList *);

#include "QPError.h"

DSOperatorIndex GetIDFromSort(DSSortRef p_sort)
{
  int i;

  for (i = 0;
       i < DS_SORT_ILLEGAL;
       i++)
  {
    if (!strcmp(p_sort->GetName()->GetString(), SortNames[i]))
    {
      return (DSOperatorIndex)i;
		}
	}
  return DS_SORT_ILLEGAL;
}

DSSortRef check_compatibility(DSSortRef p_sort1,
                              DSSortRef p_sort2,
                              DSExpressionOperator opt)
{
  char str[120];
  int id1, id2, result_id;
  DSSortRef result_sort;

  if (p_sort1 == NULL)
  {
    return p_sort2;
  }

  if (p_sort2 == NULL)
  {
    return p_sort1;
  }

  id1 = GetIDFromSort(p_sort1);
  id2 = GetIDFromSort(p_sort2);

  if (id1 == DS_SORT_ILLEGAL &&
      id2 == DS_SORT_ILLEGAL)  // beide Sorten keine "Basissorte"?
  {
    if (p_sort1 == p_sort2) return p_sort1;  // wenn gleich dann OK
#ifdef DEBUG
    sprintf(str,
            "Incompatible operand types for operation (%s, %s)\n",
            p_sort1->GetName()->GetString(),
            p_sort2->GetName()->GetString());
    yywarning(str);
#endif
    return NULL;                             // ansonsten Fehler!
	}

  if (id1 == DS_SORT_ILLEGAL)    // bei Verknuepfungen von Basissorten mit
  {                              // "nicht"-Basissorten: Ergebnis = "nicht"-Basissorte
    return p_sort1;
	}

  if (id2 == DS_SORT_ILLEGAL)
  {
    return p_sort2;
	}

  switch(opt)
  {
    case DS_OPT_ADDITION:
      result_id = PlusOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " + ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '+' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_SUBTRACTION:
      result_id = MinusOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " - ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '-' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
	    }
      break;
    case DS_OPT_MULTIPLICATION:
      result_id = MultOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " * ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '*' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_DIVISION:
      result_id = DivOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " / ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '/' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
	    }
      break;
    case DS_OPT_EQUAL:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " = ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '=' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
	    }
      break;
    case DS_OPT_NOT_EQUAL:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " /= ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '/=' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_GREATER:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " > ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '>' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_GREATER_EQUAL:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " >= ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '>=' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_LESS:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " < ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '<' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_LESS_EQUAL:
      result_id = EqualOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " <= ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation '<=' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
	    }
      break;
    case DS_OPT_AND:
      result_id = AndOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " AND ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation AND (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_OR:
      result_id = OrOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " OR ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation OR (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_XOR:
      result_id = XorOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " XOR ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation XOR (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_MOD:
      result_id = ModOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " MOD ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation 'MOD' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    case DS_OPT_REM:
      result_id = RemOperator[id1][id2];
      if (result_id != DS_SORT_ILLEGAL)
      {
#ifdef DEBUG
        qpDebugLog << "OPERATION: " << SortNames[id1] << " REM ";
        qpDebugLog << SortNames[id2] << " -> " << SortNames[result_id] << endl;
#endif
      }
      else
      {
        sprintf(str,
                "Incompatible operand types for operation 'MOD' (%s, %s)\n",
                p_sort1->GetName()->GetString(),
                p_sort2->GetName()->GetString());
        yywarning(str);
        return NULL;
      }
      break;
    default:
      result_id = DS_SORT_ILLEGAL;
      sprintf(str,
              "Unkown operation (%s, %s)\n",
              p_sort1->GetName()->GetString(),
              p_sort2->GetName()->GetString());
      yyerror(str);
      return NULL;
      break;
  }
  result_sort = p_sort1->GetSortRefByName(SortNames[result_id]);
  assert(result_sort);
  return result_sort;
}

void opt_expression_1(void)
{
  DSExpression     *p_expression;

#ifdef DEBUG
  qpDebugLog << "opt_expression_1 (empty expression)" << endl;
#endif

  // NULL bedeutet Expression wurde ausgelassen!

  p_expression = NewExpression(NULL);
  assert(p_expression);

  assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

void operand_binary(int opt)
{
  DSExpression  *p_expression1, *p_expression2;
  DSOperand     *p_operand1, *p_operand2;
  DSExpression  *p_expression;
  DSSortRef      p_expression_sort_ref = NULL;
  DSSortRef      p_sort_ref1, p_sort_ref2;

#ifdef DEBUG
  qpDebugLog << "operand_binary: " << opt;
  qpDebugLog << " (pop 2 expressions + push expression)" << endl;
#endif

  assert((DSExpressionOperator)opt != DS_OPT_NONE);
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression2 = (DSExpression*)p_stack.Top();
  assert(p_expression2);

  assert(p_stack.Pop());    // Expression vom Stack entfernen
  assert(p_stack.Top());
  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression1 = (DSExpression*)p_stack.Top();
  assert(p_expression1);

  assert(p_stack.Pop());    // Expression vom Stack entfernen

  if (p_expression1->GetOperator() == DS_OPT_NONE) // Blatt im Expression-Baum?
  {
    p_operand1 = p_expression1->GetOperand1();
    if (p_operand1) // im Fehlerfall (z.B. undefinierte Variable) nicht gegeben!
    {
      p_operand1->SetParent(NULL);
    }
	}
  else  // kein Blatt, daher Expression erzeugen:
  {
    p_operand1 = NewOperandExpression(NULL, p_expression1);
    assert(p_operand1);
	}

  if (p_expression2->GetOperator() == DS_OPT_NONE) // Blatt im Expression-Baum?
  {
    p_operand2 = p_expression2->GetOperand1();
    if (p_operand2) // im Fehlerfall (z.B. undefinierte Variable) nicht gegeben!
    {
      p_operand2->SetParent(NULL);
    }
	}
  else  // kein Blatt, daher Expression erzeugen:
  {
    p_operand2 = NewOperandExpression(NULL, p_expression2);
    assert(p_operand2);
	}

  p_sort_ref1 = p_expression1->GetSortRef();
  p_sort_ref2 = p_expression2->GetSortRef();

  p_expression_sort_ref = check_compatibility(p_sort_ref1,
                                              p_sort_ref2,
                                              (DSExpressionOperator)opt);
  p_expression = NewExpression(NULL,
                               (DSOperand*)p_operand1,
                               (DSExpressionOperator)opt,
                               (DSOperand*)p_operand2,
                               p_expression_sort_ref);
  assert(p_expression);

  assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

void operand_unary(int opt)
{
  DSExpression *p_expression;
  DSExpression *p_new_expression;
  DSOperandExpression *p_operand;

  if ((DSExpressionOperator)opt == DS_OPT_NONE) return;

#ifdef DEBUG
  qpDebugLog << "operand_unary: " << opt << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);

  p_expression = (DSExpression*)p_stack.Top();
  assert(p_expression);

  if (p_expression->GetOperator() == DS_OPT_NONE)
  {
    p_expression->SetOperator((DSExpressionOperator)opt);
  }
  else // neue Expression aus alter Expression aufbauen
  {
    assert(p_stack.Pop());    // alte Expression vom Stack entfernen

    p_operand = NewOperandExpression(NULL, p_expression);
    assert(p_operand);
    p_new_expression = NewExpression(NULL, p_operand,
                                     (DSExpressionOperator)opt, (DSOperand *)NULL,
                                     p_expression->GetSortRefByName(DS_SORT_NAME_BOOLEAN));
    assert(p_new_expression);
  
    assert(p_stack.Push((DSObjectRef)p_new_expression) == DS_OK);
                              // neue Expression auf den Stack legen
  }
}

//
// wichtigste Methode: ist fuer das Aufloesen der Atome
//                     einer Expression zustaendig:
//
void primary_1(const char *name)
{
  DSObject           *p_object = NULL;
  DSExpression       *p_expression;
  DSVariableRef       p_variable_ref;
  DSSensorRef         p_sensor_ref;
  DSSignalRef         p_signal_ref;
  DSStateRef          p_state_ref;
  DSMachineServiceRef p_machine_service_ref;
  DSProcessRef        p_process_ref;
  DSOperatorRef       p_operator_ref;
  DSVariableAccess   *p_variable_access;
  DSProcessAccess    *p_process_access;
  DSSortRef           p_sort_ref;
  DSSynonym          *p_synonym;
  DSOperand          *p_operand = NULL;
  DSString           *p_identifier;
  DSSortRef           p_expression_sort_ref = NULL;
  DSResult            status;
  char                str[120];

  assert(name);

  // Hilfsvariable anlegen:
  p_identifier = new DSString(name);
  assert(p_identifier);

  // nach einem geeigneten Objekt auf
  // dem Stack gesucht werden (System, Process oder
  // Procedure), bei dem die Suche nach Variablen-
  // Synonym- oder Literal-Deklarationen beginnen kann.
  // (Das Top-Element des Stacks kann z. B. DSExpression
  // sein (ohne parent), daher muss die Suche bei
  // einem Prozess oder einer Prozedur beginnen!)

  if (p_scope_object)
  {
    p_object = p_scope_object;
    p_scope_object = NULL;
  }
  else
  {
    for (status = p_stack.MoveFirst();
         status == DS_OK;
         status = p_stack.MoveNext())
    {
      p_object = (DSObject*)p_stack.GetCurrentData();
      assert(p_object);
      if (p_object->GetType() == DS_SYSTEM ||
          p_object->GetType() == DS_BLOCK ||
          p_object->GetType() == DS_PROCEDURE ||
          p_object->GetType() == DS_PROCESS)
      {
        break;
      }
      p_object = NULL;
    }
  }
  if (!p_object) p_object = p_system;

  // Im folgenden wird getestet um welchen Identifier-Typ es sich handelt:
  // 1. Natural-Konstante
  // 2. Real-Konstante
  // 3. Variable
  // 4. Synonym
  // 5. Literal
  // 6. Operator
  // 7. Sensor
  // 8. Signal name (in Sensor-Operatoren moeglich)
  // 9. Machine service name (in Sensor-Operatoren moeglich)
  // 10. Process name (in Sensor-Operatoren moeglich)
  // 11. State name (in Sensor-Operatoren moeglich)

  // Testen, ob es sich um eine Natural-Konstante handelt:
  if (p_identifier->IsNatural())
  {
#ifdef DEBUG
    qpDebugLog << "primary_1: " << name;
    qpDebugLog << " (operand integer + push expression)" << endl;
#endif
    p_operand = NewOperandConstant(NULL, name, DS_TRUE);
    assert(p_operand);
  }

  // Testen, ob es sich um eine Real-Konstante handelt:
  if (!p_operand)
  {
    if (p_identifier->IsNumeric())
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand real + push expression)" << endl;
#endif

      p_operand = NewOperandConstant(NULL, name, DS_TRUE);
      assert(p_operand);
    }
  }

  // Hilfsvariable freigeben:
  delete p_identifier;
  p_identifier = NULL;

  // Testen, ob es sich um eine Variable handelt:
  if (!p_operand)
  {
    p_variable_ref = p_object->GetVariableRefByName(name);

    if (p_variable_ref) // Variable gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand variable + push expression)" << endl;
#endif

      p_variable_access = NewVariableAccess(NULL, p_variable_ref);
      assert(p_variable_access);
      p_operand = NewOperandVariableAccess(NULL, p_variable_access);
      assert(p_operand);
      p_expression_sort_ref = p_variable_ref->GetSortRef();
      assert(p_expression_sort_ref);
    }
  }

  // Testen, ob es sich um ein Synonym handelt:
  if (!p_operand)
  {
    p_sort_ref = p_object->GetSortRefByName(name);
    if (p_sort_ref) // Sorte gefunden?
    {
      if (p_sort_ref->GetTag() == DS_SORT_SYNONYM) // ist es auch ein Synonym?
      {
#ifdef DEBUG
        qpDebugLog << "primary_1: " << name;
        qpDebugLog << " (operand synonym + push expression)" << endl;
#endif

        p_synonym = (DSSynonym*)p_sort_ref;
        p_operand = NewOperandSynonym(NULL, p_synonym);
        assert(p_operand);
        p_expression_sort_ref = p_synonym->GetSortRef();
      } // richtige Sorte ?
    } // Sorte gefunden ?
  }

  // Testen, ob es sich um ein Literal handelt:
  if (!p_operand)
  {
    p_sort_ref = p_object->GetSortRefByLiteralName(name);
    if (p_sort_ref) // Sorte gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand literal + push expression)" << endl;
#endif

      p_operand = NewOperandLiteral(NULL, name, p_sort_ref);
      assert(p_operand);
      p_expression_sort_ref = p_sort_ref;
    } // Sorte gefunden ?
  }

  // Testen, ob es sich um ein Operator handelt:
  if (!p_operand)
  {
    // Zunaest einmal irgendeinen Operator mit diesem Namen
    // suchen; eine genauere Ueberpruefung findet nach Parsen
    // der aktuellen Parameter in der Funktion indexed_primary_operator()
    // statt (s.u.):
    p_operator_ref = p_object->GetOperatorRefByName(name);
    if (p_operator_ref) // Operator gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand operator + push expression)" << endl;
#endif

      p_operand = NewOperandOperator(NULL, p_operator_ref);
      assert(p_operand);
      p_expression_sort_ref = p_operator_ref->GetResultSortRef();
    } // Sorte gefunden ?
    else // Testen ob der Name + '!' als Operator existiert.
         // Ist z.B. bei 'duration!' der Fall. Das Ausrufungszeichen
         // steht aber nicht in 'name' da es erst von der Regel
         // 'indexed_primary' erkannt wird (s. QSDL92.y).
         // Daher Hilfsnamen = 'name' + '!' verwenden:
    {
      strcpy(str, name);
      strcat(str, "!");
      p_operator_ref = p_object->GetOperatorRefByName(str);
      if (p_operator_ref) // Operator gefunden?
      {
#ifdef DEBUG
        qpDebugLog << "primary_1: " << str;
        qpDebugLog << " (operand operator + push expression)" << endl;
#endif
        p_operand = NewOperandOperator(NULL, p_operator_ref);
        assert(p_operand);
        p_expression_sort_ref = p_operator_ref->GetResultSortRef();
      } // Sorte gefunden ?
    }
  }

  // Testen, ob es sich um einen Sensor handelt:
  if (!p_operand)
  {
    p_sensor_ref = p_object->GetSensorRefByName(name);

    if (p_sensor_ref) // Sensor gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand sensor + push expression)" << endl;
#endif

      p_operand = NewOperandSensor(NULL, p_sensor_ref);
      assert(p_operand);
      p_expression_sort_ref = p_sensor_ref->GetSortRef();
      assert(p_expression_sort_ref);
    }
  }

  // Testen, ob es sich um ein Signal handelt (bei Sensorzugriff moeglich):
  if (!p_operand)
  {
    p_signal_ref = p_object->GetSignalRefByName(name);

    if (p_signal_ref) // Signal gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand signal + push expression)" << endl;
#endif

      p_operand = NewOperandSignal(NULL, p_signal_ref);
      assert(p_operand);
      p_expression_sort_ref = NULL;
    }
  }

  // Testen, ob es sich um einen Dienst handelt (bei Sensorzugriff moeglich):
  if (!p_operand)
  {
    p_machine_service_ref = p_object->GetMachineServiceRefByName(name);

    if (p_machine_service_ref) // Dienst gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand machine service + push expression)" << endl;
#endif

      p_operand = NewOperandMachineService(NULL, p_machine_service_ref);
      assert(p_operand);
      p_expression_sort_ref = NULL;
    }
  }

  // Testen, ob es sich um ein Prozess handelt (bei Sensorzugriff moeglich):
  if (!p_operand)
  {
    p_process_ref = p_object->GetProcessRefByName(name);

    if (p_process_ref) // Process gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand process + push expression)" << endl;
#endif

      p_process_access = NewProcessAccess(NULL, p_process_ref);
      assert(p_process_access);
      p_operand = NewOperandProcessAccess(NULL, p_process_access);
      assert(p_operand);

      p_expression_sort_ref = NULL;
    }
  }

  // Testen, ob es sich um einen Zustand handelt (bei Sensorzugriff moeglich):
  if (!p_operand)
  {
    p_state_ref = p_object->GetStateRefByName(name);

    if (p_state_ref) // Process gefunden?
    {
#ifdef DEBUG
      qpDebugLog << "primary_1: " << name;
      qpDebugLog << " (operand state + push expression)" << endl;
#endif

      p_operand = NewOperandState(NULL, p_state_ref);
      assert(p_operand);
      p_expression_sort_ref = NULL;
    }
  }

  if (!p_operand)
  {
    sprintf(str, "Undefined identifier '%s' in expression.\n", name);
    yyerror(str);
  }

  p_expression = NewExpression(NULL,
                               p_operand,  // Anlegen + Einfuegen
                               DS_OPT_NONE,
                               NULL,
                               p_expression_sort_ref);
  assert(p_expression);

  assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

void primary_2(const char *name) // Charstring-Konstante!!!
{
  DSSortRef          p_sort_ref;
  DSOperandConstant *p_operand = NULL;
  DSExpression      *p_expression;
  DSResult           status;
  DSObject          *p_object = NULL;

  assert(name);

#ifdef DEBUG
    qpDebugLog << "primary_2: " << name;
    qpDebugLog << " (operand constant (charstring) + push expression)" << endl;
#endif

  // nach einem geeigneten Objekt auf
  // dem Stack gesucht werden (System, Process oder
  // Procedure), bei dem die Suche nach Variablen-
  // Synonym- oder Literal-Deklarationen beginnen kann.
  // (Das Top-Element des Stacks kann z. B. DSExpression
  // sein (ohne parent), daher muss die Suche bei
  // einem Prozess oder einer Prozedur beginnen!)

  for (status = p_stack.MoveFirst();
       status == DS_OK;
       status = p_stack.MoveNext())
  {
    p_object = (DSObject*)p_stack.GetCurrentData();
    assert(p_object);
    if (p_object->GetType() == DS_SYSTEM ||
        p_object->GetType() == DS_BLOCK ||
        p_object->GetType() == DS_PROCEDURE ||
        p_object->GetType() == DS_PROCESS)
    {
      break;
    }
    p_object = NULL;
  }
  if (!p_object) p_object = p_system;

  p_operand = NewOperandConstant(NULL, name, DS_FALSE);
  assert(p_operand);

  p_sort_ref = p_object->GetSortRefByName(DS_SORT_NAME_CHARSTRING);
  assert(p_sort_ref);

  p_expression = NewExpression(NULL,
                               p_operand,  // Anlegen + Einfuegen
                               DS_OPT_NONE,
                               NULL,
                               p_sort_ref);
  assert(p_expression);

  assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

void indexed_primary_1(void)  // wird nach '(' aufgerufen!
{
  DSExpression    *p_expression;
  DSOperand       *p_operand;

#ifdef DEBUG
  qpDebugLog << "indexed_primary_1 (push indexed expression on index-stack)" << endl;
#endif

  assert(p_stack.Top());

  assert((p_stack.Top())->GetType() == DS_EXPRESSION);  

  p_expression = (DSExpression *)p_stack.Top();
  assert(p_expression);
  p_operand = p_expression->GetOperand1();
  if (p_operand) // bei Syntax-Fehlern eventuell NULL
  {
    assert(p_operand->GetTag() == DS_OPN_VARIABLE_ACCESS || // nur hinter Array-Var.
           p_operand->GetTag() == DS_OPN_OPERATOR ||        // oder Operatoren folgt
           p_operand->GetTag() == DS_OPN_PROCESS_ACCESS);   // eine Liste von Expr.!
  }
  assert(p_indexed_expression_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

void indexed_primary_2(void)    // wird nach ')' aufgerufen!
{
  DSExpression           *p_expression;
  DSExpressionRefList    *p_expression_ref_list;
  DSOperand              *p_operand;
  DSExpressionOperandTag  p_operand_tag;
  DSSortRef               p_sort_ref;

  assert(p_stack.Top());

  p_expression_ref_list = new DSExpressionRefList;
  assert(p_expression_ref_list);

  // Expressions vom Stack holen, bis das indizierte Element
  // erreicht ist (wurde auf speziellem Stack gemerkt)
  while ((p_stack.Top())->GetType() == DS_EXPRESSION)
  {
    if (p_stack.Top() ==
        p_indexed_expression_stack.Top())   // indiziertes Element?
    {
      break;                                 // dann keinen Index mehr holen!
    }
    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert(p_stack.Top());

    assert(p_expression_ref_list->Prepend(p_expression) == DS_OK);
  }

  p_expression = (DSExpression *)p_stack.Top();
  assert(p_expression);
  p_operand = p_expression->GetOperand1();
  assert(p_expression->GetOperand2() == NULL);

  if (!p_operand) // kann bei unterliegendem Syntax-Error passieren!
  {
    goto bail_out;
  }
  
  p_operand_tag = p_operand->GetTag();

  switch(p_operand_tag)
  {
    case DS_OPN_VARIABLE_ACCESS:
      p_sort_ref = indexed_primary_variable(p_operand, p_expression_ref_list);
      if (p_sort_ref) p_expression->SetSortRef(p_sort_ref);
      break;
    case DS_OPN_OPERATOR:
      indexed_primary_operator(p_operand, p_expression_ref_list);
      break;
    case DS_OPN_PROCESS_ACCESS:
      p_sort_ref = indexed_primary_process(p_operand, p_expression_ref_list);
      if (p_sort_ref) p_expression->SetSortRef(p_sort_ref);
      break;
    default:
      assert(DS_FALSE);
      break;
  }

bail_out:

#ifdef DEBUG
  qpDebugLog << "indexed_primary_2 (pop indexed expression from index-stack)" << endl;
#endif

  assert(p_indexed_expression_stack.Pop());  // Indexliste abgeschlossen:
                                             // oberstes Element vom Stack der
                                             // indizierten Elemente entfernen
                                             
  delete p_expression_ref_list;
}

DSSortRef indexed_primary_variable(DSOperand           *p_operand,
                                   DSExpressionRefList *p_expression_ref_list)
{
  DSExpression            *p_index_expression;
  DSVariableAccessIndex   *p_variable_access_index;
  DSVariableAccessField   *p_variable_access_field;
  DSVariableAccessElem    *p_variable_access_elem;
  DSSortRef                p_sort_ref;
  DSGenerator             *p_generator;
  DSNameSortRef            p_namesort_ref;
  DSOperandVariableAccess *p_operand_variable_access;
  DSVariableAccess        *p_variable_access;
  DSVariableRef            p_variable_ref;
  DSResult                 status;
  char                     str[120];

  assert(p_operand);
  assert(p_expression_ref_list);

  assert(p_operand->GetTag() == DS_OPN_VARIABLE_ACCESS);

  p_operand_variable_access = (DSOperandVariableAccess *)p_operand;

  p_variable_access = p_operand_variable_access->GetVariableAccess();
  assert(p_variable_access);

  p_variable_ref = p_variable_access->GetVariableRef();
  assert (p_variable_ref);

#ifdef DEBUG
  qpDebugLog << "indexed_primary_variable: " << p_variable_ref->GetName();
  qpDebugLog << " (pop + set " << p_expression_ref_list->NumberOfElements();
  qpDebugLog << " index expression(s))" << endl;
#endif

  p_sort_ref = p_variable_ref->GetSortRef();
  assert(p_sort_ref);

  // Die folgende Schleife dereferenziert die Variablensorte
  // soweit bereits Felder geparst wurden:
  for (p_variable_access_elem = p_variable_access->GetFirstElem();
       p_variable_access_elem != NULL;
       p_variable_access_elem = p_variable_access->GetNextElem())
  {
    switch (p_variable_access_elem->GetTag())
    {
      case DS_ACCESS_INDEX:
        assert(p_sort_ref->GetTag() == DS_SORT_GENERATOR);
        p_variable_access_index = (DSVariableAccessIndex*)p_variable_access_elem;
        p_generator = (DSGenerator*)p_sort_ref;
        p_sort_ref = p_generator->GetFirstSortRef();    // Indexsorte
        p_sort_ref = p_generator->GetNextSortRef();     // Elementssorte
        break;
      case DS_ACCESS_FIELD:
        assert(p_sort_ref->GetTag() == DS_SORT_STRUCT);
        p_variable_access_field = (DSVariableAccessField*)p_variable_access_elem;
        p_namesort_ref = p_variable_access_field->GetField();
        p_sort_ref = p_namesort_ref->GetSortRef();
        break;
      default:
        assert(DS_FALSE);
    }
  }

  // p_sort steht jetzt auf der Komponente bei der der Variablen-
  // zugriff mit dem aktuellen Index fortgesetzt wird:
  if (p_sort_ref->GetTag() != DS_SORT_GENERATOR)
  {
    sprintf(str, "Illegal index access of non-generator type '%s'.\n",
            p_sort_ref->GetName()->GetString());
    yyerror(str);
    return NULL;
  }

  for (status = p_expression_ref_list->MoveFirst();
       status == DS_OK;
       status = p_expression_ref_list->MoveNext())
  {
    p_index_expression = (DSExpression*)p_expression_ref_list->GetCurrentData();
    p_variable_access_index = NewVariableAccessIndex(p_variable_access,
                                                     p_index_expression);
    assert(p_variable_access_index);
  }


  p_generator = (DSGenerator*)p_sort_ref;
  p_sort_ref = p_generator->GetFirstSortRef();  //   Indexsorte
  p_sort_ref = p_generator->GetNextSortRef();   //   Elementssorte

  return p_sort_ref;  // aktuelle Sorte des Zugriffs zurueckgeben!
}


void indexed_primary_operator(DSOperand           *p_operand,
                              DSExpressionRefList *p_expression_ref_list)
{
  DSOperatorRef      p_operator_ref, p_new_operator_ref;
  DSOperandOperator *p_operand_operator;
  DSActualParam     *p_actual_param;
  DSResult           status;
  DSSort            *p_sort;
  DSSortRefList     *p_sort_ref_list;
  DSObject          *p_object = NULL;
  char               str[120];

  assert(p_operand);
  assert(p_expression_ref_list);

  p_operand_operator = (DSOperandOperator*)p_operand;

  p_operator_ref = p_operand_operator->GetOperatorRef();
  assert(p_operator_ref);

#ifdef DEBUG
  qpDebugLog << "indexed_primary_operator: " << p_operator_ref->GetName();
  qpDebugLog << " (pop + set " << p_expression_ref_list->NumberOfElements();
  qpDebugLog << " parameter expression(s))" << endl;
#endif

  p_sort_ref_list = new DSSortRefList;
  assert(p_sort_ref_list);

  for (status = p_expression_ref_list->MoveFirst();
       status == DS_OK;
       status = p_expression_ref_list->MoveNext())
  {
    p_actual_param = (DSActualParam*)p_expression_ref_list->GetCurrentData();
    p_operand_operator->InsertActualParam(p_actual_param);    

    p_sort = (DSSort*)p_actual_param->GetSortRef();

    p_sort_ref_list->Append(p_sort);  // Sorten der aktuellen Parameter
                                      // sammeln
  }

  for (status = p_stack.MoveFirst();
       status == DS_OK;
       status = p_stack.MoveNext())
  {
    p_object = (DSObject*)p_stack.GetCurrentData();
    assert(p_object);
    if (p_object->GetType() == DS_SYSTEM ||
        p_object->GetType() == DS_BLOCK ||
        p_object->GetType() == DS_PROCEDURE ||
        p_object->GetType() == DS_PROCESS)
    {
      break;
    }
    p_object = NULL;
  }
  if (!p_object) p_object = p_system;

  // Jetzt wird mit Hilfe der Typen der aktuellen
  // Parameter nochmal ueberprueft, ob die
  // Operatorsorte welche in 'primary_1()'
  // eingetragen wurde auch stimmt:
  p_new_operator_ref =
    p_object->GetOperatorRefByNameAndParamSorts(p_operator_ref->GetName(),
                                                p_sort_ref_list);
  delete p_sort_ref_list;

  if (!p_new_operator_ref)
  {
    sprintf(str, "Wrong types of actual parameters for operator '%s'.\n",
            p_operator_ref->GetName()->GetString());
    yywarning(str);
    return;
  }

  if (p_new_operator_ref != p_operator_ref)
  {
    p_operand_operator->SetOperatorRef(p_new_operator_ref);
  }
}


DSSortRef indexed_primary_process(DSOperand           *p_operand,
                                  DSExpressionRefList *p_expression_ref_list)
{
  DSExpression            *p_index_expression;
  DSOperandProcessAccess  *p_operand_process_access;
  DSProcessAccess         *p_process_access;
  DSProcessRef             p_process_ref;

  assert(p_operand);
  assert(p_expression_ref_list);

  assert(p_operand->GetTag() == DS_OPN_PROCESS_ACCESS);

  p_operand_process_access = (DSOperandProcessAccess *)p_operand;

  p_process_access = p_operand_process_access->GetProcessAccess();
  assert(p_process_access);

  p_process_ref = p_process_access->GetProcessRef();
  assert (p_process_ref);

#ifdef DEBUG
  qpDebugLog << "indexed_primary_process: " << p_process_ref->GetName();
  qpDebugLog << " (pop + set instance id)" << endl;
#endif

  assert(p_expression_ref_list->NumberOfElements() == 1);
  
  p_expression_ref_list->MoveFirst();
  p_index_expression = (DSExpression*)p_expression_ref_list->GetCurrentData();
  
  p_process_access->SetProcessID(p_index_expression);

  return NULL;  // aktuelle Sorte des Zugriffs zurueckgeben!
}


void field_primary_1(const char *field)
{
  DSVariableRef            p_variable_ref;
  DSSensorRef              p_sensor_ref;
  DSProcessRef             p_process_ref;
//  DSSortRef                p_expression_sort_ref = NULL;
  DSVariableAccessElem    *p_variable_access_elem;
//  DSVariableAccessIndex   *p_variable_access_index;
  DSVariableAccessField   *p_variable_access_field;
  DSSortRef                p_sort_ref;
  DSGenerator             *p_generator;
  DSStruct                *p_struct;
  DSNameSortRef            p_namesort_ref;
  DSExpression            *p_expression;
  DSOperand               *p_operand;
  DSOperandVariableAccess *p_operand_variable_access;
  DSVariableAccess        *p_variable_access;
  DSOperandProcessAccess  *p_operand_process_access;
  DSProcessAccess         *p_process_access;
  char                     str[120];

  assert(field);

  assert(p_stack.Top());

  // Die Expression auf dem Stack muss als ersten (und einzigsten)
  // Operanden einen Operanden vom Type 'Variable' enthalten!
  p_expression = (DSExpression *)p_stack.Top();
  assert(p_expression);
  p_operand = p_expression->GetOperand1();
  assert(p_operand);

  if (p_operand->GetTag() == DS_OPN_PROCESS_ACCESS)
  {
    p_operand_process_access = (DSOperandProcessAccess *)p_operand;

    p_process_access = p_operand_process_access->GetProcessAccess();
    assert(p_process_access);

    p_process_ref = p_process_access->GetProcessRef();
    assert (p_process_ref);

    p_variable_access = p_process_access->GetVariableAccess();
    
    if (!p_variable_access)
    {
      p_variable_ref = p_process_ref->GetVariableRefByName(field);

      if (p_variable_ref) // Variable gefunden?
      {
#ifdef DEBUG
        qpDebugLog << "field_primary_1: " << field;
        qpDebugLog << " (set variable access for process " << p_process_ref->GetName();
        qpDebugLog << ")" << endl;
#endif

        p_variable_access = NewVariableAccess(NULL, p_variable_ref);
        assert(p_variable_access);
 
        p_process_access->SetVariableAccess(p_variable_access);

        return;
      }

      p_sensor_ref = p_process_ref->GetSensorRefByName(field);

      if (p_sensor_ref) // Sensor gefunden?
      {
#ifdef DEBUG
        qpDebugLog << "field_primary_1: " << field;
        qpDebugLog << " (set sensor access for process " << p_process_ref->GetName();
        qpDebugLog << ")" << endl;
#endif

        p_process_access->SetSensorRef(p_sensor_ref);
 
        return;
      }
      else
      {
        sprintf(str, "Undefined process component '%s'.\n", field);
        yyerror(str);
        return;
      }
    }
  }
  else
  {
    assert(p_operand->GetTag() == DS_OPN_VARIABLE_ACCESS);

    p_operand_variable_access = (DSOperandVariableAccess *)p_operand;

    p_variable_access = p_operand_variable_access->GetVariableAccess();
    assert(p_variable_access);
  }

  assert(p_variable_access);
    
  p_variable_ref = p_variable_access->GetVariableRef();
  assert (p_variable_ref);

#ifdef DEBUG
  qpDebugLog << "field_primary_1: " << field;
  qpDebugLog << " (insert field for variable " << p_variable_ref->GetName();
  qpDebugLog << ")" << endl;
#endif

  p_sort_ref = p_variable_ref->GetSortRef();

  // Die folgende Schleife dereferenziert die Variablensorte
  // soweit bereits Felder geparst wurden:
  for (p_variable_access_elem = p_variable_access->GetFirstElem();
       p_variable_access_elem != NULL;
       p_variable_access_elem = p_variable_access->GetNextElem())
  {
    assert(p_sort_ref);

    switch (p_variable_access_elem->GetTag())
    {
      case DS_ACCESS_INDEX:
        assert(p_sort_ref->GetTag() == DS_SORT_GENERATOR);
//        p_variable_access_index = (DSVariableAccessIndex*)p_variable_access_elem;
        p_generator = (DSGenerator*)p_sort_ref;
        p_sort_ref = p_generator->GetFirstSortRef();    // Indexsorte
        p_sort_ref = p_generator->GetNextSortRef();     // Elementssorte
        break;
      case DS_ACCESS_FIELD:
        assert(p_sort_ref->GetTag() == DS_SORT_STRUCT);
        p_variable_access_field = (DSVariableAccessField*)p_variable_access_elem;
        p_namesort_ref = p_variable_access_field->GetField();
        p_sort_ref = p_namesort_ref->GetSortRef();
        break;
      default:
        assert(DS_FALSE);
		}
  }

  // p_sort_ref steht jetzt auf der Komponente bei der der Variablen-
  // zugriff mit dem aktuellen Feld fortgesetzt wird:
  if (p_sort_ref->GetTag() != DS_SORT_STRUCT)
  {
    sprintf(str, "Illegal field access of non-struct type '%s'.\n",
            p_sort_ref->GetName()->GetString());
    yyerror(str);
    return;
	}

  p_struct = (DSStruct*)p_sort_ref;

  p_namesort_ref = p_struct->GetField(field);
  if (!p_namesort_ref)
  {
    sprintf(str, "Undefined field '%s' for sort '%s' (variable '%s').\n",
            field, p_sort_ref->GetName()->GetString(),
            p_variable_ref->GetName()->GetString());
    yyerror(str);
    return;
  }

  p_variable_access_field = NewVariableAccessField(p_variable_access, // Anlegen + Einf!
                                                   p_namesort_ref);
  assert(p_variable_access_field);

  // Typ der Expression = Typ des Feldes setzen:
  p_expression->SetSortRef(p_namesort_ref->GetSortRef());
}

// Diese Funktion wird fuer SELF, NOW, PARENT benoetigt:

void constant_expression(const char *token)
{
  DSExpression      *p_expression;
  DSOperandConstant *p_operand_constant;
  DSResult           status;
  DSObject          *p_object = NULL;
  DSSortRef          p_sort_ref = NULL;
  DSSynonym         *p_synonym;
  DSSort            *p_sort;

  assert(token);

#ifdef DEBUG
  qpDebugLog << "constant_expression: " << token;
  qpDebugLog << " (push expression)" << endl;
#endif

  // Es muss nun
  // nach einem geeigneten Objekt auf
  // dem Stack gesucht werden (System, Process oder
  // Procedure), bei dem die Suche nach Variablen-
  // Synonym- oder Literal-Deklarationen beginnen kann.
  // (Das Top-Element des Stacks kann z. B. DSExpression
  // sein (ohne parent), daher muss die Suche bei
  // einem Prozess oder einer Prozedur beginnen!)

  for (status = p_stack.MoveFirst();
       status == DS_OK;
       status = p_stack.MoveNext())
  {
    p_object = (DSObject*)p_stack.GetCurrentData();
    assert(p_object);
    if (p_object->GetType() == DS_SYSTEM ||
        p_object->GetType() == DS_BLOCK ||
        p_object->GetType() == DS_PROCEDURE ||
        p_object->GetType() == DS_PROCESS)
    {
      break;
    }
    p_object = NULL;
  }
  if (!p_object) p_object = p_system;

  if (!strcmp(token, DS_SORT_OPERATOR_NAME_SELF)   || // ist es eine Konstante
      !strcmp(token, DS_SORT_OPERATOR_NAME_PARENT) || // vom Datentyp "PID"?
      !strcmp(token, DS_SORT_OPERATOR_NAME_OFFSPRING) ||
      !strcmp(token, DS_SORT_OPERATOR_NAME_SENDER))
  {
    p_sort_ref = p_object->GetSortRefByName(DS_SORT_NAME_PID);
    assert(p_sort_ref);
  }
  else if (!strcmp(token, DS_SORT_OPERATOR_NAME_NOW))
  {
    p_sort_ref = p_object->GetSortRefByName(DS_SORT_NAME_TIME);
    assert(p_sort_ref);
  }
  else if (!strcmp(token, DS_NAME_EXTERNAL))  // nur bei Synonymen erlaubt!!!
  {
    p_object = (DSObject*)p_stack.Top();
    assert(p_object->GetType() == DS_SORT);
    p_sort = (DSSort*)p_object;
    assert(p_sort->GetTag() == DS_SORT_SYNONYM);
    p_synonym = (DSSynonym*)p_sort;
    p_sort_ref = p_synonym->GetSortRef();
//    assert(p_sort_ref); // bei Synonymen ist die Sorte nur optional!
  }

  p_operand_constant = NewOperandConstant(NULL, token, DS_FALSE);
  assert(p_operand_constant);

  p_expression = NewExpression(NULL,
                               p_operand_constant,
                               DS_OPT_NONE,
                               NULL,
                               p_sort_ref);  // Anlegen + Einfuegen
  assert(p_expression);

  assert(p_stack.Push((DSObjectRef)p_expression) == DS_OK);
}

} // extern "C"
