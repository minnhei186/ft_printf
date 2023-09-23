#ifndef FT_PRINTF_H
#define FT_PRINTF_H


#include <stdarg.h>

void c_output(va_list args);
void s_output(va_list args);
void p_output(va_list args);
void d_output(va_list args);
void i_output(va_list args);
void u_output(va_list args);
void x_output(va_list args);
void xx_output(va_list args);
void ft_putchar(char c);
void ft_putstr(char *str);


char *base_16(unsigned long long p);
void output_state(va_list args,char specifier);
void analysis_state(const char **format_p,va_list args);
void ft_printf(const char *format,...);

#endif


