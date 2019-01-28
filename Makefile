#
# Makefile fuer den QSDL-Parser
#
#
# Author: Marc Diefenbruch
# $Date: 1998/02/19 16:14:30 $
#
# (C) 1995 Universitaet GH Essen
#
# Dieses Makefile stellt folgende Operationen zur Verfuegung:
#
# -) make [all]     : Compiler erzeugen
# -) make install   : Neues Release des Parsers fuer Benutzer zugaenglich machen
# -) make release   :   "      "     "     "      "     "          "        "
# -) make checkout  : alle Projektdateien auschecken
# -) make checkout-lock: alle Projektdateien zum Aendern auschecken
# -) make depend    : alle Abhaengigkeiten zwischen Projektdateien feststellen
# -) make clean     : Objektdateien (*.o) und temporaere Dateien entfernen
# -) make veryclean : make clean + rcsclean + alle Postscriptdateien entfernen
# -) make git-pull  : pull sources from github
# -) make git-push  : push sources to github
# -) make git-add   : add changed sources to git staging
# -) make git-commit: commit staged sources to git HEAD
# -) make postscript: Postscriptdateien aus alle *.h Dateien erzeugen
# -) make print     : alle *.h Dateien ausdrucken
# -) make backup    : Backup von allen *.cpp *.h Dateien und dem Makefile
# -) make find-error: Compilierungsfehler anzeigen
# -) make tags      : Source-Browser-Datei erzeugen
#
# Der Aufbau dieses Makefiles gliedert sich wie folgt:
#
#  0. Globale Umschalter (z.Z zwischen GNU- und SUN-Tools)
#  1. Makefiledirektiven
#  2. Pfade und Dateinamen
#  3. Programme, Kommandos, Kommandooptionen
#  4. Compilierungs- und Linkeroptionen
#  5. Quelldateien des Projekts
#  6. Objektdateien des Projekts
#  7. Makefileregeln (Operationen, s.o.)
#

###############################
# Figure out host system type #
###############################

## Don't rely on $HOSTTYPE being set correctly!
## Try to figure it out ourselves:

## Prevent make from interpreting special characters:
SCRIPT := \
	case `uname -s` in\
    	Linux)	case `uname -m` in\
					i?86) echo ix86-linux;;\
					arm*) echo arm-linux;;\
					sparc) echo sparc-linux;;\
					*) echo unknown-linux;;\
				esac;;\
		SunOS)	echo `uname -p`-SunOS;;\
		*) echo unknown-unknown;;\
	esac

## Run script and store result in variable:
QUEST_HOSTTYPE := $(shell $(SCRIPT))

##########################
# 0. Globale Umschalter: #
##########################

ifeq ($(QUEST_HOSTTYPE), sparc-SunOS)

#TOOLS = SUN
TOOLS = GNU

else

TOOLS = GNU

endif

#PROFILING = yes
PROFILING = no

##########################
# 1. Makefiledirektiven: #
##########################

.SILENT:
                         # alle Make Operationen ohne Ausgaben

.PHONY:	clean all release
                         # Welche Operationen sollen gespraechig sein?

.SUFFIXES: .c .cpp .h .o .y .l
                         # verwendete Dateiendungen 

############################
# 2. Pfade und Dateinamen: #
############################

INCDIR = ../../include
                         # Verzeichnis der DS-Includedateien fuer die
                         # Benutzer der DS (Generator, ...)

LIBDIR = ../../lib/$(QUEST_HOSTTYPE)
                         # Verzeichnis der DS-Library fuer die
                         # Benutzer der DS (Generator, ...)

BINDIR = ../../bin/$(QUEST_HOSTTYPE)
                         # Verzeichnis in dem die Binaerdateien gespeichert
                         # werden sollen
OBJBASEDIR = obj
                         # Verzeichnis unter dem die Objektdateien aller Hosts
                         # gespeichert werden sollen
OBJDIR = $(OBJBASEDIR)/$(QUEST_HOSTTYPE)
                         # Verzeichnis in dem die Objektdateien gespeichert
                         # werden sollen
PSDIR = ps
                         # Directory in dem die Postscriptversionen der
                         # Dateien gespeichert werden sollen
LOGFILE = $(USER).$(QUEST_HOSTTYPE).make.log
                         # Protokollierungsdatei fuer den make-Vorgang
DEPFILE = .depend.$(QUEST_HOSTTYPE)
                         # Dependency-Datei (automatisch generiert)
OUTPUT = $(OBJDIR)/libQP.a
                         # Name des erzeugten Programms/Library
BACKUP = qp
                         # Name des Backupfiles (ohne Endungen!)

##############################################
# 3. Programme, Kommandos, Kommandooptionen: #
##############################################

LEX = flex
                         # Kommando zum Starten des lexikalischen Analysators
LEXFLAGS = -i -l
                         # Flags fuer Lexer-Generator
YACC = bison
                         # Kommando zum Starten des Parser-Generators
YACCFLAGS = -d -v
                         # Flags fuer Parser-Generator
TAR = tar cf
                         # Befehl zum Erzeugen eines Sourcecode-Archievs
UNTAR = tar xf
                         # Befehl zum Expandieren eines Sourcecode-Archievs
TAR_SUFFIX = tar
                         # Endung welche das tar-Kommando verwendet
COMPRESS = gzip -9
                         # Befehl zum Komprimieren von Dateien
UNCOMPRESS = gzip -d
                         # Befehl zum Dekomprimieren von Dateien
COMPRESS_SUFFIX = gz
                         # Endung welche das Komprimierungsprogramm verwendet
EDITOR = nano
                         # Name des verwendeten Editors

GIT = git                # git

TAGS = ctags -t
                         # Programm zum Erzeugen von Sourcebrowsing-Infos
                         # (wo ist eine bestimmte Funktion definiert?, etc)
MAKE_PS = a2ps
                         # Kommando zum Erzeugen von Postscript aus ASCII
MAKE_PS_FLAGS = -o
                         # Option fuer MAKE_PS
PS_SUFFIX = ps

PRINT = lp -d mono515s
                         # Druckkommando

ifeq ($(TOOLS), GNU)     # GNU-Version ?

CC = gcc
                         # Name des C-Compilers
C++ = g++
                         # Name des C++-Compilers
AR = ar
                         # Name des Archivers (zum Erzeugen von Libraries)
ARFLAGS = r
                         # Flags fuer den Archiver
else                     # SUN-Version

CC = cc
                         # Name des C-Compilers
C++ = CC
                         # Name des C++-Compilers
AR = $(C++)
                         # Name des Archivers (zum Erzeugen von Libraries)
ARFLAGS = -xar -o
                         # Flags fuer den Archiver
endif

RCSCLEAN = rcsclean
                         # Befehl zum "Aufraeumen" des Projekts (Loeschen
                         # der nicht mit Lock Option "ausgecheckten"
                         # Dateien
RM = /bin/rm -f
                         # Befehl zum Loeschen von Dateien
MV = /bin/mv
                         # Befehl zum Verschieben von Dateien
CP = /bin/cp -p
                         # Befehl zum Kopieren von Dateien
TOUCH = touch
                         # Befehl zum Aktualisieren des Dateidatums
MKDIR = mkdir
                         # Befehl zum Erzeugen von Directories
ifeq ($(TOOLS), GNU)

MAKE_DEPEND = $(C++) -M

else

MAKE_DEPEND = $(C++) -xM

endif
                         # Befehl zum Erzeugen der Abhaengigkeiten
STRIP = strip
                         # Befehl zum entfernen von Symbolen aus Binaerfiles
SED = sed
                         # Name des Stream-Editors sed
COFLAGS += -M -q
                         # Flags for checkout program.

#########################################
# 4. Compilierungs- und Linkeroptionen: #
#########################################

ifeq ($(TOOLS), GNU)     # GNU-Version ?

DEFINES =
#-DDMALLOC -DDMALLOC_FUNC_CHECK -DDEBUG 
                         # Defines fuer die Compiler
INCLUDES = -I. -I$(INCDIR)
                         # Include-Verzeichnisse fuer die Compiler
CDEBUG = -O3 -pipe 
                         # Debug-/Optimierungsoptionen
CFLAGS = $(CDEBUG) -Wall -pedantic-errors -Wstrict-prototypes
                         # Compiler-Flags (C)
CPPFLAGS = $(CDEBUG) -Wall -pedantic-errors
                         # Compiler-Flags (C++)
TFLAGS = -fno-implicit-templates
                         # Template-Flags

ifeq ($(PROFILING), yes) # Profiling einschalten ?

PFLAGS = -pg

endif

LIBS = -L$(LIBDIR) -lCG -lDS -liostream
                         # Libraries die zum Projekt gelinkt werden sollen

else                     # Sun-Version !

DEFINES = # -DDEBUG 
                         # Defines fuer die Compiler
INCLUDES = -I$(INCDIR)
                         # Include-Verzeichnisse fuer die Compiler
CDEBUG = -O -sb
                         # Debug-/Optimierungsoptionen
CFLAGS = $(CDEBUG) 
                         # Compiler-Flags (C)
CPPFLAGS = $(CDEBUG)
                         # Compiler-Flags (C++)
TFLAGS = 
                         # Template-Flags

ifeq ($(PROFILING), yes) # Profiling einschalten ?

PFLAGS = -xpg

endif

LIBS = -L$(LIBDIR) -lCG -lDS -liostream
                         # Libraries die zum Projekt gelinkt werden sollen

endif

#################################
# 5. Quelldateien des Projekts: #
#################################

YFILES = QSDL92.y

LFILES = QSDL92.l

YOUTPUT = QSDL92.tab.c

LOUTPUT = lex.yy.c

TMPHEADERS =\
  $(YOUTPUT:.c=.h)

HEADERS =\
	QPBasicTypes.h\
	QPAction.h\
	QPActual.h\
	QPBind.h\
	QPBlock.h\
	QPBlockSubstructure.h\
	QPChannel.h\
	QPConnection.h\
	QPData.h\
	QPError.h\
	QPExpression.h\
	QPIdentifier.h\
	QPInput.h\
	QPLexYacc.h\
	QPLink.h\
	QPLiteral.h\
	QPMachine.h\
	QPMachineService.h\
	QPMain.h\
	QPName.h\
	QPObjects.h\
	QPPipe.h\
	QPProcedure.h\
	QPProcess.h\
	QPSensor.h\
	QPSignal.h\
	QPSignalItem.h\
	QPSignalList.h\
	QPSignalRoute.h\
	QPSort.h\
	QPState.h\
	QPSystem.h\
	QPTimer.h\
	QPVariable.h

TMPSRCS =\
	$(YOUTPUT)\
	$(LOUTPUT)
	
SRCS =\
	QPAction.cpp\
	QPActual.cpp\
	QPBind.cpp\
	QPBlock.cpp\
	QPBlockSubstructure.cpp\
	QPChannel.cpp\
	QPConnection.cpp\
	QPData.cpp\
	QPError.cpp\
	QPExpression.cpp\
	QPIdentifier.cpp\
	QPInput.cpp\
	QPLink.cpp\
	QPLiteral.cpp\
	QPMachine.cpp\
	QPMachineService.cpp\
	QPMain.cpp\
	QPName.cpp\
	QPPipe.cpp\
	QPProcedure.cpp\
	QPProcess.cpp\
	QPSensor.cpp\
	QPSignal.cpp\
	QPSignalItem.cpp\
	QPSignalList.cpp\
	QPSignalRoute.cpp\
	QPSort.cpp\
	QPState.cpp\
	QPSystem.cpp\
	QPTimer.cpp\
	QPVariable.cpp


##################################
# 6. Objektdateien des Projekts: #
##################################

OBJS = $(addprefix $(OBJDIR)/, $(TMPSRCS:.c=.o)) \
       $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

######################
# 7. Makefileregeln: #
######################

default: clean-rubbish $(OBJDIR) $(OUTPUT)


$(OUTPUT): $(OBJS)
	@echo Constructing $(OUTPUT) ...
	$(AR) $(ARFLAGS) $(OUTPUT)\
		$(OBJS)\
		2>> $(LOGFILE)

all: $(OUTPUT)

$(OBJDIR)/%.o: %.c 
	@echo Compiling $< ...
	$(CC) -c $(CFLAGS) $(PFLAGS) -I$(INCDIR) $(DEFINES) $< -o $@ 2>> $(LOGFILE)

$(OBJDIR)/%.o: %.cpp 
	@echo Compiling $< ...
	$(C++) -c $(CPPFLAGS) $(TFLAGS) $(PFLAGS) $(DEFINES) $(INCLUDES) $< -o $@ 2>> $(LOGFILE)

#
# THE FOLLOWING RULES DEPEND ON THE ORDER OF THE DEPENDENCIES LIST!
# 
# The rule $< will return the first dependency in the dependency list.
# If you change the dependency list, make sure that the dependency you want
# to process with the commands of the rule is first in the list!!!
#

$(LOUTPUT): $(LFILES) $(TMPHEADERS)
	@echo Lexing $< ...
	$(LEX) $(LEXFLAGS) $< 2>> $(LOGFILE)

$(TMPHEADERS) : $(YFILES) $(YOUTPUT)
	@echo Yaccing $< ...
	$(YACC) $(YACCFLAGS) $< 2>> $(LOGFILE)

$(YOUTPUT): $(YFILES)
	@echo Yaccing $< ...
	$(YACC) $(YACCFLAGS) $< 2>> $(LOGFILE)

$(OBJBASEDIR): 
	@if [ ! \( -d $(OBJBASEDIR) \) ]; then \
		echo Creating $(OBJBASEDIR) ...; \
		$(MKDIR) $(OBJBASEDIR); fi

$(OBJDIR): $(OBJBASEDIR)
	@if [ ! \( -d $(OBJDIR) \) ]; then \
		echo Creating $(OBJDIR) ...; \
		$(MKDIR) $(OBJDIR); fi

$(LIBDIR): 
	@if [ ! \( -d $(LIBDIR) \) ]; then \
		echo Creating $(LIBDIR) ...; \
		$(MKDIR) $(LIBDIR); fi

$(PSDIR): 
	@if [ ! \( -d $(PSDIR) \) ]; then \
		echo Creating $(PSDIR) ...; \
		$(MKDIR) $(PSDIR); fi

$(INCDIR): 
	@if [ ! \( -d $(INCDIR) \) ]; then \
		echo Creating $(INCDIR) ...; \
		$(MKDIR) $(INCDIR); fi

$(INCDIR)/QP: $(INCDIR)
	@if [ ! \( -d $(INCDIR)/QP \) ]; then \
		echo Creating $(INCDIR)/QP ...; \
		$(MKDIR) $(INCDIR)/QP; fi

$(DEPFILE):
	$(TOUCH) $(DEPFILE)

install-lib: $(OUTPUT) $(LIBDIR)
	@echo Deleting old library $(notdir $(OUTPUT)) from $(LIBDIR) ...
	-$(RM) $(LIBDIR)/$(OUTPUT)
	@echo Installing new library $(notdir $(OUTPUT)) in $(LIBDIR) ...
	$(CP)  $(OUTPUT) $(LIBDIR)

install-includes:  $(HEADERS) $(INCDIR)/QP
	@echo Deleting old include files from $(INCDIR)/QP ...
	-$(RM) $(INCDIR)/QP/*.h
	@echo Installing new include files in $(INCDIR)/QP ...
	for X in $(HEADERS); do \
		$(CP) $${X} $(INCDIR)/QP; done

install: install-includes install-lib

release: install

git-pull:
	@echo Pulling sources form github...
	$(GIT) pull

git-add:
	@echo Staging changed local sources...
	$(GIT) add -A

git-commit:
	@echo Committing changed local sources...
	$(GIT) commit

git-push:
	@echo Pushing sources to github...
	$(GIT) push 

postscript: $(LFILES) $(YFILES) $(PSDIR)
	@for X in $(LFILES); do \
		echo Generating $$X.$(PS_SUFFIX) from $$X ...; \
		$(MAKE_PS) $(MAKE_PS_FLAGS) $(PSDIR)/$$X.$(PS_SUFFIX) $$X; done
	@for X in $(YFILES); do \
		echo Generating $$X.$(PS_SUFFIX) from $$X ...; \
		$(MAKE_PS) $(MAKE_PS_FLAGS) $(PSDIR)/$$X.$(PS_SUFFIX) $$X; done

print: postscript
	$(PRINT) $(PSDIR)/*.$(PS_SUFFIX)
	-$(RM) *.$(PS_SUFFIX)

backup:		$(SRCS) $(HEADERS) $(LFILES) $(YFILES)
	-$(RM) $(BACKUP).$(TAR_SUFFIX) $(BACKUP).$(TAR_SUFFIX).$(COMPRESS_SUFFIX)
	$(TAR) $(BACKUP).$(TAR_SUFFIX) $(SRCS) $(HEADERS) $(LFILES) $(YFILES) Makefile*
	$(COMPRESS) $(BACKUP).$(TAR_SUFFIX)
	-$(MV) $(BACKUP).$(TAR_SUFFIX).$(COMPRESS_SUFFIX) $(BACKUP).taz

fe find-error:
	$(EDITOR) -p $(LOGFILE)

tags: $(SRCS)
	-$(TAGS) $(C_SRCS) $(CPP_SRCS)

clean-rubbish:
	-$(RM) core* *.output *.bak *~ $(LOGFILE)

clean-tmps:
	-$(RM) $(YOUTPUT) $(LOUTPUT) $(YOUTPUT:.c=.h)

clean-objects:
	-$(RM) $(OBJDIR)/*.o $(OUTPUT) $(TEST_OUTPUT)

clean-rcs:
	-@$(RCSCLEAN) 2> /dev/null

clean: clean-rubbish clean-objects

veryclean: clean clean-tmps clean-rcs 
	-$(RM) $(PSDIR)/*.$(PS_SUFFIX) *.$(PS_SUFFIX) *.$(TAR_SUFFIX) *.$(COMPRESS_SUFFIX) *.taz *tags 2> /dev/null

checkout:
	-@$(CO) -q $(HEADERS)\
						 $(SRCS)\
             $(LFILES)\
             $(YFILES)

checkout-lock:
	-@$(CO) -l $(HEADERS)\
						 $(SRCS)\
             $(LFILES)\
             $(YFILES)

depend: $(HEADERS) $(SRCS) $(TMPSRCS)
	@echo Building dependency file $(DEPFILE) ...
	$(MAKE_DEPEND) $(DEFINES) $(SRCS) $(TMPSRCS) $(INCLUDES) > $(DEPFILE)
	$(SED) 's/^\(.*\)\.o/\$$(OBJDIR)\/\1\.o/g' $(DEPFILE) > $(DEPFILE).sed
	$(MV) $(DEPFILE).sed $(DEPFILE)


-include $(DEPFILE)

