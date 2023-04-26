#include "main.h"
int print_number(int n)
{
    
    if (n < 0)
    {
        _putchar('-');
        n = n * (-1);
    }
    if (n >= 10)
    {
        print_number(n / 10);
        print_number(n % 10);
    }
    else if(n < 10 )
    {
        _putchar(n + 48);

    }
return(1);

}