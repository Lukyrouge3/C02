/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:56:57 by fltorren          #+#    #+#             */
/*   Updated: 2023/08/31 15:18:31 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_alphanumeric(int c)
{
	return (ft_is_alpha(c) || ft_is_digit(c));
}

void	ft_wrdcapitalize(char *str, int word_start, int i)
{
	if (str[word_start] >= 'a' && str[word_start] <= 'z')
		str[word_start] -= 32;
	while (++word_start < i)
	{
		if (str[word_start] >= 'A' && str[word_start] <= 'Z')
			str[word_start] += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word_start;

	i = 0;
	word_start = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alphanumeric(str[i]) == 0)
		{
			ft_wrdcapitalize(str, word_start, i);
			word_start = i + 1;
		}
		i++;
	}
	ft_wrdcapitalize(str, word_start, i);
	return (str);
}
