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
    template <class T, typename Node >
    MapIter<T, Node >::MapIter() : _node(NULL)
    {
    }

    template <class T, typename Node >
    MapIter<T, Node >::MapIter(MapIter const& src)
    {
        *this = src;
    }

    template <class T, typename Node >
    MapIter<T, Node >::MapIter(Node *src)
    {
        _node = src;
    }


    template <class T, typename Node >
    MapIter<T, Node >::~MapIter()
    {
    }

    template <class T, typename Node >
    MapIter<T, Node >& MapIter<T, Node>::operator=(MapIter const& rhs)
    {
        if (this != &rhs)
            _node = rhs._node;
        return *this; 
    }

    template <class T, typename Node >
    bool MapIter<T, Node >::operator==(MapIter const& rhs)
    {
            return _node == rhs._node;
    }

    template < class T, typename Node >
    bool MapIter<T, Node >::operator!=(MapIter const& rhs)
    {
        return _node != rhs._node;
    }

    template < class T, typename Node>
    MapIter<T, Node> &MapIter<T, Node>::operator++()
    {
        if (_node->right)
            _node = min_node(_node->right);
        else if (_node->parent)
        {
            Node  *tmp = _node;
            _node = _node->parent;
            while (_node && tmp == _node->right)
            {
                tmp = _node;
                _node = _node->parent;        
            }
        }
        return *this;
    }

    template < class T, typename Node >
    MapIter<T, Node> MapIter<T, Node>::operator++(int)
    {
        MapIter<T, Node> tmp(*this);
        operator++();
        return tmp;
    }

    template < class T, typename Node >
    MapIter<T, Node >& MapIter<T, Node>::operator--()
    {
        if (_node->left)
            _node = max_node(_node->left);
        else if (_node->parent)
        {
            Node  *tmp = _node;
            _node = _node->parent;
            while (_node && tmp == _node->left)
            {
                tmp = _node;
                _node = _node->parent;        
            }
        }
        return *this;
    }

    template < class T, typename Node >
    MapIter<T, Node > MapIter<T, Node>::operator--(int)
    {
        MapIter<T, Node> tmp(*this);
        operator--();
        return tmp;
    }

    template < class T, typename Node >
    typename MapIter<T, Node>::reference MapIter<T, Node>::operator*() const
    {
        return _node->data;
    }

    template < class T, typename Node >
    typename MapIter<T, Node >::pointer MapIter<T, Node>::operator->() const
    {
        return &this->_node->data;
    }
}

#endif
