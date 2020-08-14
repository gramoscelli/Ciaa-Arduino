# Rama develop:
Se usa para testing de funciones Arduino vía sAPI. 

Funciones a implementar:

## Analog I/O
*   analogRead() 
*   analogReference() 
*   analogWrite() 

Requisitos (sacados de la referencia oficial de Arduino):

1\) **analogRead()** Reads the value from the specified analog pin. Arduino boards contain a multichannel, 10-bit analog to digital converter. This means that it will map input voltages between 0 and the operating voltage(5V or 3.3V) into integer values between 0 and 1023. On an Arduino UNO, for example, this yields a resolution between readings of: 5 volts / 1024 units or, 0.0049 volts (4.9 mV) per unit. See the table below for the usable pins, operating voltage and maximum resolution for some Arduino boards.

The input range can be changed using analogReference(), while the resolution can be changed (only for Zero, Due and MKR boards) using analogReadResolution().

On ATmega based boards (UNO, Nano, Mini, Mega), it takes about 100 microseconds (0.0001 s) to read an analog input, so the maximum reading rate is about 10,000 times a second.

2\) **analogReference()** (No se usa)

3\) **analogWrite()** Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds. After a call to **analogWrite()**, the pin will generate a steady rectangular wave of the specified duty cycle until the next call to analogWrite() (or a call to **digitalRead()** or **digitalWrite()**) on the same pin.

De la documentación de sapi_pwm.h (sAPI):

1\) **pwmInit()** Initializes the pwm peripheral.

>        param uint8_t pwmNumber
>        param uint8_t config
>        return bool_t true (1) if config it is ok
>        bool_t pwmInit( pwmMap_t pwmNumber, pwmInit_t config);

2\) **pwmWrite()** Change the value of the pwm at the selected pin.

        param  pwmMap_t pwmNumber:   ID of the pwm, from 0 to 10
        param  uint8_t  value:   8bit value, from 0 to 255
        return bool_t True if the value was successfully changed, False if not.
        bool_t pwmWrite( pwmMap_t pwmNumber, uint8_t percent );



De la documentación de sapi_adc.h (sAPI):

1\) **adcInit()** Initializes the pwm peripheral.

        - param  adcInit_t config : enumerado (ADC_ENABLE, ADC_DISABLE)
        void adcInit( adcInit_t config );



2\) **adcRead()** Change the value of the pwm at the selected pin.

        - param  adcMap_t analogInput: pin de entrada (enumerado)
        - return uint16_t valor del ADC
        uint16_t adcRead( adcMap_t analogInput );


# Usando el IDE de Arduino para programar las tarjetas CIAA-NXP/EDU-CIAA-NXP

Implementación no oficial de las especificaciones de Arduino (https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification) para compilar programas de la CIAA/Edu-CIAA usando el IDE de Arduino. Más información del proyecto CIAA en http://www.proyecto-ciaa.com.ar.

  Pasos para instalar la placa en el IDE Arduino:
  
  1\) Acceder a Archivo -> Preferencias. 
  
  ![Screenshot](doc/platform.jpg)
  
  2\) Agregar el URL del archivo JSON de instalación: https://raw.githubusercontent.com/gramoscelli/Install-Arduino-Ciaa/master/package_ciaa_index.json.
  
  ![Screenshot](doc/platform2.jpg)
  
  3\) Iniciar el Gestor de Tarjetas desde Herramientas -> Placa...
  
  ![Screenshot](doc/platform3.jpg)
  
  4\) Instalar la tarjeta Ciaa
  
  ![Screenshot](doc/platform4.jpg)
  
  5\) Elegir la tarjeta Ciaa recién instalada, desde Herramientas -> Placa...
  
  ![Screenshot](doc/platform5.jpg)
  
