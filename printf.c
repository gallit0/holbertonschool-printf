#include "main.h"

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
	unsigned int i = 0;

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
