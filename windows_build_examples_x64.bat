@echo off

set opts=-FC -Isrc\ -std=c++17
set include=src\mine_hashtable.cpp src\utils.cpp
set CC=g++

echo compiling 'using table example'
call %CC% %opts% examples\using_table.cpp %include% -o bin\using_table.exe
IF NOT %ERRORLEVEL% == 0 IF EXIST bin\using_table.exe call del bin\using_table.exe

popd