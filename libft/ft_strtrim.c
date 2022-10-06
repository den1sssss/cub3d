/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:45 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/18 20:12:33 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	proverka(char const *str, char const c)
{
	while (*str)
	{
		if (c ==*str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (proverka(set, s1[i]) == 1)
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (proverka(set, s1[j - 1]) == 1)
		j--;
	return (ft_substr(s1, i, j - i));
}
