/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:42 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/20 21:07:13 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ultrakek(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	lenn;
	int	lenh;
	int	tlen;

	lenn = ft_strlen(needle);
	lenh = ft_strlen(haystack);
	i = 0;
	tlen = len - lenn + 1;
	while (i < lenh - lenn + 2 && tlen--)
	{
		j = 0;
		while (j < lenn)
		{
			if (needle[j] == haystack[i + j])
				j++;
			else
				break ;
		}
		if (j == lenn)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	return (ultrakek(haystack, needle, len));
}
