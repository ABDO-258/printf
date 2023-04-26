#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int count = 0;
    const char* p;
    va_list args;

    if (format == NULL)
        return(-1);

   va_start (args, format);

    for (p = format; *p != '\0'; ++p)
    {        
        if(*p == '%')
        {
            p++;
            if (*p == '\0' || *p == ' ')
                    return(-1);
            else if (*p == '%')
             {
                    _putchar('%');   
                    count++;
            }   
            else if (*p == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
        
                count++;
            }
            else if (*p == 's' )
            {
                char *ptrs = va_arg(args, char *);
                
                count = count + print_str(ptrs);
                
            }
            else if (*p == 'd' || *p == 'i' )
            {
                int n = va_arg(args, int);
                print_number(n);
            }
            else  
            {
                _putchar('%');
                _putchar(*p);   
                    count += 2;
            }
        }
        else
        {
        _putchar(*p);
        count++;
        }
    }
    va_end(args);
    return (count);
}
