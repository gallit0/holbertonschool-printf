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
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		counter++;
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
	int counter = 0;
	int i = 0, j;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == '%' || format[i + 1] == 0))
		{
			_putchar('%');
			i += 2;
			counter++;
		}
		else if (format[i] == '%')
		{
			for (j = 0; j < 2; j++)
			{
				if (*dat[j].type == format[i + 1])
					counter += dat[j].f(ptr);
			}
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			i++;
			counter++;
		}
	}
	va_end(ptr);
	return (counter);
}
