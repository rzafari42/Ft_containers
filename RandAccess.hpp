/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandAccess.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:29:27 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/24 12:07:41 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDACCESS_HPP
# define RANDACCESS_HPP
# include "RandAccess_class.hpp"
# include "utils.hpp"


namespace ft
{
    template< class T >
    RandAccess<T>::RandAccess() : _val(NULL) 
    { 
    }

    template< class T >
    RandAccess<T>::RandAccess(T *src) : _val(src)
    {
    }

    template< class T >
    RandAccess<T>::RandAccess(RandAccess const& src) : _val(NULL) 
    {
        *this = src;
    }

    template< class T >
    RandAccess<T>::~RandAccess() 
    {
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator=(RandAccess const& rhs)
    { 
        if (this != &rhs)
            _val = rhs._val;
        return (*this);
    }

    template< class T >
    bool RandAccess<T>::operator==(RandAccess const& rhs) const
    {
        return _val == rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator!=(RandAccess const& rhs) const
    {
        return _val != rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator>(RandAccess const& rhs) const
    {
        return _val > rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator>=(RandAccess const& rhs) const
    {
        return _val >= rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator<(RandAccess const& rhs) const
    {
        return _val < rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator<=(RandAccess const& rhs) const
    {
        return _val <= rhs._val;
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator++()
    {
        _val++;
        return *this;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator++(int)
    {
        RandAccess<T> tmp(*this);
        _val++;
        return tmp;
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator--()
    {
        _val--;
        return *this;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator--(int)
    {
        RandAccess<T> tmp(*this);
        _val--;
        return tmp;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator+(difference_type n) const
    {
        return RandAccess(_val + n);
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator-(difference_type n) const
    {
        return RandAccess(_val - n);
    }

    template< class T >
    typename RandAccess<T>::difference_type RandAccess<T>::operator-(RandAccess const& n) const
    {
        return _val - n._val;
    }

    template< class T >
    RandAccess<T>&  RandAccess<T>::operator+=(difference_type n)
    {
        _val += n;
        return *this;
    }

    template< class T >
    RandAccess<T>&  RandAccess<T>::operator-=(difference_type n)
    {
        _val -= n;
        return *this;
    }

    template< class T >
    typename RandAccess<T>::pointer RandAccess<T>::operator->() const
    {
        return _val;
    }

    template< class T >
    typename RandAccess<T>::reference RandAccess<T>::operator*() const
    {
        return *_val;
    }

    template< class T >
    typename RandAccess<T>::reference RandAccess<T>::operator[](difference_type n) const
    {
        return _val[n];
    }
}

#endif