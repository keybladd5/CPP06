/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:57:39 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/27 10:57:41 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base destructor called." << std::endl;
}
// This function allocates memory dynamically (using `new`) and returns a Base* pointer. 
// The pointer randomly points to an instance of one of the derived classes: A, B, or C.
Base * generate(void)
{
	Base *ptr = NULL;
	int tmp = std::rand() % 3;
	if (tmp == 0)
		ptr = new A();
	else if (tmp == 1)
		ptr = new B();
	else
		ptr = new C();
	return (ptr);
}

// This function identifies the actual type of the dynamically allocated instance.
// It uses `dynamic_cast` to attempt converting the `Base*` pointer to `A*`, `B*`, or `C*`.
// If the cast fails, `dynamic_cast` sets the result to `nullptr`, allowing type detection.
void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "The actual type of the object pointed by ptr is 🅰️\n";
	else if (b)
		std::cout << "The actual type of the object pointed by ptr is 🅱️\n";
	else if (c)
		std::cout << "The actual type of the object pointed by ptr is 🇨\n";
}

// This function identifies the actual type of a dynamically allocated instance passed by reference.
// It uses `dynamic_cast` to check if the reference can be converted to `A&`, `B&`, or `C&`.
// If the cast fails, a `std::bad_cast` exception is thrown and caught, allowing type detection.
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The actual type of the object pointed by ptr is 🅰️\n";
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "The actual type of the object pointed by ptr is 🅱️\n";
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "The actual type of the object pointed by ptr is 🇨\n";
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}
