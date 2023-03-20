/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:02:03 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 12:28:20 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_return_res(unsigned long int nbr, char *base, int index, int *len);

int	ft_iscommand(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' || ch == 'i' \
		|| ch == 'u' || ch == 'x' || ch == 'X' || ch == '%')
		return (1);
	else
		return (0);
}

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	int	index;
	int	len[1];

	len[0] = 0;
	index = 0;
	while (base[index] != '\0')
		index++;
	ft_return_res(nbr, base, index, len);
	return (len[0]);
}

void	ft_return_res(unsigned long int nbr, char *base, int index, int *len)
{
	unsigned long int	nb;
	char				str;

	nb = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * (-1);
		len[0] += 1;
	}
	else
		nb = nbr;
	if (nb >= (unsigned long int)index)
		ft_return_res(nb / index, base, index, len);
	str = base[nb % index];
	write(1, &str, 1);
	len[0]++;
}

int	ft_handle_integer_space(int arg, int len, t_params *my_struct)
{
	if (arg >= 0)
		len += write(1, " ", 1);
	else if (arg < 0)
		len += write(1, "-", 1);
	ft_putnbr2(arg, my_struct);
	return (len);
}
