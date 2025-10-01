/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:12 by anikoyan          #+#    #+#             */
/*   Updated: 2025/10/01 16:48:56 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Array.hpp"

void test_default_constructor()
{
    std::cout << "=== Testing Default Constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    Array<double> empty_double;
    std::cout << "Empty double array size: " << empty_double.size() << std::endl;
    std::cout << std::endl;
}

void test_parameterized_constructor()
{
    std::cout << "=== Testing Parameterized Constructor ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    
    Array<char> char_arr(10);
    std::cout << "Char array size: " << char_arr.size() << std::endl;
    std::cout << std::endl;
}

void test_copy_constructor()
{
    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    Array<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    Array<int> copy(original);
    std::cout << "Original size: " << original.size() << ", Copy size: " << copy.size() << std::endl;
    
    original[0] = 100;
    std::cout << "After modifying original[0] to 100:" << std::endl;
    std::cout << "Original[0]: " << original[0] << ", Copy[0]: " << copy[0] << std::endl;
    std::cout << std::endl;
}

void test_assignment_operator()
{
    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    Array<int> first(3);
    first[0] = 10;
    first[1] = 20;
    first[2] = 30;
    
    Array<int> second(2);
    second = first;
    
    std::cout << "First size: " << first.size() << ", Second size: " << second.size() << std::endl;
    
    first[1] = 200;
    std::cout << "After modifying first[1] to 200:" << std::endl;
    std::cout << "First[1]: " << first[1] << ", Second[1]: " << second[1] << std::endl;
    
    first = first;
    std::cout << "After self-assignment, first[0]: " << first[0] << std::endl;
    std::cout << std::endl;
}

void test_element_access()
{
    std::cout << "=== Testing Element Access ===" << std::endl;
    Array<int> arr(4);
    
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i * 10);
    
    std::cout << "Array elements: ";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    Array<double> double_arr(3);
    double_arr[0] = 1.1;
    double_arr[1] = 2.2;
    double_arr[2] = 3.3;
    
    std::cout << "Double array: ";
    for (size_t i = 0; i < double_arr.size(); ++i)
        std::cout << double_arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_out_of_bounds()
{
    std::cout << "=== Testing Out of Bounds Access ===" << std::endl;
    Array<int> arr(3);
    
    try {
        std::cout << "Trying to access index 5..." << std::endl;
        int value = arr[5];
        std::cout << "Unexpected success: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Trying to access index -1..." << std::endl;
        int value = arr[-1];
        std::cout << "Unexpected success: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    Array<int> empty;
    try {
        std::cout << "Trying to access empty array..." << std::endl;
        int value = empty[0];
        std::cout << "Unexpected success: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void test_zero_size_array()
{
    std::cout << "=== Testing Zero Size Array ===" << std::endl;
    Array<int> arr(0);
    std::cout << "Zero-sized array size: " << arr.size() << std::endl;
    
    try {
        std::cout << "Trying to access zero-sized array..." << std::endl;
        int value = arr[0];
        std::cout << "Unexpected success: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void test_different_data_types()
{
    std::cout << "=== Testing Different Data Types ===" << std::endl;
    
    Array<char> char_arr(5);
    for (size_t i = 0; i < char_arr.size(); ++i)
        char_arr[i] = 'A' + static_cast<char>(i);
    std::cout << "Char array: ";
    for (size_t i = 0; i < char_arr.size(); ++i)
        std::cout << char_arr[i] << " ";
    std::cout << std::endl;
    
    Array<float> float_arr(3);
    float_arr[0] = 1.5f;
    float_arr[1] = 2.5f;
    float_arr[2] = 3.5f;
    std::cout << "Float array: ";
    for (size_t i = 0; i < float_arr.size(); ++i)
        std::cout << float_arr[i] << " ";
    std::cout << std::endl;
    
    Array<bool> bool_arr(4);
    for (size_t i = 0; i < bool_arr.size(); ++i)
        bool_arr[i] = (i % 2 == 0);
    std::cout << "Bool array: ";
    for (size_t i = 0; i < bool_arr.size(); ++i)
        std::cout << (bool_arr[i] ? "true" : "false") << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_modification_through_index()
{
    std::cout << "=== Testing Modification Through Index ===" << std::endl;
    Array<int> arr(4);
    
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i);
    
    std::cout << "Before modification: ";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    arr[0] = 100;
    arr[2] = 300;
    
    std::cout << "After modification: ";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_large_array()
{
    std::cout << "=== Testing Large Array ===" << std::endl;
    const size_t large_size = 1000;
    Array<int> large_arr(large_size);
    
    for (size_t i = 0; i < large_arr.size(); ++i)
        large_arr[i] = static_cast<int>(i * 2);
    
    std::cout << "Large array size: " << large_arr.size() << std::endl;
    std::cout << "First element: " << large_arr[0] << std::endl;
    std::cout << "Middle element: " << large_arr[large_size / 2] << std::endl;
    std::cout << "Last element: " << large_arr[large_size - 1] << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << "Starting Array class tests..." << std::endl;
    std::cout << "===============================" << std::endl;
    
    test_default_constructor();
    test_parameterized_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_element_access();
    test_out_of_bounds();
    test_zero_size_array();
    test_different_data_types();
    test_modification_through_index();
    test_large_array();
    
    std::cout << "All tests completed!" << std::endl;
    
    return 0;
}
