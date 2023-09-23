#include "ft_printf.h"



char *base_16(unsigned long long p)
{
	char base_16[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	char output[19];
	memset(output,'0',sizeof(output));
	int i;
	i=17;

	while(p)
	{
		output[i]=base_16[p%16];
		p=p/16;
		i--;
	}

	output[0]='0';
	output[1]='x';
	output[18]='\0';
	return (output);
}

void p_output(va_list args)
{
	unsigned long long p=(unsigned long long)(va_arg(args,void * ));
	char *str;
	str=base_16(p);

	ft_putstr(str);
}
