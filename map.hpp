/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:39:48 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/03 20:45:25 by rzafari          ###   ########.fr       */
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
    ft::map< Key, T, Compare, Alloc >::const_iterator::reference ft::map< Key, T, Compare, Alloc >::const_iterator::operator*() const
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
        if (this != &x)
        {
                //to complete
        }    
    }

    //Iterators
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::iterator map< Key, T, Compare, Alloc>::begin()
    {

    } 

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::const_iterator map< Key, T, Compare, Alloc>::begin() const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::iterator map< Key, T, Compare, Alloc>::end()
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::const_iterator map< Key, T, Compare, Alloc>::end() const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::reverse_iterator map< Key, T, Compare, Alloc>::rbegin()
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::const_reverse_iterator map< Key, T, Compare, Alloc>::rbegin() const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::reverse_iterator map< Key, T, Compare, Alloc>::rend()
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::const_reverse_iterator map< Key, T, Compare, Alloc>::rend() const
    {

    }

    //Capacity
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
    
    //Element Access
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc>::mapped_type& map< Key, T, Compare, Alloc >::operator[] (const key_type& k)
    {

    }

    //Modifiers

    template< class Key, class T, class Compare, class Alloc >
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>
    map< Key, T, Compare, Alloc >::insert(const value_type& val)
    {

    }


    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::insert(iterator position, const value_type& val)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    void map< Key, T, Compare, Alloc >::insert(InputIterator first, InputIterator last)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::erase(iterator position)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::erase(const key_type& k)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::erase(iterator first, iterator last)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::swap(map& x)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::clear()
    {

    }  

    //Observers
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::key_compare map< Key, T, Compare, Alloc >::key_comp() const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::value_compare map< Key, T, Compare, Alloc >::value_comp() const
    {

    }

    //Operation
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::find(const key_type& k)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::find(const key_type& k) const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::count(const key_type& k) const
    {

    }    

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::lower_bound(const key_type& k)
    {

    }    

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::lower_bound(const key_type& k) const
    {

    } 

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k)
    {

    }    

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k) const
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map< Key, T, Compare , Alloc >::iterator>
    map< Key, T, Compare, Alloc >::equal_range(const key_type& k)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map< Key, T, Compare , Alloc >::const_iterator>
    map< Key, T, Compare, Alloc >::equal_range(const key_type& k) const
    {

    }

    //Allocator
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::allocator_type map< Key, T, Compare, Alloc >::get_allocator() const
    {

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
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::insertNode(node_ptr node, int key)
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
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::min_node(node_ptr node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node; 
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::max_node(node_ptr node)
    {
        while (node && node->right != NULL)
            node = node->right;
        return node; 
    }

}

#endif