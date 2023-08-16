/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.42kocaeli.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:51:36 by emmodogl          #+#    #+#             */
/*   Updated: 2023/07/19 10:51:37 by emmodogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		leng;
	int		counter;
	int		tmp;

	counter = -1;
	leng = 0;
	va_start(args, str);
	while (str[++counter] != '\0')
	{
		if (str[counter] == '%' && ft_check(str[counter + 1]))
		{
			tmp = ft_format(&args, str[++counter]);
			if (tmp == -1)
				return (-1);
			leng += tmp - 1;
		}
		else if (ft_putchar(str[counter]) == -1)
			return (-1);
		leng++;
	}
	va_end(args);
	return (leng);
}

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_putchar(char x)
{
	return (write(1, &x, 1));
}

int	ft_format(va_list *args, char em)
{
	if (em == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (em == '%')
		return (ft_putchar('%'));
	else if (em == 'd' || em == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (em == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (em == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (em == 'X' || em == 'x')
		return (ft_hex(va_arg((*args), unsigned int), em));
	else if (em == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (0);
}
