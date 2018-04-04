###########################################################################
## Makefile generated for MATLAB file/project 'calculations'. 
## 
## Makefile     : calculations_rtw.mk
## Generated on : Wed Apr 04 12:39:43 2018
## MATLAB Coder version: 3.1 (R2016a)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/calculations.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file

PRODUCT_NAME              = calculations
MAKEFILE                  = calculations_rtw.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = D:/PROGRA~1/MATLAB/R2016a
MATLAB_BIN                = D:/PROGRA~1/MATLAB/R2016a/bin
MATLAB_ARCH_BIN           = D:/PROGRA~1/MATLAB/R2016a/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/MEX
ARCH                      = win64
RELATIVE_PATH_TO_ANCHOR   = .
PERL                      = $(MATLAB_ROOT)/sys/perl/win32/bin/perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)/rtw/c/tools/mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   R2016a
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64
MEX_OPTS_FILE      = $(MATLAB_ROOT/rtw/c/tools/lcc-win64.xml

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = $(CC_PATH)/lcc64

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = $(LD_PATH)/lcclnk64

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = $(AR_PATH)/lcclib64

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CFLAGS           = -win64 $(MEX_SRC) $(MEX_OPT_FILE)$(INCLUDES) -outdir $(RELATIVE_PATH_TO_ANCHOR)
MEX_LDFLAGS          = LINKFLAGS="$$LINKFLAGS $(LDFLAGS_ADDITIONAL)"
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/calculations.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1 -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_STANDARD = -DMODEL=calculations -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/CALCUL~1.C C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/CALCUL~2.C C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/CALCUL~3.C C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/CALCUL~4.C C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/poore.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/mrdivide.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/isfinite.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/eig.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzggev.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/sqrt.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlangeM.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlartg.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzhgeqz.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlanhs.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/mod.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xztgevc.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/diag.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/RT_NON~1.C C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/rtGetNaN.c C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/rtGetInf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = calculations_rtwutil.obj calculations_initialize.obj calculations_terminate.obj calculations.obj poore.obj mrdivide.obj isfinite.obj eig.obj xzggev.obj sqrt.obj xzlangeM.obj xzlartg.obj xzhgeqz.obj xzlanhs.obj mod.obj xztgevc.obj diag.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(subst /,\,$(OBJS))
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) /out:$(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


calculations_rtwutil.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/calculations_rtwutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


calculations_initialize.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/calculations_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


calculations_terminate.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/calculations_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


calculations.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/calculations.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


poore.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/poore.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mrdivide.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/mrdivide.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


isfinite.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/isfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eig.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/eig.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzggev.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzggev.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


sqrt.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/sqrt.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlangeM.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlangeM.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlartg.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlartg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzhgeqz.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzhgeqz.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlanhs.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xzlanhs.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mod.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/mod.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xztgevc.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/xztgevc.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


diag.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/diag.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : C:/Users/Riho/Desktop/PPEMAT~1/BA(TIO~1/matlab/average/katse14/NEWFOL~1/codegen/lib/CALCUL~1/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


