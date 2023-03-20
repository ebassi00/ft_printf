/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:46:11 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/01 16:46:41 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_integer_2(t_params *my_struct, int arg, int len, char *arg_str);
int	ft_handle_integer_minus(int arg, t_params *my_struct, \
							int len, char *arg_str);
int	ft_handle_integer_point(int nbr, int arg, int len, t_params *my_struct);
int	ft_handle_integer_else(t_params *my_struct, int arg, int nbr, int len);

int	ft_handle_integer(va_list args, t_params *my_struct, long int nbr)
{
	int		len;
	int		tmp;
	int		arg;
	int		flag;
	char	*arg_str;

	len = 0;
	flag = 0;
	tmp = nbr;
	arg = va_arg(args, int);
	arg_str = ft_itoa(arg);
	if (arg_str[0] == '-')
		flag = 1;
	if (my_struct->space)
		len += ft_handle_integer_space(arg, len, my_struct);
	else if (my_struct->plus || (my_struct->wdth && !my_struct->point))
		len += ft_handle_integer_2(my_struct, arg, len, arg_str);
	else
		len += ft_handle_integer_else(my_struct, arg, nbr, len);
	len += ft_strlen(arg_str) - flag;
	free(arg_str);
	return (len);
}

int	ft_handle_integer_2(t_params *my_struct, int arg, int len, char *arg_str)
{
	if (my_struct->plus)
	{
		if (arg >= 0)
			len += write(1, "+", 1);
		else
			len += write(1, "-", 1);
		ft_putnbr2(arg, my_struct);
	}
	else if (my_struct->wdth && !my_struct->point)
	{
		while (my_struct->wdth > (int)ft_strlen(arg_str))
		{
			len += write(1, " ", 1);
			my_struct->wdth--;
		}
		if (arg < 0)
			len += ft_putchar('-');
		ft_putnbr2(arg, my_struct);
	}
	return (len);
}

int	ft_handle_integer_minus(int arg, t_params *my_struct, int len, \
							char *arg_str)
{
	if (arg < 0)
		len += ft_putchar('-');
	if (arg != 0)
		ft_putnbr2(arg, my_struct);
	else if (arg == 0 && my_struct->minus && my_struct->wdth)
		ft_putchar(' ');
	else if (arg == 0 && my_struct->minus)
		ft_putnbr2(arg, my_struct);
	while (my_struct->minus-- > (int)ft_strlen(arg_str))
		len += write(1, " ", 1);
	return (len);
}

int	ft_handle_integer_point(int nbr, int arg, int len, t_params *my_struct)
{
	int		tmp;
	int		flag;
	char	*arg_str;

	tmp = nbr;
	flag = 0;
	arg_str = ft_itoa(arg);
	if (arg_str[0] == '-')
		flag = 1;
	if (arg < 0)
		len += ft_putchar('-');
	if (tmp > (int)ft_strlen(arg_str) - flag)
	{
		while (tmp-- > (int)ft_strlen(arg_str) - flag)
			len += ft_putchar('0');
		if (arg == 0)
			len += ft_putchar('0');
	}
	if (tmp || arg != 0)
		ft_putnbr2(arg, my_struct);
	else
		len -= 1;
	free(arg_str);
	return (len);
}

int	ft_handle_integer_else(t_params *my_struct, int arg, int nbr, int len)
{
	int		tmp;
	int		flag;
	char	*arg_str;

	tmp = nbr;
	flag = 0;
	arg_str = ft_itoa(arg);
	if (arg_str[0] == '-')
		flag = 1;
	if (my_struct->zeros && !my_struct->point)
		len += ft_handle_integer_else_2(arg, len, tmp, my_struct);
	else if (my_struct->minus)
		len += ft_handle_integer_minus(arg, my_struct, len, arg_str);
	else if (my_struct->point)
		len += ft_handle_integer_point(nbr, arg, len, my_struct);
	else if (!my_struct->space)
	{
		if (arg < 0)
			len += ft_putchar('-');
		ft_putnbr2(arg, my_struct);
	}
	free(arg_str);
	return (len);
}
