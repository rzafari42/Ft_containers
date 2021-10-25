/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:39:48 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/25 14:57:36 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "map_class.hpp"

namespace ft
{
    //iterator
    /*template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(T *src): MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(iterator const& src) : MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::iterator(const MapIter<value_type, node_type>& src) : MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::iterator::~iterator()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator& map< Key, T, Compare, Alloc >::iterator::operator++()
    {
        return MapIter<T, Node<T> >::operator++();
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::iterator::operator++(int)
    {
        return MapIter<T, Node<T> >::operator++(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator& map< Key, T, Compare, Alloc >::iterator::operator--()
    {
        return MapIter<T, Node<T> >::operator--();
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::iterator::operator--(int)
    {
        return MapIter<T, Node<T> >::operator--(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator::reference map< Key, T, Compare, Alloc >::iterator::operator*() const
    {
        return *(this->_data);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator::pointer map< Key, T, Compare, Alloc >::iterator::operator->() const
    {
        return this->_data;
    }

    //const_iterator
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator() : MapIter<T, Node<T> >()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(T *src) : MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(iterator const& src) : MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::const_iterator(const MapIter<value_type, node_type>& src) : MapIter<T, Node<T> >(src)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::const_iterator::~const_iterator()
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator& map< Key, T, Compare, Alloc >::const_iterator::operator++()
    {
        return MapIter<T, Node<T> >::operator++();
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::const_iterator::operator++(int)
    {
        return MapIter<T, Node<T> >::operator++(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator& map< Key, T, Compare, Alloc >::const_iterator::operator--()
    {
        return MapIter<T, Node<T> >::operator--();
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::const_iterator::operator--(int)
    {
        return MapIter<T, Node<T> >::operator--(0);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename ft::map< Key, T, Compare, Alloc >::const_iterator::reference ft::map< Key, T, Compare, Alloc >::const_iterator::operator*() const
    {
        return *(this->_val);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator::pointer map< Key, T, Compare, Alloc >::const_iterator::operator->() const
    {
        return this->_val;
    }*/

    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::map(const key_compare& comp, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL), _ghost(NULL)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    map< Key, T, Compare, Alloc >::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL), _ghost(NULL)
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

    //Operator=
    template <class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >& map< Key, T, Compare, Alloc >::operator=(const map& x)
    {
        if (this != &x)
        {
            x._data = this->_data;
            x._alloc = this->_alloc;
            x._size = this->_size;
            x._max_size = this->_max_size;
            x._comp = this->_comp;
            x._node_alloc = this->_node_alloc;
            x._root = this->_root;
            x._ghost = this->_ghost;
        }
        return *this;
    }

    //Iterators

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::iterator map< Key, T, Compare, Alloc>::begin()
    {
        return iterator(min_node(_root));
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::const_iterator map< Key, T, Compare, Alloc>::begin() const
    {
        return const_iterator(min_node(_root));
    }
 
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::iterator map< Key, T, Compare, Alloc>::end()
    {
        return iterator(max_node(_root));
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::const_iterator map< Key, T, Compare, Alloc>::end() const
    {
        return const_iterator(max_node(_root));
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::reverse_iterator map< Key, T, Compare, Alloc>::rbegin()
    {
        return reverse_iterator(_ghost);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::const_reverse_iterator map< Key, T, Compare, Alloc>::rbegin() const
    {
        return const_reverse_iterator(_ghost);
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::reverse_iterator map< Key, T, Compare, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::const_reverse_iterator map< Key, T, Compare, Alloc>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    //Capacity
    template <class Key, class T, class Compare, class Alloc >
    bool map< Key, T, Compare, Alloc >::empty() const
    {
        if (!_size)
            return true;
        return false;
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
    typename map< Key, T, Compare, Alloc>::mapped_type& map< Key, T, Compare, Alloc >::operator[] (const key_type& k)
    {
        return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
    }

    //Modifiers
    template< class Key, class T, class Compare, class Alloc >
    pair<typename map<Key, T, Compare, Alloc>::iterator, bool> map< Key, T, Compare, Alloc >::insert(const value_type& val)
    {
        ft::pair<iterator, bool> ret;
        if (count(val.first))
            ret.second = false;
        else
        {
            _root = insertNode(_root, val);
            ret.second = true;
        }
        ret.first = find(val.first);
        return ret;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::insert(iterator position, const value_type& val)
    {
        static_cast<void>(position);
        return insert(val).first;
    }

    template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    void map< Key, T, Compare, Alloc >::insert(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(*first);
            first++;
        }
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::erase(iterator position)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::erase(const key_type& k)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::erase(iterator first, iterator last)
    {

    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::swap(map& x)
    {
        map<Key, T, Compare, Alloc> tmp;

        tmp._data = _data;
        tmp._alloc = _alloc;
        tmp._size = _size;
        tmp._max_size = _max_size;
        tmp._comp = _comp;
        tmp._node_alloc = _node_alloc;
        tmp._root = _root;
        tmp._ghost = _ghost;

        _data = x._data;
        _alloc = x._alloc;
        _size = x._size;
        _max_size = x._max_size;
        _comp = x._comp;
        _node_alloc = x._node_alloc;
        _root = x._root;
        _ghost = x._ghost;

        x._data = _data;
        x._alloc = _alloc;
        x._size = _size;
        x._max_size = _max_size;
        x._comp = _comp;
        x._node_alloc = _node_alloc;
        x._root = _root;
        x._ghost = _ghost;
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::clear()
    {

    }  

    //Observers
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::key_compare map< Key, T, Compare, Alloc >::key_comp() const
    {
        return key_compare();
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::value_compare map< Key, T, Compare, Alloc >::value_comp() const
    {
        return value_compare(key_compare());
    }

    //Operation
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::find(const key_type& k)
    {
        iterator it = begin();
        iterator ite = end();

        while (it != ite)
        {
            if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
                return it;
            it++;
        }
        return ite;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::find(const key_type& k) const
    {
        const_iterator it = begin();
        const_iterator ite = end();

        while (it != ite)
        {
            if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
                return it;
            it++;
        }
        return ++ite;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::count(const key_type& k) const
    {
        const_iterator it = begin();
        const_iterator ite = end();

        if (!_root)
            return 0;
        while (it != ite)
        {
            if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
                return 1;
            it++;
        }
        return 0;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::lower_bound(const key_type& k)
    {

    }    

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::lower_bound(const key_type& k) const
    {

    } 

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k)
    {

    }    

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k) const
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
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::newNode(value_type &val)
    {
        node_ptr node = _node_alloc.allocate(1);
        _alloc.construct(&node->key, val);
        
        node->right = NULL;
        node->left = NULL;
        node->parent = NULL;
        return node;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::insertNode(node_ptr node, value_type val)
    {
        if (node == NULL)
        {
            node = newNode(val);
            _size++;
        }
        if (key_comp()(val.first, node->key.first))
        {
            node->right = insertNode(node->right, val);
            node->right->parent = node;
        }
        if (key_comp()(node->key.first, val.first))
        {
            node->left = insertNode(node->left, val);
            node->left->parent = node;
        }
        return node;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::delete_node(node_ptr node, int key)
    {
        if (node == NULL)
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
            tmp->parent = node->parent;
            _node_alloc.destroy(&node);
            return tmp;
        }
        else if (node->right == NULL || node->right == _ghost)
        {
            node_ptr tmp = node->left;
            tmp->parent = node->parent;
            _node_alloc.destroy(&node);
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
            _node_alloc.destroy(&succ);
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
        return;
    }
}

#endif