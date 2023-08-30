/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:56:57 by fltorren          #+#    #+#             */
/*   Updated: 2023/08/30 22:12:12 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || ft_is_alphanumeric(str[i - 1] == 0))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		} else {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
