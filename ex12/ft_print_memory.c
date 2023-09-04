/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:47:50 by fltorren          #+#    #+#             */
/*   Updated: 2023/09/04 16:18:06 by fltorren         ###   ########.fr       */
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
	const char	*hex;

	hex = "0123456789abcdef";
	if (addr > 16 || size > 1)
		ft_print_hex(addr / 16, --size);
	addr %= 16;
	ft_putchar(hex[addr]);
}

void	ft_print_bytes_line(unsigned char *addr, int size)
{
	int				i;
	unsigned char	temp;

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
	while (i < size && i < 16)
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
		ft_print_bytes_line((unsigned char *)addr, size - (i * 16));
		ft_putchar(' ');
		ft_print_printables((char *)addr, size - (i * 16));
		ft_putchar('\n');
		addr += 16;
		i++;
	}
	return (addr);
}

/*int	main(void)
{
	char *str = "Bonjour les aminches	\n	c\a est fou	tout"
	"	ce qu on peut faire avec	\n	print_memory\n\n\n	lol.lol\n  ";
	ft_print_memory((char *)str, 200);
	return (0);
}*/