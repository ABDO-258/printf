#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"
/**
*_printf - my printf for alx project
*@format:argument to be printed
*Return:number of char printed
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0' || *format == ' ')
				return (-1);
			else if (*format == '%')
				count += _putchar('%');
			else if (*format == 'c')
			{
				count += _putchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				count += print_str(va_arg(args, char *));
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += print_number(va_arg(args, int));
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
			count += _putchar(*format);
	}
	va_end(args);
	return (count);
}
