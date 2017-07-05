/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "HardwareSerial.h"


// Constructors ////////////////////////////////////////////////////////////////
_serial::_serial(uartMap_t uart, uint32_t baud)
{
    this_uart = uart;
    this_baud = baud;

    uartConfig(uart, baud);
}

// Actual interrupt handlers //////////////////////////////////////////////////////////////

void _serial::_rx_complete_irq(uartMap_t uart)
{
 /*
  // No Parity error, read byte and store it in the buffer if there is
  // room
  unsigned char c = uart_getc(obj);

  rx_buffer_index_t i = (unsigned int)(obj->rx_head + 1) % SERIAL_RX_BUFFER_SIZE;

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != obj->rx_tail) {
    obj->rx_buff[obj->rx_head] = c;
    obj->rx_head = i;
  }
  */
}

// Actual interrupt handlers //////////////////////////////////////////////////////////////

int _serial::_tx_complete_irq(uartMap_t uart)
{
  /*
  // If interrupts are enabled, there must be more data in the output
  // buffer. Send the next byte
  unsigned char c = obj->tx_buff[obj->tx_tail];
  obj->tx_tail = (obj->tx_tail + 1) % SERIAL_TX_BUFFER_SIZE;

  if (obj->tx_head == obj->tx_tail) {
    return -1;
  }

  return c;
  */
}

// Public Methods //////////////////////////////////////////////////////////////

void _serial::begin(unsigned long baud)
{
    this_baud = baud;

    uartConfig(this_uart, baud);
}

void _serial::end()
{
/*
  // wait for transmission of outgoing data
  flush();

  uart_deinit(&_serial);

  // clear any received data
  _serial.rx_head = _serial.rx_tail;
*/
}

int _serial::available(void)
{
//  return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + _serial.rx_head - _serial.rx_tail)) % SERIAL_RX_BUFFER_SIZE;
}

int _serial::peek(void)
{
  /*
  if (_serial.rx_head == _serial.rx_tail) {
    return -1;
  } else {
    return _serial.rx_buff[_serial.rx_tail];
  }
  */
}

int _serial::read(void)
{
  /*
  // if the head isn't ahead of the tail, we don't have any characters
  if (_serial.rx_head == _serial.rx_tail) {
    return -1;
  } else {
    unsigned char c = _serial.rx_buff[_serial.rx_tail];
    _serial.rx_tail = (rx_buffer_index_t)(_serial.rx_tail + 1) % SERIAL_RX_BUFFER_SIZE;
    return c;
  }
  */
}

int _serial::availableForWrite(void)
{
  /*
  tx_buffer_index_t head = _serial.tx_head;
  tx_buffer_index_t tail = _serial.tx_tail;

  if (head >= tail) return SERIAL_TX_BUFFER_SIZE - 1 - head + tail;
  return tail - head - 1;
  */
}

void _serial::flush()
{
  /*
  // If we have never written a byte, no need to flush. This special
  // case is needed since there is no way to force the TXC (transmit
  // complete) bit to 1 during initialization
  if (!_written)
    return;

  while((_serial.tx_head != _serial.tx_tail)) {
    // nop, the interrupt handler will free up space for us
  }
  // If we get here, nothing is queued anymore (DRIE is disabled) and
  // the hardware finished tranmission (TXC is set).
  */
}

size_t _serial::write(uint8_t c)
{
  /*
  _written = true;

  tx_buffer_index_t i = (_serial.tx_head + 1) % SERIAL_TX_BUFFER_SIZE;

  // If the output buffer is full, there's nothing for it other than to
  // wait for the interrupt handler to empty it a bit
  while (i == _serial.tx_tail) {
    // nop, the interrupt handler will free up space for us
  }

  _serial.tx_buff[_serial.tx_head] = c;
  _serial.tx_head = i;

  if(!serial_tx_active(&_serial)) {
    uart_attach_tx_callback(&_serial, _tx_complete_irq);
  }

  return 1;
  */
}

_serial Serial(UART_USB, 115200);
