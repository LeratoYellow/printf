#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _print_char - Prints a single character to stdout
 * @c: Character to print
 * Return: Number of characters printed
 */
int _print_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * _print_string - Prints a string of characters to stdout
 * @str: string to print
 * Return: Number of characters printed
 */
int _print_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _print_percent - Prints a single percent sign to stdout
 * Return: Number of characters printed
 */
int _print_percent(void)
{
	_putchar('%');
	return (1);
}
/**
 * _printf - Prints a formatted string of characters to stdout
 * @format: String to print
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int num_of_chars = 0;
	va_list arg_container;
	char *str;

	va_start(arg_container, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
					num_of_chars += _print_percent();
					break;
				case 'c':
					num_of_chars += _print_char(va_arg(arg_container, int));
					break;
				case 's':
					str = va_arg(arg_container, char *);
					if (!str)
						str = "(null)";
					num_of_chars += _print_string(str);
					break;
				default:
					num_of_chars += _print_percent();
					num_of_chars += _print_char(*format);
					break;
			}
		}
		else
		{
			num_of_chars += _print_char(*format);
		}
		format++;
	}
	va_end(arg_container);
	return (num_of_chars);
}
