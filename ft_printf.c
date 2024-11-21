/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:13:23 by zlee              #+#    #+#             */
/*   Updated: 2024/11/21 09:30:53 by zlee             ###   ########.fr       */
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

int	ft_printf(const char *s, ...)
{
	va_list	list_params;
	int		i;

	i = 0;
	va_start(list_params, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				ft_putchar_fd(va_arg(list_params, int), 1);
			else if (s[i + 1] == 'i' || s[i + 1] == 'd')
				ft_putnbr_fd(va_arg(list_params, int), 1);
			else if (s[i + 1] == 's' )
				ft_putstr_fd(va_arg(list_params, char *), 1);
			else if (s[i + 1] == 'u')
				ft_putnbr_fd(va_arg(list_params, unsigned int), 1);
			else if (s[i + 1] == 'x' || s[i + 1] == 'X')
				ft_put_base_low(va_arg(list_params, unsigned int), s[i + 1]);
			else if (s[i + 1] == 'p')
				ft_putvoid(va_arg(list_params, void *));
		}
	}
	va_end(list_params);
	return (0);
}

