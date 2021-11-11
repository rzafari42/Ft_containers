/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:49:40 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/11 19:56:40 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp" 

#ifndef NAMESPACE
    #define NAMESPACE ft
#endif

template<class T>
void print_elem_vector(NAMESPACE::vector<T> vt)
{
    typename NAMESPACE::vector<T>::iterator it = vt.begin();
    typename NAMESPACE::vector<T>::iterator ite = vt.end();

    typename NAMESPACE::vector<T>::const_iterator ct_it = vt.begin();
    typename NAMESPACE::vector<T>::const_iterator ct_ite = vt.end();

    typename NAMESPACE::vector<T>::reverse_iterator rev_it = vt.rbegin();
    typename NAMESPACE::vector<T>::reverse_iterator rev_ite = vt.rend();

    typename NAMESPACE::vector<T>::const_reverse_iterator crev_it = vt.rbegin();
    typename NAMESPACE::vector<T>::const_reverse_iterator crev_ite = vt.rend();
    
    std::cout << "Elem (iterator):               ";
    while(it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
    std::cout << "Elem (const_iterator):         ";
    while(ct_it != ct_ite)
    {
        std::cout << *ct_it << " ";
        ct_it++;
    }
    std::cout << "\n";
    std::cout << "Elem (reverse_iterator):       ";
    while(rev_it != rev_ite)
    {
        std::cout << *rev_it << " ";
        rev_it++;
    }
    std::cout << "\n";
    std::cout << "Elem (const_reverse_iterator): ";
    while(crev_it != crev_ite)
    {
        std::cout << *crev_it << " ";
        crev_it++;
    }
    std::cout << "\n";
    std::cout << "Front:       " << vt.front() << std::endl;
    std::cout << "Back:        " << vt.back() << std::endl;
    if (!vt.empty())
    {
        std::cout << "AT[4]:       " << vt.at(4) << std::endl;
        std::cout << "operator[4]: " << vt[4] << std::endl;
    }
    std::cout << "\n";
}

template<class T>
void print_size_vector(NAMESPACE::vector<T> vt)
{
    std::cout << "Empty:    " << vt.empty() << std::endl;
    std::cout << "Size:     " << vt.size() << std::endl;
    std::cout << "Max_Size: " << vt.max_size() << std::endl;
    std::cout << "Capacity: " << vt.capacity() << std::endl;
    std::cout << "\n";
}

void vector(void)
{
    std::cout << "#######" << std::endl;
    std::cout << "VECTOR" << std::endl;
    std::cout << "#######" << std::endl;

    std::cout << "Constructors\n\n";
    
    NAMESPACE::vector<int> vt_empty;
    NAMESPACE::vector<int> vt_default;
    NAMESPACE::vector<int> vt_fill(10, 42);
    NAMESPACE::vector<int> vt_range(vt_fill.begin(), vt_fill.end());
    NAMESPACE::vector<int> vt_cpy(vt_range);
    NAMESPACE::vector<int> vt_equal_op = vt_cpy;

    std::cout << "### vt_empty ###" << std::endl;
    print_elem_vector(vt_empty);
    print_size_vector(vt_empty);
    std::cout << "#################" << std::endl;

    std::cout << "### vt_fill ###" << std::endl;
    print_elem_vector(vt_fill);
    print_size_vector(vt_fill);
    std::cout << "#################" << std::endl;

    std::cout << "### vt_range ###" << std::endl;
    print_elem_vector(vt_range);
    print_size_vector(vt_range);
    std::cout << "#################" << std::endl;

    std::cout << "### vt_cpy ###" << std::endl;
    print_elem_vector(vt_cpy);
    print_size_vector(vt_cpy);
    std::cout << "#################" << std::endl;

    std::cout << "### operator= ###" << std::endl;
    print_elem_vector(vt_equal_op);
    print_size_vector(vt_equal_op);
    std::cout << "################" << std::endl;

    std::cout << "### vt_default ###" << std::endl;
    std::cout << "Let's try the 'insert' function !\n" << std::endl;
    for (int i = 0; i < 10; i++)
        vt_default.insert(vt_default.begin(), i * 3);    
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'push_back' function !\n" << std::endl;
    vt_default.push_back(124);
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'pop_back' function !\n" << std::endl;
    vt_default.pop_back();
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'erase' function !\n" << std::endl;
    NAMESPACE::vector<int>::iterator it = ++(++(vt_default.begin()));
    vt_default.erase(it);
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'assign(n, val)' function !\n" << std::endl;
    vt_default.assign(5, 21);
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'clear' function !\n" << std::endl;
    vt_default.clear();
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'assign(first, last)' function !\n" << std::endl;
    it = vt_default.begin();
    vt_default.assign(it, it + 15);
    print_elem_vector(vt_default);
    print_size_vector(vt_default);

    std::cout << "Let's try the 'insert(position, first, last)' function ! (We need to clear before)\n" << std::endl;
    int val[] = {1,2,3,4};
    it = vt_default.begin();
    vt_default.insert(it+3, val, val+4);
    print_elem_vector(vt_default);
    print_size_vector(vt_default);
    std::cout << "################" << std::endl;
    
    std::cout << "### SWAP ###" << std::endl;
    std::cout << "Let's swap between vt_default and vt_fill" << std::endl;
    vt_default.swap(vt_fill);
    std::cout << "New vt_default" << std::endl;
    print_elem_vector(vt_default);
    print_size_vector(vt_default);
    std::cout << "New vt_fill" << std::endl;
    print_elem_vector(vt_fill);
    print_size_vector(vt_fill);

    std::cout << "### Relational Operators ###" << std::endl;
    std::cout << "### EQUAL ### " << std::endl;
    std::cout << "vt_cpy == vt_equal_op ? " << (vt_cpy == vt_equal_op) << std::endl;
    std::cout << "### DIFFERENT ###" << std::endl;
    std::cout << "vt_cpy != vt_equal_op ? " << (vt_cpy != vt_equal_op) << std::endl;
    std::cout << "vt_cpy != vt_fill ? " << (vt_cpy != vt_fill) << std::endl;
    std::cout << "### GREATER ###" << std::endl;
    std::cout << "vt_cpy > vt_equal_op ? " << (vt_cpy > vt_equal_op) << std::endl;
    std::cout << "vt_cpy > vt_fill ? " << (vt_cpy > vt_fill) << std::endl;
    std::cout << "### GREATER OR EQUAL ###" << std::endl;
    std::cout << "vt_cpy >= vt_equal_op ? " << (vt_cpy >= vt_equal_op) << std::endl;
    std::cout << "vt_cpy >= vt_fill ? " << (vt_cpy >= vt_fill) << std::endl;
    std::cout << "### LOWER ###" << std::endl;
    std::cout << "vt_cpy < vt_equal_op ? " << (vt_cpy < vt_equal_op) << std::endl;
    std::cout << "vt_cpy < vt_fill ? " << (vt_cpy < vt_fill) << std::endl;
    std::cout << "### LOWER OR EQUAL ###" << std::endl;
    std::cout << "vt_cpy <= vt_equal_op ? " << (vt_cpy <= vt_equal_op) << std::endl;
    std::cout << "vt_cpy <= vt_fill ? " << (vt_cpy <= vt_fill) << std::endl;
}   

template<class T>
void print_size_stack(NAMESPACE::stack<T> st)
{
    std::cout << "Empty:    " << st.empty() << std::endl;
    std::cout << "Size:     " << st.size() << std::endl;
    std::cout << "\n";
}

void stack(void)
{
    std::cout << "#######" << std::endl;
    std::cout << "STACK" << std::endl;
    std::cout << "#######" << std::endl;

    std::cout << "Constructors\n\n";
    
    NAMESPACE::stack<int> st;
    NAMESPACE::stack<int> st2;

    std::cout << "### st ###" << std::endl;
    std::cout << "Let's try the 'push' function ! (10 elem. insertion)" << std::endl;
    for (int i = 0; i < 10; i++)
        st.push(i * 2);
    print_size_stack(st);
    std::cout << "Let's try the 'top' function ! (should be 18)" << std::endl;
    std::cout << "TOP : " << st.top() << std::endl;
    std::cout << "Let's try the 'pop' function !" << std::endl;
    st.pop();
    std::cout << "Last element should now be 16. Let's check it !" << std::endl;
    std::cout << "TOP : " << st.top() << std::endl;

    std::cout << "### Relational Operators ###" << std::endl;
    std::cout << "Filling another stack container ...." << std::endl;
    for (int i = 0; i < 10; i++)
        st2.push(i * 9);
    std::cout << "st2 top element is: " << st2.top()  << std::endl;
    std::cout << "### EQUAL ###" << std::endl;
    std::cout << "st == st2 ? " << (st == st2) << std::endl;
    std::cout << "### DIFFERENT ###" << std::endl;
    std::cout << "st != st2 ? " << (st != st2) << std::endl;
    std::cout << "### GREATER ###" << std::endl;
    std::cout << "st > st2 ? " << (st > st2) << std::endl;
    std::cout << "### GREATER OR EQUAL ###" << std::endl;
    std::cout << "st >= st2 ? " << (st > st2) << std::endl;
    std::cout << "### LOWER ###" << std::endl;
    std::cout << "st < st2 ? " << (st < st2) << std::endl;
    std::cout << "### LOWER OR EQUAL ###" << std::endl;
    std::cout << "st <= st2 ? " << (st <= st2) << std::endl;
}

template<class T1, class T2>
void print_elem_map(NAMESPACE::map<T1, T2> mp)
{
    typename NAMESPACE::map<T1, T2>::iterator it = mp.begin();
    typename NAMESPACE::map<T1, T2>::iterator ite = mp.end();

    typename NAMESPACE::map<T1, T2>::const_iterator ct_it = mp.begin();
    typename NAMESPACE::map<T1, T2>::const_iterator ct_ite = mp.end();

    typename NAMESPACE::map<T1, T2>::reverse_iterator rev_it = mp.rbegin();
    typename NAMESPACE::map<T1, T2>::reverse_iterator rev_ite = mp.rend();

    typename NAMESPACE::map<T1, T2>::const_reverse_iterator crev_it = mp.rbegin();
    typename NAMESPACE::map<T1, T2>::const_reverse_iterator crev_ite = mp.rend();
    
    std::cout << "Elem (iterator):               \n";
    while(it != ite)
    {
        std::cout << "fisrt: " << it->first << "| Second: " << it->second << "\n";
        it++;
    }
    std::cout << "Elem (const_iterator):         \n";
    while(ct_it != ct_ite)
    {
        std::cout << "fisrt: " << ct_it->first << "| Second: " << ct_it->second << "\n";
        ct_it++;
    }
    std::cout << "Elem (reverse_iterator):       \n";
    while(rev_it != rev_ite)
    {
        std::cout << "fisrt: " << rev_it->first << "| Second: " << rev_it->second << "\n";
        rev_it++;
    }
    std::cout << "Elem (const_reverse_iterator): \n";
    while(crev_it != crev_ite)
    {
        std::cout << "fisrt: " << crev_it->first << "| Second: " << crev_it->second << "\n";
        crev_it++;
    }
    if (!mp.empty())
        std::cout << "operator[4]: " << mp[4] << std::endl;
    std::cout << "\n";
}

template<class T1, class T2>
void print_size_map(NAMESPACE::map<T1, T2> mp)
{
    std::cout << "Empty:    " << mp.empty() << std::endl;
    std::cout << "Size:     " << mp.size() << std::endl;
    std::cout << "Max_Size: " << mp.max_size() << std::endl;
    std::cout << "\n";
}

void map(void)
{
    std::cout << "#######" << std::endl;
    std::cout << "map" << std::endl;
    std::cout << "#######" << std::endl;

    std::cout << "Constructors\n\n";
    
    std::cout << "Default:" << std::endl;
    NAMESPACE::map<int, int> mp;
    NAMESPACE::map<int, int> mp_;

    std::cout << "Let's try the insert(value_type) function" << std::endl;
    NAMESPACE::pair<int, int> foo;
    foo = NAMESPACE::make_pair(1,10);
    mp.insert(foo);
    foo = NAMESPACE::make_pair(2,15);
    mp.insert(foo);
    foo = NAMESPACE::make_pair(3,20);
    mp.insert(foo);
    foo = NAMESPACE::make_pair(4,25);
    mp.insert(foo);
    foo = NAMESPACE::make_pair(5,30);
    mp.insert(foo);
    print_elem_map(mp);
    print_size_map(mp);
    
    std::cout << "Let's try the insert(position, val) function" << std::endl;
    foo = NAMESPACE::make_pair(6,35);
    mp.insert(mp.begin(), foo);
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Let's try the insert(first, last) function. With an empty map instance of course !" << std::endl;
    mp_.insert(mp.begin(), mp.end());
    print_elem_map(mp_);
    print_size_map(mp_);

    std::cout << "Range:" << std::endl;
    NAMESPACE::map<int, int> mp_range(mp.begin(), (--(mp.end())));
    print_elem_map(mp_range);
    print_size_map(mp_range);

    std::cout << "Copy:" << std::endl;
    NAMESPACE::map<int, int> mp_cpy(mp);
    print_elem_map(mp_cpy);
    print_size_map(mp_cpy);

    std::cout << "Operator= :" << std::endl;
    NAMESPACE::map<int, int> mp_equal_op;
    mp_equal_op = mp;
    print_elem_map(mp_equal_op);
    print_size_map(mp_equal_op);

    std::cout << "Erase(position) :" << std::endl;
    mp.erase(++(++mp.begin()));
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Erase(key_type) :" << std::endl;
    mp.erase(5);
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Erase(first, last) :" << std::endl;
    mp.erase(mp.begin(), (++(++(++(mp.begin())))));
    print_elem_map(mp);
    print_size_map(mp);

    std::cout << "Swap:" << std::endl;
    mp.swap(mp_range);
    std::cout << "mp:" << std::endl;
    print_elem_map(mp);
    print_size_map(mp);
    std::cout << "mp_range:" << std::endl;
    print_elem_map(mp_range);
    print_size_map(mp_range);

    std::cout << "Clear:" << std::endl;
    mp.clear();
    std::cout << "mp:" << std::endl;
    print_elem_map(mp);
    print_size_map(mp);
}   

int main(void)
{
    vector();
    std::cout << "\n\n";
    stack();
    std::cout << "\n\n";
    map();
    
    return 0;
}
