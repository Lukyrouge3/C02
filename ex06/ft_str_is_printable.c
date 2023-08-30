/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:38:33 by fltorren          #+#    #+#             */
/*   Updated: 2023/08/30 21:41:05 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
** https://bitly.ws/Twxe
*/