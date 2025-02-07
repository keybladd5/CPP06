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

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) 
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


static bool checkSpecial(std::string const &input)
{
	if (!(input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf" || input == "nan" || input == "nanf"))
		return (false);
	return (true);
}

static bool checkInt(std::string const &input)
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			return (false);
		}
	}
	if (std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < INT_MIN || input == "-")
		return (false);
	return (true);
}

static bool checkDouble(std::string const &input)
{
	char *tmpPtr;
	bool checkDot = false;
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			else if (*it == '.' && it != input.begin() && it != (input.end() - 1) && !checkDot)
			{
				checkDot = true;
				continue;
			}
			else
				return (false);
		}
	}

	std::cout << std::strtod(input.c_str(), &tmpPtr) << std::endl;
	if (input == "-")
		return (false);
	return (true);
}

static bool checkFloat(std::string const &input)
{
	bool checkDot = false;
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			else if (*it == '.' && it != input.begin() && it != (input.end() - 1) && !checkDot)
			{
				checkDot = true;
				continue;
			}
			else if (*it == 'f' && it == (input.end() - 1))
				continue;
			else
				return (false);
		}
	}
	if (input == "-")
		return (false);
	return (true);
}

static bool checkChar(std::string const &input)
{
		if (input.size() > 1)
			return (false);
		else if (!std::isprint(input[0]))
			return (false);
		return (true);
}

static char parse_type(std::string const &input)
{
	if (input.empty())
		return('n');
	else if (checkSpecial(input))
		return ('s');
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

static void isChar(char input)
{
	std::cout << "Char: '" << input << "'"<<std::endl;
	std::cout << "Int: " << static_cast<int>(input) << std::endl;
	std::cout << "Float: " << static_cast<float>(input) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(input) << ".00" << std::endl;
}

static void isInt(int input)
{
	if (std::isprint(input))
		std::cout << "Char: '" << static_cast<char>(input) << "'"<<std::endl;
	else
		std::cout << "Char: Non displayable"<<std::endl;
	std::cout << "Int: " << input << std::endl;
	std::cout << "Float: " << static_cast<float>(input) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(input) << ".00" << std::endl;
}

static void isFloat(float input)
{
	if (input >= 32 && input <= 126)
		std::cout << "Char: '" << static_cast<char>(input) << "'"<<std::endl;
	else
		std::cout << "Char: Non displayable"<<std::endl;
	std::cout << "Int: " << static_cast<int>(input) << std::endl;
	if (std::floor(input) != input)
	{
		std::cout << "Float: " << input << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(input) << std::endl;
	}
	else
	{
		std::cout << "Float: " << input << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(input) << ".00" << std::endl;
	}
}

static void isDouble(double input)
{
	if (input >= 32 && input <= 126)
		std::cout << "Char: '" << static_cast<char>(input) << "'"<<std::endl;
	else
		std::cout << "Char: Non displayable"<<std::endl;
	std::cout << "Int: " << static_cast<int>(input) << std::endl;
	if (std::floor(input) != input)
	{
		std::cout << "Float: " << static_cast<double>(input) << "f" << std::endl;
		std::cout << "Double: " << input << std::endl;
	}
	else
	{
		std::cout << "Float: " << static_cast<float>(input) << ".0f" << std::endl;
		std::cout << "Double: " << input << ".00" << std::endl;
	}
}

static void isSpecial(std::string const &input)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	if (input == "+inf" || input == "-inf" || input == "nan")
		std::cout << "Float: " << input << "f" << std::endl;
	else
		std::cout << "Float: " << input << std::endl;
	if (input == "+inff" || input == "-inff" || input == "nanf")
		std::cout << "Double: " << input.substr(0, input.size()-1) << std::endl;
	else
		std::cout << "Double: " << input << std::endl;

}

static void isNothing(void)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: impossible" << std::endl;
	std::cout << "Double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	char type = parse_type(input);
	if (type == 'c')
		isChar(input[0]);
	else if (type == 'i')
		isInt(std::atoi(input.c_str()));
	else if (type == 'f')
		isFloat(std::atof(input.c_str()));
	else if (type == 'd')
		isDouble(std::atof(input.c_str()));
	else if (type == 's')
		isSpecial(input);
	else
		isNothing();
}
