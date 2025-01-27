/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:34:06 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/27 10:34:08 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	data_t *x = new data_t;
	x->nbr = 42;
	uintptr_t y = Serializer::serialize(x);
	std::cout << "x value is: " << x->nbr << " and y value is: " << y << std::endl;
	data_t *j = Serializer::deserialize(y);
	std::cout << "j value is: " << j->nbr << " and y value is: " << y << std::endl;
	delete x;
	return (0);
}
