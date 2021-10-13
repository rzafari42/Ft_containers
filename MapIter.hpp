/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:39 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/13 15:31:22 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITER_HPP
# define MAPITER_HPP
# include "MapIter_class.hpp"

namespace ft
{
    template <class T, typename node >
    MapIter<T, node >::MapIter() : _val(NULL)
    {
    }

    template <class T, typename node >
    MapIter<T, node >::MapIter(MapIter const& src)
    {
        *this = src;
    }

    template <class T, typename node >
    MapIter<T, node >::~MapIter()
    {
    }

    template <class T, typename node >
    MapIter<T, node >& MapIter<T, node>::operator=(MapIter const& rhs)
    {
        if (this != &rhs)
            _val = rhs._val;
        return *this; 
    }

    template <class T, typename node >
    bool MapIter<T, node >::operator==(MapIter const& rhs)
    {
            return _val == rhs._val;
    }

    template < class T, typename node >
    bool MapIter<T, node >::operator!=(MapIter const& rhs)
    {
        return _val != rhs._val;
    }

    template < class T, typename node >
    MapIter<T, node> &MapIter<T, node>::operator++()
    {
        _val++;
        return *this;
    }

    template < class T, typename node >
    MapIter<T, node> MapIter<T, node>::operator++(int)
    {
        MapIter<T> tmp(*this);
        tmp = _val;
        _val++;
        return tmp;
    }

    template < class T, typename node >
    MapIter<T, node >& MapIter<T, node>::operator--()
    {
        _val--;
        return *this;
    }

    template < class T, typename node >
    MapIter<T, node > MapIter<T, node>::operator--(int)
    {
        MapIter<T> tmp(*this);
        tmp = _val;
        _val--;
        return tmp;
    }

    template < class T, typename node >
    MapIter<T, node>::reference MapIter<T, node>::operator*() const
    {
        return *_val;
    }

    template < class T, typename node >
    MapIter<T, node >::pointer MapIter<T, node>::operator->() const
    {
        return _val;
    }
}

#endif
