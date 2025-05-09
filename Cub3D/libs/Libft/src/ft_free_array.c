/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:52:00 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 17:52:41 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **array)
{
	int	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (array[i])
		ft_secure_free(&array[i++]);
	ft_secure_free((void **)&array);
}
