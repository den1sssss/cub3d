/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:25 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/20 20:12:06 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_ochistka(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
	return (NULL);
}

static int	sledslovo(char const *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static int	kolvoslov(char const *s, char c)
{
	int	count;
	int	i;

	if (!*s)
		return (0);
	i = 0;
	count = 0;
	i = sledslovo(s, c, i);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		i = sledslovo(s, c, i);
		count++;
	}
	return (count);
}

static int	dlina_slova(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		start;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = kolvoslov(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < count)
	{
		start = sledslovo(s, c, start);
		arr[i] = ft_substr(s, start, dlina_slova(s, c, start));
		if (!arr[i])
			return (ft_ochistka(arr));
		while (s[start] && s[start] != c)
			start++;
	}
	arr[i] = NULL;
	return (arr);
}
