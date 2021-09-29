/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:39:48 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/29 18:06:11 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "map_class.hpp"

namespace ft
{
    //iterator
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator() : Bidirect<T>()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(T *src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(iterator const& src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(const Bidirect<value_type>& src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::~iterator()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator& map< Key, T, Compare, Alloc >::iterator::operator++()
    {
        return Bidirect<T>::operator++();
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::iterator::operator++(int)
    {
        return Bidirect<T>::operator++(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator& map< Key, T, Compare, Alloc >::iterator::operator--()
    {
        return Bidirect<T>::operator--();
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::iterator::operator--(int)
    {
        return Bidirect<T>::operator--(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::reference map< Key, T, Compare, Alloc >::iterator::operator*() const
    {
        return *(this->_val);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::pointer map< Key, T, Compare, Alloc >::iterator::operator->() const
    {
        return this->_val;
    }

    //const_iterator
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator() : Bidirect<T>()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(T *src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(iterator const& src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(const Bidirect<value_type>& src) : Bidirect<T>(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::~const_iterator()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator& map< Key, T, Compare, Alloc >::const_iterator::operator++()
    {
        return Bidirect<T>::operator++();
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::const_iterator::operator++(int)
    {
        return Bidirect<T>::operator++(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator& map< Key, T, Compare, Alloc >::const_iterator::operator--()
    {
        return Bidirect<T>::operator--();
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::const_iterator::operator--(int)
    {
        return Bidirect<T>::operator--(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::reference map< Key, T, Compare, Alloc >::const_iterator::operator*() const
    {
        return *(this->_val);
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::pointer map< Key, T, Compare, Alloc >::const_iterator::operator->() const
    {
        return this->_val;
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::map(const key_compare& comp, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL)
    {
    }

    /*template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    map< Key, T, Compare, Alloc >::map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL)
    {
    }*/

}

#endif