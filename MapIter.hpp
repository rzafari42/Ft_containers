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
    MapIter<T, node >::MapIter() : _node(NULL)
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
            _node = rhs._node;
        return *this; 
    }

    template <class T, typename node >
    bool MapIter<T, node >::operator==(MapIter const& rhs)
    {
            return _node == rhs._node;
    }

    template < class T, typename node >
    bool MapIter<T, node >::operator!=(MapIter const& rhs)
    {
        return _node != rhs._node;
    }

    template < class T, typename node>
    MapIter<T, node> &MapIter<T, node>::operator++()
    {
        if (_node->right)
            _node = min_node(_node->right);
        else if (_node->parent)
        {
            node  *tmp = _node;
    
            _node = _node->parent;
            while (_node && tmp = _node->right)
            {
                tmp = _node;
                _node = _node->parents;        
            }
        }
        return *this;
    }

    template < class T, typename node >
    MapIter<T, node> MapIter<T, node>::operator++(int)
    {
        MapIter<T, node> tmp(*this);
        operator++();
        return tmp;
    }

    template < class T, typename node >
    MapIter<T, node >& MapIter<T, node>::operator--()
    {
        if (_node->left)
            _node = max_node(_node->right);
        else if (_node->parent)
        {
            node  *tmp = _node;
    
            _node = _node->parent;
            while (_node && tmp = _node->left)
            {
                tmp = _node;
                _node = _node->parents;        
            }
        }
        return *this;
    }

    template < class T, typename node >
    MapIter<T, node > MapIter<T, node>::operator--(int)
    {
        MapIter<T, node> tmp(*this);
        operator--();
        return tmp;
    }

    template < class T, typename node >
    MapIter<T, node>::reference MapIter<T, node>::operator*() const
    {
        return _node->key;
    }

    template < class T, typename node >
    MapIter<T, node >::pointer MapIter<T, node>::operator->() const
    {
        return &_node->key;
    }
}

#endif
