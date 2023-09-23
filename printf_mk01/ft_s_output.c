#include "ft_printf.h"

void s_output(va_list args)
{
	ft_putstr(va_arg(args,char *));
}
