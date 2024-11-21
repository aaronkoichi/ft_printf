/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:39:50 by zlee              #+#    #+#             */
/*   Updated: 2024/11/21 21:40:51 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_base_low(unsigned int num, char cap)
{
	if (num > 15)
		ft_put_base_low(num / 16, cap);
	if (cap == 'x')
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	else
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
}

void	ft_putvoid(void *ptr)
{
	int				index;
	unsigned char	*temp;

	index = 0;
	temp = ptr;
	ft_putstr_fd("0x", 1);
	ft_put_base_low(*(int *)&ptr, 'x');
}


void	ft_process_percent(char	*str)
{
	return ;
}

int	ft_percent_prep(char *s, va_list list_variable)
{
	char	*find_conver;
	int		cycle;
	int		i;
	int		is_neg;

	cycle = 0;
	is_neg = 0;
	i = 0;
		// search for the presence of cspdiuxX% or not.
		i = 1;
		while (s[i] != '\0')
		{
			if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
			s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' ||
			s[i] == '%')
				ft_process_percent(ft_substr(s, 0, i));
			i++;
		}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	list_variable;
	int		index;
	int		bytes;

	index = 0;
	bytes = 0;
	va_start(list_variable, string);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
			ft_percent_prep((char *)&string[index], list_variable);
	}
	va_end(list_variable);
	return (0);
}
