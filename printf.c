#include "main.h"

/**
 * _printf - print with format
 * @format: format of the string
 * Return: counter
 */

int _printf(const char *format, ...)
{
	unsigned int counter = 0;
	unsigned int i = 0;
	va_list ptr;

	va_start(ptr, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i += 2;
			counter++;
		}
		else if (format[i] == '%')
		{
			
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
