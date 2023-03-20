/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:31 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/01 18:07:20 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_return_res_x(unsigned int nbr, char *base, int index, int *len);
int			non_valid_arg(char *base);

void	ft_putnbr2(long int nb, t_params *my_struct)
{
	if (nb < 0)
		nb *= -1;
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	else
		ft_putnbr2(nb / 10, my_struct);
	ft_putnbr2(nb % 10, my_struct);
	return ;
}

char	*ft_convert_base(unsigned long int nbr, char *base)
{
	size_t				index;
	char				*res;
	unsigned long int	nb;
	int					i;

	index = ft_strlen(base);
	nb = nbr;
	res = (char *) malloc (index + 1);
	i = 0;
	while (nb >= (unsigned long int)index)
	{
		res[i] = base[nb % index];
		nb /= index;
		i++;
	}
	res[i] = base[nb % index];
	i++;
	res[i] = '\0';
	return (res);
}

int	ft_putnbr_base_x(unsigned int nbr, char *base)
{
	int	index;
	int	len[1];

	len[0] = 0;
	index = 0;
	while (base[index] != '\0')
		index++;
	ft_return_res_x(nbr, base, index, len);
	return (len[0]);
}

void	ft_return_res_x(unsigned int nbr, char *base, int index, int *len)
{
	unsigned int	nb;
	char			str;

	nb = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * (-1);
		len[0] += 1;
	}
	else
		nb = nbr;
	if (nb >= (unsigned int)index)
		ft_return_res_x(nb / index, base, index, len);
	str = base[nb % index];
	write(1, &str, 1);
	len[0]++;
}

int	non_valid_arg(char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		else if (base[index] == base[index + 1])
			return (0);
		index++;
	}
	if (index <= 1)
		return (0);
	return (1);
}
