/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:35 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/20 21:06:48 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	while (src[i] && j + i + 1 < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j != size)
		dst[j + i] = 0;
	while (src[i])
		i++;
	return (i + j);
}
