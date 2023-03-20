/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:43 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 14:15:47 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int		ft_struct_init(char *input, va_list args);
int		print_value(char ch, va_list args, t_params *my_struct, int nbr);
int		ft_others(int index, char *input, t_params *my_struct);

void	ft_initialize(t_params *my_struct)
{
	my_struct->hash = 0;
	my_struct->minus = 0;
	my_struct->plus = 0;
	my_struct->point = 0;
	my_struct->space = 0;
	my_struct->zeros = 0;
	my_struct->wdth = 0;
}

int	ft_struct_init(char *input, va_list args)
{
	t_params	*my_struct;
	int			len;
	int			nbr;

	len = 0;
	nbr = 0;
	my_struct = malloc(sizeof(t_params));
	if (!my_struct)
		return (0);
	ft_initialize(my_struct);
	len = ft_handle_while(input, my_struct, nbr, args);
	free(my_struct);
	return (len);
}

int	print_value(char ch, va_list args, t_params *my_struct, int nbr)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	if (ch == 'd' || ch == 'i')
		len += ft_handle_integer(args, my_struct, nbr);
	else if (ch == 's')
		len += ft_handle_string(args, my_struct, nbr);
	else if (ch == 'c')
		len += ft_handle_char(args, my_struct, nbr);
	else if (ch == 'p')
		len += ft_handle_pointer(args, my_struct, nbr);
	else if (ch == 'u')
		len += ft_handle_unsigned(args, my_struct, nbr);
	else if (ch == 'x')
		len += ft_handle_hexa_lower(args, my_struct, nbr);
	else if (ch == 'X')
		len += ft_handle_hexa_upper(args, my_struct, nbr);
	else if (ch == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;
	int		index;
	int		tmp_len;

	len = 0;
	index = 0;
	tmp_len = 0;
	va_start(args, input);
	while (input[index] != '\0')
	{
		if (input[index] != '%')
			len += ft_putchar(input[index]);
		else
		{
			len += ft_struct_init((char *)&input[index + 1], args);
			index += ft_strchr(&input[index + 1]);
		}
		index++;
	}
	va_end(args);
	return (len);
}
