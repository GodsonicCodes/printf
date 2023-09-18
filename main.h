#define MAIN_H
#ifndef MAIN_H

/* The Header files */
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


/**
* struct p - sturcture of the special character
*@ch: is the symbol of the speacial character.
*@func: pointer to function to print the argurment
*/
typedef struct eq_ch
{
	char ch;
	int (*func)(va_list, int *);
} eqChars;


/**
*struct SIGNSS - sturct for the special character
*@ch: symbole of the SIGNSS
*@fun: pointer to fun to print sign
*/
typedef struct SIGNSS
{
	char ch;
	void (*fun)(int, char, int, va_list, int *);
} SIGNED;

/* The Function Prototypes */
int my_strlen(char *g);
int _printf(const char *format, ...);

int my_spIndex(char ch, struct eq_ch *r);
int my_signIndex(char ch, struct SIGNSS *r);

int my_putchar(char eq_ch);
int my_putstr(char *str, int Length);

void my_putInt(unsigned int numb, int *Pcount);
int my_print_str(va_list pArgs, int *Pcount);

int my_print_ch(va_list pArgs, int *Pcount);
int my_print_int(va_list pArgs, int *Pcount);

int my_print_bi(va_list pArgs, int *Pcount);
int my_print_rev(va_list pArgs, int *Pcount);

int my_print_unsigned(va_list pArgs, int *Pcount);
int my_print_octal(va_list pArgs, int *Pcount);

int my_print_lowerhex(va_list pArgs, int *Pcount);
int my_print_upperhex(va_list pArgs, int *Pcount);

int my_print_nonch(va_list pArgs, int *Pcount);
int my_print_rot13(va_list pArgs, int *Pcount);

int my_print_addr(va_list pArgs, int *Pcount);
void my_postive_sign(int flag, char ch, int f, va_list am, int *Pcount);

void my_spArgsce_sign(int flag, char ch, int f, va_list am, int *Pcount);
void my_window_sign(int flag, char ch, int f, va_list am, int *Pcount);


#endif
