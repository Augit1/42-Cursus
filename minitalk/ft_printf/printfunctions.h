/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:57:54 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:01:51 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFUNCTIONS_H
# define PRINTFUNCTIONS_H

# include <stdarg.h>

int	ft_printchar(va_list *args);
int	ft_printstr(va_list *args);
int	ft_printnbr(va_list *args);
int	ft_printunbr(va_list *args);

#endif
