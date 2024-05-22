/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:04:17 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:07:19 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTHEXA_H
# define PRINTHEXA_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printhexa_ptr(va_list *args);
int	ft_printhexa(va_list *args, char up);
int	ft_puthexa(unsigned long num_hexa);
int	ft_puthexa_up(unsigned long num_hexa);

#endif
