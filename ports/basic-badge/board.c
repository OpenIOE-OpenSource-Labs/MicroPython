/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <xc.h>
#include <plib.h>
#include "board.h"
#include "hw.h"

/********************************************************************/
// LEDs

void led_state(int led, int state) {
    set_led(led-1,state);
}

void led_toggle(int led) {
    uint8_t val =  (get_led_word() & (1<<(led-1))) ? 0 : 1;
    set_led(led-1,val);
}

/********************************************************************/
// switches

int switch_get(int sw) {
    return 0;
}

/********************************************************************/
// UART

int uart_rx_any(void) {
    return stdio_get_state();
}

int uart_rx_char(void) {
    int8_t char_out;
	stdio_get(&char_out);
    return char_out;
}

void uart_tx_char(int data) {
    stdio_c(data);
}