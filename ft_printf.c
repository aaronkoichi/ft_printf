/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:13:23 by zlee              #+#    #+#             */
/*   Updated: 2024/11/20 18:48:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (s[i + 1] == 'c' || s[i + 1] == 'i' || s[i + 1] == 'd')
				ft_putchar_fd(va_arg(list_params, int), 1);
			else if (s[i + 1] == 's' )
				ft_putstr_fd(va_arg(list_params, char *), 1);
			else if (s[i + 1] == 'u')
				ft_putnbr_fd(va_arg(list_params, unsigned int), 1);
		}
	}
	return (0);
}

