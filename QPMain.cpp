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
| QPMain        |   QPMain.cpp      | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

/****************************************************************************
 *                               Modul: QPMain
 *
 * Aufgabe: Dies ist der Hauptmodul des Parsers.
 * Funktionen: yywarning(): Funktion zum Ausgeben der Parser-Warnungen
 *             yyerror(): Funktion zum Ausgeben der Parser-Fehlermeldungen
 *             ParseSpecification(): Eigentliche Parse-Funktion
 ****************************************************************************/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************
 *  Includes
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "QPLexYacc.h"

#include <DS/DSSystem.h>
#include <DS/DSString.h>

#include "QPBasicTypes.h"
#include "QPObjects.h"
#ifdef DMALLOC
#include <dmalloc.h>
#endif

/****************************************************************************
 *  Externe Variablen
 ****************************************************************************/

extern int line_count;
extern FILE *yyin;
extern int err_recover;
extern int error_counter;
extern int warning_counter;

/****************************************************************************
 *  Globale Variablen
 ****************************************************************************/

int warnings;

DSSystem *p_system = NULL;

DSStream *qp_cout;

DSObjectRefStack p_stack;

extern "C" {

extern int yyparse(void);
extern void yyrestart(FILE *);

}

/****************************************************************************
 *  Funktionen
 ****************************************************************************/

QPResult ParseSpecification(DSSystem **system,
                            DSString *filename,
                            DSStream &myCout,
                            DSBoolean verbose,
                            DSBoolean print_warnings)
{
  int ret;
  DSString path;

  error_counter = 0;
  warning_counter = 0;
  line_count = 1;

  p_system = NULL;
  qp_cout = &myCout;

  warnings = (int)print_warnings;

  if (filename == NULL)    // wird von stdin gelesen?
  {
    if (verbose) *qp_cout << "\nParsing stdin...\n";

    ret = yyparse();

    if (!ret)
    {
      if (verbose)
      {
        *qp_cout << std::endl << "Syntax check complete." << std::endl;
        *qp_cout << line_count << " lines processed." << std::endl;
        *qp_cout << error_counter << " errors." << std::endl;
        if (warnings)
          *qp_cout << warning_counter << " warnings." << std::endl;
      }
    }
  }
  else
  {
    yyin = fopen(filename->GetString(), "r");

    if(!yyin)
    {
      if (getenv("QUEST_SPEC_DIR") != NULL)
      {
        path = getenv("QUEST_SPEC_DIR");
        if (path[path.Length() - 1] != CG_PATH_SEPARATOR_CHAR)
        {
          path += CG_PATH_SEPARATOR_STRING;
        }
        path += *filename;
      }
      else
      {
        *qp_cout << "Warning: environment variable 'QUEST_SPEC_DIR' not set." << std::endl;
        path = *filename;
      }
      yyin = fopen(path.GetString(), "r");
    }

    if(!yyin)
    {
      *qp_cout << "Can't open file " << path << "!" << std::endl;
      return QP_ERROR;
    }

    if (verbose)
      *qp_cout << "Parsing file " << filename << "..." << std::endl;

    yyrestart(yyin);
    ret = yyparse();

    fclose(yyin);

    if (!ret)
    {
      if (verbose)
      {
        *qp_cout << std::endl << "Syntax check complete." << std::endl;
        *qp_cout << line_count << " lines of file " << filename << " processed." << std::endl;
        *qp_cout << error_counter << " errors." << std::endl;
        if (warnings)
          *qp_cout << warning_counter << " warnings." << std::endl;
      }
    }
  }
  *system = p_system;

  if (ret || error_counter > 0) return QP_SYNTAX_ERROR;

  return QP_OK;
}
