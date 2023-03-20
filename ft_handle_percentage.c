/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:33:11 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 11:54:58 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_percentage_2(t_params *my_struct, unsigned int arg, int len, \
							int nbr);

int	ft_handle_percentage(va_list args, t_params *my_struct, int nbr)
{
	int	len;
	int	tmp;
	int	arg;

	len = 0;
	tmp = nbr;
	arg = va_arg(args, int);
	if (my_struct->space)
		len += write(1, " ", 1);
	if (my_struct->zeros)
	{
		while (tmp > 0)
		{
			len += write(1, "0", 1);
			tmp--;
		}
	}
	len += ft_handle_percentage_2(my_struct, arg, len, nbr);
	len += ft_putchar('%');
	return (len);
}

int	ft_handle_percentage_2(t_params *my_struct, unsigned int arg, int len, \
							int nbr)
{
	int	tmp;

	tmp = nbr;
	if (my_struct->plus)
	{
		if (arg < 0)
			len += write(1, "-", 1);
		else if (arg > 0)
			len += write(1, "+", 1);
	}
	if (my_struct->point)
	{
		while (tmp-- > 0)
			len += write(1, "0", 1);
	}
	tmp = nbr;
	if (my_struct->minus)
	{
		while (tmp > 0)
		{
			len += write(1, "0", 1);
			tmp--;
		}
	}
	return (len);
}
