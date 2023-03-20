/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:32:55 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 12:26:44 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_unsigned2(t_params *my_struct, int nbr, int len, long int arg);
int	ft_handle_unsigned3(t_params *my_struct, int nbr, int len, long int arg);
int	ft_handle_unsigned4(t_params *my_struct, long int arg, int len, int nbr);

int	ft_handle_unsigned(va_list args, t_params *my_struct, int nbr)
{
	int			len;
	int			tmp;
	long int	arg;
	char		*arg_str;

	len = 0;
	tmp = nbr;
	arg = va_arg(args, unsigned int);
	arg_str = ft_uitoa(arg);
	if (my_struct->plus || my_struct->point \
		|| (my_struct->zeros && !my_struct->point) \
		|| (my_struct->wdth && !my_struct->point) || my_struct->space)
		len += ft_handle_unsigned4(my_struct, arg, len, nbr);
	else if (my_struct->minus)
	{
		ft_putnbr2(arg, my_struct);
		while (my_struct->minus-- > (int)ft_strlen(arg_str))
			len += write(1, " ", 1);
	}
	else
		ft_putnbr2(arg, my_struct);
	len += ft_strlen(arg_str);
	free(arg_str);
	return (len);
}

int	ft_handle_unsigned2(t_params *my_struct, int nbr, int len, long int arg)
{
	int		tmp;
	char	*arg_str;

	tmp = nbr;
	arg_str = ft_uitoa(arg);
	if (my_struct->point)
	{
		tmp = nbr;
		if (tmp > (int)ft_strlen(arg_str))
		{
			while (tmp-- > (int)ft_strlen(arg_str))
				len += write(1, "0", 1);
			if (arg == 0)
				len += ft_putchar('0');
		}
		if (tmp || arg != 0)
			ft_putnbr2(arg, my_struct);
		else
			len -= 1;
	}
	free(arg_str);
	return (len);
}

int	ft_handle_unsigned3(t_params *my_struct, int nbr, int len, long int arg)
{
	int		tmp;
	char	*arg_str;

	tmp = nbr;
	arg_str = ft_uitoa(arg);
	if (my_struct->zeros && !my_struct->point)
	{
		while (tmp-- > (int)ft_strlen(arg_str))
			len += write(1, "0", 1);
		ft_putnbr2(arg, my_struct);
	}
	else if (my_struct->wdth && !my_struct->point)
	{
		while (my_struct->wdth > (int)ft_strlen(arg_str))
		{
			len += write(1, " ", 1);
			my_struct->wdth--;
		}
		ft_putnbr2(arg, my_struct);
	}
	free(arg_str);
	return (len);
}

int	ft_handle_unsigned4(t_params *my_struct, long int arg, int len, int nbr)
{
	int	flag;

	flag = 0;
	if (my_struct->space)
		len += write(1, " ", 1);
	else if (my_struct->plus)
	{
		if (arg > 0)
		{
			len += write(1, "+", 1);
			flag = 1;
		}
	}
	else if (my_struct->point)
		len += ft_handle_unsigned2(my_struct, nbr, len, arg);
	else if ((my_struct->zeros && !my_struct->point) \
				|| (my_struct->wdth && !my_struct->point))
		len += ft_handle_unsigned3(my_struct, nbr, len, arg);
	return (len);
}
