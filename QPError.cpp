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
| QPError       |   QPError.cpp     | 9. Aug 1994   |   QP              |       |
+------------------------------------------------------------------------------*/

/*  Lineal
000000000011111111112222222222333333333344444444445555555555666666666677777777778
012345678901234567890123456789012345678901234567890123456789012345678901234567890
*/

/****************************************************************************
 *                               Modul: QPError
 *
 * Aufgabe: Dies ist der Fehlermodul des Parsers.
 * Funktionen: yywarning(): Funktion zum Ausgeben der Parser-Warnungen
 *             yyerror(): Funktion zum Ausgeben der Parser-Fehlermeldungen
 ****************************************************************************/

#ifdef USE_PRAGMA
#pragma interface
#endif

/****************************************************************************
 *  Includes
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#ifdef DMALLOC
#include <dmalloc.h>
#endif

#include <DS/DSStream.h>

#include "QPLexYacc.h"

/****************************************************************************
 *  Externe Variablen
 ****************************************************************************/

extern int line_count;
extern int warnings;

/****************************************************************************
 *  Globale Variablen
 ****************************************************************************/

int err_recover = 0;
int error_counter = 0;
int warning_counter = 0;

extern DSStream *qp_cout;

#ifdef DEBUG

ofstream qpDebugLog("QP.log");

#endif

extern "C" {

/****************************************************************************
 *  Funktionen
 ****************************************************************************/

void yyerror(const char* s)
{
  *qp_cout << "Error: linenumber " << line_count;
  *qp_cout << ": " << s << std::endl;

  error_counter++;
}

void yywarning(const char* s)
{
  if (warnings)
  {
    *qp_cout << "Warning: linenumber " << line_count;
    *qp_cout << ": " << s << std::endl;
  }
  warning_counter++;
}

}
