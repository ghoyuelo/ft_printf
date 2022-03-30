/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:47:00 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/11/23 18:18:33 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typeof(const char *str, int i, va_list args)
{
	int	c;

	c = 0;
	i += 1;
	if (str[i] == 'c')
		c = ft_char(va_arg(args, int));
	if (str[i] == 's')
		c = ft_string(va_arg(args, char *));
	if (str[i] == 'p')
		c = ft_string("0x") + ft_hexa_x(va_arg(args, unsigned long int), 'x');
	if (str[i] == 'i' || str[i] == 'd')
		c = ft_digit(va_arg(args, int));
	if (str[i] == 'u')
		c = ft_undigit(va_arg(args, unsigned int));
	if (str[i] == 'x')
		c = ft_hexa_x(va_arg(args, unsigned int), 'x');
	if (str[i] == 'X')
		c = ft_hexa_x(va_arg(args, unsigned int), 'X');
	if (str[i] == '%')
		c = ft_char('%');
	return (c);
}

int	ft_printstr(const char *str, va_list args)
{
	int	i;
	int	count;
	int	arg_len;

	i = 0;
	count = 0;
	arg_len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
		else
		{
			arg_len = ft_typeof(str, i, args);
			count += arg_len;
			arg_len = 0;
			i += 2;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!str)
		return (0);
	len = 0;
	i = 0;
	va_start (args, str);
	len = ft_printstr(str, args);
	va_end(args);
	return (len);
}
