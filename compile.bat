@echo off 
echo Gali WIN32 qmake version
set file_pro=dtvqt.pro

echo qmake -project
qmake -project

echo win32:CONFIG += console>>%file_pro%

echo qmake
qmake

@echo on