#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdarg.h> /* varidic functions */

#include <unistd.h>/*  write function  */
#include <stdio.h>


/**
*struct signs - STRUCT for the special character
*@ch: SYMBOL of the signs
*@fun: POINTER to fun to print sign
*/

typedef struct signs
{
	char ch;
	void (*fun)(int, char, int, va_list, int *);
} sign;


/**
* struct sp_char - STRUCT for the special character
*@ch: SYMBOL of the speacial character
*@fun: POINTER to fun to print the argurment
*/
typedef struct sp_char
{
	char ch;
	int (*fun)(va_list, int *);
} spChar;


int _putchar(char sp_ch);
int _putstr(char *str, int len);

void _putInt(unsigned int num, int *pCount);
int print_bi(va_list pa, int *pCount);

int print_rev(va_list pa, int *pCount);
int print_unsigned(va_list pa, int *pCount);

int print_octal(va_list pa, int *pCount);

int print_lowerhex(va_list pa, int *pCount);
int print_str(va_list pa, int *pCount);

int print_ch(va_list pa, int *pCount);
int print_int(va_list pa, int *pCount);

int print_upperhex(va_list pa, int *pCount);
int print_nonch(va_list pa, int *pCount);

int print_rot13(va_list pa, int *pCount);
int print_addr(va_list pa, int *pCount);

int signIndex(char ch, struct signs *p);
void postive_sign(int flag, char ch, int j, va_list ap, int *pCount);

void space_sign(int flag, char ch, int j, va_list ap, int *pCount);
void window_sign(int flag, char ch, int j, va_list ap, int *pCount);

int _strlen(char *s);
int _printf(const char *format, ...);
int spIndex(char ch, struct sp_char *p);
void custom_printf(const char *format, ...);

#endif
