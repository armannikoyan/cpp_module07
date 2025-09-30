/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:32:43 by anikoyan          #+#    #+#             */
/*   Updated: 2025/09/30 20:03:21 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
void iter(T* address, const size_t len, void (*f)(T&))
{
  if (!address || len == 0)
    return;
  for (size_t i = 0; i < len; ++i)
    f(address[i]);
}

template <typename T>
void iter(T const * address, const size_t len, void (*f)(const T&))
{
  if (!address || len == 0)
    return;
  for (size_t i = 0; i < len; ++i)
    f(address[i]);
}
