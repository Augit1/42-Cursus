/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/11 14:09:07 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat pedro("pedro", 125);
		Form	taxForm("Tax Form", 100, 50);

        std::cout << pedro << std::endl;
        std::cout << taxForm << std::endl;
        
		pedro.signForm(taxForm);
        std::cout << "After signature: " << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat john("John", 5);
		Form	otherone("otherone", 5, 2);

		john.signForm(otherone);
		std::cout << otherone << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
