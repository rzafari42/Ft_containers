/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/10 17:16:44 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITER_HPP
# define MAPITER_HPP
# include "utils.hpp"
# include "map_class.hpp"

namespace ft
{
    template < class T, typename Node >
    class MapIter
    {
        protected:
            Node    *_node;
            MapIter(Node *src) { _node = src; } 

        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef value_type const&   const_reference;
            typedef value_type*         pointer;
            typedef ptrdiff_t           difference_type;
            typedef Node*               node_ptr;

            MapIter() : _node(NULL) {}
            MapIter(MapIter const& src) { *this = src; }
            virtual ~MapIter() {}
            MapIter&  operator=(MapIter const& rhs)
            {
                if (this != &rhs)
                    _node = rhs._node;
                return *this; 
            }
            operator MapIter<const T, Node>(void) const { return MapIter<const T, Node>(this->_node); };

            bool operator==(MapIter const& rhs) { return _node == rhs._node; }
            bool operator!=(MapIter const& rhs) { return _node != rhs._node; }
            
            MapIter& operator++() 
            {
                if (_node->right)
                {
                    _node = min_node(_node->right);
                }
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

            MapIter operator++(int)
            {
                MapIter<T, Node> tmp(*this);
                operator++();
                return tmp;
            }
            
            MapIter& operator--()
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

            MapIter operator--(int)
            {
                MapIter<T, Node> tmp(*this);
                operator--();
                return tmp;
            }

            reference operator*() const { return _node->data; }
            pointer operator->() const { return &_node->data; }

            template <class, class, class, class>
            friend class map;
            template <class, class>
            friend class MapIter;
    };
}

#endif