%{
/******************************************************************************
 *  Modul: $RCSfile: QSDL92.y,v $
 *
 *  $Author: md $
 *  $Date: 1997/10/22 16:09:04 $
 *  $Revision: 1.2 $
 *
 *  Copyright 1994-1997: University of Essen / Germany. All rights reserved.
 *
 *  WICHTIG:
 *    Die erste Zeile dieses Moduls muss (!) mit %{ beginnen!!!
 *    Sonst kann yacc/bison die Grammatik nicht bearbeiten!!!
 *
 *  Aufgabe:
 *    Der Modul enthaelt die yacc-/bison-Grammatik fuer QSDL. Aus dieser
 *    Grammatik wird mit Hilfe von yacc/bison automatisch C-Code fuer
 *    einen Parser generiert. In die Grammatik sind aktive Teile (C-Code)
 *    eingebunden, die mit in den generierten C-Code kopiert werden und den
 *    Parser zu einem Compiler vervollstaendigen.
 *    Naeheres siehe
 *      Z100 (SDL)
 *    und
 *      Levine, John R. and Mason, Tony and Brown, Doug: lex & yacc.
 *      2nd Edition, Sebastopol, California/U.S.A: O'Reilly & Associates, 1992.
 *    sowie
 *      Bison-Documentation (bison.ps), verfuegbar per anonymous ftp.
 *
 *  Hinweise:
 *    + Bei Nonterminals, die in der Z100 mit "textual" beginnen, z.B.
 *      <textual process reference>, wurde das "textual" weggelassen, d.h.
 *      <textual process reference> wird zu process_reference.
 *    + Leere Symbole werden durch ein kommentiertes "empty" dargestellt, da
 *      "empty" als eigenstaendige Regel zu shift/reduce-Konflikten fuehrt.
 *    + "QSDL" als Kommentar markiert QSDL-spezifische Teile der Grammatik.
 *    + "HERE" als Kommentar markiert unfertige oder fehlerhafte Teile der
 *      Grammatik, und darf in der Endversion nicht mehr auftauchen.
 *    + Nicht implementierte Teile sind auskommentiert.
 *    + Verschachtelte Kommentare sind in yacc/bison NICHT erlaubt!!!
 *    + Der Lexer liefert alle lexikalischen Werte in Kleinschrift!
 *
 ******************************************************************************/          

#include <string.h>                              /* DO NOT CONFUSE THIS WITH
                                                    <String.h>, which is a
                                                    GNU-specific library NOT
                                                    in the ANSI-standard!!! */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define YYERROR_VERBOSE 1                        /* Makes parser issue verbose
                                                    error messages indicating
                                                    the token that lead to the
                                                    parse error. */
                                                    
#define YYDEBUG 1                                /* Enable debugging code. */

#include <DS/DSBasicTypes.h>

#include "QPAction.h"
#include "QPActual.h"
#include "QPBind.h"
#include "QPBlock.h"
#include "QPBlockSubstructure.h"
#include "QPChannel.h"
#include "QPConnection.h"
#include "QPData.h"
#include "QPExpression.h"
#include "QPIdentifier.h"
#include "QPInput.h"
#include "QPLink.h"
#include "QPLiteral.h"
#include "QPMachine.h"
#include "QPMachineService.h"
#include "QPName.h"
#include "QPPipe.h"
#include "QPProcedure.h"
#include "QPProcess.h"
#include "QPSensor.h"
#include "QPSignal.h"
#include "QPSignalItem.h"
#include "QPSignalList.h"
#include "QPSignalRoute.h"
#include "QPSort.h"
#include "QPState.h"
#include "QPSystem.h"
#include "QPTimer.h"
#include "QPVariable.h"

extern int yylex(void);
extern void yyerror (const char* s);

%}

%union { char *symval;
         int oprtr; }                             /* Set type for the lexical
                                                     values of the tokens.
                                                     The values are inserted by
                                                     the lexer. */
    

%token <symval> ACTIVEtoken
%token <symval> ADDINGtoken
%token <symval> ALLtoken
%token <symval> ALTERNATIVEtoken
%token <symval> ANYtoken
%token <symval> AStoken
%token <symval> ATLEASTtoken
%token <symval> AXIOMStoken
%token <symval> BLOCKtoken
%token <symval> CALLtoken
%token <symval> CHANNELtoken
%token <symval> COMMENTtoken
%token <symval> CONNECTtoken
%token <symval> CONNECTIONtoken
%token <symval> CONSTANTtoken
%token <symval> CONSTANTStoken
%token <symval> CREATEtoken
%token <symval> DCLtoken
%token <symval> DECISIONtoken
%token <symval> DEFAULTtoken
%token <symval> DELAYtoken
%token <symval> ELSEtoken
%token <symval> ENDALTERNATIVEtoken
%token <symval> ENDBLOCKtoken
%token <symval> ENDCHANNELtoken
%token <symval> ENDCONNECTIONtoken
%token <symval> ENDDECISIONtoken
%token <symval> ENDGENERATORtoken
%token <symval> ENDMACROtoken
%token <symval> ENDNEWTYPEtoken
%token <symval> ENDOPERATORtoken
%token <symval> ENDPACKAGEtoken
%token <symval> ENDPROCEDUREtoken
%token <symval> ENDPROCESStoken
%token <symval> ENDREFINEMENTtoken
%token <symval> ENDSELECTtoken
%token <symval> ENDSERVICEtoken
%token <symval> ENDSTATEtoken
%token <symval> ENDSUBSTRUCTUREtoken
%token <symval> ENDSYNTYPEtoken
%token <symval> ENDSYSTEMtoken
%token <symval> ENVtoken
%token <symval> ERRORtoken
%token <symval> EXPORTtoken
%token <symval> EXPORTEDtoken
%token <symval> EXTERNALtoken
%token <symval> FItoken
%token <symval> FINALIZEDtoken
%token <symval> FORtoken
%token <symval> FPARtoken
%token <symval> FROMtoken
%token <symval> GATEtoken
%token <symval> GENERATORtoken
%token <symval> IFtoken
%token <symval> IMPORTtoken
%token <symval> IMPORTEDtoken
%token <symval> INtoken
%token <symval> INHERITStoken
%token <symval> INPUTtoken
%token <symval> INTERFACEtoken
%token <symval> JOINtoken
%token <symval> LITERALtoken
%token <symval> LITERALStoken
%token <symval> MACROtoken
%token <symval> MACRODEFINITIONtoken
%token <symval> MACROIDtoken
%token <symval> MAPtoken
%token <symval> NAMECLASStoken
%token <symval> NEWTYPEtoken
%token <symval> NEXTSTATEtoken
%token <symval> NODELAYtoken
%token <symval> NOEQUALITYtoken
%token <symval> NONEtoken
%token <symval> NOWtoken
%token <symval> OFFSPRINGtoken
%token <symval> OPERATORtoken
%token <symval> OPERATORStoken
%token <symval> ORDERINGtoken
%token <symval> OUTtoken
%token <symval> OUTPUTtoken
%token <symval> PACKAGEtoken
%token <symval> PARENTtoken
%token <symval> PRIORITYtoken
%token <symval> PROCEDUREtoken
%token <symval> PROCESStoken
%token <symval> PROVIDEDtoken
%token <symval> REDEFINEDtoken
%token <symval> REFERENCEDtoken
%token <symval> REFINEMENTtoken
%token <symval> REMOTEtoken
%token <symval> RESETtoken
%token <symval> RETURNtoken
%token <symval> RETURNStoken
%token <symval> REVEALEDtoken
%token <symval> REVERSEtoken
%token <symval> SAVEtoken
%token <symval> SELECTtoken
%token <symval> SELFtoken
%token <symval> SENDERtoken
%token <symval> SERVICEtoken
%token <symval> SETtoken
%token <symval> SIGNALtoken
%token <symval> SIGNALLISTtoken
%token <symval> SIGNALROUTEtoken
%token <symval> SIGNALSETtoken
%token <symval> SPELLINGtoken
%token <symval> STARTtoken
%token <symval> STATEtoken
%token <symval> STOPtoken
%token <symval> STRUCTtoken
%token <symval> SUBSTRUCTUREtoken
%token <symval> SYNONYMtoken
%token <symval> SYNTYPEtoken
%token <symval> SYSTEMtoken
%token <symval> TASKtoken
%token <symval> THENtoken
%token <symval> THIStoken
%token <symval> TIMERtoken
%token <symval> TOtoken
%token <symval> TYPEtoken
%token <symval> USEtoken
%token <symval> VIAtoken
%token <symval> VIEWtoken
%token <symval> VIEWEDtoken
%token <symval> VIRTUALtoken
%token <symval> WITHtoken
%token <symval> ANDtoken
%token <symval> MODtoken
%token <symval> NOTtoken
%token <symval> ORtoken
%token <symval> REMtoken
%token <symval> XORtoken
%token <symval> LTLTtoken
%token <symval> GTGTtoken
%token <symval> OTHER_CHARtoken
%token <symval> APOSTROPHEtoken
%token <symval> SPACEtoken
%token <symval> LINEBREAKtoken
%token <symval> TABULATORtoken
%token <symval> COMMAtoken
%token <symval> PLUStoken
%token <symval> MINUStoken
%token <symval> EXCLAMATIONtoken
%token <symval> GREATERtoken
%token <symval> ASTERISKtoken
%token <symval> LEFTPARtoken
%token <symval> RIGHTPARtoken
%token <symval> QUOTEtoken
%token <symval> SEMICOLONtoken
%token <symval> LESStoken
%token <symval> EQUALtoken
%token <symval> COLONtoken
%token <symval> FULLSTOPtoken
%token <symval> DOUBLEEQUALtoken
%token <symval> LONGTHICKARROWtoken
%token <symval> NOTEQUALtoken
%token <symval> LESSEQUALtoken
%token <symval> GREATEREQUALtoken
%token <symval> CONCATENATIONtoken
%token <symval> ASSIGNMENTtoken
%token <symval> THICKARROWtoken
%token <symval> THINARROWtoken
%token <symval> LEFTPARPERIODtoken
%token <symval> RIGHTPARPERIODtoken

%token <symval> NATURAL_NUMBERtoken
%token <symval> CHARSTRINGtoken
%token <symval> WORDtoken
%token <symval> SLASHtoken
%token <symval> UNDERLINEtoken


/************* QSDL extensions *************/
%token <symval> HISTtoken

%token <symval> PIPEtoken
%token <symval> ENDPIPEtoken
%token <symval> MACHINEtoken
%token <symval> ENDMACHINEtoken
%token <symval> SERVERtoken
%token <symval> DISCIPLINEtoken
%token <symval> OFFERStoken
%token <symval> MACHINESERVICEtoken
%token <symval> AWAKEtoken
%token <symval> LINKtoken
%token <symval> BINDtoken
%token <symval> REQUESTtoken
%token <symval> CLEARtoken
%token <symval> UPDATEtoken
%token <symval> ASSERTtoken

%token <symval> BASECOUNTERtoken
%token <symval> BASEFREQUENCYtoken
%token <symval> BASETALLYtoken
%token <symval> BASETIMEtoken

%token <symval> FREQPROCESSCREATEtoken
%token <symval> FREQPROCESSSTOPtoken
%token <symval> FREQREQUESTtoken
%token <symval> FREQSIGNALCONSUMEtoken
%token <symval> FREQSIGNALDROPtoken
%token <symval> FREQSIGNALRECEIVEtoken
%token <symval> FREQSIGNALLOSEtoken
%token <symval> FREQSIGNALSAVEtoken
%token <symval> FREQSIGNALSENDtoken
%token <symval> FREQSIGNALtoken
%token <symval> FREQSTATEtoken
%token <symval> FREQTRANSITIONtoken
%token <symval> COUNTPROCESSCREATEtoken
%token <symval> COUNTPROCESSSTOPtoken
%token <symval> COUNTREQUESTtoken
%token <symval> COUNTSIGNALCONSUMEtoken
%token <symval> COUNTSIGNALDROPtoken
%token <symval> COUNTSIGNALRECEIVEtoken
%token <symval> COUNTSIGNALLOSEtoken
%token <symval> COUNTSIGNALSAVEtoken
%token <symval> COUNTSIGNALSENDtoken
%token <symval> COUNTSIGNALtoken
%token <symval> COUNTSTATEtoken
%token <symval> COUNTTRANSITIONtoken
%token <symval> LIFETIMEPROCESStoken
%token <symval> QUEUECONTENTtoken
%token <symval> QUEUELENGTHtoken
%token <symval> RESPONSETIMEREQUESTtoken
%token <symval> SENSORtoken
%token <symval> SERVICETIMEREQUESTtoken
%token <symval> THROUGHPUTtoken
%token <symval> UTILIZATIONtoken
%token <symval> WAITTIMEREQUESTtoken
%token <symval> WAITTIMESIGNALtoken
%token <symval> TRANSMISSIONTIMESIGNALtoken
%token <symval> WAITTIMESTATEtoken

/************ Extensions for temporal logic ***************/
%token <symval> ATOMtoken

/************ precedence rules *************/

                                                 /* DO NOT BREAK THE FOLLOWING
                                                    LINES! THE PHYSICAL
                                                    ARRANGEMENT OF LINES IS
                                                    VITAL FOR THE ORDER OF
                                                    PRECEDENCE!!!
                                                    Precedence currently is
                                                    coded into the grammar,
                                                    but this may change!!! */
%left ORtoken, XORtoken
%left ANDtoken
%left NOTEQUALtoken, GREATERtoken, LESStoken, EQUALtoken, LESSEQUALtoken, GREATEREQUALtoken, INtoken
%left PLUStoken, MINUStoken, CONCATENATIONtoken
%left ASTERISKtoken, SLASHtoken, MODtoken, REMtoken
%right NOTtoken, unary_minus

%start sdl_specification                          /* Declare start symbol. */


/************ type declarations *************/
                 
%type <symval> name
%type <symval> opt_name
%type <symval> comma_name_list
%type <symval> par_comma_name_list
%type <symval> opt_par_comma_name_list
%type <symval> identifier
%type <symval> opt_identifier
%type <symval> comma_ident_list
%type <symval> qualifier
%type <symval> opt_qualifier
%type <symval> ltlt_path_item_list
%type <symval> path_item
%type <symval> path_item_list
%type <symval> name_or_quoted_operator
%type <symval> scope_unit_kind
%type <symval> informal_text
%type <symval> end
%type <symval> opt_end
%type <symval> opt_comment
%type <symval> comment
%type <symval> sdl_specification
%type <symval> opt_sdl_spec_body
%type <symval> sdl_spec_body
%type <symval> opt_referenced_def_list
%type <symval> referenced_def_list
%type <symval> package_list
%type <symval> pckg_opt_ref_def_list_list
%type <symval> package
%type <symval> package_definition
%type <symval> opt_packg_ref_clause_list
%type <symval> packg_ref_clause_list
%type <symval> opt_entity_in_pckg_list
%type <symval> entity_in_pckg_list
%type <symval> entity_in_package
%type <symval> package_reference_clause
%type <symval> opt_slash_def_sel
%type <symval> definition_selection_list
%type <symval> definition_selection
%type <symval> opt_entity_kind
%type <symval> entity_kind
%type <symval> opt_interface
%type <symval> interface
%type <symval> referenced_definition
%type <symval> system_definition
%type <symval> definition
%type <symval> textual_system_definition
%type <symval> text_sys_def_body
%type <symval> entity_in_sys_list
%type <symval> entity_in_system
%type <symval> block_reference
%type <symval> block_definition
%type <symval> block_substructure_definition
%type <symval> block_substructure_reference
%type <symval> opt_block_substruct_def_or_ref
%type <symval> block_substruct_def_or_ref
%type <symval> opt_block_body_list
%type <symval> block_body_list
%type <symval> block_body_list_item
%type <symval> entity_in_block
%type <symval> entity_in_substructure_list
%type <symval> entity_in_substructure
%type <symval> process_reference
%type <symval> process_definition
%type <symval> opt_fpar_end_item
%type <symval> fpar_end_item
%type <symval> opt_pcs_entity_item_list
%type <symval> pcs_entity_item_list
%type <symval> pcs_entity_item
%type <symval> entity_in_process
%type <symval> procedure_reference
%type <symval> valid_input_signal_set
%type <symval> opt_valid_input_signal_set
%type <symval> process_body
%type <symval> opt_process_body
%type <symval> opt_state_or_free_action_list
%type <symval> state_or_free_action_list
%type <symval> state_or_free_action
%type <symval> formal_parameters
%type <symval> comma_parameters_of_sort_list
%type <symval> parameters_of_sort
%type <symval> number_of_process_instances
%type <symval> opt_number_of_process_instances
%type <symval> opt_comma_opt_max_no
%type <symval> comma_opt_max_no
%type <symval> opt_comma_opt_queue_length
%type <symval> comma_opt_queue_length
%type <symval> initial_number
%type <symval> opt_initial_number
%type <symval> maximum_number
%type <symval> opt_maximum_number
%type <symval> queue_length
%type <symval> opt_queue_length
%type <symval> service_definition
%type <symval> opt_entity_in_service_list
%type <symval> entity_in_service_list
%type <symval> entity_in_service
%type <symval> service_body
%type <symval> procedure_definition
%type <symval> opt_proc_fpar_end_item
%type <symval> proc_fpar_end_item
%type <symval> opt_proc_result_end_item
%type <symval> proc_result_end_item
%type <symval> opt_entity_in_proc_item_list
%type <symval> entity_in_proc_item_list
%type <symval> entity_in_proc_item
%type <symval> procedure_formal_parameters
%type <symval> opt_comma_formal_var_param_list
%type <symval> comma_formal_var_param_list
%type <symval> formal_variable_parameters
%type <symval> parameter_kind
%type <symval> in_out
%type <symval> procedure_result
%type <symval> entity_in_procedure
%type <symval> procedure_body
%type <symval> opt_procedure_body
%type <symval> channel_definition
%type <symval> opt_nodelay
%type <symval> channel_path
%type <symval> opt_channel_path
%type <symval> channel_endpoint
%type <symval> ident_or_env
%type <symval> signal_route_definition
%type <symval> signal_route_path
%type <symval> opt_signal_route_path
%type <symval> signal_route_endpoint
%type <symval> channel_connection
%type <symval> channel_to_route_connection
%type <symval> signal_route_to_route_connection
%type <symval> signal_definition
%type <symval> comma_sig_def_item_list
%type <symval> signal_definition_item
%type <symval> sort_list
%type <symval> opt_sort_list
%type <symval> comma_sort_list
%type <symval> signallist_definition
%type <symval> signallist
%type <symval> opt_signallist
%type <symval> signallist_item
%type <symval> variable_definition
%type <symval> opt_revealed_exported_item
%type <symval> revealed_exported_item
%type <symval> variables_of_sort
%type <symval> comma_var_exported_list
%type <symval> var_exported
%type <symval> opt_var_init
%type <symval> var_init
%type <symval> variables_of_sort_list
%type <symval> exported_as
%type <symval> opt_exported_as
%type <symval> start
%type <symval> state
%type <symval> opt_state_body_list
%type <symval> state_body_list
%type <symval> state_body_item
%type <symval> opt_endstate_item
%type <symval> endstate_item
%type <symval> state_list
%type <symval> input_part
%type <symval> basic_input_part
%type <symval> input_list
%type <symval> stimulus
%type <symval> opt_par_comma_opt_var_list
%type <symval> par_comma_opt_var_list
%type <symval> comma_opt_var_list
%type <symval> comma_stimulus_list
%type <symval> save_part
%type <symval> basic_save_part
%type <symval> save_list
%type <symval> spontaneous_transition
%type <symval> spontaneous_designator
%type <symval> label
%type <symval> opt_label
%type <symval> free_action
%type <symval> opt_endconnection_item
%type <symval> endconnection_item
%type <symval> transition
%type <symval> opt_transition
%type <symval> transition_string
%type <symval> action_statement
%type <symval> action
%type <symval> terminator_statement
%type <symval> opt_terminator_statement
%type <symval> terminator
%type <symval> nextstate
%type <symval> nextstate_body
%type <symval> join
%type <symval> stop
%type <symval> return
%type <symval> task
%type <symval> task_body
%type <symval> comma_assignment_statement_list
%type <symval> comma_informal_text_list
%type <symval> create_request
%type <symval> create_body
%type <symval> ident_or_this
%type <symval> actual_parameters
%type <symval> opt_actual_parameters
%type <symval> procedure_call
%type <symval> procedure_call_body
%type <symval> output
%type <symval> output_body
%type <symval> comma_ident_actual_param_list
%type <symval> ident_actual_param
%type <symval> opt_to_destination
%type <symval> to_destination
%type <symval> opt_via_path_item
%type <symval> via_path_item
%type <symval> opt_all
%type <symval> destination
%type <symval> via_path
%type <symval> opt_delay
%type <symval> delay
%type <symval> decision
%type <symval> decision_body
%type <symval> answer_part
%type <symval> answer_part_list
%type <symval> answer
%type <symval> opt_answer
%type <symval> else_part
%type <symval> opt_else_part
%type <symval> question
%type <symval> timer_definition
%type <symval> timer_definition_item
%type <symval> opt_timer_init
%type <symval> timer_init
%type <symval> timer_definition_item_list
%type <symval> reset
%type <symval> par_comma_reset_statement_list
%type <symval> reset_statement
%type <symval> comma_reset_statement_list
%type <symval> set
%type <symval> set_statement
%type <symval> expr_comma
%type <symval> comma_set_statement_list
%type <symval> simple_expression
%type <symval> asterisk_state_list
%type <symval> asterisk_input_list
%type <symval> asterisk_save_list
%type <symval> dash_nextstate
%type <symval> priority_input
%type <symval> priority_input_list
%type <symval> continuous_signal
%type <symval> opt_priority_name_end_item
%type <symval> priority_name_end_item
%type <symval> enabling_condition
%type <symval> opt_enabling_condition
%type <symval> partial_type_definition
%type <symval> properties_expression
%type <symval> operators
%type <symval> literal_list
%type <symval> opt_literal_list
%type <symval> literal_signature
%type <symval> comma_literal_signature_list
%type <symval> operator_list
%type <symval> operator_signature_end_list
%type <symval> opt_operator_list
%type <symval> operator_signature
%type <symval> operator_name
%type <symval> result
%type <symval> extended_sort
%type <symval> sort
%type <symval> opt_sort
%type <symval> extended_properties
%type <symval> opt_extended_properties
%type <symval> quoted_operator
%type <symval> quote
%type <symval> infix_operator
%type <symval> monadic_operator
%type <symval> noequality
%type <symval> ordering
%type <symval> syntype_definition
%type <symval> const_range_item
%type <symval> opt_const_range_item
%type <symval> parent_sort_identifier
%type <symval> range_condition
%type <symval> closed_open_range
%type <symval> closed_range
%type <symval> open_range
%type <oprtr>  range_op
%type <symval> constant
%type <symval> structure_definition
%type <symval> opt_adding
%type <symval> field_list
%type <symval> fields
%type <symval> field_sort
%type <symval> generator_transformations
%type <symval> generator_trans_item
%type <symval> generator_transformation
%type <symval> generator_actual_list
%type <symval> generator_actual
%type <symval> synonym_definition
%type <symval> internal_synonym_definition
%type <symval> synonym_definition_item
%type <symval> comma_synonym_definition_item_list
%type <symval> ground_expression
%type <symval> expression
%type <symval> opt_expression
%type <symval> sub_expression
%type <symval> operand0
%type <oprtr>  or_op
%type <symval> operand1
%type <symval> operand2
%type <oprtr>  equ_op
%type <symval> operand3
%type <oprtr>  add_op
%type <symval> operand4
%type <oprtr>  div_op
%type <symval> operand5
%type <oprtr>  opt_unary_op
%type <oprtr>  unary_op
%type <symval> primary
/* %type <symval> ground_expression_list */
/* %type <symval> operator_identifier */
%type <symval> indexed_primary
%type <symval> field_primary
%type <symval> field_selection
%type <symval> data_definition
%type <symval> def_item
%type <symval> expression_list
%type <symval> par_comma_opt_expr_list
%type <symval> comma_opt_expr_list
%type <symval> opt_par_expression_list
%type <symval> par_expression_list
%type <symval> assignment_statement
%type <symval> variable
%type <symval> opt_variable
%type <symval> indexed_variable
%type <symval> field_variable
%type <symval> default_initialization
%type <symval> opt_default_initialization
%type <symval> imperative_operator
%type <symval> now_expression
%type <symval> PID_expression
%type <symval> value_returning_procedure_call
%type <symval> virtuality
%type <symval> opt_virtuality

/******************** QSDL extensions ***********************/
%type <symval> opt_history_item

%type <symval> machine_service_definition
%type <symval> comma_ms_def_item_list
%type <symval> machineservice_definition_item
%type <symval> machine_definition
%type <symval> mach_body_list
%type <symval> mach_body_list_item
%type <symval> machine_reference
%type <symval> server_item
%type <symval> discipline_item
%type <symval> machservice_name_speed_list
%type <symval> machservice_name_speed_list_item
%type <symval> machineservice_speed
%type <symval> pipe_definition
%type <symval> pipe_path
%type <symval> opt_pipe_path
%type <symval> pipe_endpoint
%type <symval> link_definition
%type <symval> link_path
%type <symval> link_endpoint
%type <symval> machineservicelist
%type <symval> pipe_binding
%type <symval> pipe_to_link_binding
%type <symval> opt_awake_item
%type <symval> awake_item
%type <symval> request
%type <symval> request_body
%type <symval> request_parameter_list
%type <symval> request_parameter
%type <symval> opt_target
%type <symval> from_item
%type <symval> opt_comma_priority
%type <symval> comma_priority
%type <symval> priority
%type <symval> via_request_path
%type <symval> clear
%type <symval> update
%type <symval> opt_update_body
%type <symval> update_body
%type <symval> opt_comma_value
%type <symval> comma_value
%type <symval> assert
%type <symval> sys_sensor_definition
%type <oprtr>  sys_sensor_type        /* This rule returns int, not char* !!! */
%type <oprtr>  sys_sensor_type_param  /* This rule returns int, not char* !!! */
%type <symval> pcs_sensor_definition
%type <oprtr>  pcs_sensor_type        /* This rule returns int, not char* !!! */
%type <oprtr>  pcs_sensor_type_param  /* This rule returns int, not char* !!! */
/* %type <symval> opt_par_name */
%type <symval> mach_sensor_list
%type <symval> mach_sensor_definition
%type <oprtr>  mach_sensor_type       /* This rule returns int, not char* !!! */
%type <oprtr>  mach_sensor_type_param /* This rule returns int, not char* !!! */

/*********************** Extensions for temporal logic ************************/
%type <symval> opt_atom_definition
%type <symval> atom_definition
%type <symval> atom_definition_item
%type <symval> name_expr_pair_list
%type <symval> name_expr_pair

%%

/**** <name> */
name:                           WORDtoken {$$ = $1;}
                                ;

opt_name:                       /* empty */ { $$ = NULL; } |
                                name {$$ = $1;}
                                ;

comma_name_list:                comma_name_list
                                    COMMAtoken
                                    name {comma_name_list_1($3);} |
                                name {comma_name_list_1($1);} /* STORE name in list */
                                ;                           

par_comma_name_list:            LEFTPARtoken
                                    comma_name_list
                                    RIGHTPARtoken
                                ;

opt_par_comma_name_list:        /* empty */ { $$ = NULL; } |
                                par_comma_name_list
                                ;

/**** <identifier> */
identifier:                     opt_qualifier
                                     name { $$ = $2; }
                                ;

opt_identifier:                 /* empty */ { $$ = NULL; } |
                                identifier { $$ = $1; }
                                ;
                                
comma_ident_list:               comma_ident_list
                                    COMMAtoken
                                    identifier {comma_ident_list_1($3);} |
                                identifier {comma_ident_list_1($1);} /* STORE ident in list */
                                ;

/**** <qualifier> */
qualifier:                      path_item_list |
                                ltlt_path_item_list
                                ;

opt_qualifier:                  /* empty */ { $$ = NULL; opt_qualifier_1(); } |
                                qualifier
                                ;

ltlt_path_item_list:            LTLTtoken
                                    path_item_list
                                    GTGTtoken
                                ;

/**** <path item> */
path_item:                      scope_unit_kind name_or_quoted_operator
                                ;

path_item_list:                 path_item |
                                path_item_list
                                    SLASHtoken
                                    path_item
                                ;

name_or_quoted_operator:        name { name_or_quoted_operator_1($1); } |
                                quoted_operator
                                ;

/**** <scope unit kind> */
scope_unit_kind:                PACKAGEtoken |
                                SYSTEMtoken {scope_unit_kind_1( DS_SYSTEM ); } |
                                BLOCKtoken {scope_unit_kind_1( DS_BLOCK ); } |
                                SUBSTRUCTUREtoken |
                                PROCESStoken {scope_unit_kind_1( DS_PROCESS ); } |
                                SERVICEtoken |
                                PROCEDUREtoken |
                                SIGNALtoken |
                                OPERATORtoken |
                                TYPEtoken |
                                MACHINEtoken {scope_unit_kind_1( DS_MACHINE ); } /* QSDL */
                                ;

/**** <informal text> */
informal_text:                  CHARSTRINGtoken
                                ;

/**** <end> */
end:                            opt_comment SEMICOLONtoken
                                ;

opt_end:                        /* empty */ { $$ = NULL; } |
                                end
                                ;

/**** <comment> */
opt_comment:                    /* empty */ { $$ = NULL; } |
                                comment
                                ;

comment:                        COMMENTtoken CHARSTRINGtoken
                                ;

/**** <sdl specification> */
sdl_specification:              package_list opt_sdl_spec_body
                                ;

opt_sdl_spec_body:              /* empty */ { $$ = NULL; } |
                                sdl_spec_body
                                ;

sdl_spec_body:                  system_definition
                                  opt_referenced_def_list
                                  opt_atom_definition /* QSDL */
                                ;

opt_referenced_def_list:        /* empty */ { $$ = NULL; } |
                                referenced_def_list
                                ;

referenced_def_list:            referenced_definition | /* referenced_definition = definition ! */
                                referenced_def_list referenced_definition
                                ;

/**** <package list> */
package_list:                   /* empty */ { $$ = NULL; } |
                                pckg_opt_ref_def_list_list
                                ;

pckg_opt_ref_def_list_list:     package opt_referenced_def_list |
                                pckg_opt_ref_def_list_list
                                    package
                                    opt_referenced_def_list
                                ;

/**** <package> */
package:                        package_definition
                                ;

/**** <package definition> */
package_definition:             opt_packg_ref_clause_list
                                    PACKAGEtoken
                                    name
                                    opt_interface
                                    end
                                    opt_entity_in_pckg_list
                                    ENDPACKAGEtoken
                                    opt_name
                                    end
                                ;

opt_packg_ref_clause_list:      /* empty */ { $$ = NULL; } |
                                packg_ref_clause_list
                                ;

packg_ref_clause_list:          packg_ref_clause_list
                                    package_reference_clause |
                                package_reference_clause
                                ;

opt_entity_in_pckg_list:        /* empty */ { $$ = NULL; } |
                                entity_in_pckg_list
                                ;

entity_in_pckg_list:            entity_in_pckg_list
                                    entity_in_package |
                                entity_in_package
                                ;

/**** <entity in package> */
entity_in_package:              
                                procedure_definition |
                                procedure_reference |
                                signal_definition |
                                signallist_definition |
                                data_definition
                                ;
                                /*
                                system_type_definition |
                                system_type_reference |
                                block_type_definition |
                                block_type_reference |
                                process_type_definition |
                                process_type_reference |
                                service_type_reference |
                                service_type_definition |
                                remote_procedure_definition |
                                remote_variable_definition |
                                select_definition |
                                macro_definition |
                                */

/**** <package reference clause> */
package_reference_clause:       USEtoken name opt_slash_def_sel end
                                ;

opt_slash_def_sel:              /* empty */ { $$ = NULL; } |
                                SLASHtoken definition_selection_list
                                ;

/**** <definition selection list> */
definition_selection_list:      definition_selection_list COMMAtoken
                                    definition_selection |
                                definition_selection
                                ;

/**** <definition selection> */
definition_selection:           opt_entity_kind name
                                ;

/**** <entity kind> */
opt_entity_kind:                /* empty */ { $$ = NULL; } |
                                entity_kind
                                ;

entity_kind:                    SYSTEMtoken |
                                BLOCKtoken |
                                PROCESStoken |
                                SERVICEtoken |
                                SIGNALtoken |
                                PROCEDUREtoken |
                                NEWTYPEtoken |
                                SIGNALLISTtoken |
                                GENERATORtoken |
                                SYNONYMtoken |
                                REMOTEtoken
                                ;

/**** <interface> */
opt_interface:                  /* empty */ { $$ = NULL; } |
                                interface
                                ;

interface:                      INTERFACEtoken definition_selection_list
                                ;

/**** <referenced definition> */
referenced_definition:          definition
                                ;

/**** <system definition> */
system_definition:              textual_system_definition
                                ;

/**** <definition> */
definition:                     block_definition |
                                process_definition |
                                service_definition |
                                procedure_definition |
                                block_substructure_definition |
                                machine_definition /* QSDL */
                                ;
                                /*
                                process_type_definition |
                                block_type_definition |
                                system_type_definition |
                                service_type_definition |
                                channel_substructure_definition |
                                macro_definition |
                                operator_definition |
                                */

/**** <textual system definition> */
textual_system_definition:      opt_packg_ref_clause_list text_sys_def_body
                                ;

text_sys_def_body:              SYSTEMtoken
                                    name {text_sys_def_body_1($2);} /* PUSH DSSystem */
                                    end
                                    entity_in_sys_list
                                    ENDSYSTEMtoken
                                    opt_name
                                    end {text_sys_def_body_2($7);} /* POP DSSystem + Check Name */
                                ;
                                /*
                                | textual_typebased_system_definition end
                                */


entity_in_sys_list:             entity_in_sys_list entity_in_system |
                                entity_in_system
                                ;

/**** <entity in system> */
entity_in_system:               block_definition |
                                block_reference |
                                channel_definition |
                                signal_definition |
                                signallist_definition |
                                data_definition |
                                procedure_definition |
                                procedure_reference |
                                machine_service_definition /* QSDL */ |
                                pipe_definition /* QSDL */ |
                                sys_sensor_definition /* QSDL */
                                ;
                                /*
                                process_type_reference |
                                process_type_definition |
                                service_type_reference |
                                service_type_definition |
                                remote_procedure_definition |
                                remote_variable_definition |
                                select_definition |
                                typebased_block_definition |
                                macro_definition |
                                block_type_reference |
                                block_type_definition |
                                */


opt_block_substruct_def_or_ref: /* empty */ { $$ = NULL; } |
                                block_substruct_def_or_ref
                                ;

block_substruct_def_or_ref: block_substructure_definition |
                            block_substructure_reference
                            ;

block_substructure_reference:   SUBSTRUCTUREtoken
                                    identifier
                                    REFERENCEDtoken
                                    end {block_substructure_reference_1($2);} /* INSERT DSBlockSubstructure */
                                ;

block_substructure_definition:  SUBSTRUCTUREtoken
                                    identifier {block_substructure_definition_1($2);} /* PUSH DSBlockSubstructure */
                                    end
                                    entity_in_substructure_list
                                    ENDSUBSTRUCTUREtoken
                                    opt_name
                                    end {block_substructure_definition_2($7);} /* POP DSBlockSubstructure + Check Name */
                                ;


entity_in_substructure_list:    entity_in_substructure_list entity_in_substructure |
                                entity_in_substructure
                                ;
 
entity_in_substructure: entity_in_system |
                        channel_connection |
                        pipe_binding
                        ;

/* QSDL */
sys_sensor_definition:          SENSORtoken
                                    sys_sensor_list
                                    end
                                ;
                                
sys_sensor_list:                sys_sensor_list
                                    COMMAtoken
                                    sys_sensor_item |
                                sys_sensor_item
                                ;

sys_sensor_item:                identifier
                                    sys_sensor_type { sys_sensor_definition_1 ($1, $2); } |
                                identifier
                                    sys_sensor_type_param
                                    opt_par_comma_name_list { sys_sensor_definition_2 ($1, $2); }
                                ;

sys_sensor_type:                BASECOUNTERtoken  { $$ = DS_SENSOR_COUNTER; } |
                                BASEFREQUENCYtoken  { $$ = DS_SENSOR_FREQUENCY; } |
                                BASETALLYtoken  { $$ = DS_SENSOR_TALLY; } |
                                FREQSIGNALtoken  { $$ = DS_SENSOR_SYS_FREQ_SIGNAL; } |
                                FREQREQUESTtoken { $$ = DS_SENSOR_SYS_FREQ_REQUEST; } |
                                FREQPROCESSCREATEtoken { $$ = DS_SENSOR_SYS_FREQ_PROCESS_CREATE; } |
                                FREQPROCESSSTOPtoken { $$ = DS_SENSOR_SYS_FREQ_PROCESS_STOP; }
                                ;

sys_sensor_type_param:          LIFETIMEPROCESStoken { $$ = DS_SENSOR_SYS_LIFETIME_PROCESS; } |
                                COUNTPROCESSCREATEtoken { $$ = DS_SENSOR_SYS_COUNT_PROCESS_CREATE; } |
                                COUNTPROCESSSTOPtoken { $$ = DS_SENSOR_SYS_COUNT_PROCESS_STOP; } |
                                COUNTSIGNALtoken { $$ = DS_SENSOR_SYS_COUNT_SIGNAL; } |
                                COUNTREQUESTtoken { $$ = DS_SENSOR_SYS_COUNT_REQUEST; }
                                ;


/**** <textual block reference> */
block_reference:                BLOCKtoken
                                    identifier
                                    REFERENCEDtoken
                                    end {block_reference_1($2);} /* INSERT + APPEND DSBlock */
                                ;

/**** <block definition> */
block_definition:               BLOCKtoken
                                    identifier {block_definition_1($2);} /* INSERT + PUSH DSBlock */
                                    end
                                    opt_block_body_list
                                    opt_block_substruct_def_or_ref
                                    ENDBLOCKtoken
                                    opt_identifier
                                    end {block_definition_2($8);} /* POP DSBlock + Check Name */ 
                                ;

opt_block_body_list:            /* empty */ { $$ = NULL; } |
                                block_body_list
                                ;

block_body_list:                block_body_list block_body_list_item |
                                block_body_list_item
                                ;

block_body_list_item:           channel_to_route_connection |
                                pipe_to_link_binding /* QSDL */ |
                                entity_in_block
                                ;

/**** <entity in block> */
entity_in_block:                signal_definition |
                                signallist_definition |
                                process_definition |
                                process_reference | 
                                signal_route_definition |
                                data_definition |
                                procedure_reference |
                                procedure_definition |
                                machine_service_definition /* QSDL */ |
                                machine_definition /* QSDL */ |
                                machine_reference /* QSDL */ |
                                link_definition /* QSDL */ |
                                sys_sensor_definition /* QSDL */  
                                ;
                                /*
                                process_type_definition
                                process_type_reference |
                                block_type_definition |
                                service_type_reference |
                                service_type_definition |
                                remote_procedure_definition |
                                remote_variable_definition |
                                select_definition |
                                typebased_process_definition |
                                macro_definition |
                                block_type_reference |
                                */

/**** <textual process reference> */
process_reference:              PROCESStoken
                                    identifier
                                    opt_number_of_process_instances
                                    REFERENCEDtoken {process_reference_1($2);}
                                    end
                                ;

/**** <process definition> */ 
process_definition:             PROCESStoken
                                    identifier
                                    opt_number_of_process_instances
                                    end {process_definition_1($2);} /* PUSH + INSERT DSProcess */
                                    opt_fpar_end_item
                                    opt_valid_input_signal_set
                                    opt_pcs_entity_item_list
                                    opt_process_body
                                    ENDPROCESStoken
                                    opt_identifier
                                    end {process_definition_2($11);} /* POP DSProcess + Check Name */
                                ;

opt_fpar_end_item:              /* empty */ { $$ = NULL; } |
                                fpar_end_item
                                ;

fpar_end_item:                  formal_parameters end
                                ;

opt_pcs_entity_item_list:       /* empty */ { $$ = NULL; } |
                                pcs_entity_item_list
                                ;

pcs_entity_item_list:           pcs_entity_item_list pcs_entity_item |
                                pcs_entity_item
                                ;

pcs_entity_item:                entity_in_process |
                                signal_route_to_route_connection
                                ;

/**** <entity in process> */
entity_in_process:              signal_definition |
                                signallist_definition |
                                procedure_reference |
                                procedure_definition |
                                data_definition |
                                variable_definition |
                                timer_definition |
                                signal_route_definition |
                                pcs_sensor_definition /* QSDL */
                                ;
                                /*
                                service_definition |
                                service_reference |
                                view_definition |
                                service_type_reference |
                                service_type_definition |
                                remote_variable_definition |
                                select_definition |
                                imported_procedure_specification |
                                macro_definition |
                                imported_variable_specification |
                                textual_typebased_service_definition |
                                */

/* QSDL */
pcs_sensor_definition:          SENSORtoken
                                    pcs_sensor_list
                                    end
                                ;

pcs_sensor_list:                pcs_sensor_list
                                    COMMAtoken
                                    pcs_sensor_item |
                                pcs_sensor_item
                                ;
                                
pcs_sensor_item:                identifier
                                  pcs_sensor_type { pcs_sensor_definition_1 ($1, $2); } |
                                identifier
                                  pcs_sensor_type_param
                                  opt_par_comma_name_list { pcs_sensor_definition_2 ($1, $2); }
                                ;

pcs_sensor_type:                BASECOUNTERtoken  { $$ = DS_SENSOR_COUNTER; } |
                                BASEFREQUENCYtoken  { $$ = DS_SENSOR_FREQUENCY; } |
                                BASETALLYtoken  { $$ = DS_SENSOR_TALLY; } |
                                FREQSIGNALRECEIVEtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_RECEIVE; }|
                                FREQSIGNALSENDtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_SEND; } |
                                FREQSIGNALDROPtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_DROP; } |
                                FREQSIGNALCONSUMEtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_CONSUME; } |
                                FREQSIGNALSAVEtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_SAVE; } |
                                FREQSIGNALLOSEtoken { $$ = DS_SENSOR_PCS_FREQ_SIGNAL_LOSE; } |
                                FREQREQUESTtoken { $$ = DS_SENSOR_PCS_FREQ_REQUEST; } |
                                FREQSTATEtoken { $$ = DS_SENSOR_PCS_FREQ_STATE; } |
                                QUEUELENGTHtoken { $$ = DS_SENSOR_PCS_QUEUE_LENGTH; } |
                                QUEUECONTENTtoken { $$ = DS_SENSOR_PCS_QUEUE_CONTENT; }
                                ;

pcs_sensor_type_param:          COUNTSIGNALRECEIVEtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_RECEIVE; }|
                                COUNTSIGNALSENDtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_SEND; } |
                                COUNTSIGNALDROPtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_DROP; } |
                                COUNTSIGNALCONSUMEtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_CONSUME; } |
                                COUNTSIGNALSAVEtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_SAVE; } |
                                COUNTSIGNALLOSEtoken { $$ = DS_SENSOR_PCS_COUNT_SIGNAL_LOSE; } |
                                COUNTREQUESTtoken { $$ = DS_SENSOR_PCS_COUNT_REQUEST; } |
                                COUNTSTATEtoken { $$ = DS_SENSOR_PCS_COUNT_STATE; } |
                                WAITTIMESIGNALtoken { $$ = DS_SENSOR_PCS_WAITTIME_SIGNAL; } |
                                WAITTIMESTATEtoken  { $$ = DS_SENSOR_PCS_WAITTIME_STATE; } |
                                RESPONSETIMEREQUESTtoken { $$ = DS_SENSOR_PCS_RESPONSETIME_REQUEST; } |
                                TRANSMISSIONTIMESIGNALtoken { $$ = DS_SENSOR_PCS_TRANSMISSIONTIME_SIGNAL; } |
                                FREQTRANSITIONtoken { $$ = DS_SENSOR_PCS_FREQ_TRANSITION; } |
                                COUNTTRANSITIONtoken { $$ = DS_SENSOR_PCS_COUNT_TRANSITION; }
                                ;

                                
/**** <textual procedure reference> */
procedure_reference:            PROCEDUREtoken
                                    name
                                    REFERENCEDtoken
                                    end {procedure_reference_1($2);} /* INSERT + APPEND DSProcedure */
                                ;


/**** <valid input signal set> */
valid_input_signal_set:         SIGNALSETtoken {valid_input_signal_set_1();} /* PUSH DSSignalItemList */
                                    opt_signallist {valid_input_signal_set_2();} /* POP DSSignalItemList */
                                    end
                                ;

opt_valid_input_signal_set:     /* empty */ { $$ = NULL; } |
                                valid_input_signal_set
                                ;

/**** <process body> */
process_body:                   start
                                    opt_state_or_free_action_list
                                ;

opt_process_body:               /* empty */ { $$ = NULL; } |
                                process_body
                                ;

opt_state_or_free_action_list:  /* empty */ { $$ = NULL; } |
                                state_or_free_action_list
                                ;
                                
state_or_free_action_list:      state_or_free_action_list
                                    state_or_free_action |
                                state_or_free_action
                                ;

state_or_free_action:           state |
                                free_action
                                ;

/**** <formal parameters> */
formal_parameters:              FPARtoken {formal_parameters_1();} /* CREATE name list */
                                    comma_parameters_of_sort_list {formal_parameters_2();} /* DELETE last obsolete name list */
                                ;

comma_parameters_of_sort_list:  comma_parameters_of_sort_list
                                    COMMAtoken
                                    parameters_of_sort {comma_parameters_of_sort_list_1($3);} | /* CREATE DSFormalParam + INSERT */
                                parameters_of_sort {comma_parameters_of_sort_list_1($1);} /* CREATE DSFormalParam + INSERT */
                                ;

/**** <parameters of sort> */
parameters_of_sort:             comma_name_list sort {$$ = $2;}
                                ;

/**** <number of process instances> */
number_of_process_instances:    LEFTPARtoken
                                    opt_initial_number
                                    opt_comma_opt_max_no
                                    opt_comma_opt_queue_length
                                    RIGHTPARtoken
                                ;

opt_number_of_process_instances: /* empty */ { $$ = NULL; } |
                                number_of_process_instances
                                ;

opt_comma_opt_max_no:           /* empty */ { $$ = NULL; } |
                                comma_opt_max_no
                                ;

comma_opt_max_no:               COMMAtoken
                                    opt_maximum_number
                                ;

opt_comma_opt_queue_length:     /* empty */ { $$ = NULL; } |
                                comma_opt_queue_length
                                ;

comma_opt_queue_length:         COMMAtoken
                                    opt_queue_length
                                ;

/**** <initial number> */
initial_number:                 simple_expression
                                ;

opt_initial_number:             /* empty */ {opt_expression_1();} | /* PUSH empty DSExpression */
                                initial_number
                                ;

/**** <maximum number> */
maximum_number:                 simple_expression
                                ;

opt_maximum_number:             /* empty */ {opt_expression_1();} | /* PUSH empty DSExpression */
                                maximum_number
                                ;

/**** <queue length> */
queue_length:                   simple_expression
                                ;

opt_queue_length:               /* empty */ {opt_expression_1();} | /* PUSH empty DSExpression */
                                queue_length
                                ;

/**** <service definition> */
service_definition:             SERVICEtoken identifier /* ident can be name! */
                                    end opt_valid_input_signal_set
                                    opt_entity_in_service_list
                                    service_body
                                    ENDSERVICEtoken opt_identifier end
                                ;

opt_entity_in_service_list:     /* empty */ { $$ = NULL; } |
                                entity_in_service_list
                                ;

entity_in_service_list:         entity_in_service_list
                                    entity_in_service |
                                entity_in_service
                                ;

/**** <entity in servive> */
entity_in_service:              variable_definition |
                                data_definition |
                                procedure_definition |
                                procedure_reference |
                                timer_definition
                                ;
                                /*
                                view_definition |
                                select_definition |
                                imported_variable_specification |
                                imported_procedure_specification |
                                macro_definition |
                                */

/**** <service body> */
service_body:                   process_body
                                ;

/**** <procedure definition> */
procedure_definition:           PROCEDUREtoken
                                    identifier
                                    end {procedure_definition_1($2);} /* PUSH DSProcedure */
                                    opt_proc_fpar_end_item
                                    opt_proc_result_end_item
                                    opt_entity_in_proc_item_list
                                    opt_procedure_body
                                    ENDPROCEDUREtoken
                                    opt_identifier
                                    end {procedure_definition_2($10);} /* POP DSProcedure + Check Name */
                                    ;

opt_proc_fpar_end_item:         /* empty */ { $$ = NULL; } |
                                proc_fpar_end_item
                                ;

proc_fpar_end_item:             procedure_formal_parameters end
                                ;

opt_proc_result_end_item:       /* empty */ { $$ = NULL; } |
                                proc_result_end_item
                                ;

proc_result_end_item:           procedure_result end
                                ;

opt_entity_in_proc_item_list:   /* empty */ { $$ = NULL; } |
                                entity_in_proc_item_list
                                ;

entity_in_proc_item_list:       entity_in_proc_item_list entity_in_proc_item |
                                entity_in_proc_item
                                ;

entity_in_proc_item:            entity_in_procedure
                                ;
                                /*
                                select_definition |
                                macro_definition |
                                */

/**** <procedure formal parameters> */
procedure_formal_parameters:    FPARtoken {procedure_formal_parameters_1();} /* CREATE name list */
                                    opt_comma_formal_var_param_list {procedure_formal_parameters_2();} /* DELETE last obsolete name list */
                                ;

opt_comma_formal_var_param_list:/* empty */ { $$ = NULL; } |
                                comma_formal_var_param_list
                                ;

comma_formal_var_param_list:    comma_formal_var_param_list
                                    COMMAtoken
                                    formal_variable_parameters |
                                formal_variable_parameters 
                                ;

/**** <formal variable parameters> */
formal_variable_parameters:     parameter_kind parameters_of_sort {formal_variable_parameters_1($1, $2);} /* CREATE DSFormalParam + INSERT */
                                ;

/**** <parameter kind> */
parameter_kind:                 /* empty */ { $$ = "IN"; } |
                                in_out {$$ = $1;}
                                ;

in_out:                         INtoken SLASHtoken OUTtoken {$$ = "IN/OUT";} |
                                INtoken {$$ = "IN";}
                                ;

/**** <procedure result> */
procedure_result:               RETURNStoken
                                    opt_name
                                    sort {procedure_result_1($2, $3);} /* Result ist shorthand for special IN/OUT param see p. 42 Z100 */
                                ;

/**** <entity in procedure> */
entity_in_procedure:            data_definition |
                                variable_definition |
                                procedure_reference |
                                procedure_definition 
                                ;

/**** <procedure body> */
procedure_body:                 start opt_state_or_free_action_list |
                                state_or_free_action_list
                                ;

opt_procedure_body:             /* empty */ { $$ = NULL; } |
                                procedure_body
                                ;

/**** <channel definition> */
channel_definition:             CHANNELtoken
                                    name {channel_definition_1($2);} /* PUSH + INSERT DSChannel */
                                    opt_nodelay
                                    channel_path
                                    opt_channel_path
                                    /* opt_channel_body */
                                    ENDCHANNELtoken
                                    opt_name
                                    end {channel_definition_2($8);} /* POP DSChannel + Check Name */
                                ;

opt_nodelay:                    /* empty */ { $$ = NULL; } |
                                NODELAYtoken {opt_nodelay_1();}
                                ;

/**** <channel path> */
channel_path:                   FROMtoken
                                    channel_endpoint {channel_path_1($2);} /* SET Block1 Ref */
                                    TOtoken
                                    channel_endpoint {channel_path_2($5);} /* SET Block2 Ref */
                                    WITHtoken {channel_path_3();} /* PUSH + INSERT DSignalItemList */
                                    signallist {channel_path_4();} /* POP DSSignalItemList */
                                    end
                                ;

opt_channel_path:               /* empty */ { $$ = NULL; } |
                                channel_path { $$ = $1; }
                                ;

/**** channel endpoint> */
channel_endpoint:               ident_or_env /* opt_via_gate */ { $$ = $1; }
                                ;

ident_or_env:                   identifier { $$ = $1; }|
                                ENVtoken { $$ = DS_NAME_ENV; }
                                ;

/**** <signal route definition> */
signal_route_definition:        SIGNALROUTEtoken
                                    name {signal_route_definition_1($2);} /* PUSH + INSERT DSSignalRoute */
                                    signal_route_path
                                    opt_signal_route_path {signal_route_definition_2();} /* POP DSSignalRoute */
                                ;

/**** <signal route path> */
signal_route_path:              FROMtoken
                                    signal_route_endpoint {signal_route_path_1($2);} /* SET Process1 Ref */
                                    TOtoken
                                    signal_route_endpoint {signal_route_path_2($5);} /* SET Process2 Ref */
                                    WITHtoken {signal_route_path_3();} /* PUSH + INSERT DSignalItemList */
                                    signallist {signal_route_path_4();} /* POP DSSignalItemList */
                                    end
                                ;

opt_signal_route_path:          /* empty */ { $$ = NULL; } |
                                signal_route_path
                                ;

/**** <signal route endpoint> */
signal_route_endpoint:          ident_or_env /* opt_via_gate */ { $$ = $1; }
                                ;

/**** <channel connection> */
channel_connection:             CONNECTtoken {channel_to_channel_connection_1();} /* PUSH + INSERT DSChannel2ChannelConnection + CREATE ident list */
                                    comma_ident_list {channel_to_channel_connection_2();} /* SET ident list + CREATE ident list */
                                    ANDtoken
                                    comma_ident_list
                                    end {channel_to_channel_connection_3();} /* SET ident list + POP DSChannel2ChannelConnection */
                                ;

/**** <channel to route connection> */
channel_to_route_connection:    CONNECTtoken {channel_to_route_connection_1();} /* PUSH + INSERT DSChannel2RouteConnection + CREATE ident list */
                                    comma_ident_list {channel_to_route_connection_2();} /* SET ident list + CREATE ident list */
                                    ANDtoken
                                    comma_ident_list
                                    end {channel_to_route_connection_3();} /* SET ident list + POP DSChannel2RouteConnection */
                                ;

/**** <signal route to route connection> */
signal_route_to_route_connection: CONNECTtoken
                                    comma_ident_list
                                    ANDtoken
                                    comma_ident_list
                                    end
                                ;

/**** <signal definition> */
signal_definition:              SIGNALtoken {/* nichts tun s.u. */}
                                    comma_sig_def_item_list 
                                    end
                                ;

comma_sig_def_item_list:        comma_sig_def_item_list
                                    COMMAtoken
                                    signal_definition_item |
                                signal_definition_item
                                ;

/**** <signal definition item> */
signal_definition_item:         name {signal_definition_item_1($1);} /* PUSH + INSERT DSSignal */
                                    /* opt_formal_context_parameters */
                                    /* opt_specialization */
                                    opt_sort_list {signal_definition_item_2();} /* POP DSSignal */
                                    /* opt_signal_refinement */
                                ;

/**** <sort list> */
sort_list:                      LEFTPARtoken
                                    comma_sort_list
                                    RIGHTPARtoken
                                ;

opt_sort_list:                  /* empty */ { $$ = NULL; } |
                                sort_list
                                ;

comma_sort_list:                comma_sort_list
                                  COMMAtoken sort {comma_sort_list_1($3);} | /* INSERT Sort Ref in List */
                                sort {comma_sort_list_1($1);} /* INSERT Sort Ref in List */
                                ;

/**** <signallist definition> */
signallist_definition:          SIGNALLISTtoken
                                    name {signallist_definition_1($2);} /* PUSH + INSERT DSSignalList */
                                    EQUALtoken {signallist_definition_2();} /* PUSH + INSERT DSSignalItemList */
                                    signallist {signallist_definition_3();} /* POP DSSignalItemList */
                                    end {signallist_definition_4();} /* POP DSSignalList */
                                ;

/**** <signal list> entspricht DSSignalItemList */
signallist:                     signallist_item |
                                signallist
                                    COMMAtoken
                                    signallist_item
                                ;

opt_signallist:                 /* empty */ { $$ = NULL; } |
                                signallist
                                ;

/**** <signal list item> */
signallist_item:                identifier {signallist_item_1($1);} /* einzelnes Signal in Stack.top() einfuegen. */ |
                                LEFTPARtoken
                                    identifier {signallist_item_2($2);} /* Signalliste in Stack.Top() einfuegen. */
                                    RIGHTPARtoken
                                ;

/**** variable definition> */
variable_definition:            DCLtoken {variable_definition_1();} /* CREATE List */
                                    opt_history_item
                                    opt_revealed_exported_item
                                    variables_of_sort_list
                                    end {variable_definition_2();} /* DELETE List */
                                ;

opt_history_item:               /* empty */ { $$ = NULL; } |
                                HISTtoken {opt_history_item_1();} /* Set history indicator flag. */
                                ;

opt_revealed_exported_item:     /* empty */ { $$ = NULL; } |
                                revealed_exported_item
                                ;

revealed_exported_item:         REVEALEDtoken {revealed_exported_item_1();} | /* SET Flags */
                                EXPORTEDtoken {revealed_exported_item_2();} |
                                REVEALEDtoken EXPORTEDtoken {revealed_exported_item_3();} |
                                EXPORTEDtoken REVEALEDtoken {revealed_exported_item_3();} 
                                ;

/**** <variables of sort> */
variables_of_sort:              comma_var_exported_list
                                    sort {variables_of_sort_1($2);} /* SET DSSort for all list members */
                                    opt_var_init {variables_of_sort_2();} /* SET DSExpression for all list members (if on stack) */
                                ;

comma_var_exported_list:        comma_var_exported_list
                                    COMMAtoken var_exported |
                                    var_exported
                                ;

var_exported:                   name 
                                    opt_exported_as {var_exported_1($1, $2);} /* INSERT DSVariable + APPEND list */
                                ;

opt_var_init:                   /* empty */ { $$ = NULL; } |
                                var_init
                                ;

var_init:                       ASSIGNMENTtoken
                                    ground_expression
                                ;

variables_of_sort_list:         variables_of_sort_list
                                    COMMAtoken variables_of_sort |
                                variables_of_sort
                                ;

/**** <exported as> */
exported_as:                    AStoken identifier {$$ = $2;}
                                ;

opt_exported_as:                /* empty */ { $$ = NULL; } |
                                exported_as {$$ = $1;}
                                ;

/**** <view definition> */
/*
view_definition:                VIEWEDtoken comma_view_item_list end
                                ;

comma_view_item_list:           comma_view_item_list COMMAtoken view_item |
                                view_item
                                ;

view_item:                      comma_name_list sort
                                ;
*/

/**** <start> */
start:                          STARTtoken {start_1();} /* PUSH + INSERT DSTransition */
                                    opt_virtuality
                                    end 
                                    transition {start_2();} /* POP DSTransition */
                                ;

/**** <state> */
state:                          STATEtoken {state_1();}         /* PUSH DSState + CREATE name list */
                                    state_list {state_2();}     /* INSERT DSState + SET name list*/
                                    opt_awake_item {state_3();} /* QSDL: SET awake time */
                                    end
                                    opt_state_body_list
                                    opt_endstate_item {state_4($9);} /* POP DSState + Check Name */
                                ;


opt_state_body_list:            /* empty */ { $$ = NULL; } |
                                state_body_list
                                ;

state_body_list:                state_body_list state_body_item |
                                state_body_item
                                ;

state_body_item:                input_part |
                                priority_input |
                                save_part |
                                spontaneous_transition |
                                continuous_signal
                                ;

opt_endstate_item:              /* empty */ { $$ = NULL; } |
                                endstate_item
                                ;

endstate_item:                  ENDSTATEtoken opt_name end {$$ = $2;}
                                ;

/**** <state list> */
state_list:                     comma_name_list |
                                asterisk_state_list /* '*' MIT Ausnahmen */
                                ;

/**** <input part> */
input_part:                     basic_input_part
                                ;
                                /*
                                remote_procedure_input_transition
                                */

/**** <basic input part> */                                
basic_input_part:               INPUTtoken 
                                    opt_virtuality {basic_input_part_1();} /* PUSH + INSERT DSInput */
                                    input_list
                                    end
                                    opt_enabling_condition {basic_input_part_2();} /* SET DSExpression (if on stack) + PUSH DSTransition */
                                    transition {basic_input_part_3();} /* POP DSTransition + POP DSInput */
                                ;

/**** <input list> */
input_list:                     asterisk_input_list | /* '*' OHNE Ausnahmen */
                                comma_stimulus_list
                                ;

/**** <stimulus> */
stimulus:                       identifier {stimulus_1($1);}
                                    opt_par_comma_opt_var_list {stimulus_2();}
                                ;

opt_par_comma_opt_var_list:     /* empty */ { $$ = NULL; } |
                                par_comma_opt_var_list
                                ;

par_comma_opt_var_list:         LEFTPARtoken comma_opt_var_list RIGHTPARtoken
                                ;

comma_opt_var_list:             comma_opt_var_list COMMAtoken opt_variable |
                                opt_variable
                                ;

comma_stimulus_list:            comma_stimulus_list COMMAtoken stimulus |
                                stimulus
                                ;

/**** <save part> */
save_part:                      basic_save_part
                                ;
                                /*
                                remote_procedure_save
                                */

/**** <basic save part> */
basic_save_part:                SAVEtoken
                                    opt_virtuality {basic_save_part_1();} /* PUSH + INSERT DSSave + PUSH DSSignalItemList */
                                    save_list
                                    end {basic_save_part_2();} /* SET + POP DSSignalItemList + POP DSSave */
                                ;

/**** <save list> */
save_list:                      signallist |
                                asterisk_save_list
                                ;

/**** <spontaneous transition> */
spontaneous_transition:         INPUTtoken 
                                    opt_virtuality
                                    spontaneous_designator {spontaneous_transition_1();} /* PUSH + INSERT DSInput */
                                    end
                                    opt_enabling_condition {spontaneous_transition_2();} /* SET DSExpression (if on stack) + PUSH DSTransition */
                                    transition {spontaneous_transition_3();} /* POP DSTransition + POP DSInput */
                                ;
                                
/**** <spontaneous designator> */
spontaneous_designator:         NONEtoken
                                ;

/**** <label> */
label:                          name COLONtoken {$$ = $1;}
                                ;

opt_label:                      /* empty */ { $$ = NULL; } |
                                label
                                ;

/**** <free action> */
free_action:                    CONNECTIONtoken
                                    transition
                                    opt_endconnection_item
                                ;

opt_endconnection_item:         /* empty */ { $$ = NULL; } |
                                endconnection_item
                                ;

endconnection_item:             ENDCONNECTIONtoken
                                    opt_name
                                    end {$$ = $2;}
                                ;

/**** <transition> */
transition:                     transition_string
                                    opt_terminator_statement |
                                terminator_statement
                                ;

opt_transition:                 /* empty */ { $$ = NULL; } |
                                transition
                                ;

/**** <transition string> */
transition_string:              transition_string
                                    action_statement |
                                action_statement
                                ;

/**** action statement> */
action_statement:               opt_label {action_statement_1($1);} /* STORE label */
                                    action
                                    end {action_statement_2();} /* Cleanup */
                                ;

/**** <action> */
action:                         request /* QSDL */ |
                                task |
                                output |
                                create_request |
                                decision |
                                set |
                                reset |
                                procedure_call |
                                update /* QSDL */ |
                                clear /* QSDL */ |
                                assert /* QSDL */
                                ;
                                /*
                                transition_option |
                                export |
                                remote_procedure_call
                                */

/**** <terminator statement> */
terminator_statement:           opt_label {terminator_statement_1($1);} /* STORE label */
                                    terminator
                                    end {terminator_statement_2();} /* Cleanup */
                                ;

opt_terminator_statement:       /* empty */ { $$ = NULL; } |
                                terminator_statement
                                ;

/**** <terminator> */
terminator:                     nextstate |
                                join |
                                stop |
                                return
                                ;

/**** <nextstate> */
nextstate:                      NEXTSTATEtoken
                                    nextstate_body {nextstate_1($2);} /* INSERT DSNextstate */
                                ;

nextstate_body:                 name {$$ = $1;} |
                                dash_nextstate {$$ = "-";}
                                ;

/**** <join> */
join:                           JOINtoken name {join_1($2);}
                                ;

/**** <stop> */
stop:                           STOPtoken {stop_1();}
                                ;

/**** <return> */
return:                         RETURNtoken opt_expression {return_1();}
                                ;

/**** <task> */
task:                           TASKtoken {task_1();} /* PUSH DSTask */
                                    task_body;

task_body:                      comma_assignment_statement_list |
                                comma_informal_text_list
                                ;

comma_assignment_statement_list: comma_assignment_statement_list
                                    COMMAtoken {task_1();}
                                    assignment_statement {comma_assignment_statement_list_1();} /* SET DSExpression + POP DSTask */ |
                                assignment_statement {comma_assignment_statement_list_1();} /* SET DSExpression + POP DSTask */
                                ;

comma_informal_text_list:       comma_informal_text_list
                                  COMMAtoken {task_1();}
                                  informal_text {comma_informal_text_list_1($1);} /* SET Text + POP DSTask + PUSH DSTask */ |
                                informal_text {comma_informal_text_list_1($1);} /* SET Text + POP DSTask + PUSH DSTask */
                                ;

/**** <create request> */
create_request:                 CREATEtoken create_body
                                ;

/**** <create body> */
create_body:                    ident_or_this 
                                    opt_actual_parameters {create_body_1($1);} /* INSERT DSCreate */
                                ;

ident_or_this:                  identifier /* |
                                THIStoken {$$ = DS_SORT_OPERATOR_NAME_THIS;} this is allowed in <process type definition> only, see Z100 p. 63 */ 
                                ;

/**** <actual parameters> */
actual_parameters:              par_comma_opt_expr_list
                                ;

opt_actual_parameters:          /* empty */ { $$ = NULL; } |
                                actual_parameters
                                ;

/**** <procedure call> */
procedure_call:                 CALLtoken procedure_call_body
                                ;

/* <procedure call body> */
procedure_call_body:        /*    opt_this */
                                    identifier {procedure_call_body_1($1);} /* PUSH DSCall */
                                    opt_actual_parameters {procedure_call_body_2();} /* INSERT DSExpression + POP DSCall */
                                ;

/**** <output> */
output:                         OUTPUTtoken {output_1();} /* CREATE output list */
                                    output_body
                                ;

/**** <output body> */
output_body:                    comma_ident_actual_param_list
                                    opt_to_destination {output_body_1();} /* SET destination (if DSExpression on stack) + CREATE ident list */
                                    opt_via_path_item {output_body_2();} /* SET ident list */
                                    opt_delay {output_body_3();} /* SET output delay */
                                ;

comma_ident_actual_param_list:  comma_ident_actual_param_list COMMAtoken
                                    ident_actual_param |
                                ident_actual_param
                                ;

ident_actual_param:             identifier
                                    opt_actual_parameters {ident_actual_param_1($1);}
                                ;

opt_to_destination:             /* empty */ { $$ = NULL; } |
                                to_destination
                                ;

to_destination:                 TOtoken destination
                                ;

opt_via_path_item:              /* empty */ { $$ = NULL; } |
                                via_path_item
                                ;

via_path_item:                  VIAtoken opt_all via_path
                                ;

opt_all:                        /* empty */ { $$ = NULL; } |
                                ALLtoken
                                ;

/**** <opt_delay> (QSDL) */

opt_delay:                      /* empty */ { $$ = NULL; } |
                                delay
                                ;
                                
delay:                          DELAYtoken expression
                                ;

/**** <destination> */
destination:                    expression |
                                /* identifier | */ /* r/r-conflict! */
                                THIStoken {constant_expression(DS_SORT_OPERATOR_NAME_THIS);} /* PUSH DSExpression (DSOperand: textual constant) */
                                ;

/**** <via path> */
via_path:                       comma_ident_list
                                ;

/**** <decision> */
decision:                       DECISIONtoken {decision_1();} /* PUSH + INSERT DSDecision */
                                    question {decision_2();} /* SET DSExpression (if on stack) */
                                    end
                                    decision_body
                                    ENDDECISIONtoken {decision_3();} /* POP DSDecision */
                                ;

/**** <decision body> */
decision_body:                  answer_part else_part |
                                answer_part answer_part_list opt_else_part
                                ;

/**** <answer part> */
answer_part:                    LEFTPARtoken
                                    opt_answer /* DSRange inserts itself in DSDecision */
                                    RIGHTPARtoken
                                    COLONtoken {answer_part_1();} /* PUSH + INSERT DSTransition */
                                    opt_transition {answer_part_2();} /* POP DSTransition */
                                ;

answer_part_list:               answer_part_list answer_part |
                                answer_part
                                ;

/**** <answer> */
answer:                         range_condition |
                                informal_text
                                ;

opt_answer:                     /* empty */ { $$ = NULL; } |
                                answer
                                ;

/**** <else part> */
else_part:                      ELSEtoken
                                    COLONtoken {else_part_1();}
                                    opt_transition {else_part_2();}
                                ;

opt_else_part:                  /* empty */ { $$ = NULL; } |
                                else_part
                                ;

/**** <question> */
question:                       expression |
                                informal_text |
                                ANYtoken
                                ;

/**** <timer definition> */
timer_definition:               TIMERtoken
                                    timer_definition_item_list
                                    end
                                ;

/**** <timer defintion item> */
timer_definition_item:          name {timer_definition_item_1($1);} /* PUSH + INSERT DSTimer + CREATE sort list */
                                    opt_sort_list
                                    opt_timer_init {timer_definition_item_2();} /* SET Sort list + SET init (if DSExpression on stack) + POP DSTimer */
                                ;

opt_timer_init:                 /* empty */ { $$ = NULL; } |
                                timer_init
                                ;

timer_init:                     ASSIGNMENTtoken ground_expression
                                ;

timer_definition_item_list:     timer_definition_item_list COMMAtoken
                                    timer_definition_item |
                                timer_definition_item
                                ;

/**** <reset> */
reset:                          RESETtoken par_comma_reset_statement_list
                                ;

par_comma_reset_statement_list: LEFTPARtoken comma_reset_statement_list
                                    RIGHTPARtoken
                                ;

/**** <reset statement> */
reset_statement:                identifier
                                    opt_par_expression_list {reset_statement_1($1);}
                                ;

comma_reset_statement_list:     comma_reset_statement_list COMMAtoken reset_statement |
                                reset_statement
                                ;

/**** <set> */
set:                            SETtoken comma_set_statement_list
                                ;

/**** <set statement> */
set_statement:                  LEFTPARtoken
                                    expr_comma
                                    identifier
                                    opt_par_expression_list
                                    RIGHTPARtoken {set_statement_1($3);} /* INSERT DSSet + SET time + SET index list */
                                ;

expr_comma:                     expression COMMAtoken
                                ;

comma_set_statement_list:       comma_set_statement_list COMMAtoken
                                    set_statement |
                                set_statement
                                ;

/**** <simple expression> */
simple_expression:              ground_expression
                                ;

/**** <asterisk state list> */
asterisk_state_list:            ASTERISKtoken {asterisk_state_list_1();} /* *-FLAG setzen */
                                    opt_par_comma_name_list
                                ;

/**** <asterisk input list> */
asterisk_input_list:            ASTERISKtoken
                                ;

/**** <asterisk save list> */
asterisk_save_list:             ASTERISKtoken
                                ;

/**** <dash nextstate> */
dash_nextstate:                 MINUStoken
                                ;

/**** <priority input> */
priority_input:                 PRIORITYtoken
                                    INPUTtoken
                                    opt_virtuality {priority_input_1();} /* PUSH + INSERT DSInput */
                                    priority_input_list
                                    end  {priority_input_2();} /* PUSH + INSERT DSTransition */
                                    transition {priority_input_3();} /* POP DSTransition + POP DSInput */
                                ;

/**** <priority input list> */
priority_input_list:            comma_stimulus_list
                                ;

/**** <continuous signal> */
continuous_signal:              PROVIDEDtoken
                                    opt_virtuality {continuous_signal_1();} /* PUSH + INSERT DSInput */
                                    expression {continuous_signal_2();} /* SET DSExpression + PUSH + INSERT DSTransition */
                                    end
                                    opt_priority_name_end_item
                                    transition {continuous_signal_3($7);} /* POP DSTransition + POP DSInput */
                                ;

opt_priority_name_end_item:     /* empty */ { $$ = NULL; } |
                                priority_name_end_item
                                ;

priority_name_end_item:         PRIORITYtoken name end {$$ = $2;}
                                ;

/**** <enabling condition> */
enabling_condition:             PROVIDEDtoken expression end
                                ;

opt_enabling_condition:         /* empty */ { $$ = NULL; } |
                                enabling_condition
                                ;

/**** <partial type definition> */
partial_type_definition:        NEWTYPEtoken
                                    name {partial_type_definition_1($2);} /* STORE name */
                                    /* opt_formal_context_parameters */
                                    opt_extended_properties /* Generator or Struct */
                                    properties_expression /* Default Value + Literal list + Operatoren */
                                    ENDNEWTYPEtoken
                                    opt_name {partial_type_definition_2($7);} /* SET default init + POP DSSort (if DSGenerator or DSStruct or DSSortExtended on stack) */
                                ;

/**** <properties expression> */
properties_expression:          operators /* int_ext_props */
                                /* r/r conflict in composite_term_list */
                                    opt_default_initialization
                                ;

/**** <operators> */
operators:                      opt_literal_list opt_operator_list
                                ;

/**** <literal list> */
literal_list:                   LITERALStoken {literal_list_1();} /* Eventuell PUSH DSSortExtended + CREATE Name List */
                                    comma_literal_signature_list
                                    opt_end {literal_list_2();} /* Set Name List */
                                ;

opt_literal_list:               /* empty */ { $$ = NULL; } |
                                literal_list
                                ;

/**** <literal signature> */
literal_signature:              name
                                ;

comma_literal_signature_list:   comma_literal_signature_list
                                    COMMAtoken
                                    literal_signature {comma_literal_signature_list_1($3);} |
                                literal_signature {comma_literal_signature_list_1($1);}
                                ;

/**** <operator list> */
operator_list:                  OPERATORStoken
                                    operator_signature_end_list
                                    opt_end
                                ;

operator_signature_end_list:    operator_signature_end_list end
                                    operator_signature |
                                operator_signature
                                ;

opt_operator_list:              /* empty */ { $$ = NULL; } |
                                operator_list
                                ;

/**** <operator_signature> */
operator_signature:             operator_name
                                    COLONtoken {operator_signature_1();} /* CREATE sort list */
                                    comma_sort_list /* argument_list */
                                    THINARROWtoken
                                    result {operator_signature_2($1, $5);} |
                                ordering |
                                noequality
                                ;

/**** <operator name> */
operator_name:                  name
                                ;
                                /*
                                extended_operator_name
                                */

/**** <result> */
result:                         extended_sort
                                ;

/**** <extended sort> */
extended_sort:                  sort
                                ;
                                /*
                                generator_sort
                                */

/**** <sort> */
sort:                           identifier { $$ = $1; }
                                ;
                                /* <syntype> leads to reduce/reduce conflict. */

opt_sort:                       /* empty */ { $$ = NULL; } |
                                sort { $$ = $1; }
                                ;

/**** <ground term> */
/* ground_term is syntactically a subset of composite_term */

/**** <extended properties> */
extended_properties:            structure_definition |
                                generator_transformations
                                ;
                                /*
                                inheritance_rule |
                                */

opt_extended_properties:        /* empty */ { $$ = NULL; } |
                                extended_properties
                                ;


/**** <quoted operator> */
quoted_operator:                quote infix_operator quote |
                                quote monadic_operator quote
                                ;

/**** <quote> */
quote:                          QUOTEtoken
                                ;

/**** <infix operator> */
infix_operator:                 THICKARROWtoken |
                                ORtoken |
                                XORtoken |
                                ANDtoken |
                                INtoken |
                                NOTEQUALtoken |
                                EQUALtoken |
                                GREATERtoken |
                                LESStoken |
                                LESSEQUALtoken |
                                GREATEREQUALtoken |
                                PLUStoken |
                                SLASHtoken |
                                ASTERISKtoken |
                                CONCATENATIONtoken |
                                MODtoken |
                                REMtoken |
                                MINUStoken
                                ;

/**** <monadic operator> */
monadic_operator:               NOTtoken
                                /* MINUStoken */
                                /* r/r conflict with infix_operator */
                                ;

/**** <noequality> */
noequality:                     NOEQUALITYtoken
                                ;


/**** <ordering> */
ordering:                       ORDERINGtoken
                                ;

/**** <syntype> */
                                /* syntype is an identifier and thus leads to
                                   reduce/reduce conflicts. */

/**** <syntype definition> */
syntype_definition:             SYNTYPEtoken
                                    name {syntype_definition_1($2);} /* PUSH + INSERT DSSyntype */
                                    EQUALtoken
                                    parent_sort_identifier {syntype_definition_2($5);} /* SET parent sort */
                                    opt_default_initialization
                                    opt_const_range_item
                                    ENDSYNTYPEtoken
                                    opt_name {syntype_definition_3($10);} /* SET default init + POP DSSyntype + Check Name */
/*                                    |
                                NEWTYPEtoken
                                    name
                                    opt_extended_properties
                                    properties_expression
                                    CONSTANTStoken
                                    range_condition
                                    ENDNEWTYPEtoken
                                    opt_name */
                                ;

const_range_item:               CONSTANTStoken
                                    range_condition
                                ;

opt_const_range_item:           /* empty */ { $$ = NULL; } |
                                const_range_item
                                ;

/**** <parent sort identifier> */
parent_sort_identifier:         identifier
                                ;

/**** <range condition> */
range_condition:                range_condition COMMAtoken closed_open_range |
                                closed_open_range
                                ;

closed_open_range:              closed_range |
                                open_range
                                ;

/**** <closed range> */
closed_range:                   constant COLONtoken constant {closed_range_1();} /* CREATE + INSERT DSRange + SET DSExpressions */
                                ;

/**** <open range> */
open_range:                     constant {open_range_1();} |
                                range_op constant {open_range_2($1);}
                                ;

range_op:                       EQUALtoken {$$ = DS_RANGE_OPT_EQUAL;} |
                                NOTEQUALtoken {$$ = DS_RANGE_OPT_NOT_EQUAL;} |
                                LESStoken {$$ = DS_RANGE_OPT_LESS;} |
                                GREATERtoken {$$ = DS_RANGE_OPT_GREATER;} |
                                LESSEQUALtoken {$$ = DS_RANGE_OPT_LESS_EQUAL;} |
                                GREATEREQUALtoken {$$ = DS_RANGE_OPT_GREATER_EQUAL;} 
                                ;

/**** <constant> */
constant:                       ground_expression
                                ;

/**** <structure definition> */
structure_definition:           STRUCTtoken {structure_definition_1();} /* PUSH DSStruct */
                                  field_list
                                  opt_end
                                  opt_adding {structure_definition_2();} /* do nothing */
                                ;

opt_adding:                     /* empty */ { $$ = NULL; } |
                                ADDINGtoken
                                ;

/**** <field list> */
field_list:                     field_list end fields |
                                fields
                                ;

/**** <fields> */
fields:                         comma_name_list
                                    field_sort {fields_1($2);}
                                ;

/**** <field sort> */
field_sort:                     sort {$$ = $1;}
                                ;
/**** <generator transformations> */
generator_transformations:      generator_transformations
                                    generator_trans_item |
                                generator_trans_item
                                ;

generator_trans_item:           generator_transformation
                                    opt_end
                                    opt_adding
                                ;

/**** <generator transformation> */
generator_transformation:       identifier
                                    LEFTPARtoken {generator_transformation_1($1);} /* PUSH DSGenerator + CREATE Actual (sort) list*/
                                    generator_actual_list
                                    RIGHTPARtoken {generator_transformation_2();} /* SET Actual Sort List */
                                ;

/**** <generator actual list> */
generator_actual_list:          generator_actual_list
                                    COMMAtoken
                                    generator_actual {generator_actual_list_1($3);} /* INSERT sort in current generator actual list */ |
                                generator_actual {generator_actual_list_1($1);} /* INSERT sort in current generator actual list */
                                ;

/**** <gnerator actual> */
generator_actual:               extended_sort {$$ = $1;}
                                ;
                                /*
                                literal_signature |
                                operator_name |
                                ground_term
                                */

/**** <synonym_definition> */
synonym_definition:             internal_synonym_definition /* |
                                external_synonym_definition */
                                ;

/**** <internal synonym definition> */
internal_synonym_definition:    SYNONYMtoken
                                  comma_synonym_definition_item_list
                                ;

/**** <synonym definition item> */
synonym_definition_item:        name {synonym_definition_item_1($1);} /* PUSH + INSERT DSSynonym */
                                  opt_sort {synonym_definition_item_2($3);} /* SET Sort */
                                  EQUALtoken
                                  ground_expression {synonym_definition_item_3();} /* POP DSSynonym */
                                ;

comma_synonym_definition_item_list: comma_synonym_definition_item_list
                                    COMMAtoken synonym_definition_item |
                                synonym_definition_item
                                ;

/**** <ground_expression> */
ground_expression:              expression
                                /* watch out for reduce/reduce-conflicts! */
                                ;

/**** <expression> */
expression:                     sub_expression |
                                value_returning_procedure_call 
                                ;

opt_expression:                 /* empty */ {opt_expression_1(); } |  /* PUSH empty DSExpression */
                                expression
                                ;

/**** <sub expression> */
sub_expression:                 operand0 |
                                sub_expression
                                    THICKARROWtoken
                                    operand0 {operand_binary(DS_OPT_THICKARROW);}
                                ;

/**** <operand0> */
operand0:                       operand1 |
                                operand0
                                    or_op
                                    operand1 {operand_binary($2);}
                                ;

or_op:                          ORtoken {$$ = DS_OPT_OR;} |
                                XORtoken {$$ = DS_OPT_XOR;}
                                ;

/**** <operand1> */
operand1:                       operand2 |
                                operand1
                                    ANDtoken
                                    operand2 {operand_binary(DS_OPT_AND);} 
                                ;

/**** <operand2> */
operand2:                       operand3 |
                                operand2
                                    equ_op
                                    operand3 {operand_binary($2);} 
                                ;

equ_op:                         EQUALtoken {$$ = DS_OPT_EQUAL;} |
                                NOTEQUALtoken {$$ = DS_OPT_NOT_EQUAL;} |
                                GREATERtoken {$$ = DS_OPT_GREATER;} |
                                GREATEREQUALtoken {$$ = DS_OPT_GREATER_EQUAL;} |
                                LESStoken {$$ = DS_OPT_LESS;} |
                                LESSEQUALtoken {$$ = DS_OPT_LESS_EQUAL;} |
                                INtoken {$$ = DS_OPT_IN;} 
                                ;

/**** <operand3> */
operand3:                       operand4 |
                                operand3 add_op operand4 {operand_binary($2);} 
                                ;

add_op:                         PLUStoken {$$ = DS_OPT_ADDITION;} |
                                MINUStoken {$$ = DS_OPT_SUBTRACTION;} |
                                CONCATENATIONtoken {$$ = DS_OPT_CONCATENATION;}
                                ;

/**** <operand4> */
operand4:                       operand5 |
                                operand4 div_op operand5 {operand_binary($2);} 
                                ;

div_op:                         ASTERISKtoken {$$ = DS_OPT_MULTIPLICATION;} |
                                SLASHtoken {$$ = DS_OPT_DIVISION;} |
                                MODtoken {$$ = DS_OPT_MOD;} |
                                REMtoken {$$ = DS_OPT_REM;} 
                                ;

/**** <operand5> */
operand5:                       opt_unary_op
                                    primary {operand_unary($1);}
                                ;

opt_unary_op:                   /* empty */  {$$ = DS_OPT_NONE;}  |
                                unary_op {$$ = $1;}
                                ;

unary_op:                       MINUStoken {$$ = DS_OPT_MINUS;} |
                                NOTtoken {$$ = DS_OPT_NOT;} 
                                ;

/**** <primary> */

primary:                        identifier {primary_1($1);} /* PUSH DSExpression */ |
                                CHARSTRINGtoken {primary_2($1);} | /* PUSH DSExpression */
                                LEFTPARtoken expression RIGHTPARtoken |
                                indexed_primary /* POP DSExpression + SET index */ |
                                field_primary /* SET field */ |
                                imperative_operator /* PUSH DSExpression NOW, SELF, OFFSPRING, etc. */
                                ;

/**** <ground_expression_list> 
ground_expression_list:         ground_expression_list
                                    COMMAtoken
                                    ground_expression |
                                ground_expression
                                ; */

/**** <indexed primary> */
indexed_primary:                primary
                                    LEFTPARtoken {indexed_primary_1();}
                                    expression_list
                                    RIGHTPARtoken {indexed_primary_2();} |
                                primary EXCLAMATIONtoken  /* z.B. duration!(real) */
                                    LEFTPARtoken {indexed_primary_1();}
                                    expression_list
                                    RIGHTPARtoken {indexed_primary_2();}
                                ; /* watch for reduce/reduce-conflicts! */

/**** <field_primary> */
field_primary:                  primary
                                    field_selection {field_primary_1($2);}
                                ;

/**** <field_selection> */
field_selection:                EXCLAMATIONtoken name {$$ = $2;}
                                /* LEFTPARtoken comma_name_list RIGHTPARtoken */
                                ;

/**** <data definition> */
data_definition:                def_item end
                                ;

def_item:                       partial_type_definition |
                                syntype_definition |
                                synonym_definition 
                                ;
                                /*
                                generator_definition
                                */

/**** <expression_list> */
expression_list:                expression_list COMMAtoken expression |
                                expression
                                ;

par_comma_opt_expr_list:        LEFTPARtoken comma_opt_expr_list RIGHTPARtoken
                                ;

comma_opt_expr_list:            comma_opt_expr_list COMMAtoken opt_expression |
                                opt_expression
                                ;

opt_par_expression_list:        /* empty */ { $$ = NULL; } |
                                par_expression_list
                                ;

par_expression_list:            LEFTPARtoken expression_list RIGHTPARtoken
                                ;

/**** <assignment_statement> */
assignment_statement:           variable ASSIGNMENTtoken expression
                                ;

/**** <variable> */
variable:                       identifier {variable_1($1);} /* INSERT + STORE DSVariableAccess */ |
                                indexed_variable |
                                field_variable
                                ; /* watch for reduce/reduce-conflicts! */

opt_variable:                   /* empty */ {opt_variable_1(); } | /* PUSH empty DSVariable */
                                variable
                                ;

/**** <indexed variable> */
indexed_variable:               variable 
                                    LEFTPARtoken
                                    expression_list
                                    RIGHTPARtoken {indexed_variable_1();} /* INSERT DSExpressions (if on stack) */
                                ;

/**** <field variable> */
field_variable:                 variable
                                    field_selection {field_variable_1($2);} /* INSERT field name */
                                ;

/**** <default initialization> */
default_initialization:         DEFAULTtoken ground_expression opt_end
                                ;

opt_default_initialization:     /* empty */ { $$ = NULL; } |
                                default_initialization
                                ;

/**** <imperative operator> */
imperative_operator:            now_expression |
                                PID_expression |
                                EXTERNALtoken {constant_expression(DS_NAME_EXTERNAL);}
                                ;
                                /*
                                timer_active_expression |
                                view_expression |
                                anyvalue_expression
                                import_expression |
                                */

/**** <now expression> */
now_expression:                 NOWtoken {constant_expression(DS_SORT_OPERATOR_NAME_NOW);}  /* PUSH DSExpression (DSOperand: textual constant) */
                                ;

/**** <PID expression> */
PID_expression:                 SELFtoken {constant_expression(DS_SORT_OPERATOR_NAME_SELF);} | /* PUSH DSExpression (DSOperand: textual constant) */
                                PARENTtoken {constant_expression(DS_SORT_OPERATOR_NAME_PARENT);} |
                                OFFSPRINGtoken {constant_expression(DS_SORT_OPERATOR_NAME_OFFSPRING);} |
                                SENDERtoken {constant_expression(DS_SORT_OPERATOR_NAME_SENDER);}
                                ;

/**** <value returning procedure call> */
value_returning_procedure_call: procedure_call
                                ;
                                /*
                                remote_procedure_call
                                */

/**** <virtuality> */
virtuality:                     VIRTUALtoken |
                                REDEFINEDtoken |
                                FINALIZEDtoken
                                ;

opt_virtuality:                 /* empty */ { $$ = NULL; } |
                                virtuality
                                ;

/********************** QSDL extension ***********************/
/**** <machineservice definition> */
machine_service_definition:     MACHINESERVICEtoken
                                    comma_ms_def_item_list
                                    end
                                ;

comma_ms_def_item_list:         comma_ms_def_item_list
                                    COMMAtoken
                                    machineservice_definition_item |
                                machineservice_definition_item
                                ;

machineservice_definition_item: name {machineservice_definition_item_1($1);} /* PUSH + INSERT DSMachineService */
                                    opt_sort_list {machineservice_definition_item_2();} /* SET sort list + POP DSMachineService */
                                ;

/**** <textual machine reference> */
machine_reference:              MACHINEtoken
                                    identifier
                                    REFERENCEDtoken
                                    end {machine_reference_1($2);} /* INSERT + APPEND DSMachine */
                                ;

/**** <machine definition> */
machine_definition:             MACHINEtoken
                                    identifier
                                    end {machine_definition_1($2);} /* PUSH + INSERT DSMachine */
                                    mach_body_list
                                    ENDMACHINEtoken
                                    opt_name
                                    end {machine_definition_4($7);} /* POP DSMachine + Check Name */
                                ;


mach_body_list:                 mach_body_list
                                    mach_body_list_item |
                                mach_body_list_item
                                ;
                                
mach_body_list_item:            server_item end {machine_definition_2();} /* SET servers (if DSExpression on stack) */ |
                                discipline_item end {machine_definition_3();} /* SET discipline (if DSExpression on stack) */ |
                                OFFERStoken
                                    machservice_name_speed_list end |
                                SENSORtoken mach_sensor_list end
                                ;

server_item:                    SERVERtoken
                                    expression
                                ;

discipline_item:                DISCIPLINEtoken
                                    ground_expression
                                ;

machservice_name_speed_list:    machservice_name_speed_list
                                    COMMAtoken
                                    machservice_name_speed_list_item |
                                machservice_name_speed_list_item
                                ;

machservice_name_speed_list_item: name
                                    COLONtoken
                                    machineservice_speed {machservice_name_speed_list_item_1($1);}
                                ;

machineservice_speed:           ground_expression
                                ;

mach_sensor_list:               mach_sensor_list
                                    COMMAtoken
                                    mach_sensor_definition |
                                mach_sensor_definition
                                ;

mach_sensor_definition:         identifier
                                    mach_sensor_type { mach_sensor_definition_1 ($1, $2); } |
                                identifier
                                    mach_sensor_type_param
                                    opt_par_comma_name_list { mach_sensor_definition_2 ($1, $2); }
                                ;

mach_sensor_type:               FREQREQUESTtoken { $$ = DS_SENSOR_MACH_FREQ_REQUEST; } |
                                QUEUELENGTHtoken { $$ = DS_SENSOR_MACH_QUEUE_LENGTH; } |
                                QUEUECONTENTtoken { $$ = DS_SENSOR_MACH_QUEUE_CONTENT; } |
                                UTILIZATIONtoken { $$ = DS_SENSOR_MACH_UTILIZATION; }
                                ;
                                
mach_sensor_type_param:         COUNTREQUESTtoken { $$ = DS_SENSOR_MACH_COUNT_REQUEST; } |
                                WAITTIMEREQUESTtoken { $$ = DS_SENSOR_MACH_WAITTIME_REQUEST; } |
                                THROUGHPUTtoken { $$ = DS_SENSOR_MACH_THROUGHPUT;} |
                                SERVICETIMEREQUESTtoken { $$ = DS_SENSOR_MACH_SERVICETIME_REQUEST; }
                                ;
                                
pipe_definition:                PIPEtoken
                                    name {pipe_definition_1($2);} /* PUSH + INSERT DSPipe */
                                    pipe_path
                                    opt_pipe_path
                                    ENDPIPEtoken
                                    opt_name
                                    end {pipe_definition_2($6);} /* POP DSPipe + Check Name */
                                ;

pipe_path:                      FROMtoken
                                    pipe_endpoint {pipe_path_1($2);} /* SET Block1 Ref */
                                    TOtoken
                                    pipe_endpoint {pipe_path_2($5);} /* SET Block2 Ref + CREATE service list */
                                    WITHtoken
                                    machineservicelist {pipe_path_3();} /* SET service list */
                                    end
                                ;

opt_pipe_path:                  /* empty */ { $$ = NULL; } |
                                pipe_path { $$ = $1; }
                                ;

/**** pipe endpoint> */
pipe_endpoint:                  ident_or_env /* opt_via_gate */ { $$ = $1; }
                                ;

link_definition:                LINKtoken
                                    name {link_definition_1($2);} /* PUSH + INSERT DSLink */
                                    link_path {link_definition_2();} /* POP DSLink */
                                ;

link_path:                      FROMtoken
                                    link_endpoint {link_path_1($2);} /* SET Process Ref */
                                    TOtoken
                                    link_endpoint {link_path_2($5);} /* SET Machine Ref + CREATE service list */
                                    WITHtoken
                                    machineservicelist {link_path_3();} /* SET service list */
                                    end
                                ;

/**** link endpoint> */
link_endpoint:                  ident_or_env /* opt_via_gate */ { $$ = $1; }
                                ;

machineservicelist:             comma_ident_list
                                ;

pipe_binding:                   BINDtoken {pipe_to_pipe_binding_1();} /* PUSH + INSERT DSPipe2PipeBinding + CREATE ident list */
                                    comma_ident_list {pipe_to_pipe_binding_2();} /* SET ident list + CREATE ident list */
                                    TOtoken
                                    comma_ident_list
                                    end {pipe_to_pipe_binding_3();} /* SET ident list + POP DSPipe2PipeBinding */
                                ;

pipe_to_link_binding:           BINDtoken {pipe_to_link_binding_1();} /* PUSH + INSERT DSPipe2LinkBinding + CREATE ident list */
                                    comma_ident_list {pipe_to_link_binding_2();} /* SET ident list + CREATE ident list */
                                    TOtoken
                                    comma_ident_list
                                    end {pipe_to_link_binding_3();} /* SET ident list + POP DSPipe2LinkBinding */
                                ;

opt_awake_item:                 /* empty */ { $$ = NULL; } |
                                awake_item
                                ;

awake_item:                     AWAKEtoken
                                    expression
                                ;

/**** <request> */
request:                        REQUESTtoken {request_1();} /* CREATE request list */
                                    request_body
                                ;

/**** <request body> */
request_body:                   request_parameter_list
                                    opt_target
                                ;


opt_target:                     /* empty */ { $$ = NULL; } |
                                via_request_path { request_body_1(); } | /* SET identifier list */
                                from_item { request_body_2($1); }        /* SET identifier */
                                ;


from_item:                      FROMtoken identifier { $$ = $2; }


/**** <request parameters> */
request_parameter_list:         request_parameter_list
                                    COMMAtoken
                                    request_parameter |
                                request_parameter
                                ;

request_parameter:              identifier
                                    LEFTPARtoken
                                    expression
                                    opt_comma_priority
                                    RIGHTPARtoken {request_parameter_1($1);}
                                ;
                                
opt_comma_priority:             /* empty */ { $$ = NULL; } |
                                comma_priority
                                ;

comma_priority:                 COMMAtoken
                                    priority
                                ;

/**** <priority> */
priority:                       expression
                                ;


via_request_path:               VIAtoken
                                    via_path
                                ;
                                
/**** <clear> */
clear:                          CLEARtoken LEFTPARtoken
                                    identifier
                                    RIGHTPARtoken {clear_1($3);}
                                ;

/**** <update> */
update:                         UPDATEtoken LEFTPARtoken
                                    identifier opt_update_body
                                    RIGHTPARtoken {update_1($3);}
                                ;

opt_update_body:                /* empty */ { $$ = NULL; } |
                                update_body
                                ;

update_body:                    COMMAtoken
                                    expression opt_comma_value
                                ;
                                
opt_comma_value:                /* empty */ { $$ = NULL; } |
                                comma_value
                                ;

comma_value:                    COMMAtoken
                                    expression
                                ;

/**** <assert> */
assert:                         ASSERTtoken LEFTPARtoken
                                    expression
                                    RIGHTPARtoken {assert_1();}
                                ;

/**** <atom_definition> */

opt_atom_definition:            /* empty */ { $$ = NULL; } |
                                atom_definition
                                ;


atom_definition:                atom_definition
                                    atom_definition_item |
                                atom_definition_item
                                ;

atom_definition_item:           ATOMtoken
                                    name_expr_pair_list
                                    end
                                ;

name_expr_pair_list:            name_expr_pair_list
                                  COMMAtoken
                                  name_expr_pair |
                                name_expr_pair
                                ;

name_expr_pair:                 name
                                  ASSIGNMENTtoken
                                  ground_expression { atom_1($1); }
                                ;
%%
