#include "main.h"
/**
*print_str - fonction to print a string
*
*@str:pointer to string to be printed
*
*Return: lenght of the string
*/

int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		print_str("(null)");
		return (6);
	}
	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}
