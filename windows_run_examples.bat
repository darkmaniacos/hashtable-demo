@echo off

echo FIRST EXAMPLE: Using table
IF EXIST "bin\using_table.exe" call "bin\using_table.exe"
IF NOT EXIST "bin\using_table.exe" echo "Example 1 failed to compile or could not be found."
echo