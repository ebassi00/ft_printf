/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:13:55 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 11:57:44 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_not_str(char *str, t_params *my_struct, int len);
int	ft_str_point(int tmp, char *str, int len);
int	ft_str_minus(int nbr, int len, t_params *my_struct, char *str);

int	ft_handle_string(va_list args, t_params *my_struct, int nbr)
{
	int		len;
	int		tmp;
	char	*str;
	int		i;

	len = 0;
	i = 0;
	tmp = nbr;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (my_struct->wdth && !my_struct->point)
		len += ft_not_str(str, my_struct, len);
	else if (my_struct->point)
		len += ft_str_point(tmp, str, len);
	else if (my_struct->minus)
		len += ft_str_minus(nbr, len, my_struct, str);
	else
	{
		if (!str)
			len += ft_putstr("(null)");
		else
			len += ft_putstr(str);
	}
	return (len);
}

int	ft_not_str(char *str, t_params *my_struct, int len)
{
	if (!str)
	{
		while (my_struct->wdth-- > 6)
			len += ft_putchar(' ');
		len += ft_putstr("(null)");
	}
	else
	{
		while (my_struct->wdth-- > (int)ft_strlen(str))
			len += write(1, " ", 1);
		len += ft_putstr(str);
	}
	return (len);
}

int	ft_str_point(int tmp, char *str, int len)
{
	int	i;

	i = 0;
	while (tmp-- > 0 && str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_str_minus(int nbr, int len, t_params *my_struct, char *str)
{
	int	tmp;

	tmp = nbr;
	len += ft_putstr(str);
	while (my_struct->minus-- > (int)ft_strlen(str))
		len += write(1, " ", 1);
	return (len);
}
