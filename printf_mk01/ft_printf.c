#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

void output_state(va_list args,char specifier)
{
	if(specifier=='c')
		c_output(args);
	if(specifier=='s')
		s_output(args);
	if(specifier=='p')
		p_output(args);
	if(specifier=='d')
		s_output(args);
	if(specifier=='i')
		s_output(args);
	if(specifier=='u')
		s_output(args);
	if(specifier=='x')
		s_output(args);
	if(specifier=='X')
		s_output(args);
	if(specifier=='%')
		s_output(args);

}



void analysis_state(const char **format_p,va_list args)
{
	if(**format_p=='%')
	{
		(*format_p)++; //skip '%'
		output_state(args,**format_p);
	}
	else
	{
		putchar(**format_p);
	}
}


void ft_printf(const char *format,...)
{
	va_list args;
	va_start(args,format);

	while(*format)
	{
		analysis_state(&format,args);
		format++;
	}

	va_end(args);
}


int main()
{
	long  d;
	d=-2147483649;

	//ft_printf("Hello,%s!","world");
	//ft_printf("%p",&i);
	printf("d decimal=%d",d);
	printf("i integer=%i",d);
	return 0;
}
