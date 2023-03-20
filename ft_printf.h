/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebassi <ebassi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:31:59 by ebassi            #+#    #+#             */
/*   Updated: 2022/02/02 14:17:39 by ebassi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_params {
	int	minus;
	int	zeros;
	int	point;
	int	hash;
	int	space;
	int	plus;
	int	wdth;
}	t_params;

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned long int nbr, char *base);
int		ft_putnbr_base_x(unsigned int nbr, char *base);
void	ft_putnbr2(long int nb, t_params *my_struct);
int		ft_putnbr(int nb, t_params *my_struct);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
int		ft_iscommand(char ch);
int		ft_isdigit(int c);
int		ft_handle_integer(va_list args, t_params *my_struct, long int nbr);
int		ft_handle_string(va_list args, t_params *my_struct, int nbr);
int		ft_handle_char(va_list args, t_params *my_struct, int nbr);
int		ft_handle_pointer(va_list args, t_params *my_struct, int nbr);
int		ft_handle_hexa_lower(va_list args, t_params *my_struct, int nbr);
int		ft_handle_hexa_upper(va_list args, t_params *my_struct, int nbr);
int		ft_handle_percentage(va_list args, t_params *my_struct, int nbr);
int		ft_handle_unsigned(va_list args, t_params *my_struct, int nbr);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strchr(const char *s);
char	*ft_uitoa(unsigned int n);
char	*ft_convert_base(unsigned long int nbr, char *base);
int		ft_minus(int index, char *input, int nbr, t_params *my_struct);
int		ft_width(int index, char *input, int nbr, t_params *my_struct);
int		ft_handle_integer_space(int arg, int len, t_params *my_struct);
int		ft_handle_integer_else_2(int arg, int len, int tmp, \
								t_params *my_struct);
int		ft_others(int index, char *input, t_params *my_struct);
int		ft_handle_while(char *input, t_params *my_struct, int nbr, \
						va_list args);
int		print_value(char ch, va_list args, t_params *my_struct, int nbr);
int		ft_point(int index, t_params *my_struct, char *input, int *nbr);
int		ft_zero(int index, t_params *my_struct, char *input, int *nbr);

#endif
