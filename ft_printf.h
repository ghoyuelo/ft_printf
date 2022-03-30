/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:51:17 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/11/23 18:18:19 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_char(int c);
int		ft_string(char *s);
int		ft_digit(int n);
char	*ft_itoa(int n);
int		flen(long num);
int		ft_undigit(unsigned int num);
char	*ft_unitoa(unsigned int n);
int		uflen(long num);
int		ft_hexa_x(unsigned long int value, char hex);

#endif
