#define MAIN_H
#ifndef MAIN_H

/* The Header files */
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int my_putchar(char p);
int my_putstr(char *str, int Length);

int my_print_str(va_list pArgs, int *Pcount);
int my_print_ch(va_list pArgs, int *Pcount);
