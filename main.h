#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
int _putchar(char c);
int _printf(const char *format, ...);

typedef struct data
{
	char *type;
	int (*f)(va_list ptr);
} data;

#endif
