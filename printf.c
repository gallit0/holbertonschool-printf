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
 *
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
		counter = 6;
	}
	else
	{
		while (*s)
		{
			_putchar(*s);
			s++;
			counter++;
		}
	}
	return (counter);
}

/**
 * p_int - print int and decimal
 * @ptr: list
 * Return: counter
 */

int p_int(va_list ptr)
{
	long int n = va_arg(ptr, int);
	int counter = 0;
	long int i = 1;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		counter++;
		n = n * -1;
	}
	for (; i <= n; i *= 10)
		counter++;
	i /= 10;
	for (; i > 0; i /= 10)
	{
		_putchar(((n / i) % 10)+ '0');
	}
	return (counter);
}

/**
 * check_printf - checks printf
 * @format: string
 * Return: -1 if mistake 1 if ok
 *
 */

int check_printf(const char *format)
{
	if (!format || !strcmp(format, "%"))
	{
		return (-1);
	}
	return (1);
}

/**
 * get_function - gets the function to use
 * @formi: char
 * @ptr: list
 * Return: int
 *
 */

int get_function(const char formi, va_list ptr)
{
	data dat[] = {
		{"c", p_char},
		{"s", p_string},
		{"d", p_int},
		{"i", p_int},
	};
	int counter = 0, i;

	for (i = 0; i < 4; i++)
	{
		if (*dat[i].type == formi)
			return (counter += dat[i].f(ptr));
	}
	_putchar('%');
	_putchar(formi);
	return (2);
}

/**
 * _printf - print with format
 * @format: format of the string
 * Return: counter
 *
 */

int _printf(const char *format, ...)
{
	va_list ptr;
	int counter = 0;
	int i = 0;

	if (check_printf(format) == -1)
		return (-1);
	va_start(ptr, format);
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == '%' || format[i + 1] == 0))
		{
			_putchar('%');
			i += 2;
			counter++;
		}
		else if (format[i] == '%')
		{
			counter += get_function(format[i + 1], ptr);
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
