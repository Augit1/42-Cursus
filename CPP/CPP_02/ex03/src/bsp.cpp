/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:15:28 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/23 18:35:46 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calculateArea(Point const a, Point const b, Point const c)
{
	return Fixed(
		std::fabs(
			(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
			(b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
			(c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))
		)
	) / 2.0f;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = calculateArea(a, b, c);
	Fixed	areaPAB = calculateArea(point, a, b);
	Fixed	areaPBC = calculateArea(point, b, c);
	Fixed	areaPCA = calculateArea(point, c, a);
	
	return (areaPAB + areaPBC + areaPCA) == areaABC;
}
