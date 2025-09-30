/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:19:09 by anikoyan          #+#    #+#             */
/*   Updated: 2025/09/30 19:23:57 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b)
{
  T c = a;
  a = b;
  b = c;
}

template <typename T>
T& min(T& a, T&b)
{
  return a < b ? a : b;
}

template <typename T>
T& max(T& a, T& b)
{
  return a > b ? a : b;
}
