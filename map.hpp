/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:39:48 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/01 16:21:48 by rzafari          ###   ########.fr       */
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

    template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    map< Key, T, Compare, Alloc >::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL)
    {
        insert(first, last);
        return;
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::map(const map& x)
    {
        *this = x;
        return;
    }

    template <class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::~map()
    {
        clear();
        _data = NULL;
    }

    template <class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >& map< Key, T, Compare, Alloc >::operator=(const map& x)
    {
        if (this != &c)
        {
                //to complete
        }    
    }

    template <class Key, class T, class Compare, class Alloc >
    bool map< Key, T, Compare, Alloc >::empty() const
    {
        
    }

    template <class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::size() const
    {
            return _size;
    }

    template <class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::max_size() const
    {
            return _node_alloc.max_size();
    }
    
    //Binary Search Tree specific functions
    template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::newNode(int key)
    {
        node_ptr node = _node_alloc.allocate(1);
        node->key = key;
        node->right = NULL;
        node->left = NULL;
        return node;
    }

     template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::insertNode(node_ptr node, int key)
    {
        if (node == NULL)
        {
            node = newNode(key);     
            _size++;
        }
        if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        return node; 
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::PrintInOrder(node_ptr node)
    {
        if (node)
        {
            PrintInOrder(node->left);
            std::cout << node->key << ' ';
            PrintInOrder(node->right);
        }
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::min_node(node_ptr node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node; 
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::max_node(node_ptr node)
    {
        while (node && node->right != NULL)
            node = node->right;
        return node; 
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::delete_node(node_ptr node, int key)
    {
        /*if (node == NULL)
            return node;
        if (key > node->key)
        {
            node->right = delete_node(node->right, key);
            return node;
        }
        else if (key < node->key)
        {
            node->left = delete_node(node->left, key);
            return node;
        }

        if (node->left == NULL)
        {
            node_ptr tmp = node->right;
            delete node;
            return tmp;
        }
        else if (node->right == NULL)
        {
            node_ptr tmp = node->left;
            delete node;
            return tmp;
        }
        //2 Children case: Get the inOrder successor (smallest in the right subtree)
        else
        {
            node_ptr succParent = node;
            node_ptr succ = node->right;

            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succParent->left;  
            }
            if (succParent != node)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            node->key = succ->key; 
            _node_alloc.destroy(&);
            return node;
        }
        return node;
    }*/
}

#endif