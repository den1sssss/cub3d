/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:17 by dshirely          #+#    #+#             */
/*   Updated: 2022/10/07 01:06:19 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*kek;
	unsigned char	*lel;

	kek = (unsigned char *)dest;
	lel = (unsigned char *)src;
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		while (--n + 1)
			kek[n] = lel[n];
	}
	return (kek);
}
