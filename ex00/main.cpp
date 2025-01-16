/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:45:44 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/16 17:45:46 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Format should be -> ./ScalarConverter \"string\"" << std::endl;
		return (1);
	}
	std::cout << "SUPER CONVERSOR OUTPUT\n";
	ScalarConverter::convert(argv[1]);
	return (0);
}
