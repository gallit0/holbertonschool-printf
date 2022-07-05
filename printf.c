#include "main.h"

/**
 * p_char - print char
 * @ptr: variadic list
 * Return: counter
 */

int p_char(va_list ptr)
{
	_putchar(va_arg(ptr, int));
	return (1);
}

/**
 * p_string - print a string
 * @ptr: variadic list
 * Return: counter
 */

int p_string(va_list ptr)
{
	char *s;
	int counter = 0;

	s = va_arg(ptr, char *);
	if (!s)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
	}
	else
	{
		while(*s)
		{
			_putchar(*s);
			s++;
			counter++;
		}
	}
	return (counter);
}

/**
 * _printf - print with format
 * @format: format of the string
 * Return: counter
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	data dat[] = {
		{"c",p_char},
		{"s",p_string},
	};
	unsigned int counter = 0;
	int i = 0;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i += 2;
			counter++;
		}
		else if (format[i] == '%' && *dat[i + 1].type == format[i + 1])
		{
			counter += dat[i + 1].f(ptr);
			i += = 2;
		}
		else
		{
			_putchar(format[i]);
			i++;
			counter++;
		}
	}
	return (counter);
}
