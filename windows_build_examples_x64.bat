@echo off

set opts=-FC -GR- -EHa- -nologo -Zi
set code=%cd%\src
set exmp=%cd%\examples
set include=%code%\hashtable.c

call vcvars64

pushd bin\

cl %opts% %exmp%\using_table.c %include% %code% -FeBAT
IF NOT %errorlevel% == 0 IF EXIST "using_table.exe" call rm "using_table.exe"

popd