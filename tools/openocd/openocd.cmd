@echo off
rem Argumento 1 Path absoluto a .../Arduino15/packages/CIAA/tools/...
rem Argumento 2 Path absoluto a openocd.exe
rem Argumento 3 Path absoluto a la configuración (e.g. lpc4337.cfg)
rem Argumento 4 Parth absoluto al firmware 
rem El resto de los argumentos se copian

chcp 65001

%1\drv_ciaa_nxp.exe
if %errorlevel% NEQ 0 goto ERROR

%~2 -f %~3 -c "init" -c "halt" -c "flash write_image erase unlock {%4} 0x1A000000 bin" -c "reset run" -c "shutdown" %*
if %errorlevel% NEQ 0 goto ERROR
goto OK

:ERROR
Echo Error: no se pudo grabar el Sketch
goto END

:OK
Echo Todo bien! (Sketch grabado en la placa)

:END