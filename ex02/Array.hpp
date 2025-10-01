/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:19 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:00 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

template <typename T>
class Array
{
  private:
    T* _array;
    size_t _size;

  public:
    Array();
    ~Array();
    Array(const Array& other);
    const Array& operator=(const Array& other);

    Array(const unsigned int& n);

    T& operator[](const size_t& location);
    const T& operator[](const size_t& location) const;

    const size_t& size() const;
};

# include "Array.tpp"

#endif
