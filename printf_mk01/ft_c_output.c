#include "ft_printf.h"

void c_output(va_list args)
{
	putchar(va_arg(args,int));
}

