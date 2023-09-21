#include "main.h"



/* Custom printf function */
void custom_printf(const char *format, ...) {
    /* Initialize length modifier flags */
    int is_long = 0;
    int is_short = 0;

    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            putchar(*format); /* Print character as-is */
            format++;
            continue;
        }

        format++;

        while (*format == 'l' || *format == 'h') {
            if (*format == 'l') {
                is_long++; /* Increment long counter */
            } else if (*format == 'h') {
                is_short++; /* Increment short counter */
            }
            format++;
        }

        switch (*format) {
            case 'd':
            case 'i': {
                int num;
                if (is_long) {
                    long l_num = va_arg(args, long);
                    num = (int)l_num; /* Cast to int */
                    printf("%ld", l_num);
                } else if (is_short) {
                    short s_num = va_arg(args, int);
                    num = (int)s_num; /* Cast to int */
                    printf("%hd", s_num);
                } else {
                    num = va_arg(args, int);
                    printf("%d", num);
                }
                break;
            }
            /* Rest of the code... */
        }
        format++;
    }

    va_end(args);
}

int main() {
    /* Test the custom printf function */
    custom_printf("Testing custom printf: %d, %ld, %hx, %X, %o, %hu, %u, %hX, %%\n", 42, 1234567890L, 255, 255, 255, 65535, 4294967295U, 65535);
    return 0;
}
