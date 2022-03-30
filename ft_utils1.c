/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:02:06 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/11/23 18:30:45 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_string(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_hexa_x(unsigned long int value, char hex)
{
	char			*base;
	static int		count;

	count = 0;
	if (hex == 'x')
		base = "0123456789abcdef";
	if (hex == 'X')
		base = "0123456789ABCDEF";
	if (value > 15)
	{
		ft_hexa_x(value / 16, hex);
	}
	count++;
	ft_char(base[value % 16]);
	return (count);
}
