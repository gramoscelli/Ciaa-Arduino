!/bin/sh

# Argumento 1 Path absoluto a openocd
# Argumento 2 Path absoluto a la configuración (e.g. lpc4337.cfg
# Argumento 3 Parth absoluto al firmware
# El resto de los argumentos se copian al final


$1 -f $2 -c "init" -c "halt" -c "flash write_image erase unlock $3 0x1A000000 bin" -c "reset run" -c "shutdown" $4 $5 $6 $ $7 $8
