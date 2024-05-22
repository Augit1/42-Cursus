/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:39:29 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/23 12:44:39 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			ft_lstfail(newlst, new_content, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}

void	ft_lstfail(t_list *newlst, void *new_content, void (*del)(void *))
{
	t_list	*temp;

	if (new_content && del)
		del(new_content);
	while (newlst)
	{
		temp = newlst->next;
		if (newlst->content && del)
			del(newlst->content);
		free(newlst);
		newlst = temp;
	}
}
