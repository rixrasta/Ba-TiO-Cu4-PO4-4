@echo off
set MATLAB=D:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=calculations_mex
set MEX_NAME=calculations_mex
set MEX_EXT=.mexw64
call "D:\PROGRA~1\MATLAB\R2016a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for calculations > calculations_mex.mki
echo COMPILER=%COMPILER%>> calculations_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> calculations_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> calculations_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> calculations_mex.mki
echo LINKER=%LINKER%>> calculations_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> calculations_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> calculations_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> calculations_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> calculations_mex.mki
echo BORLAND=%BORLAND%>> calculations_mex.mki
echo OMPFLAGS= >> calculations_mex.mki
echo OMPLINKFLAGS= >> calculations_mex.mki
echo EMC_COMPILER=lcc64>> calculations_mex.mki
echo EMC_CONFIG=optim>> calculations_mex.mki
"D:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f calculations_mex.mk
