#include "main.h"

int _printf(const char *format, ...)
{
	int char_print = 0;


	va_list args_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
		}

		if (*format == '\0')
		{
			break;
		}

		if (*format == '%')
		{

			write(1, format, 1);
			char_print++;
		}

		else if (*format == 'c')
		{

			char c = va_arg(args_list, int);
			write(1, &c, 1);
			char_print++;
		}

		else if (*format == 's')
		{
			char *str = va_arg(args_list, char *);
			int str_len = 0;


			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			char_print += str_len;
		}
	}
	format++;

	va_end(args_list);
	return (char_print);
}

int main()
{
	_printf("Leo\n");
	_printf("%c\n", 'v');
	_printf("%s\n", "String");
	_printf("%%\n");
	return 0;
}
