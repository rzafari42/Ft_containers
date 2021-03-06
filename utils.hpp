/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 23:55:41 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/13 10:22:09 by rzafari          ###   ########.fr       */
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

    template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

     ////////////////////////
    //        NODE       //
    ///////////////////////
    template<class T>
    struct Node
    {
        private:
            bool empty;
        public:
            T       data;
            Node    *right;
            Node    *left;
            Node    *parent;
    };

    template< class T >
    Node<T>* min_node(Node<T>* node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    template< class T >
    Node<T>* max_node(Node<T>* node)
    {
        while (node && node->right != NULL)
            node = node->right;
        return node;
    }

    template <typename T>
    void	printPairs(const T &iterator)
    {
        std::cout << "key: " << iterator->first << " | value: " << iterator->second << std::endl;
    }
}

#endif