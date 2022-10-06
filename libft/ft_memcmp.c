/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:15 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/20 21:06:21 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	if (n == 0)
		return (0);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	while (*a1 == *a2 && n - 1 > 0)
	{
		a1++;
		a2++;
		n--;
	}
	return (*a1 - *a2);
}
