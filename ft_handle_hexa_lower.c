/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:26:35 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 11:49:47 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hexa_pl_wdth(t_params *my_struct, unsigned int arg, int len, \
							char *len_nbr);
int	ft_handle_hexa_point(int nbr, char *len_nbr, unsigned int arg, int len);
int	ft_handle_hexa_zeros(int nbr, char *len_nbr, int len, unsigned int arg);
int	ft_handle_hexa_all(t_params *my_struct, int len, unsigned int arg, int nbr);

int	ft_handle_hexa_lower(va_list args, t_params *my_struct, int nbr)
{
	int				len;
	unsigned int	arg;
	int				tmp;
	char			*len_nbr;
	int				flag;

	len = 0;
	flag = 0;
	tmp = nbr;
	arg = va_arg(args, unsigned int);
	len_nbr = ft_convert_base(arg, "0123456789abcdef");
	if (my_struct->hash)
	{
		if (arg)
			len += write(1, "0x", 2);
		len += ft_putnbr_base_x(arg, "0123456789abcdef");
	}
	else if (my_struct->minus || my_struct->plus || my_struct->point \
			|| my_struct->space || my_struct->wdth || my_struct->zeros)
		len += ft_handle_hexa_all(my_struct, len, arg, nbr);
	else
		len += ft_putnbr_base_x(arg, "0123456789abcdef");
	free(len_nbr);
	return (len);
}

int	ft_handle_hexa_pl_wdth(t_params *my_struct, unsigned int arg, \
							int len, char *len_nbr)
{
	int	flag;

	flag = 0;
	if (my_struct->plus)
	{
		if (arg > 0)
		{
			len += write(1, "+", 1);
			flag = 1;
		}
		if (arg < 0)
			len += write(1, "-", 1);
	}
	else if (my_struct->wdth && !my_struct->point)
	{
		while (my_struct->wdth-- > (int)ft_strlen(len_nbr) - flag)
			len += write(1, " ", 1);
		len += ft_putnbr_base_x(arg, "0123456789abcdef");
	}
	return (len);
}

int	ft_handle_hexa_point(int nbr, char *len_nbr, unsigned int arg, int len)
{
	int	tmp;

	tmp = nbr;
	if (tmp > (int)ft_strlen(len_nbr))
	{
		while (tmp-- > (int)ft_strlen(len_nbr))
			len += ft_putchar('0');
		if (arg == 0)
				len += ft_putchar('0');
	}
	if (tmp || arg != 0)
		len += ft_putnbr_base_x(arg, "0123456789abcdef");
	return (len);
}

int	ft_handle_hexa_zeros(int nbr, char *len_nbr, int len, unsigned int arg)
{
	int	tmp;

	tmp = nbr;
	while (tmp > (int)ft_strlen(len_nbr))
	{
		len += write(1, "0", 1);
		tmp--;
	}
	len += ft_putnbr_base_x(arg, "0123456789abcdef");
	return (len);
}

int	ft_handle_hexa_all(t_params *my_struct, int len, unsigned int arg, int nbr)
{
	int		tmp;
	char	*len_nbr;

	tmp = nbr;
	len_nbr = ft_convert_base(arg, "0123456789abcdef");
	if (my_struct->space)
		len += write(1, " ", 1);
	else if (my_struct->zeros && !my_struct->point)
		len += ft_handle_hexa_zeros(nbr, len_nbr, len, arg);
	else if (my_struct->plus || (my_struct->wdth && !my_struct->point))
		len += ft_handle_hexa_pl_wdth(my_struct, arg, len, len_nbr);
	else if (my_struct->point)
		len += ft_handle_hexa_point(nbr, len_nbr, arg, len);
	else if (my_struct->minus)
	{
		tmp = nbr;
		len += ft_putnbr_base_x(arg, "0123456789abcdef");
		while (my_struct->minus-- > (int)ft_strlen(len_nbr))
			len += write(1, " ", 1);
	}
	free(len_nbr);
	return (len);
}
