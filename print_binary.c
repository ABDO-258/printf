#include "main.h"
#include <stdlib.h>
/**
*print_binary- print binary number
*
*
*@number: number to print in binary
*
*
*Return:length of binary number
*/

int print_binary(unsigned int number)
{
	int length = 0, i = 0, j;
	unsigned int num = number;
	char *binary;

	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		length++;
		num /= 2;
	}

	binary = malloc(sizeof(char) * (length + 1));
	if (binary == NULL)
		return (-1);

	while (number > 0)
	{
		binary[i] = number % 2;
		number = number / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(binary[j] + 48);
	}
	return (length);
}
