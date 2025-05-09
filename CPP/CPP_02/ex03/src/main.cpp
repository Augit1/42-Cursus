/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:49 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/23 18:34:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	Point	inside(2, 2);
	Point	outside(-2, 1);

	std::cout << "Point inside triangle: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Point outside triangle: " << bsp(a, b, c, outside) << std::endl;
	
	return 0;
}
