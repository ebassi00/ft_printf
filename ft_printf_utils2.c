/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:27:59 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 12:27:50 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus(int index, char *input, int nbr, t_params *my_struct)
{
	index++;
	while (ft_isdigit(input[index]))
	{
		nbr = nbr * 10 + input[index] - '0';
		index++;
	}
	my_struct->minus = nbr;
	return (index);
}

int	ft_width(int index, char *input, int nbr, t_params *my_struct)
{
	while (ft_isdigit(input[index]))
	{
		nbr = nbr * 10 + input[index] - '0';
		index++;
	}
	my_struct->wdth = nbr;
	return (index);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
