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

bool checkSpecial(std::string const &input)
{
	if (!(input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf" || input == "nan"))
		return (false);
	return (true);
}

bool checkInt(std::string const &input)
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			else
				return (false);
		}
	}
	if (std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < INT_MIN)
		return (false);
	return (true);
}


bool checkDouble(std::string const &input)
{
	char *end;
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			else if (*it == '.' && it != input.begin() && *it != input[input.size()-1] && std::strtod(input.c_str(), &end) != 0)
				continue;
			else
				return (false);
		}
	}
	return (true);
}

bool checkFloat(std::string const &input)
{
	char *end;
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '-' && it == input.begin())
				continue;
			else if (*it == '.' && it != input.begin() && *it != input[input.size()-1] && std::strtod(input.c_str(), &end) != 0)
				continue;
			else if (*it == 'f' && *it == input[input.size()-1])
				continue;
			else
				return (false);
		}
	}
	return (true);
}

bool checkChar(std::string const &input)
{
		if (input.size() > 1)
			return (false);
		else if (!std::isprint(input[0]))
			return (false);
		return (true);
}



char parse_type(std::string const &input)
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


//Convertor funcs, with type set, just will print the specific conversion in every funcs depending on the type

/*void isChar(char input)
{
	char *end;
	std::cout << "Char: ";
	if (type == 'c')
		std::cout << "'" << input << "'";
	else if ((type == 'f' || type == 'd' || type == 'i') && std::strtold(input.c_str(), &end) >= 32 && std::strtold(input.c_str(), &end) <= 126)
		std::cout << static_cast<char>(input)
}

void isInt(int input)
{
	std::cout << "Int: " << std::atoi(input.c_str()) << std::endl;
}

void isFloat(float input)
{
	std::cout << "Float: " << static_cast<float>(std::atof(input.c_str())) << std::endl;
}

void isDouble(double input)
{
	std::cout << "Double: " << static_cast<double>(std::atof(input.c_str())) << std::endl;
}*/

void ScalarConverter::convert(std::string const &input)
{
	char type = parse_type(input);
	std::cout << "el parser ha dado: " << type << std::endl;
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
		isNothing(input);
}


/*Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan*/
