/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:55:41 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/03 20:45:17 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>

namespace ft
{
    template <bool, class _Tp = void>
    struct enable_if {};
    
    template <class _Tp>
    struct enable_if<true, _Tp>  {typedef _Tp type;};

    template <class InputIterator>
    size_t InputIterator_len(InputIterator first, InputIterator last)
    {
        size_t i = 0;
        for(; first != last; first++)
            i++;
        return i;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1)
                return false;
            else if (*first1<*first2)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template<class T>
    struct Node
    {
        T       val;
        Node    *right;
        Node    *left;
        Node    *parent;
    };

    template < class T1, class T2 >
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type  first;
        second_type second;

        pair() : first(), second() { return ;};
        template<class U, class V>
            pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {return;};
        pair (const first_type& a, const second_type& b) : first(a), second(b) { return; };

        pair& operator= (const pair& pr) {first = pr.first; second = pr.second; return *this };
    };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first = rhs.first && lhs.second = rhs.second)}

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first != rhs.first && lhs.second != rhs.second)};

    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first < rhs.second && lhs.second < rhs.second)};

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first <= rhs.second && lhs.second <= rhs.second)};

    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first > rhs.second && lhs.second > rhs.second)};

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first >= rhs.second && lhs.second >= rhs.second)};
}

#endif