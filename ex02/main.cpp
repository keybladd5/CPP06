/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:24:07 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/27 12:24:08 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::srand(std::time(0));
	{
		Base *ptr = new A();
		std::cout << "1️⃣  A test identify *: ";
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
	{
		Base *ptr = generate();
		std::cout << "1️⃣  random test identify *: ";
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
	{
		Base *ptr = new B();
		std::cout << "2️⃣  B test identify *: ";
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
	{
		std::cout << "2️⃣  random test indentify &: ";
		Base *ptr = generate();
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	{
		std::cout << "3️⃣  C test identify *: ";
		Base *ptr = new C();
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
	{
		std::cout << "3️⃣  random test identify *: ";
		Base *ptr = generate();
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
}
