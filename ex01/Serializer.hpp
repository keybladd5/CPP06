/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:39:47 by polmarti          #+#    #+#             */
/*   Updated: 2025/01/24 19:39:48 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct s_data 
{
	int nbr;
}	data_t;

class Serializer
{
	private:
			Serializer();
			Serializer(Serializer const &);
			Serializer &operator=(Serializer const &);
			~Serializer();
	public:
			static uintptr_t serialize(data_t *);
			static data_t *deserialize(uintptr_t);
};

#endif