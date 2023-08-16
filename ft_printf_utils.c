/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.42kocaeli.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:51:10 by emmodogl          #+#    #+#             */
/*   Updated: 2023/07/19 10:51:12 by emmodogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int em)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (em == 0)
		return (write(1, "0", 1));
	if (em == -2147483648)
		return (write(1, "-2147483648", 11));
	if (em < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		leng++;
		em *= -1;
	}
	if (em >= 10)
	{
		tmp = ft_int(em / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[em % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_unsigned(unsigned int em)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (em >= 10)
	{
		tmp = ft_unsigned(em / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[em % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int d, char em)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, em);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (em == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (em == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (leng + 1);
}

int	ft_point(unsigned long em, int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		leng += 2;
	}
	if (em >= 16)
	{
		tmp = ft_point(em / 16, i);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789abcdef"[em % 16], 1) == -1)
		return (-1);
	return (leng + 1);
}
