/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:16 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 11:42:54 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*kek;
	unsigned char	*lel;

	if (!dest && !src)
		return (NULL);
	i = 0;
	kek = (unsigned char *)dest;
	lel = (unsigned char *)src;
	while (i < n)
	{
		kek[i] = lel[i];
		i++;
	}
	return (kek);
}
