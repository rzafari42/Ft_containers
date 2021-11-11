/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:49:40 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/11 13:47:23 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "vector_class.hpp"
#include "stack_class.hpp"
#include "map_class.hpp" 

#ifndef NAMESPACE
    #define NAMESPACE ft
#endif

template<class T>
void print_elem_vector(NAMESPACE::vector<T> vt)
{
    typename NAMESPACE::vector<T>::iterator it = vt.begin();
    typename NAMESPACE::vector<T>::iterator ite = vt.end();

    std::cout << "Elemn:    ";
    while(it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}

template<class T>
void print_size_vector(NAMESPACE::vector<T> vt)
{
    std::cout << "Empty:    " << vt.empty() << std::endl;
    std::cout << "Size:     " << vt.size() << std::endl;
    std::cout << "Max_Size: " << vt.max_size() << std::endl;
    std::cout << "\n";
}

void vector(void)
{
    std::cout << "#######" << std::endl;
    std::cout << "VECTOR" << std::endl;
    std::cout << "#######" << std::endl;

    std::cout << "Constructors\n\n";
    
    NAMESPACE::vector<int> vt_fill(10, 42);
    NAMESPACE::vector<int> vt_range(vt_fill.begin(), vt_fill.end());
    NAMESPACE::vector<int> vt_cpy(vt_range);
    NAMESPACE::vector<int> vt_equal_op = vt_cpy;

    std::cout << "### vt_fill ###" << std::endl;
    print_elem_vector(vt_fill);
    print_size_vector(vt_fill);
    std::cout << "### vt_range ###" << std::endl;
    print_elem_vector(vt_range);
    print_size_vector(vt_range);
    std::cout << "### vt_cpy ###" << std::endl;
    print_elem_vector(vt_cpy);
    print_size_vector(vt_cpy);
    std::cout << "### operator= ###" << std::endl;
    print_elem_vector(vt_equal_op);


}

void stack(void)
{

}

void map(void)
{

}

int main(void)
{
    vector();
    /* stack();
    map(); */
    
    return 0;
}
