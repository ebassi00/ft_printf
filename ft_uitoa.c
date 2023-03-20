/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:58 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 12:30:16 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_uitoa_malloc(unsigned int n)
{
	size_t			len;
	size_t			m;
	unsigned int	nb;

	len = 1;
	m = 1;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while ((nb / m) > 9)
	{
		m *= 10;
		len++;
	}
	if (n < 0)
		len += 1;
	return (len);
}

static unsigned long int	ft_uitoa3(unsigned int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	return (nb);
}

static char	*ft_uitoa2(unsigned int n)
{
	size_t			i;
	size_t			m;
	unsigned int	nb;
	char			*r;

	i = 0;
	m = 1;
	r = (char *)malloc(ft_uitoa_malloc(n) + 1);
	if (!r)
		return (NULL);
	if (n < 0)
	{
		r[i] = 45;
		i++;
	}
	nb = ft_uitoa3(n);
	while ((nb / m) > 9)
		m *= 10;
	while (m > 0)
	{
		r[i++] = ((nb / m) % 10) + 48;
		m /= 10;
	}
	r[i] = 0;
	return (r);
}

char	*ft_uitoa(unsigned int n)
{
	char	*r;

	if (n == 0)
	{
		r = (char *)malloc(2);
		if (!r)
			return (NULL);
		r[0] = 48;
		r[1] = 0;
		return (r);
	}
	else
	{
		r = ft_uitoa2(n);
		return (r);
	}
}
