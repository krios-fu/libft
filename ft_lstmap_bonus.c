/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 03:26:17 by krios-fu          #+#    #+#             */
/*   Updated: 2021/03/31 16:45:29 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_n;
	t_list	*ele_n;

	if (!f || !lst)
		return (NULL);
	list_n = NULL;
	while (lst)
	{
		ele_n = ft_lstnew(f(lst->content));
		if (!ele_n)
		{
			ft_lstclear(&list_n, del);
		}
		ft_lstadd_back(&list_n, ele_n);
		lst = lst->next;
	}
	return (list_n);
}
