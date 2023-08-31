/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:47:50 by fltorren          #+#    #+#             */
/*   Updated: 2023/08/31 18:16:40 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(uintptr_t addr, int size)
{
	if (addr > 16 || size > 1)
		ft_print_hex(addr / 16, --size);
	addr %= 16;
	if (addr <= 9)
		ft_putchar('0' + addr);
	else
		ft_putchar('a' + addr - 10);
}

void	ft_print_bytes_line(char *addr, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 16)
	{
		temp = addr[i];
		if (i < size)
			ft_print_hex((uintptr_t)temp, 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_printables(char *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (addr[i] < ' ' || addr[i] > '~')
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (addr);
	i = 0;
	while (i < (1 + ((size - 1) / 16)))
	{
		ft_print_hex((uintptr_t)addr, 16);
		write(1, ": ", 2);
		ft_print_bytes_line((char *)addr, size - (i * 16));
		ft_putchar(' ');
		ft_print_printables((char *)addr, 16);
		ft_putchar('\n');
		addr += 16;
		i++;
	}
	return (addr);
}

// int	main(void)
// {
// 	char *str = "Bonjour les aminches\n\0";
// 	ft_print_memory((char *)str, 20);
// 	return (0);
// }