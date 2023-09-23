/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:30:19 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/08/24 14:52:32 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void test_putstr(char *str)
{
	while(*str)
	{
		putchar(*str);
		str++;
	}
}

char	*base_16(unsigned long long p)
{
	char	base_16[16];
	char	output[19];
	int		i;
	int		t;
	int k;
	k=0;
	while(k<19)
	{
		output[k]='0';
		k++;
	}

	i=0;
	t=0;
	while (t < 10)
	{
		base_16[t] = i + '0';
		i++;
		t++;
	}
	i=0;
	while (t < 16)
	{
		base_16[t] = i+ 'a';
		i++;
		t++;
	}
	//memset(output, '0', sizeof(char)); メムセットがイカれてる。
	i = 17;
	while (p)
	{
		output[i] = base_16[p % 16];
		p = p / 16;
		i--;
	}
	output[0] = '0';
	output[1] = 'x';
	output[18] = '\0';
	return (output);
}

int ft_p_output(void *p)
{
	char				*str;
	int count ;
	unsigned long long pto;

	pto=(unsigned long long)p;

	str = base_16(pto);
	count=strlen(str);
	test_putstr(str);
	free(str);
	return count;
}

 int main(void)
 {
 	int i;
 	i=123;
 	int count;

 	count=ft_p_output(&i);
 	return 0;
 }
