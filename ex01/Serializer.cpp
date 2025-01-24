/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:39:36 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/24 19:39:41 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src)
{
	(void)src;
}

Serializer &Serializer::operator=(Serializer const &src) 
{
	(void)src;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(data_t *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

data_t *Serializer::deserialize(uintptr_t var) { return (reinterpret_cast<data_t*>(var)); }