/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:44:05 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 14:03:11 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_integer_else_2(int arg, int len, int tmp, t_params *my_struct)
{
	char	*arg_str;

	arg_str = ft_itoa(arg);
	if (arg < 0)
		len += ft_putchar('-');
	while (tmp-- > (int)ft_strlen(arg_str))
		len += write(1, "0", 1);
	ft_putnbr2(arg, my_struct);
	free(arg_str);
	return (len);
}

int	ft_others(int index, char *input, t_params *my_struct)
{
	if (input[index] == '+')
	{
		my_struct->plus = 1;
		index++;
	}
	else if (input[index] == '#')
	{
		my_struct->hash = 1;
		index++;
	}
	else if (input[index] == ' ')
	{
		my_struct->space = 1;
		index++;
	}
	else
		index++;
	return (index);
}

int	ft_point(int index, t_params *my_struct, char *input, int *nbr)
{
	index++;
	my_struct->point = 1;
	while (ft_isdigit(input[index]))
	{
		*nbr = *nbr * 10 + input[index] - '0';
		index++;
	}
	return (index);
}

int	ft_zero(int index, t_params *my_struct, char *input, int *nbr)
{
	my_struct->zeros = 1;
	while (ft_isdigit(input[index]))
	{
		*nbr = *nbr * 10 + input[index] - '0';
		index++;
	}
	return (index);
}

int	ft_handle_while(char *input, t_params *my_struct, int nbr, va_list args)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (input[index] && !(ft_iscommand(input[index])))
	{
		nbr = 0;
		if (input[index] == '-')
			index = ft_minus(index, input, nbr, my_struct);
		else if (input[index] == '0')
			index = ft_zero(index, my_struct, input, &nbr);
		else if (input[index] >= '1' && input[index] <= '9')
			index = ft_width(index, input, nbr, my_struct);
		else if (input[index] == '.')
			index = ft_point(index, my_struct, input, &nbr);
		else
			index = ft_others(index, input, my_struct);
	}
	len += print_value(input[index], args, my_struct, nbr);
	return (len);
}
