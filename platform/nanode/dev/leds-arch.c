/*
 * Copyright (c) 2012, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
 
/* 
 *  LED implementation for Nanode
 *  
 *  Nanode 5 has a Red LED connected to Dig6
 *  Nanode RF/Classic also has a Green LED connected to Dig5
 *
*/

#include <avr/io.h>
#include "contiki-conf.h"
#include "dev/leds.h"

/*
 * PORT where LEDs are connected
 */
#define LED_PORT                        (PORTD)
#define LED_PORT_DIR                    (DDRD)

/*
 * PINs where LEDs are connected
 */
#define LED_RED_PIN                     (PD6)
#define LED_GREEN_PIN                   (PD5)   

/*---------------------------------------------------------------------------*/
void
leds_arch_init(void)
{
  LED_PORT |= (1 << LED_RED_PIN);
  LED_PORT_DIR |= (1 << LED_RED_PIN);
  LED_PORT |= (1 << LED_GREEN_PIN);
  LED_PORT_DIR |= (1 << LED_GREEN_PIN);
}
/*---------------------------------------------------------------------------*/
unsigned char
leds_arch_get(void)
{
  unsigned char result = 0;

  if ( LED_PORT & _BV(LED_RED_PIN ) )
    result |= LEDS_RED;
  if ( LED_PORT & _BV(LED_GREEN_PIN ) )
    result |= LEDS_GREEN;

  return result;
}

/*---------------------------------------------------------------------------*/
void
leds_arch_set(unsigned char leds)
{
  uint8_t led_port = LED_PORT;

  led_port &= ~_BV(LED_RED_PIN);
  if ( leds & LEDS_RED )
    led_port |= _BV(LED_RED_PIN);

  led_port &= ~_BV(LED_GREEN_PIN);
  if ( leds & LEDS_GREEN )
    led_port |= _BV(LED_GREEN_PIN);

  LED_PORT = led_port;
}
/*---------------------------------------------------------------------------*/
