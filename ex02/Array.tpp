/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:23 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:16 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array()
  : _array(NULL)
  , _size(0)
{
}

template <typename T>
Array<T>::~Array()
{
  delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& other)
  : _array(new T[other._size])
  , _size(other._size)
{
  for (size_t i = 0; i < _size; ++i)
    _array[i] = other._array[i];
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array& other)
{
  if (this == &other)
    return *this;

  if (_size != other._size)
  {
    delete[] _array;
    _array = new T[other._size];
  }

  for (size_t i = 0; i < _size; ++i)
    _array[i] = other._array[i];
  return *this;
}

template <typename T>
Array<T>::Array(const unsigned int& n)
  : _array(new T[n])
  , _size(n)
{
}

template <typename T>
T& Array<T>::operator[](const size_t& location)
{
  if (location >= _size)
    throw std::out_of_range("Out of the bounds\n");

  return _array[location];
}

template <typename T>
const T& Array<T>::operator[](const size_t& location) const
{
  if (location >= _size)
    throw std::out_of_range("Out of the bounds\n");

  return _array[location];
}

template <typename T>
const size_t& Array<T>::size() const
{
  return _size;
}

#endif
