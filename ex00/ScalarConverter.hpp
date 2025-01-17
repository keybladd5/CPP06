/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:45:32 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/16 17:45:33 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits.h>

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(ScalarConverter const &);
			~ScalarConverter();
	public:
			static void convert(std::string const &);
};
#endif
