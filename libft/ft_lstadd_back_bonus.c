/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:44 by dshirely          #+#    #+#             */
/*   Updated: 2021/10/17 11:37:16 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*kek;

	kek = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		kek = *lst;
		while (kek->next != NULL)
			kek = kek->next;
	}
	if (kek != NULL)
		kek->next = new;
}
