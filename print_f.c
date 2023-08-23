#include "main.h"

int _printf(const char *format, ...)
{
	int char_print = 0;

	// initialize list of arguments to take
	va_list args_list; // create a room to receive a large number of arguments

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args_list, format);

	while (*format)
	{						// a loop to iterate the characters of the format string
		if (*format != '%') // if format is not the % sign
		{
			write(1, format, 1); // write the character to the standard output
			char_print++;
		}
		else
		{			  // if format is the % sign
			format++; // skip '%' sign and check the next character
		}

		if (*format == '\0')
		{
			break;
		}

		if (*format == '%') // this solves %%
		{
			// handle '%%' (double '%')
			write(1, format, 1);
			char_print++;
		}

		else if (*format == 'c')
		{
			// handle the 'c' character
			char c = va_arg(args_list, int); // use va_arg(list, char) for char
			write(1, &c, 1);
			char_print++;
		}

		else if (*format == 's')
		{
			char *str = va_arg(args_list, char *);
			int str_len = 0;

			// calculate the length of the string
			while (str[str_len] != '\0')
				str_len++;

			// write the string to the standard output
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
