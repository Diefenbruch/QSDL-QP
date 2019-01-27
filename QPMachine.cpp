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
| QPMachine     |   QPMachine.cpp   | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

#ifdef USE_PRAGMA
#pragma interface
#endif

#include <stdio.h>

#include <DS/DSRef.h>
#include <DS/DSMachine.h>
#include <DS/DSString.h>

#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

extern DSObjectRefStack p_stack;
extern DSStringList    *p_name_list;

DSMachineRefList p_machine_ref_list;

extern "C" {

#include "QPError.h"

void machine_reference_1(const char* name)
{
  DSMachine *p_machine;

  assert(name);

#ifdef DEBUG
  qpDebugLog << "machine_reference_1: " << name;
  qpDebugLog << " (machine name + append ref list)" << endl;
#endif

  assert(p_stack.Top());

  p_machine = NewMachine((DSObject*)p_stack.Top(),
                         name);  // Anlegen + Einfuegen
  assert(p_machine);

  assert(p_machine_ref_list.Append(p_machine) == DS_OK);
}

void machine_definition_1(const char* name)
{
  DSMachine *p_machine;
  DSString   p_name(name);
  DSString  *ref_name;
  DSResult   status;
  char       str[120];

  assert(name);

  if (p_stack.Top())  // Maschine innerhalb der Hierarchie ?
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_1: " << name;
    qpDebugLog << " (machine name + push machine)" << endl;
#endif

    p_machine = NewMachine((DSObject*)p_stack.Top(),
                           name);  // Anlegen + Einfuegen
    assert(p_machine);
  }
  else  // referenzierter Maschine ausserhalb der Hierarchie !
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_1 (referenced): " << name;
    qpDebugLog << " (machine name + push machine)" << endl;
#endif

    p_machine = NULL;
    for (status = p_machine_ref_list.MoveFirst();
         status == DS_OK;
         status = p_machine_ref_list.MoveNext())
    {
      p_machine = (DSMachine*)p_machine_ref_list.GetCurrentData();
      assert(p_machine);
      ref_name = p_machine->GetName();
      assert(ref_name);
      if (*ref_name == p_name) // Referenz gefunden?
      {
        p_machine_ref_list.DeleteElement();
        break;
      }       
      p_machine = NULL;
    }
    if (p_machine == NULL)
    {
      sprintf(str, "Undefined machine '%s'.\n", name);
      yyerror(str);
      return;
    }
  }
  assert(p_stack.Push((DSObjectRef)p_machine) == DS_OK);
}

void machine_definition_2(void)
{
  DSExpression *p_expression;
  DSMachine    *p_machine;

  assert(p_stack.Top());

  if (p_stack.Top()->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_2 (set server number)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert(p_stack.Top()->GetType() == DS_MACHINE);

    p_machine = (DSMachine*)p_stack.Top();
    assert(p_machine);
    p_machine->SetNumberOfServers(p_expression);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "state_3 (no server number given)" << endl;
#endif

    assert(p_stack.Top()->GetType() == DS_MACHINE);
  }
}

void machine_definition_3(void)
{
  DSExpression *p_expression;
  DSMachine    *p_machine;

  assert(p_stack.Top());

  if (p_stack.Top()->GetType() == DS_EXPRESSION)
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_3 (set discipline)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_expression);
    assert(p_stack.Pop());
    assert(p_stack.Top()->GetType() == DS_MACHINE);

    p_machine = (DSMachine*)p_stack.Top();
    assert(p_machine);
    p_machine->SetDiscipline(p_expression);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_3 (no discipline given)" << endl;
#endif

    assert(p_stack.Top()->GetType() == DS_MACHINE);
  }
}

void machine_definition_4(const char* name)
{
  DSMachine * p_machine;
  char        str[120];
  
  assert(p_stack.Top());

  assert(p_stack.Top()->GetType() == DS_MACHINE);

  p_machine = (DSMachine *)p_stack.Top();

  if (name)
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_3: " << name;
    qpDebugLog << " (check name + pop machine)" << endl;
#endif

    assert(p_machine->GetName());
    
    if (*p_machine->GetName() != name)
    {
      sprintf(str, "Wrong machine name '%s'!", name);
      yyerror(str);
    }
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_3 (pop machine)" << endl;
#endif
  }

  assert(p_stack.Pop());  /* Eingefuegt ist bereits, nur vom Stack entfernen */
}

void machservice_name_speed_list_item_1(const char *name)
{
  DSExpression          * p_expression;
  DSMachine             * p_machine;
  DSMachineServiceRef     p_machineservice_ref;
  DSMachineServiceSpeed * p_machineservice_speed;
  char                    str[120];

  assert(p_stack.Top());

  if (p_stack.Top()->GetType() == DS_EXPRESSION)
  {
    assert(name);

#ifdef DEBUG
    qpDebugLog << "machservice_name_speed_list_item_1: " << name;
    qpDebugLog << " (set service speed)" << endl;
#endif

    p_expression = (DSExpression *)p_stack.Top();
    assert(p_stack.Pop());
    assert(p_stack.Top()->GetType() == DS_MACHINE);

    p_machine = (DSMachine*)p_stack.Top();
    assert(p_machine);

    p_machineservice_ref = p_machine->GetMachineServiceRefByName(name);
    if (p_machineservice_ref == NULL)
    {
      sprintf(str, "Undefined machineservice '%s'.\n", name);
      yyerror(str);
      return;
    }
    p_machineservice_speed = NewMachineServiceSpeed(p_machine,
                                                    p_machineservice_ref,
                                                    p_expression);
    assert(p_machineservice_speed);
  }
  else
  {
#ifdef DEBUG
    qpDebugLog << "machine_definition_3 (no discipline given)" << endl;
#endif

    assert(p_stack.Top()->GetType() == DS_MACHINE);
  }
}

} // extern "C"
