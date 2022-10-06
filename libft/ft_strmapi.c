/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:40 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/18 20:13:02 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		dlina;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	dlina = ft_strlen(s);
	str = (char *)malloc(dlina + 1);
	if (!str)
		return (NULL);
	while (i < dlina)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
