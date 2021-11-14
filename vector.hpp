/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:19:53 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/14 18:21:25 by rzafari          ###   ########.fr       */
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
    typename vector<T, Alloc>::iterator::reference vector<T, Alloc>::iterator::operator*() const
    {
        return *(this->_val);
    }
    

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator::pointer vector<T, Alloc>::iterator::operator->() const
    {
        return this->_val;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator::reference vector<T, Alloc>::iterator::operator[](size_type n) const
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

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator::difference_type vector<T, Alloc>::iterator::operator-(const RandAccess<T> &n) const
    {
        return RandAccess<T>::operator-(n);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator-(difference_type n) const
    {
        return RandAccess<T>::operator-(n);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator+(difference_type n) const
    {
        return RandAccess<T>::operator+(n);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator& vector<T, Alloc>::iterator::operator++(void)
    {
        RandAccess<T>::operator++();
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator++(int)
    {
        return RandAccess<T>::operator++(0);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator& vector<T, Alloc>::iterator::operator--(void)
    {
        RandAccess<T>::operator--();
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator--(int)
    {
        return RandAccess<T>::operator--(0);
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
    typename vector<T, Alloc>::const_iterator::reference vector<T, Alloc>::const_iterator::operator*() const
    {
        return *(this->_val);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator::pointer vector<T, Alloc>::const_iterator::operator->() const
    {
        return this->_val;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator::const_reference vector<T, Alloc>::const_iterator::operator[](size_type n) const
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

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator::difference_type vector<T, Alloc>::const_iterator::operator-(const RandAccess<T> &n) const
    {
        return RandAccess<T>::operator-(n);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::const_iterator::operator-(difference_type n) const
    {
        return RandAccess<T>::operator-(n);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::const_iterator::operator+(difference_type n) const
    {
        return RandAccess<T>::operator+(n);
    }
    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator& vector<T, Alloc>::const_iterator::operator++(void)
    {
        RandAccess<T>::operator++();
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::const_iterator::operator++(int)
    {
        return RandAccess<T>::operator++(0);
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator& vector<T, Alloc>::const_iterator::operator--(void)
    {
        RandAccess<T>::operator--();
        return *this;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::const_iterator::operator--(int)
    {
        return RandAccess<T>::operator--(0);
    }

    //Constructors
    template < class T, class Alloc >
    vector<T, Alloc>::vector(const allocator_type& alloc) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) { }

    template < class T, class Alloc >
    vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) : _alloc(alloc), _size(n), _capacity(n)
    {
        _data = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
            _alloc.construct(&_data[i], val);
    }

    template < class T, class Alloc >
    template < class InputIterator >
    vector<T, Alloc>::vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) : _alloc(alloc), _size(0), _capacity(0)
    {
        _capacity = ft::InputIterator_len(first, last);
        _data = _alloc.allocate(_capacity);
        for (; first != last; ++first)
            _alloc.construct(&_data[_size++], *first);
    }

    template < class T, class Alloc >
    vector<T, Alloc>::vector(vector const &src) : _data(NULL),  _alloc(allocator_type()), _size(0), _capacity(0) 
    {
	    _size = src.size();
        _capacity = src.capacity();
        _max_size = src.max_size();
        _data = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; i++)
            _alloc.construct(&_data[i], src[i]);
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
        vector<T, Alloc> tmp;
        if (this != &x)
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_data[i]);
            if (x.size() > tmp._capacity)
                tmp._capacity = x.size();
            if (x.capacity() < _capacity)
                tmp._capacity = _capacity;
            tmp._data = _alloc.allocate(tmp._capacity);
            const_iterator first = x.begin(); const_iterator last = x.end();
            for (size_type i = 0; first != last; ++first)
                tmp._alloc.construct(&tmp._data[i++], *first);
            _data = tmp._data;
            _size = x.size();
            _capacity = tmp._capacity;
        }
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
            _capacity =  n;
            _data = tmp;
        }
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        if (n < size())
        {
            while (_size != n)
                _alloc.destroy(&_data[_size--]);
        }
        else
        {
            /*if (n <= _capacity)
                ;*/
            if (n <= _capacity * 2)
                reserve(_capacity * 2);
            else
                reserve(n);
            while (_size < n)
            {
                _alloc.construct(&_data[_size], val);
                _size++;
            }
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
    void vector<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
    {
        size_type n = InputIterator_len(first, last);
        
        clear();
        if (n > capacity())
        {
            _alloc.deallocate(_data, _capacity);
            _capacity = 0;
            _data = NULL;

            _data = _alloc.allocate(n);
            _capacity = n;
        }
        for (; first != last; first++)
            _alloc.construct(&_data[_size++], *first);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::assign(size_type n, const value_type& val)
    {
        clear();
        if (n > _capacity)
        {
            _alloc.deallocate(_data, _capacity);
            _data = NULL;

            _data = _alloc.allocate(n);
            _capacity = n;
        }
        for (size_t i = 0; i < n; i++)
            _alloc.construct(&_data[_size++], val);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::push_back(const value_type& val)
    {
        if (_size == _capacity)
            resize(_size + 1, val);
        else
            _alloc.construct(&_data[_size++], val);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::pop_back()
    {
        _alloc.destroy(&_data[_size]);
        --_size;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type& val)
    {
        difference_type const position_pos = position - this->begin();

        insert(position, 1, val);
        return (iterator(this->begin() + position_pos));
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
    {
        difference_type const old_end_pos = this->end() - this->begin();
        difference_type const position_pos = position - this->begin();
        iterator    old_end, end;

        resize(_size + n);
        old_end = this->begin() + old_end_pos;
        position = this->begin() + position_pos;
        end = this->end();

        while (old_end != position)
            *--end = *--old_end;
        while (n > 0)
        {
            *position++ = val;
            n--;
        }
    }

    template < class T, class Alloc >
    template <class InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
    {
        difference_type const old_end_pos = this->end() - this->begin();
        difference_type const position_pos = position - this->begin();

        iterator old_end, end;
        
        resize(_size + InputIterator_len(first, last));
        old_end = this->begin() + old_end_pos;
        position = this->begin() + position_pos;
        end = this->end();

        while (old_end != position)
            *--end = *--old_end;
        while (first != last)
            *position++ = *first++;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        vector<T, Alloc> tmp(position + 1, end());
        iterator it = tmp.begin();
        iterator ite = tmp.end();

        for(size_t i = 0; i <= tmp.size(); i++)
            pop_back();
        for (; it != ite; it++)
            push_back(*it);
        return position;
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        vector<T, Alloc> tmp(first + 1, end());
        vector<T, Alloc> tmp2(last, end());
        iterator it = tmp2.begin();
        iterator ite = tmp2.end();
    
        for(size_t i = 0; i <= tmp.size(); i++)
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
        for (; _size > 0; _size--)
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
        if (rhs < lhs)
            return true;
        return false;
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