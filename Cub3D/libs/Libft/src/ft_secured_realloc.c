/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secured_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:14:31 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 15:18:12 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_secured_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	if (new_size == 0)
	{
		if (ptr != NULL)
			free((char *)ptr - sizeof(size_t));
		return (NULL);
	}
	result = malloc(new_size + 1);
	if (!result)
		return (NULL);
	if (old_size && ptr)
	{
		if (old_size < new_size)
			ft_memmove(result, ptr, old_size);
		else
			ft_memmove(result, ptr, new_size);
		free(ptr);
	}
	return (result);
}
