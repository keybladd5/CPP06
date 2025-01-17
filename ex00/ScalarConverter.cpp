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


//works
bool checkInt(std::string const &input) // is the first check
{
	//ya sabemos que no esta vacio, asi que checkear que sea un integer implica solo tener numeros, como mucho un signo menos.
	//asi que podemos chequear todos los caracteres del string, si encontramos un - tiramos pero sino false
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it)) //no es un numero
		{
			if (*it == '-' && it == input.begin())
				continue;//es el signo de un integer negativo
			else
				return (false);//NO ES UN INTEGER
		}
	}
	std::cout << std::atol(input.c_str()) << std::endl;
	if (std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < INT_MIN) // checkear los limites de rango de los integers por si algun flipao intentar romperlo
		return (false);
	return (true);
}


bool checkDouble(std::string const &input) // second check
{
	//ya se que no es un integer porque contiene cosas que no son numeros mas alla de '-' en posicion 0
	//ahora solo puedo validar la excepcion anterior y otra mas, que en mitad de la sucesion de numeros contenga un '.' y nada mas.
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it)) //no es un numero
		{
			if ((*it == '-' && it == input.begin()) 
				continue;//es el signo de un integer negativo
			else if (*it == '.' && it != input.begin() && it != input.end() && input.find(it, input.end(), '.') != )
			else
				return (false);//NO ES UN INTEGER
		}
	}
	//no te puedes olvidar del check final sobre los limites de los doubles
}

/*bool checkFloat(std::string const &input) // third check
{
	
}*/

bool checkChar(std::string const &input) //last check
{
		if (input.size() > 1)
			return (false);
}



char parse_type(std::string const &input)
{
	if (input.empty())
		return('n');
	else if (checkInt(input))
		return ('i');
	else if (checkDouble(input))
		return ('d');
	/*else if (checkFloat(input))
		return ('f');*/
	else if (checkChar(input))
		return ('c');
	return ('n');
}


//Convertor funcs, with type set, just will print the specific conversion in every funcs depending on the type

/*void toChar(std::string const &input, char type)
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
}*/

void ScalarConverter::convert(std::string const &input)
{
	char type = parse_type(input);
	std::cout << "el parser ha dado: " << type << std::endl;
	//no hay que parsear nada en esta parte, llamar a todos los conversores porque queremos ver el string casteado a los siguientes 4 tipos de datos
	//toChar(input, type);
	//toInt(input), type;
	//toFloat(input, type);
	//toDouble(input, type);
}


/*Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan*/
