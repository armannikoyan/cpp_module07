/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:23:22 by anikoyan          #+#    #+#             */
/*   Updated: 2025/09/30 19:28:29 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <string>

#include "whatever.hpp"

void test_swap()
{
  std::cout << "Testing swap...\n";

  int a = 5, b = 10;
  swap(a, b);
  assert(a == 10);
  assert(b == 5);

  double x = 1.5, y = 3.14;
  swap(x, y);
  assert(x == 3.14);
  assert(y == 1.5);

  std::string s1 = "hello", s2 = "world";
  swap(s1, s2);
  assert(s1 == "world");
  assert(s2 == "hello");

  std::cout << "All swap tests passed.\n";
}

void test_min()
{
  std::cout << "Testing min...\n";

  int a = 5, b = 10;
  assert(&min(a, b) == &a);
  assert(min(a, b) == 5);

  int c = 10, d = 10;
  assert(&min(c, d) == &d);

  double x = 2.5, y = 2.4;
  assert(min(x, y) == 2.4);

  double m = 3.0, n = 3.0;
  assert(&min(m, n) == &n);

  std::string s1 = "apple", s2 = "banana";
  assert(min(s1, s2) == "apple");

  std::string s3 = "same", s4 = "same";
  assert(&min(s3, s4) == &s4);

  std::cout << "All min tests passed.\n";
}

void test_max()
{
  std::cout << "Testing max...\n";

  int a = 5, b = 10;
  assert(&max(a, b) == &b);
  assert(max(a, b) == 10);

  int c = 10, d = 10;
  assert(&max(c, d) == &d);

  double x = 2.5, y = 2.4;
  assert(max(x, y) == 2.5);

  double m = 3.0, n = 3.0;
  assert(&max(m, n) == &n);

  std::string s1 = "apple", s2 = "banana";
  assert(max(s1, s2) == "banana");

  std::string s3 = "same", s4 = "same";
  assert(&max(s3, s4) == &s4);

  std::cout << "All max tests passed.\n";
}

void test_edge_cases()
{
  std::cout << "Testing edge cases...\n";

  int x = 100, y = -50;
  swap(x, y);
  assert(x == -50);
  assert(y == 100);

  int zero = 0, one = 1;
  assert(min(zero, one) == 0);
  assert(max(zero, one) == 1);

  int same1 = 42, same2 = 42;
  swap(same1, same2);
  assert(same1 == 42);
  assert(same2 == 42);

  assert(&min(same1, same2) == &same2);
  assert(&max(same1, same2) == &same2);

  std::cout << "Edge cases tests passed.\n";
}

int main()
{
  test_swap();
  test_min();
  test_max();
  test_edge_cases();

  std::cout << "\nAll tests passed successfully!\n";
  return 0;
}
