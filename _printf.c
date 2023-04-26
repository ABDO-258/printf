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

    for (p = format; *p != '\0'; ++p, count++)
    {
        
        if(*p == '%')
        {
            p++;
            

            if (*p == 'c')
            {
                _putchar(va_arg(args, int));
                p++;
                count++;
            }
            else if (*p == 's' )
            {
                char *ptrs = va_arg(args, char *);
                
                count = count + print_str(ptrs);
                if (*p == 's')
                    p++;
                else if (*(p+1) == 's')
                    p += 2;
                else
                p += 3;
            }
            else if (*p == 'd' || *p == 'i' )
            {
                int n = va_arg(args, int);
                print_number(n);
                p++;
            }
            else if (*p == '\0' || *p == ' ')
                    return(-1);
             else if (*p == '%' && *(p+1) == '%')
             {
                    _putchar('%');   
                    count++;
                     p += 2;
             }
             else  
            {
                
                if (*p)
                {
                    _putchar(*p);   
                    count++;
                     p++;
                }
            }

        }
        _putchar(*p);
    }
    va_end(args);
    return (count);
}