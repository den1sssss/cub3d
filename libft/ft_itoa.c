/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:41 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 11:35:26 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *s, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len / 2)
	{
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
		i++;
	}
}

static int	dlina(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*kek;
	int		i;
	int		znak;
	int		len;

	i = 0;
	len = dlina(n);
	kek = (char *)malloc(len + 1);
	if (!kek)
		return (NULL);
	znak = 1;
	if (n < 0)
		znak = -1;
	if (!n)
		kek[i++] = '0';
	while (n)
	{
		kek[i++] = (n % 10) * znak + '0';
		n /= 10;
	}
	if (znak < 0)
		kek[i++] = '-';
	reverse(kek, len);
	kek[i] = '\0';
	return (kek);
}
