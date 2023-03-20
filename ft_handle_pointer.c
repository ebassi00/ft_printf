/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:23:12 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 12:02:01 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_pointer_2(t_params *my_struct, int len, \
						unsigned long int arg, int nbr);

int	ft_handle_pointer(va_list args, t_params *my_struct, int nbr)
{
	int					len;
	int					tmp;
	unsigned long int	arg;
	char				*len_str;

	len = 0;
	arg = va_arg(args, unsigned long int);
	tmp = nbr;
	len_str = ft_convert_base(arg, "0123456789abcdef");
	if (my_struct->wdth && !my_struct->point)
	{
		while (my_struct->wdth-- > (int)ft_strlen(len_str) + 2)
			len += write(1, " ", 1);
		len += write(1, "0x", 2);
		len += ft_putnbr_base(arg, "0123456789abcdef");
	}
	else if (my_struct->point || my_struct->minus)
		len += ft_handle_pointer_2(my_struct, len, arg, nbr);
	else
	{
		len += write(1, "0x", 2);
		len += ft_putnbr_base(arg, "0123456789abcdef");
	}
	free(len_str);
	return (len);
}

int	ft_handle_pointer_2(t_params *my_struct, int len, unsigned long int arg, \
						int nbr)
{
	int	tmp;
	int	len_nbr;

	len_nbr = 0;
	tmp = nbr;
	if (my_struct->point)
	{
		len += write(1, "0x", 2);
		while (tmp > 0)
		{
			len += write(1, "0", 1);
			tmp--;
		}
	}
	else if (my_struct->minus)
	{
		tmp = nbr;
		len += write(1, "0x", 2);
		len += ft_putnbr_base(arg, "0123456789abcdef");
		len_nbr = len;
		while (my_struct->minus-- > len_nbr)
			len += write(1, " ", 1);
	}
	return (len);
}
