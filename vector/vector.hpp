/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:19:53 by rzafari           #+#    #+#             */
/*   Updated: 2021/08/24 22:56:06 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vector_class.hpp"

namespace ft_
{
    //Constructors
    template < class T, class Allocator >
    vector<T, Allocator>::vector(const allocator_type& alloc) : _data(NULL), _allocator(alloc), _size(0), _capacity(0) { }

    template < class T, class Allocator >
    vector<T, Allocator>::vector(size_type n, const value_type& val, const allocator_type& alloc) : _data(NULL), _allocator(alloc), _size(n), _capacity(n)
    {
        _data = _allocator.allocate(n);
        for (size_t i = 0; i < n; i++)
            _allocator.construct(&_data[i], val);
    }

    template < class T, class Allocator >
    template < class InputIterator >
    vector<T, Allocator>::vector(typename ft_::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) : _data(NULL), _allocator(alloc), _size(0), _capacity(0)
    {
        _capacity = ft_::InputIterator_len(first, last);
        _data = _allocator.allocate(_capacity);
        for (; first != last; ++first)
            _allocator.construc(&_data[_size++], *first);
    }

    template < class T, class Allocator >
    vector<T, Allocator>::vector(const vector& x) : _data(x._data), _allocator(x._allocator), _size(x._size), _capacity(x._capacity)
    {
        *this = x;
    }

    //Destructor
    template < class T, class Allocator >
    vector<T, Allocator>::~vector()
    {
        clear();
        _data = NULL;
    }

    //Operator=
/*
    template < class T, class Allocator >
    vector<T, Allocator> & vector<T, Allocator>::operator=(const vector& x)
    {
        if (this != &x)
        {
            vector<T, Allocator> tmp;
            
            for(size_type i = 0; i < _size; i++)
                _allocator.destroy(&_data[i]);
            if (x._size() > _capacity())
                tmp.capacity() = x.size();
            const_iterator first = x.begin();
            const_iterator last = x.end();
            tmp._data = _allocator.allocate(tmp._capacity);
            for (size_type i = 0; first != last; ++first)
                _allocator.construc(&_data[i++], *first);
            _data = tmp._data;
            _size = tmp._size;
            _capacity = tmp._capacity;
        }
        return *this;
    }*/ //Currently doing the clear() function so I can simplify this part of code ;)


    //Iterators
    template < class T, class Allocator >
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
    {
        return iterator(_data);
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
    {
        return const_iterator(_data);
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
    {
        return iterator(_data + _size);
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
    {
        return const_iterator(_data + _size);
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
    {
        return reverse_iterator(end());
    }


    template < class T, class Allocator >
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend()
    {
        return reverse_iterator(begin());
    }
    
    template < class T, class Allocator >
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    //Capacity
    template < class T, class Allocator >
    typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
    {
        return _size;
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
    {
        return _allocator.max_size();
    }

    template < class T, class Allocator >
    typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
    {
        return _capacity;
    }

    template < class T, class Allocator >
    bool vector<T, Allocator>::empty() const
    {
        if (!_size)
            return true;
        return false;
    }

    /*template < class T, class Allocator >
    void vector<T, Allocator>::resize(size_type n, value_type val = value_type())
    {
        if (n < _size)
        {
            while (_size != n)
                _allocator.destroy(&_data[_size--])
        }
        else
        {
            if (n > _capacity)
                _allocator.allocate(tmp._capacity)
            //while (_size < n)
                //_allocator.construc(&_data[_size++], val);
        }
    } */ //Let's code the push_back() function so it'll be easier to do this one

    template < class T, class Allocator >
    void vector<T, Allocator>::reserve(size_type n)
    {
        if (n > _capacity)
        {
            T   *tmp;

            tmp = _alloc.allocate(n);
            for (size_type i = 0; i < _size; i++)
            {
                _alloc.construct(&tmp[i], _data[i]);
                _alloc.destroy(&_data[i]);
            }
            _alloc.deallocate(_data, _capacity);
            _capacity = n;
            _data = tmp;
        }
    }

    //Element Access
    template < class T, class Allocator >
    vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type n)
    {
        return _data[n];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type n) const
    {
        return _data[n];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::reference vector<T, Allocator>::at(size_type n)
    {
        if (n >= _size)
            throw std::out_of_range(n);
        return _data[n];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type n) const
    {
        if (n >= _size)
            throw std::out_of_range(n);
        return _data[n];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::reference vector<T, Allocator>::front()
    {
        return _data[0];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
    {
        return _data[0];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::reference vector<T, Allocator>::back()
    {
        return _data[_size - 1];
    }

    template < class T, class Allocator >
    vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
    {
        return _data[_size - 1];
    }

    //Modifiers
    template < class T, class Allocator >
    void vector<T, Allocator>::push_back(const value_type& val)
    {
        if (_size == _capacity)
            reserve(_size + 1);
        ++_size;
        _data[size] = val;
    }

    template < class T, class Allocator >
    void vector<T, Allocator>::pop_back()
    {
        _allocator.destroy(&_data[_size]);
        --_size;
    }

    /*template < class T, class Allocator >
    vector<T, Allocator>::iterator vector<T, Allocator>::insert(iterator position, const value_type& val)
    {
     
    }

    template < class T, class Allocator >
    void vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
    {
     
    }

    template < class T, class Allocator >
    template <class InputIterator>
    void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
    {
        
    }

    template < class T, class Allocator >
    vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position)
    {
     
    }

    template < class T, class Allocator >
    vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position, iterator first)
    {
     
    }

    template < class T, class Allocator >
    void vector<T, Allocator>::swap(vector& x)
    {
        
    }*/


    template < class T, class Allocator >
    void vector<T, Allocator>::clear()
    {
        for (; _size >= 0; _size--)
            _allocator.destroy(&_data[_size]);
        _allocator.deallocate(_data, _capacity);
        _size = 0;
        _capacity = 0;
    }
}

#endif