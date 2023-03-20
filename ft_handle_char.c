/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:20:52 by ebassi            #+#    #+#             */
/*   Updated: 2022/01/28 13:47:23 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(va_list args, t_params *my_struct, int nbr)
{
	int	len;
	int	tmp;
	int	arg;

	len = 0;
	tmp = nbr;
	arg = va_arg(args, int);
	if (my_struct->minus)
	{
		len += ft_putchar(arg);
		while (my_struct->minus-- > 1)
			len += ft_putchar(' ');
	}
	else if (my_struct->wdth && !my_struct->point)
	{
		while (my_struct->wdth-- > 1)
			len += ft_putchar(' ');
		len += ft_putchar(arg);
	}
	else
		len += ft_putchar(arg);
	return (len);
}
