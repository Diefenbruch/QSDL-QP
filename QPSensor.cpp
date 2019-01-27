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
| QPSensor      |   QPSensor.cpp    | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************
 *  Includes
 ****************************************************************************/

#include <stdio.h>

#include <DS/DSString.h>
#include <DS/DSSensor.h>
#include <DS/DSSensorSignal.h>
#include <DS/DSSensorMachineService.h>
#include <DS/DSSensorProcess.h>
#include <DS/DSSensorState.h>

#include "QPObjects.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************
 *  Externe Variablen
 ****************************************************************************/

extern DSObjectRefStack p_stack;
extern DSStringList    *p_name_list;
extern DSSystem        *p_system;
extern char *sensor_names[];

/****************************************************************************
 *  Globale Variablen
 ****************************************************************************/

DSSensorRefList *p_forward_sensor_list = NULL;
DSStringList    *p_forward_sensor_statename_list = NULL;

extern "C" {

#include "QPError.h"

void sys_sensor_definition_1 (char* sensor_name,
                              DSSensorType sensor_type)
{
  DSSensor* p_sensor = NULL;

#ifdef DEBUG
  qpDebugLog << "sys_sensor_definition_1: " << sensor_name << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());
  assert ((p_stack.Top())->GetType() == DS_SYSTEM ||
          (p_stack.Top())->GetType() == DS_BLOCK ||
          (p_stack.Top())->GetType() == DS_BLOCKSUBSTRUCTURE);
                                                  /* Make sure top element on
                                                     stack is a system, a block
                                                     or a blocksubstructure */
  switch (sensor_type)
  {
    case DS_SENSOR_COUNTER:
    case DS_SENSOR_FREQUENCY:
    case DS_SENSOR_TALLY:
    case DS_SENSOR_SYS_FREQ_SIGNAL:
    case DS_SENSOR_SYS_FREQ_REQUEST:
    case DS_SENSOR_SYS_FREQ_PROCESS_CREATE:
    case DS_SENSOR_SYS_FREQ_PROCESS_STOP:
      p_sensor = NewSensor ((DSObject *)p_stack.Top(),
                            sensor_type, sensor_name);
                                                  /* Create new sensor object. */
      assert (p_sensor);
      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
}

void sys_sensor_definition_2 (char* sensor_name,
                              DSSensorType sensor_type)
{
  DSObject *          p_object = NULL;              /* System/Block containing
                                                     sensor definition. */
  DSProcess *         p_process = NULL;
  DSProcessRefList *  p_process_ref_list;
  DSSensor *          p_sensor = NULL;
  DSSignal *          p_signal = NULL;
  DSSignalRefList *   p_signal_ref_list;
  DSMachineService *  p_machine_service = NULL;
  DSMachineServiceRefList *p_machine_service_ref_list;
  DSString *          p_name;
  char                str[120];
  DSResult            status;

#ifdef DEBUG
  qpDebugLog << "sys_sensor_definition_2: " << sensor_name;
  qpDebugLog << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());
  assert ((p_stack.Top())->GetType() == DS_SYSTEM ||
          (p_stack.Top())->GetType() == DS_BLOCK ||
          (p_stack.Top())->GetType() == DS_BLOCKSUBSTRUCTURE);
                                                  /* Make sure top element on
                                                     stack is a system, a block
                                                     or a blocksubstructure */

  p_object = (DSObject*) p_stack.Top();             /* Retrieve reference to
                                                     system from object stack. */
  switch (sensor_type)
  {
    case DS_SENSOR_SYS_LIFETIME_PROCESS:
    case DS_SENSOR_SYS_COUNT_PROCESS_CREATE:
    case DS_SENSOR_SYS_COUNT_PROCESS_STOP:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_process_ref_list = new DSProcessRefList;
        assert(p_process_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_process = (DSProcess *)p_object->GetProcessRefByName (p_name);
 
          if (!p_process)
          {
            sprintf(str, "Unknown process '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }

          p_process_ref_list->Append(p_process);
        }
        p_sensor = NewSensorProcess (p_object,
                                     sensor_type,
                                     sensor_name,
                                     p_process_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else // no sensor param given !
      {
        p_sensor = NewSensorProcess(p_object,
                                    sensor_type,
                                    sensor_name,     /* Create new sensor object. */
                                    NULL);
        assert (p_sensor);
      }
      break;

    case DS_SENSOR_SYS_COUNT_SIGNAL:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_signal_ref_list = new DSSignalRefList;
        assert(p_signal_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_signal = (DSSignal *)p_object->GetSignalRefByName (p_name);
 
          if (!p_signal)
          {
            sprintf(str, "Unknown signal '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }

          p_signal_ref_list->Append(p_signal);
        }
        p_sensor = NewSensorSignal (p_system,
                                    sensor_type,
                                    sensor_name,
                                    p_signal_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else // no sensor param given !
      {
        p_sensor = NewSensorSignal(p_object,
                                   sensor_type,
                                   sensor_name,     /* Create new sensor object. */
                                   NULL);
        assert (p_sensor);
      }
      break;

    case DS_SENSOR_SYS_COUNT_REQUEST:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_machine_service_ref_list = new DSMachineServiceRefList;
        assert(p_machine_service_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_machine_service = (DSMachineService *)p_object->GetMachineServiceRefByName (p_name);
 
          if (!p_machine_service)
          {
            sprintf(str, "Unknown machine service '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }

          p_machine_service_ref_list->Append(p_machine_service);
        }
        p_sensor = NewSensorMachineService (p_object,
                                            sensor_type,
                                            sensor_name,
                                            p_machine_service_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else // no sensor param given !
      {
        p_sensor = NewSensorMachineService(p_object,
                                           sensor_type,
                                           sensor_name,     /* Create new sensor object. */
                                           NULL);
        assert (p_sensor);
      }
      
      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
  if (p_name_list)
  {
    delete p_name_list;
    p_name_list = NULL;
  }
  free (sensor_name);
}



void pcs_sensor_definition_1 (char*        sensor_name,
                              DSSensorType sensor_type)
{
  DSProcess* p_process = NULL;		   /* Process containing the
            				   sensor definition. */
  DSSensor*  p_sensor = NULL;
  
  
#ifdef DEBUG
  qpDebugLog << "pcs_sensor_definition_1: " << sensor_name;
  qpDebugLog << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());
  assert ((p_stack.Top())->GetType() == DS_PROCESS);
                                                  /* Make sure top element on
                                                     stack is a process. */

  p_process = (DSProcess*) p_stack.Top();            /* Retrieve reference to
                                                     process from object stack. */
  switch (sensor_type)
  {
    case DS_SENSOR_COUNTER:
    case DS_SENSOR_FREQUENCY:
    case DS_SENSOR_TALLY:
    case DS_SENSOR_PCS_FREQ_SIGNAL_RECEIVE:
    case DS_SENSOR_PCS_FREQ_SIGNAL_DROP:
    case DS_SENSOR_PCS_FREQ_SIGNAL_CONSUME:
    case DS_SENSOR_PCS_FREQ_SIGNAL_SAVE:
    case DS_SENSOR_PCS_FREQ_SIGNAL_LOSE:
    case DS_SENSOR_PCS_FREQ_SIGNAL_SEND:
    case DS_SENSOR_PCS_FREQ_REQUEST:
    case DS_SENSOR_PCS_FREQ_STATE:
    case DS_SENSOR_PCS_QUEUE_LENGTH:
    case DS_SENSOR_PCS_QUEUE_CONTENT:
      p_sensor = NewSensor (p_process,
                            sensor_type,
                            sensor_name);          /* Create new sensor object. */
      assert (p_sensor);
      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
}



void pcs_sensor_definition_2 (char*        sensor_name,
                              DSSensorType sensor_type)
{
  DSProcess*          p_process = NULL;              /* Process containing the
                                                     sensor definition. */
  DSSensor*           p_sensor = NULL;
  DSSignalRef         p_signal = NULL;
  DSSignalRefList *   p_signal_ref_list;
  DSMachineServiceRef p_machine_service = NULL;
  DSMachineServiceRefList * p_machine_service_ref_list;
  DSStateRef          p_state = NULL;
  DSString *          p_name;
  char                str[120];
  DSResult            status;
  
#ifdef DEBUG
  qpDebugLog << "pcs_sensor_definition_2: " << sensor_name;
  qpDebugLog << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());  
  assert ((p_stack.Top())->GetType() == DS_PROCESS);
                                                  /* Make sure top element on
                                                     stack is a process. */

  p_process = (DSProcess*) p_stack.Top();            /* Retrieve reference to
                                                     process from object stack. */
  switch (sensor_type)
  {
    case DS_SENSOR_PCS_WAITTIME_SIGNAL:
    case DS_SENSOR_PCS_TRANSMISSIONTIME_SIGNAL:
    case DS_SENSOR_PCS_COUNT_SIGNAL_RECEIVE:
    case DS_SENSOR_PCS_COUNT_SIGNAL_DROP:
    case DS_SENSOR_PCS_COUNT_SIGNAL_CONSUME:
    case DS_SENSOR_PCS_COUNT_SIGNAL_SAVE:
    case DS_SENSOR_PCS_COUNT_SIGNAL_LOSE:
    case DS_SENSOR_PCS_COUNT_SIGNAL_SEND:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_signal_ref_list = new DSSignalRefList;
        assert(p_signal_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_signal = p_process->GetSignalRefByName (p_name);
 
          if (!p_signal)
          {
            sprintf(str, "Unknown signal '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }
          p_signal_ref_list->Append(p_signal);
        }
        p_sensor = NewSensorSignal (p_process,
                                    sensor_type,
                                    sensor_name,
                                    p_signal_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else                                           /* no parameter given! */
      {
        p_sensor = NewSensorSignal (p_process,
                                    sensor_type,
                                    sensor_name,     /* Create new sensor object. */
                                    NULL);
        assert (p_sensor);
      }
      break;

    case DS_SENSOR_PCS_RESPONSETIME_REQUEST:
    case DS_SENSOR_PCS_COUNT_REQUEST:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_machine_service_ref_list = new DSMachineServiceRefList;
        assert(p_machine_service_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_machine_service = (DSMachineService*) p_process->GetMachineServiceRefByName (p_name);
 
          if (!p_machine_service)
          {
            sprintf(str, "Unknown machine service '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }
          p_machine_service_ref_list->Append(p_machine_service);
        }
        p_sensor = NewSensorMachineService(p_process,
                                           sensor_type,
                                           sensor_name,
                                           p_machine_service_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else
      {
        p_sensor = NewSensorMachineService(p_process,
                                           sensor_type,
                                           sensor_name,
                                           NULL);     /* Create new sensor object. */
        assert (p_sensor);
      }      
      break;

    case DS_SENSOR_PCS_FREQ_TRANSITION:
    case DS_SENSOR_PCS_COUNT_TRANSITION:
    case DS_SENSOR_PCS_WAITTIME_STATE:
    case DS_SENSOR_PCS_COUNT_STATE:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_name_list->MoveFirst();
        p_name = p_name_list->GetCurrentData();
        assert(p_name);

        p_state = (DSState*) p_process->GetStateRefByName (p_name);

        p_sensor = NewSensorState (p_process,
                                   sensor_type,
                                   sensor_name,
                                   p_state);   /* Create new sensor object. */
        assert (p_sensor);

        if (!p_state) // Referenz konnte jetzt noch nicht aufgeloest werden
        {             // wird in process_definition_2 (QPProcess.cc) noch
                      // einmal versucht
          if (p_forward_sensor_list == NULL) // 1. Vorwaertsreferenz?
          {
            p_forward_sensor_list = new DSSensorRefList;
            assert(p_forward_sensor_list);
          }
          if (p_forward_sensor_statename_list == NULL) // 1. Vorwaertsreferenz?
          {
            p_forward_sensor_statename_list = new DSStringList;
            assert(p_forward_sensor_statename_list);
          }

          assert(p_forward_sensor_list->Append(p_sensor) == DS_OK);
          assert(p_forward_sensor_statename_list->Append(new DSString(*p_name)) == DS_OK);
        }
      }
      else // no parameter given!
      {
        if (sensor_type == DS_SENSOR_PCS_WAITTIME_STATE)
        {
          p_sensor = NewSensorState (p_process,
                                     sensor_type,
                                     sensor_name,
                                     NULL);         /* Create new sensor object. */
          assert (p_sensor);
        }
        else
        {
          sprintf(str, "Missing state parameter in declaration of sensor '%s'.",
                  sensor_name);
          yyerror (str);                      /* Call error handler. */
          return;
        }
      }

      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
  if (p_name_list)
  {
    delete p_name_list;
    p_name_list = NULL;
  }
  free (sensor_name);
}



void mach_sensor_definition_1 (char*        sensor_name,
                               DSSensorType sensor_type)
{
  DSMachine*         p_machine = NULL;         /* Machine containing the
                                                  sensor definition. */
  DSSensor*          p_sensor = NULL;
  DSExpression *     discipline;
  DSOperandLiteral * operand_literal;
  char               str[120];

#ifdef DEBUG
  qpDebugLog << "mach_sensor_definition_1: " << sensor_name;
  qpDebugLog << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());
  assert ((p_stack.Top())->GetType() == DS_MACHINE);
                                                  /* Make sure top element on
                                                     stack is a machine. */

  p_machine = (DSMachine*) p_stack.Top();           /* Retrieve reference to
                                                     process from object stack. */
  switch (sensor_type)
  {
    case DS_SENSOR_MACH_QUEUE_LENGTH:
    case DS_SENSOR_MACH_QUEUE_CONTENT:
      discipline = p_machine->GetDiscipline();
      if (discipline)  /* discipline already parsed ? */
      {
        assert (discipline->GetOperand1());
        assert (discipline->GetOperand1()->GetTag() == DS_OPN_LITERAL);
        operand_literal = (DSOperandLiteral *)discipline->GetOperand1();
        if (*operand_literal->GetName() == DS_SORT_LITERAL_NAME_PS ||
            *operand_literal->GetName() == DS_SORT_LITERAL_NAME_IS)
        {
          sprintf(str, "Sensor '%s' (%s) is not allowed for this type of machine.",
                  sensor_name, sensor_names[sensor_type]);
          yywarning(str);
          break;
        }
      }
    case DS_SENSOR_COUNTER:
    case DS_SENSOR_FREQUENCY:
    case DS_SENSOR_TALLY:
    case DS_SENSOR_MACH_FREQ_REQUEST:
    case DS_SENSOR_MACH_UTILIZATION:
      p_sensor = NewSensor (p_machine,
                            sensor_type,
                            sensor_name);          /* Create new sensor object. */
      assert (p_sensor);
      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
}



void mach_sensor_definition_2 (char*        sensor_name,
                               DSSensorType sensor_type)
{
  DSMachine*                p_machine = NULL;     /* Machine containing the
                                                     sensor definition. */
  DSSensor*                 p_sensor = NULL;
  DSMachineService*         p_machine_service = NULL;
  DSMachineServiceRefList * p_machine_service_ref_list;
  DSString *                p_name;
  char                      str[120];
  DSResult                  status;
  DSExpression *            discipline;
  DSOperandLiteral *        operand_literal;
  
#ifdef DEBUG
  qpDebugLog << "mach_sensor_definition_2: " << sensor_name;
  qpDebugLog << " " << sensor_type;
  qpDebugLog << " (sensor name + sensor type)" << endl;
#endif

  assert (p_stack.Top());  
  assert ((p_stack.Top())->GetType() == DS_MACHINE);
                                                  /* Make sure top element on
                                                     stack is a machine. */

  p_machine = (DSMachine*) p_stack.Top();           /* Retrieve reference to
                                                     machine from object stack. */
  switch (sensor_type)
  {
    case DS_SENSOR_MACH_WAITTIME_REQUEST:
      discipline = p_machine->GetDiscipline();
      if (discipline)  /* discipline already parsed ? */
      {
        assert (discipline->GetOperand1());
        assert (discipline->GetOperand1()->GetTag() == DS_OPN_LITERAL);
        operand_literal = (DSOperandLiteral *)discipline->GetOperand1();
        if (*operand_literal->GetName() == DS_SORT_LITERAL_NAME_PS ||
            *operand_literal->GetName() == DS_SORT_LITERAL_NAME_IS)
        {
          sprintf(str, "Sensor '%s' (%s) is not allowed for this type of machine.",
                  sensor_name, sensor_names[sensor_type]);
          yywarning(str);
          break;
        }
      }
    case DS_SENSOR_MACH_THROUGHPUT:
    case DS_SENSOR_MACH_SERVICETIME_REQUEST:
    case DS_SENSOR_MACH_COUNT_REQUEST:
      if (p_name_list &&
          !p_name_list->IsEmpty())                 /* parameter given ? */
      {
        p_machine_service_ref_list = new DSMachineServiceRefList;
        assert(p_machine_service_ref_list);

        // Alle Prozessparameter holen und aufloesen:
        for (status = p_name_list->MoveFirst();
             status == DS_OK;    
             status = p_name_list->MoveNext())
        {
          p_name = p_name_list->GetCurrentData();
          p_machine_service = (DSMachineService*) p_machine->GetMachineServiceRefByName (p_name);
 
          if (!p_machine_service)
          {
            sprintf(str, "Unknown machine service '%s' in declaration of sensor '%s'.",
                    p_name->GetString(), sensor_name);
            yyerror (str);                       /* Call error handler. */
            continue;
          }
          p_machine_service_ref_list->Append(p_machine_service);
        }        
        p_sensor = NewSensorMachineService(p_machine,
                                           sensor_type,
                                           sensor_name,
                                           p_machine_service_ref_list); /* Create new sensor object. */
        assert (p_sensor);
      }
      else
      {
        p_sensor = NewSensorMachineService(p_machine,
                                           sensor_type,
                                           sensor_name,
                                           NULL);     /* Create new sensor object. */
        assert (p_sensor);
      }
      
      break;

    default:
      assert (DS_FALSE);                             /* Bail out. */
  }
  if (p_name_list)
  {
    delete p_name_list;
    p_name_list = NULL;
  }
  free (sensor_name);
}


} // extern "C"
