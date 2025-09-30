/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:43:41 by anikoyan          #+#    #+#             */
/*   Updated: 2025/09/30 20:05:56 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <cstring>

#include "iter.hpp"

void increment_int(int& n)
{
    n += 1;
}

void double_value(double& d)
{
    d *= 2.0;
}

void to_uppercase_char(char& c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void print_int(const int& n)
{
    std::cout << n << " ";
}

void print_double(const double& d)
{
    std::cout << d << " ";
}

void print_char(const char& c)
{
    std::cout << c << " ";
}

void counting_const(const int& n)
{
    std::cout << n << " ";
}

int non_const_call_count = 0;

void counting_non_const(int& n)
{
    non_const_call_count++;
    n *= 2;
}

void test_basic_functionality()
{
    std::cout << "Testing basic functionality...\n";
    
    int int_arr[] = {1, 2, 3, 4, 5};
    iter(int_arr, 5, increment_int);
    assert(int_arr[0] == 2);
    assert(int_arr[1] == 3);
    assert(int_arr[4] == 6);
    
    double double_arr[] = {1.5, 2.5, 3.5};
    iter(double_arr, 3, double_value);
    assert(double_arr[0] == 3.0);
    assert(double_arr[1] == 5.0);
    assert(double_arr[2] == 7.0);
    
    char char_arr[] = {'h', 'e', 'l', 'l', 'o'};
    iter(char_arr, 5, to_uppercase_char);
    assert(char_arr[0] == 'H');
    assert(char_arr[1] == 'E');
    assert(char_arr[4] == 'O');
    
    std::cout << "Basic functionality tests passed.\n";
}

void test_const_overload()
{
    std::cout << "Testing const overload...\n";
    
    const int const_int_arr[] = {10, 20, 30};
    std::cout << "Const int array: ";
    iter(const_int_arr, 3, print_int);
    std::cout << "\n";
    
    const double const_double_arr[] = {1.1, 2.2, 3.3};
    std::cout << "Const double array: ";
    iter(const_double_arr, 3, print_double);
    std::cout << "\n";
    
    const char const_char_arr[] = {'A', 'B', 'C'};
    std::cout << "Const char array: ";
    iter(const_char_arr, 3, print_char);
    std::cout << "\n";
    
    std::cout << "Const overload tests passed.\n";
}

void test_edge_cases()
{
    std::cout << "Testing edge cases...\n";
    
    int empty_arr[] = {1};
    iter(empty_arr, 0, increment_int);
    assert(empty_arr[0] == 1);
    
    int single_arr[] = {42};
    iter(single_arr, 1, increment_int);
    assert(single_arr[0] == 43);
    
    int* null_ptr = NULL;
    iter(null_ptr, 5, increment_int);
    
    std::cout << "Edge cases tests passed.\n";
}

void test_function_call_counts()
{
    std::cout << "Testing function call counts...\n";
    
    non_const_call_count = 0;
    
    int test_arr[] = {1, 2, 3, 4};
    iter(test_arr, 4, counting_non_const);
    assert(non_const_call_count == 4);
    assert(test_arr[0] == 2);
    assert(test_arr[1] == 4);
    assert(test_arr[2] == 6);
    assert(test_arr[3] == 8);
    
    const int const_test_arr[] = {1, 2, 3};
    std::cout << "Counting const: ";
    iter(const_test_arr, 3, counting_const);
    std::cout << "\n";
    
    std::cout << "Function call count tests passed.\n";
}

void test_mixed_usage()
{
    std::cout << "Testing mixed usage...\n";
    
    int numbers[] = {100, 200, 300};
    
    std::cout << "Before: ";
    const int* const_numbers = numbers;
    iter(const_numbers, 3, print_int);
    std::cout << "\n";
    
    iter(numbers, 3, increment_int);
    
    std::cout << "After: ";
    iter(const_numbers, 3, print_int);
    std::cout << "\n";
    
    assert(numbers[0] == 101);
    assert(numbers[1] == 201);
    assert(numbers[2] == 301);
    
    std::cout << "Mixed usage tests passed.\n";
}

void test_large_array()
{
    std::cout << "Testing large array...\n";
    
    const int SIZE = 100;
    int large_arr[SIZE];
    
    for (int i = 0; i < SIZE; ++i) {
        large_arr[i] = i;
    }
    
    iter(large_arr, SIZE, increment_int);
    
    for (int i = 0; i < SIZE; ++i) {
        assert(large_arr[i] == i + 1);
    }
    
    std::cout << "Large array test passed.\n";
}

int main()
{
    test_basic_functionality();
    test_const_overload();
    test_edge_cases();
    test_function_call_counts();
    test_mixed_usage();
    test_large_array();
    
    std::cout << "\nAll iter tests passed successfully!\n";
    return 0;
}
