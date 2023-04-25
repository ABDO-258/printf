#include "main.h"
int print_str(char *str)
{
    int len = 0;

    if (str == NULL)
    {
        print_str("(null)");
        return(4);
        
    }
    while (str[len] != '\0')
    {
        _putchar(str[len]);
        len++ ;
    }
    return(len);

}