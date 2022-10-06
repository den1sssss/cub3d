/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:46 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/20 18:10:47 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*kek;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	kek = (char *)malloc(len + 1);
	if (!kek)
		return (NULL);
	while (i < len)
	{
		kek[i] = s[i + start];
		i++;
	}	
	kek[i] = '\0';
	return (kek);
}
