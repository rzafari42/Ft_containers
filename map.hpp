/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:39:48 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/10 17:10:17 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include "map_class.hpp"

namespace ft
{
    template< class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::map(const key_compare& comp, const allocator_type& alloc) : _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL), _ghost(NULL), _GreatestData(NULL)
    {
    }

    template< class Key, class T, class Compare, class Alloc >
    template <class InputIterator>
    map< Key, T, Compare, Alloc >::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) :  _alloc(alloc), _size(0), _max_size(0), _comp(comp), _root(NULL), _ghost(NULL), _GreatestData(NULL)
    {
        insert(first, last);
        return;
    }

    template< class Key, class T, class Compare, class Alloc >
    map<Key, T, Compare, Alloc>::map(map const &x) : _alloc(x._alloc), _size(x._size), _max_size(x._max_size),  _comp(x._comp), _node_alloc(x._node_alloc)
    {
        clear();
        insert(x.begin(), x.end());
    }

    template <class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >::~map()
    {
        clear();
        if (_root)
            _node_alloc.deallocate(_root, _size);
        if (_ghost)
            _node_alloc.deallocate(_ghost, 1);

        return ;
    }

    //Operator=
    template <class Key, class T, class Compare, class Alloc >
    map< Key, T, Compare, Alloc >& map< Key, T, Compare, Alloc >::operator=(const map& x)
    {
        if (this == &x)
            return *this;
        else
        {
            clear();
            insert(x.begin(), x.end());
            this->_alloc = x._alloc;
            this->_size = x._size;
            this->_max_size = x._max_size;
            this->_comp = x._comp;
            this->_node_alloc = x._node_alloc;
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
        /* if (!_root || !_size)
            return iterator(_GreatestData);
        return iterator(_GreatestData->right); */
        return iterator(max_node(_root));
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc>::const_iterator map< Key, T, Compare, Alloc>::end() const
    {
        return const_iterator(max_node(_root));
        /* if (!_root || !_size)
            return const_iterator(_GreatestData);
        return const_iterator(_GreatestData->right); */
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
        return (*((this->insert(value_type(k, mapped_type()))).first)).second;
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
        _root = delete_node(_root, value_type(position->first, position->second));
        --_size;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::size_type map< Key, T, Compare, Alloc >::erase(const key_type& k)
    {
        iterator it = find(k);
        iterator ite = end();

        if (!count(k))
            return 0;
        else
        {
            _root = delete_node(_root, value_type(it->first, it->second));
            --_size;
        }
        return 1;
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::erase(iterator first, iterator last)
    {
        while (first != last)
        {
            _root = delete_node(_root, value_type(first->first, first->second));
            _size--;
            first++;
        }
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::swap(map& x)
    {
        map<Key, T, Compare, Alloc> tmp;

        tmp._alloc = _alloc;
        tmp._size = _size;
        tmp._max_size = _max_size;
        tmp._comp = _comp;
        tmp._node_alloc = _node_alloc;
        tmp._root = _root;
        tmp._ghost = _ghost;

        _alloc = x._alloc;
        _size = x._size;
        _max_size = x._max_size;
        _comp = x._comp;
        _node_alloc = x._node_alloc;
        _root = x._root;
        _ghost = x._ghost;

        x._alloc = tmp._alloc;
        x._size = tmp._size;
        x._max_size = tmp._max_size;
        x._comp = tmp._comp;
        x._node_alloc = tmp._node_alloc;
        x._root = tmp._root;
        x._ghost = tmp._ghost;
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::clear()
    {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(&_root->data);
        _size = 0;
        _ghost =  NULL;
        _GreatestData = NULL;
        _root = NULL;
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
            if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
                return it;
            it++;
        }
        return ++ite;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::find(const key_type& k) const
    {
        const_iterator it = begin();
        const_iterator ite = end();

        while (it != ite)
        {
            if (!key_comp()(k, it->first) && !key_comp()(it->first, k))
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
        iterator it = begin();
        iterator ite = end();

        while (it != ite)
        {
            if (!key_comp()(it->first, k))
                return it;
            it++;
        }
        return ite;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::lower_bound(const key_type& k) const
    {
        const_iterator it = begin();
        const_iterator ite = end();

        while (it != ite)
        {
            if (!key_comp()(it->first, k))
                return it;
            it++;
        }
        return ite;
    } 

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k)
    {
        iterator it = begin();
        iterator ite = end();

        while (it != ite)
        {
            if (key_comp()(k, it->first))
                return it;
            it++;
        }
        return ite;
    }    

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::const_iterator map< Key, T, Compare, Alloc >::upper_bound(const key_type& k) const
    {
        const_iterator it = begin();
        const_iterator ite = end();

        while (it != ite)
        {
            if (key_comp()(k, it->first))
                return it;
            it++;
        }
        return ite;
    }

    template< class Key, class T, class Compare, class Alloc >
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map< Key, T, Compare , Alloc >::iterator>
    map< Key, T, Compare, Alloc >::equal_range(const key_type& k)
    {
        ft::pair<iterator, iterator> ret;

        ret.first = lower_bound(k);
        ret.second = upper_bound(k);

        return ret;
    }

    template< class Key, class T, class Compare, class Alloc >
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map< Key, T, Compare , Alloc >::const_iterator>
    map< Key, T, Compare, Alloc >::equal_range(const key_type& k) const
    {
        ft::pair<const_iterator, const_iterator> ret;

        ret.first = lower_bound(k);
        ret.second = upper_bound(k);

        return ret;
    }

    //Allocator
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::allocator_type map< Key, T, Compare, Alloc >::get_allocator() const
    {
        return _alloc;
    }

    //Binary Search Tree specific functions
    template< class Key, class T, class Compare, class Alloc >
    typename map<Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::newNode(value_type &data)
    {
        node_ptr node = _node_alloc.allocate(1);
        _alloc.construct(&node->data, data);
        node->right = NULL;
        node->left = NULL;
        node->parent = NULL;
        return node;
    }


/*    template<class Key, class T, class Compare, class Alloc>
    void    map<Key, T, Compare, Alloc>::_setGhost(bool add)
    {
        if (!_ghost)
            _ghost = _node_alloc.allocate(1);
        if (add)
        {
            _GreatestData = max_node(_root);
            _GreatestData->right = _ghost;
        }
        if (size() == 0)
            _GreatestData = NULL;
        _ghost->right = NULL;
        _ghost->left = NULL;
        _ghost->parent = _GreatestData;
    }
    
    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::insertNode(node_ptr node, value_type data)
    {
        if (!_root || !node || node == _ghost )
        {
            node = newNode(data);
            if (!_root)
                _root = node;
            if (node == _ghost)
            {
                _GreatestData = node;
                _ghost->parent = _GreatestData;
                _ghost->right = NULL;
                _ghost->left = NULL;
            }
            _size++;
        }
        else if (key_comp()(data.first, node->data.first))
        {
            node->left = insertNode(node->left, data);
            node->left->parent = node;
        }
        else
        {
            node->right = insertNode(node->right, data);
            node->right->parent = node;
        }
        if (!_ghost || key_comp()(_GreatestData->data.first, data.first))
        {	
            if (!_ghost)
                _ghost = _node_alloc.allocate(1);
            _GreatestData = max_node(_root);
            _GreatestData->right = _ghost;
            _ghost->right = NULL;
            _ghost->left = NULL;
            _ghost->parent = _GreatestData;
        }
        return node;
    } */

    template<class Key, class T, class Compare, class Alloc>
    void    map<Key, T, Compare, Alloc>::_setGhost(bool add)
    {
        if (!_ghost)
            _ghost = _node_alloc.allocate(1);
        if (add)
        {
            _GreatestData = max_node(_root);
            _GreatestData->right = _ghost;
        }
        if (size() == 0)
            _GreatestData = NULL;
        _ghost->right = NULL;
        _ghost->left = NULL;
        _ghost->parent = _GreatestData;
    }

    template<class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::node_ptr    map<Key, T, Compare, Alloc>::insertNode(node_ptr node, value_type val)
    {
        if (!_root || !node || node == _ghost)
        {
            node = newNode(val);
            if (!_root)
                _root = node;
            else if (node == _ghost)
                _GreatestData = node;
            _size++;
        }
        else if (key_comp()(val.first, node->data.first))
        {
            node->left = insertNode(node->left, val);
            node->left->parent = node;
        }
        else
        {
            node->right = insertNode(node->right, val);
            node->right->parent = node;
        }
        if (!_ghost || !key_comp()(val.first, _GreatestData->data.first))
        {	
            if (_ghost)
                !key_comp()(node->data.first, _GreatestData->data.first) ? _setGhost(true) : _setGhost(false);
            else
                _setGhost(true);
        }
        return node;
    }

    template< class Key, class T, class Compare, class Alloc >
    typename map< Key, T, Compare, Alloc >::node_ptr map< Key, T, Compare, Alloc >::delete_node(node_ptr node, value_type data)
    {
        if (node == NULL)
            return node;
        if (key_comp()(node->data.first, data.first))
            node->right = delete_node(node->right, data);
        else if (key_comp()(data.first, node->data.first))
            node->left = delete_node(node->left, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                _alloc.destroy(&node->data);
                return NULL;
            }
            if (node->left == NULL)
            {
                node_ptr tmp = node->right;
                tmp->parent = node->parent;
                _alloc.destroy(&node->data);
                return tmp;
            }
            else if (node->right == NULL || node->right == _ghost)
            {
                node_ptr tmp = node->left;
                tmp->parent = node->parent;
                _alloc.destroy(&node->data);
                return tmp;
            }
            node_ptr tmp = min_node(node->right);
                _alloc.destroy(&node->data);
                _alloc.construct(&node->data, tmp->data);
                node->right = delete_node(node->right, tmp->data);
        }
        return node;
    }

    template< class Key, class T, class Compare, class Alloc >
    void map< Key, T, Compare, Alloc >::PrintInOrder(node_ptr node)
    {
        if (node != NULL)
        {
            PrintInOrder(node->left);
            if (node == _ghost)
                std::cout << "Ghost: ";
            std::cout << node->data;
            PrintInOrder(node->right);
        }
        return;
    }
}
#endif