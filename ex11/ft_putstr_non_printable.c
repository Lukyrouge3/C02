/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:41:47 by fltorren          #+#    #+#             */
/*   Updated: 2023/08/31 18:16:31 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_int_to_put_hex(int n)
{
	int	temp;

	if (n < 16)
		temp = 0;
	else
		temp = n / 16;
	if (temp < 10)
		ft_putchar('0' + temp);
	else
		ft_putchar('a' + temp - 10);
	n %= 16;
	if (n < 10)
		ft_putchar('0' + n);
	else
		ft_putchar('a' + n - 10);
}

int	ft_str_is_printable(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < '!' || c > '~')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_int_to_put_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}