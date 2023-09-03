/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:41:47 by fltorren          #+#    #+#             */
/*   Updated: 2023/09/03 14:59:32 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(char c, int size)
{
	if (c > 16 || size > 1)
		ft_print_hex(c / 16, --size);
	c %= 16;
	if (c <= 9)
		ft_putchar('0' + c);
	else
		ft_putchar('a' + c - 10);
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
			ft_print_hex(str[i], 2);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

// int main()
// {
// 	char str[] = "Coucou\n\ttu vas bien ?";
// 	ft_putstr_non_printable(str);
// 	return (0);
// }