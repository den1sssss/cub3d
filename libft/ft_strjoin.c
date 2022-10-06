/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:34 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/22 17:30:01 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	a = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	while (*s1)
		a[i++] = *s1++;
	while (*s2)
		a[i++] = *s2++;
	a[i] = '\0';
	return (a);
}
