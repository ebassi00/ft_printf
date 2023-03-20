/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:05:03 by ebassi            #+#    #+#             */
/*   Updated: 2022/01/28 16:00:49 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(const char *s)
{
	int	i;
	int	len;
	int	res;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (i < len + 1)
	{
		if (ft_iscommand(s[i]))
		{
			res = i + 1;
			return (res);
		}
		i++;
	}
	return (1);
}
