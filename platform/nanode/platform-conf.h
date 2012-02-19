/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
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
 * $Id: platform-conf.h,v 1.1 2010/06/23 10:25:54 joxe Exp $
 */

/**
 * \file
 *         Platform configuration for Nanode
 * \author
 * 	   Ilya Dmitrichenko <errordeveloper@gmail.com>
 *         Niclas Finne <nfi@sics.se>
 *         Joakim Eriksson <joakime@sics.se>
 */

#ifndef __PLATFORM_CONF_H__
#define __PLATFORM_CONF_H__

/*
 * Definitions below are dictated by the hardware and not really
 * changeable!
 */
#define PLATFORM PLATFORM_AVR

/*
 * MCU and clock rate.
 */
#ifndef MCU_MHZ
 #define MCU_MHZ 16
 #warning "Setting default MCU_MHZ value (@16MHz)"
#endif

/* Clock ticks per second */
#define CLOCK_CONF_SECOND 125


#include "dev/rs232.h"

/* USART port configuration for SLIP */
#ifndef SLIP_PORT
 #ifndef RS232_PORT_0
	#error  "RS232 header was not included ?"
 #else
  #define SLIP_PORT (RS232_PORT_0)
 #endif
#endif

#ifndef SLIP_BAUD
 #ifndef USART_BAUD_115200
	#error  "RS232 header was not included ?"
 #else
  #define SLIP_BAUD (USART_BAUD_115200)
 #endif
#endif

/* USART port configuration for serial I/O */

#ifndef USART_PORT
 #ifndef RS232_PORT_0
	#error  "RS232 header was not included ?"
 #else
  #define USART_PORT (RS232_PORT_0)
 #endif
#endif

#ifndef USART_BAUD
 #ifndef USART_BAUD_38400 
	#error  "RS232 header was not included ?"
 #else
  #define USART_BAUD (USART_BAUD_38400)
  #warning "Setting default RS232 I/O baud rate (@38400)"
 #endif
#endif

#endif /* __PLATFORM_CONF_H__ */
