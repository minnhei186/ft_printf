//#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}


static int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	d_output(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	if (n == -2147483648)
	{
		str=strdup("-2147483648");
		ft_putstr(str);
		return;
	}
	len = get_num_length(n);
	if (n < 0)
	{
		sign = -1;
		n = n * sign;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(str);
		return;
	}
	*(str + len) = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	ft_putstr(str);
	return ;
}

////マロックの問題は、マイナスを定数でとっていたために発生した。動的にその場合において作成すればこれらの問題は回避される。つまりdigitに計算を追加使用。
//int digit_re(int d)
//{
//	if(d==0)
//		return 0;
//	else
//		return digit_re(d/10)+1;
//}
//
//int digit(int d)
//{
//	int len;
//	len=0;
//	if(d<=0)
//	{
//		len=1;
//		d=-d;
//	}
//	return 
//		len=len+digit_re(d);
//}
//
//
////void d_output(va_list args)
////{
////	int d=(va_arg(args,int));
//
//
//void d_output(int num)
//{
//	int d=num;
//	int digit_num=digit(d)+1; //digit+terminating character
//	int sign;
//	char *str=(char *)calloc(digit_num,sizeof(char));
//	if(str==NULL)
//		free(str);
//
//
//	if(d==-2147483648)
//	{
//		ft_putstr("-2147483648");
//		free(str);
//		return ;
//	}
//	if(d<0)
//	{
//		sign=1;
//		d=-d;
//	}
//	digit_num=digit_num-2;
//	while(digit_num)
//	{
//		str[digit_num]=d%10+'0';
//		d=d/10;
//		digit_num--;
//	}
//	if(sign)
//		str[digit_num]='-';
//	else
//		str[digit_num]=d%10+'0';
//
//	ft_putstr(str);
//	free(str);
//}
//
	
int main(void)
{
	int i;
	i=-2147483647;
	//d_output(i);
	printf("d=%d,u=%u",i,i);
	return 0;
}


	






