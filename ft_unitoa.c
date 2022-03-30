/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:07:28 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/11/23 15:12:11 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uflen(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	char	*dest;
	long	num;
	int		len;

	num = n;
	len = uflen(num);
	dest = (char *)malloc((len + 1) * sizeof (char));
	if (!dest)
		return (0);
	dest[len] = '\0';
	if (num == 0)
		dest[0] = '0';
	if (num < 0)
	{
		dest[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		dest[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (dest);
}
