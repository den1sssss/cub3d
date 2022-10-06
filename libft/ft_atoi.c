/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:41 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 16:47:53 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long				znak;
	unsigned long long	sum;

	znak = 1;
	sum = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		str++;
		znak *= -1;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (sum > 2147483647 && znak + 1)
		return (-1);
	if (sum > 2147483648)
		return (0);
	return ((int)sum * znak);
}
