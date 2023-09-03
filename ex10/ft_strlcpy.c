/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:19:42 by fltorren          #+#    #+#             */
/*   Updated: 2023/09/03 17:43:44 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/*
** #include <stdio.h>
** 
** size_t	strlcpy(char *dst, const char *src, size_t siz)
** {
** 	char *d = dst;
** 	const char *s = src;
** 	size_t n = siz;
** 
** 	
** 	if (n != 0 && --n != 0) {
** 		do {
** 			if ((*d++ = *s++) == 0)
** 				break;
** 		} while (--n != 0);
** 	}
** 
** 	
** 	if (n == 0) {
** 		if (siz != 0)
** 			*d = '\0';		
** 		while (*s++)
** 			;
** 	}
** 
** 	return(s - src - 1);
** }
** 
** int	main(void)
** {
**     char    *c1;
** 	char	c2[8];
** 
** 	c1 = "Hello World !";
** 
**     printf("base   : %s\n", c1);
** 	size_t a = strlcpy(c2, c1, 8);
** 	printf("doit retourner : %s (len: %d)\n", c2, (int) a);
** 	unsigned int b = ft_strlcpy(c2, c1, 8);
** 	printf("retourne : %s (len: %d)\n", c2, b);
** 
** 	return (0);
** }
** 
*/