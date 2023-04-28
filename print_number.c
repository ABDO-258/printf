#include "main.h"
/**
*print_number-print number
*
*@n:number to be printed
*Return: 1
*/

int print_number(int n)
{
	int count = 0;

	if (n == INT_MIN)
	{
		count += _putchar('-');
		count += _putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += _putchar('-');
		n = n * (-1);
	}
	if (n >= 10)
	{
		count += print_number(n / 10);
		count += print_number(n % 10);
	}
	else if (n < 10)
	{
		count += _putchar(n + 48);
	}
	return (count);
}
