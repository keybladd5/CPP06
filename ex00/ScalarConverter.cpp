/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:45:23 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/16 17:45:25 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//checker funcs to set the type data input

bool checkInt(std::string const &input)
{
	if (input.at(0) == 0 && (input.size() == 1 || std::atoi(input.c_str()) == 0)) // 0 si, 0
}


bool checkDouble(std::string const &input)
{
	
}
bool checkFloat(std::string const &input)
{
	
}
bool checkChar(std::string const &input)
{
	
}



char parse_type(std::string const &input)
{
	if (input.empty())
		return('n');
	else if (checkInt(input))
		return ('i');
	else if (checkDouble(input))
		return ('d');
	else if (checkFloat(input))
		return ('f');
	else if (checkChar(input))
		return ('c');
	return ('n');
}


//Convertor funcs, with type set, just will print the specific conversion in every funcs depending on the type

void toChar(std::string const &input, char type)
{
	char c = input[0];//std::atoi(input.c_str());
	std::cout << "Char: " << c << std::endl;
	//std::setprecisicion(1);??
}

void toInt(std::string const &input, char type)
{
	std::cout << "Int: " << std::atoi(input.c_str()) << std::endl;
}

void toFloat(std::string const &input, char type)
{
	std::cout << "Float: " << static_cast<float>(std::atof(input.c_str())) << std::endl;
}

void toDouble(std::string const &input, char type)
{
	std::cout << "Double: " << static_cast<double>(std::atof(input.c_str())) << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	char type = parse_type(input);
	//no hay que parsear nada en esta parte, llamar a todos los conversores porque queremos ver el string casteado a los siguientes 4 tipos de datos
	toChar(input, type);
	toInt(input), type;
	toFloat(input, type);
	toDouble(input, type);
}


/*Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan*/
