/*
 * File      : board.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2017, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-5-30      Bernard      the first version
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdint.h>

extern unsigned char __bss_start;
extern unsigned char __bss_end;

#define RT_HW_HEAP_BEGIN    (void*)&__bss_end
#define RT_HW_HEAP_END      (void*)0x43C00000

void rt_hw_board_init(void);
void rt_hw_mmu_init(void);
int rt_hw_pin_init(void);
int rt_hw_uart_init(void);

void __udelay(unsigned long usec);
ulong tick_read_timer(void);

int gpio_direction_input(unsigned gpio);
int gpio_direction_output(unsigned gpio, int value);
int gpio_direction_mode(unsigned gpio, int mode);
int gpio_get_value(unsigned gpio);
int gpio_set_value(unsigned gpio, int value);

#define UART0_BASE 0x01c28000
#define UART1_BASE 0x01c28400
#define UART2_BASE 0x01c28800
void NS16550_puts(void *com_port, const char *s);
void NS16550_putc(void *com_port, char c);

#endif
