/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:16:06 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 11:40:18 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*kek;

	if (lst != NULL)
	{
		kek = lst;
		while (kek->next != NULL)
		{
			kek = kek->next;
		}
		return (kek);
	}
	return (NULL);
}
