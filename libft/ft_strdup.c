/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:29 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/22 17:29:34 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*kek;
	int		i;

	i = -1;
	kek = (char *)malloc(ft_strlen(s1) + 1);
	if (!kek)
		return (NULL);
	while (s1[++i])
		kek[i] = s1[i];
	kek[i] = '\0';
	return (kek);
}
