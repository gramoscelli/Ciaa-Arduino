# Testing de portación de funciones para Arduino
Implementación de testing de funciones de la API de Arduino usando la biblioteca sAPI para usar el IDE Arduino con la Edu-CIAA-NXP y la CIAA-NXP. 

## Biblioteca Analog I/O

La biblioteca Analog I/O de Ardunio está compuesta por:

*   analogRead() 
*   analogReference() 
*   analogWrite() 

### Documentación extraída de la referencia oficial de Arduino:

1\) **analogRead()** Reads the value from the specified analog pin. Arduino boards contain a multichannel, 10-bit analog to digital converter. This means that it will map input voltages between 0 and the operating voltage(5V or 3.3V) into integer values between 0 and 1023. On an Arduino UNO, for example, this yields a resolution between readings of: 5 volts / 1024 units or, 0.0049 volts (4.9 mV) per unit. See the table below for the usable pins, operating voltage and maximum resolution for some Arduino boards.

The input range can be changed using analogReference(), while the resolution can be changed (only for Zero, Due and MKR boards) using analogReadResolution().

On ATmega based boards (UNO, Nano, Mini, Mega), it takes about 100 microseconds (0.0001 s) to read an analog input, so the maximum reading rate is about 10,000 times a second.

        param pin: the name of the analog input pin to read from (A0 to A5 on most boards, A0 to A6 on MKR boards, A0 to A7 on the Mini and Nano, A0 to A15 on the Mega).
        return: The analog reading on the pin. Although it is limited to the resolution of the analog to digital converter (0-1023 for 10 bits or 0-4095 for 12 bits). Data type: **int**.
        int analogRead(int pin)

2\) **analogReference()** (No se usa)

3\) **analogWrite()** Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightnesses or drive a motor at various speeds. After a call to **analogWrite()**, the pin will generate a steady rectangular wave of the specified duty cycle until the next call to analogWrite() (or a call to **digitalRead()** or **digitalWrite()**) on the same pin.

analogWrite(pin, value)

        param pin: the Arduino pin to write to. Allowed data types: int. value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int.
        return: Nothing
        int analogRead(int pin)

### Documentación de sapi_pwm.h (sAPI):

1\) **pwmInit()** Initializes the pwm peripheral.

        param uint8_t pwmNumber
        param uint8_t config
        return bool_t true (1) if config it is ok
        bool_t pwmInit( pwmMap_t pwmNumber, pwmInit_t config);

2\) **pwmWrite()** Change the value of the pwm at the selected pin.

        param  pwmMap_t pwmNumber:   ID of the pwm, from 0 to 10
        param  uint8_t  value:   8bit value, from 0 to 255
        return bool_t True if the value was successfully changed, False if not.
        bool_t pwmWrite( pwmMap_t pwmNumber, uint8_t percent );



### Documentación de sapi_adc.h (sAPI):

1\) **adcInit()** Initializes the pwm peripheral.

        - param  adcInit_t config : enumerado (ADC_ENABLE, ADC_DISABLE)
        void adcInit( adcInit_t config );

De la documentación de 


2\) **adcRead()** Change the value of the pwm at the selected pin.

        - param  adcMap_t analogInput: pin de entrada (enumerado)
        - return uint16_t valor del ADC
        uint16_t adcRead( adcMap_t analogInput );

### Documentación de sapi_gpio.h (sAPI):

1\) **gpioInit()** 

        bool_t gpioInit( gpioMap_t pin, gpioInit_t config );


2\) **gpioRead()**

        bool_t gpioRead( gpioMap_t pin );

3\) **gpioWrite)**

        bool_t gpioWrite( gpioMap_t pin, bool_t value );

4\) **gpioToggle()**

        bool_t gpioToggle( gpioMap_t pin );

## Requerimientos

1.

1. 

1.

1.

1.
