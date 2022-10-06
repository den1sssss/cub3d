/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:25 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 11:28:39 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;

	a = (unsigned char *)malloc(count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}
