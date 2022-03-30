/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:05:28 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/11/23 17:49:33 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(int n)
{
	char	*res;
	int		i;

	res = ft_itoa(n);
	i = ft_string(res);
	free(res);
	return (i);
}

int	ft_undigit(unsigned int n)
{
	char	*res;
	int		i;

	res = ft_unitoa(n);
	i = 0;
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	free (res);
	return (i);
}
