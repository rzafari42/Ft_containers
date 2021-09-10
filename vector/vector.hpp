/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:19:53 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/10 18:09:01 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "vector_class.hpp"

namespace ft
{
    template < class T, class Alloc >
    vector<T, Alloc>::iterator::iterator(): RandAccess<T>()
    {
    }

    template < class T, class Alloc >
    vector<T, Alloc>::iterator::iterator(T *src): RandAccess<T>(src)
    {
    }

    template < class T, class Alloc >
    vector<T, Alloc>::iterator::iterator(const RandAccess<T>& src): RandAccess<T>(src)
    {
    }

    template < class T, class Alloc >
    vector<T, Alloc>::iterator::iterator(iterator const& src): RandAccess<T>(src)
    {
    }

    template < class T, class Alloc >
    vector<T, Alloc>::iterator::~iterator()
    {
    }

    template < class T, class Alloc > 
    typename vector<T, Alloc>::reference vector<T, Alloc>::iterator::operator*() const
    {
        return *(this->_val);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::pointer vector<T, Alloc>::iterator::operator->() const
    {
        return this->_val;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reference vector<T, Alloc>::iterator::operator[](size_type n) const
    {
        return this->_val[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator& vector<T, Alloc>::iterator::operator+=(difference_type n)
    {
        this->_val += n;
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator& vector<T, Alloc>::iterator::operator-=(difference_type n)
    {
        this->_val -= n;
        return *this;
    }

    template< class T, class Alloc >
    vector<T,Alloc>::const_iterator::const_iterator() : RandAccess<T>()
    {
    }

    template< class T, class Alloc >
    vector<T,Alloc>::const_iterator::const_iterator(T *src) : RandAccess<T>(src)
    {
    }

    template< class T, class Alloc >
    vector<T,Alloc>::const_iterator::const_iterator(const RandAccess<T> &src) : RandAccess<T>(src)
    {
    }

    template< class T, class Alloc >
    vector<T,Alloc>::const_iterator::~const_iterator()
    {
    }

    template < class T, class Alloc > 
    typename vector<T, Alloc>::reference vector<T, Alloc>::const_iterator::operator*() const
    {
        return *(this->_val);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::pointer vector<T, Alloc>::const_iterator::operator->() const
    {
        return this->_val;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::const_iterator::operator[](size_type n) const
    {
        return this->_val[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator& vector<T, Alloc>::const_iterator::operator+=(difference_type n)
    {
        this->_val += n;
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator& vector<T, Alloc>::const_iterator::operator-=(difference_type n)
    {
        this->_val -= n;
        return *this;
    }

    //Constructors
    template < class T, class Alloc >
    vector<T, Alloc>::vector(const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) { }

    template < class T, class Alloc >
    vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(n), _capacity(n)
    {
        _data = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
            _alloc.construct(&_data[i], val);
    }

    template < class T, class Alloc >
    template < class InputIterator >
    vector<T, Alloc>::vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _capacity(0)
    {
        _capacity = ft::InputIterator_len(first, last);
        _data = _alloc.allocate(_capacity);
        for (; first != last; ++first)
            _alloc.construct(&_data[_size++], *first);
    }

    template < class T, class Alloc >
    vector<T, Alloc>::vector(const vector& x) : _data(x._data), _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
    {
        *this = x;
    }

    //Destructor
    template < class T, class Alloc >
    vector<T, Alloc>::~vector()
    {
        clear();
        _data = NULL;
    }

    //Operator=

    template < class T, class Alloc >
    vector<T, Alloc> & vector<T, Alloc>::operator=(const vector& x)
    {
        if (this != &x)
            assign(x.begin(), x.end());
        return *this;
    }

    //Iterators
    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(_data);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return const_iterator(_data);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(_data + _size);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return const_iterator(_data + _size);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }


    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return const_reverse_iterator(end());
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }
    
    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return const_reverse_iterator(begin());
    }

    //Capacity
    template < class T, class Alloc >
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return _size;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return _alloc.max_size();
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return _capacity;
    }

    template < class T, class Alloc >
    bool vector<T, Alloc>::empty() const
    {
        if (!_size)
            return true;
        return false;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        if (n < _size)
        {
            while (_size != n)
                _alloc.destroy(&_data[_size--]);
        }
        else
        {
            if (n > _capacity)
                reserve(n);
            while (n > _size)
                _data[n--] = val;
        }
        _size = n;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::reserve(size_type n)
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
    template < class T, class Alloc >
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n)
    {
        return _data[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const
    {
        return _data[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if (n >= _size)
            throw std::out_of_range("Out of Range error");
        return _data[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
    {
        if (n >= _size)
            throw std::out_of_range("Out of Range error");
        return _data[n];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return _data[0];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return _data[0];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return _data[_size - 1];
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return _data[_size - 1];
    }

    //Modifiers
    template < class T, class Alloc >
    template < class InputIterator >
    void vector<T, Alloc>::assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
    {
        if (!empty())
            clear();
        for (; first != last; first++)
            push_back(*first);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::assign(size_type n, const value_type& val)
    {
        if (!empty())
            clear();
        for(size_t i = 0; i < n; i++)
            push_back(val);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::push_back(const value_type& val)
    {
        if (_size == _capacity)
            reserve(_size + 1);
        ++_size;
        _data[_size] = val;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::pop_back()
    {
        //_alloc.destroy(&_data[_size]);
        --_size;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type& val)
    {
        vector<T, Alloc> tmp(position, end());
        iterator it = position;
        iterator ite = tmp.end();

        for (size_t i = 0; i < tmp.size(); i++)
            pop_back();
        push_back(val);
        for (; it != ite; it++)
            push_back(*it);
        return position;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
    {
        vector<T, Alloc> tmp(position, end());
        iterator it = position;
        iterator ite = tmp.end();

        for (size_t i = 0; i < tmp.size(); i++)
            pop_back();
        for (size_t i = 0; i < n; i++)
            push_back(val);
        for (; it != ite; it++)
            push_back(*it);
    }

    template < class T, class Alloc >
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
    {
        vector<T, Alloc> tmp(position, end());
        iterator it = position;
        iterator ite = tmp.end();

        for (size_t i = 0; i < tmp.size(); i++)
            pop_back();
        for (; first != last; first++)
            push_back(*first);
        for (; it != ite; it++)
            push_back(*it);
    }

    /*template < class T, class Alloc >
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
    {
        difference_type		int_pos = position - this->begin();
        size_type count = 0;
        while (first != last)
        {
            first++;
            count++;
        }
        first -= count;
        if (_capacity - _size <= count)
        {
            if (_size == 0)
                reserve(1);
            else
                reserve(_capacity * 2);
        }
        ft::vector<T>	tmp(begin() + int_pos, end());
        for (size_type i = 0; i < tmp.size(); i++)
            pop_back();
        while (first != last)
        {
            push_back(*first);
            first++;
        }
        iterator it = tmp.begin();
        for (size_type i = 0; i < tmp.size(); i++, it++)
            push_back(*it);
    }
*/
    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        vector<T, Alloc> tmp(position + 1, end());
        iterator it = tmp.begin();
        iterator ite = tmp.end();

        for(size_t i = 0; i < tmp.size(); i++)
            pop_back();
        for (; it != ite; it++)
            push_back(*it);
        return position;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        vector<T, Alloc> tmp(first, end());
        iterator it = last + 1;
        iterator ite = tmp.end();

        for(size_t i = 0; i < tmp.size(); i++)
            pop_back();
        for(; it != ite; it++)
            push_back(*it);
        return first;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::swap(vector& x)
    {
        vector<T, Alloc> tmp;

        tmp._data = _data;
        tmp._alloc = _alloc;
        tmp._size = _size;
        tmp._capacity = _capacity;

        _data = x._data;
        _alloc = x._alloc;
        _size = x._size;
        _capacity = x._capacity;

        x._data = tmp._data;
        x._alloc = tmp._alloc;
        x._size = tmp._size;
        x._capacity = tmp._capacity;
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::clear()
    {
        for (; _size > ; _size--)
            _alloc.destroy(&_data[_size]);
        _size = 0;
    }

    template< class T, class Alloc >
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return _alloc;
    }

    //Non-member function overloads
    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        size_t i = 0;

        if (lhs.size() != rhs.size())
            return false;
        while (i < rhs.size())
        {
            if (lhs[i] != rhs[i])
                return false;
            i++;
        }
        return true;
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs == rhs)
            return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (rhs < lhs)
            return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs < rhs)
            return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs < rhs)
            return false;
        return true;
    }

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

}

#endif