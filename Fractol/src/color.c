/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:57:53 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/10 20:36:58 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	pastel(int *color_set)
{
	color_set[0] = 0xFFB6C1;
	color_set[1] = 0xFFA07A;
	color_set[2] = 0x20B2AA;
	color_set[3] = 0x7FFFD4;
	color_set[4] = 0x98FB98;
	color_set[5] = 0xFA8072;
	color_set[6] = 0xF08080;
	color_set[7] = 0x87CEEB;
	color_set[8] = 0xADD8E6;
	color_set[9] = 0xFFD700;
}

void	rainbow(int *color_set)
{
	color_set[0] = 0xFF0000;
	color_set[1] = 0xFF7F00;
	color_set[2] = 0xFFFF00;
	color_set[3] = 0x00FF00;
	color_set[4] = 0x0000FF;
	color_set[5] = 0x4B0082;
	color_set[6] = 0x9400D3;
	color_set[7] = 0xFFC0CB;
	color_set[8] = 0xFFD700;
	color_set[9] = 0x00FFFF;
}

void	warm(int *color_set)
{
	color_set[0] = 0xFF4500;
	color_set[1] = 0xFFA500;
	color_set[2] = 0xFFD700;
	color_set[3] = 0xFF0000;
	color_set[4] = 0xFF6347;
	color_set[5] = 0xFA8072;
	color_set[6] = 0xF08080;
	color_set[7] = 0xCD5C5C;
	color_set[8] = 0xFF8C00;
	color_set[9] = 0xFF1493;
}

void	cold(int *color_set)
{
	color_set[0] = 0x00CED1;
	color_set[1] = 0x4682B4;
	color_set[2] = 0x4169E1;
	color_set[3] = 0x6495ED;
	color_set[4] = 0x87CEEB;
	color_set[5] = 0x87CEFA;
	color_set[6] = 0x00BFFF;
	color_set[7] = 0x1E90FF;
	color_set[8] = 0x4682B4;
	color_set[9] = 0xB0E0E6;
}

void	vibrant(int *color_set)
{
	color_set[0] = 0x74D680;
	color_set[1] = 0x44A8D1;
	color_set[2] = 0xFFD56F;
	color_set[3] = 0xFF968A;
	color_set[4] = 0x9D9D9D;
	color_set[5] = 0x6BCCB2;
	color_set[6] = 0xA6A6A6;
	color_set[7] = 0xF19E81;
	color_set[8] = 0xC7B2DE;
	color_set[9] = 0xD0EBFF;
}
