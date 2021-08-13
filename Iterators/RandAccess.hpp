/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandAccess.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:29:27 by rzafari           #+#    #+#             */
/*   Updated: 2021/08/13 19:07:22 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDACCESS_HPP
# define RANDACCESS_HPP
# include "RandAccess_class.hpp"

namespace ft_
{
    template< class T >
    RandAccess<T>::RandAccess(void) : _val(NULL) 
    { 
        return;
    }

    template< class T >
    RandAccess<T>::RandAccess(RandAccess const& src) : _val(NULL) 
    {
        *this = src
    }

    template< class T >
    RandAccess<T>::~RandAccess(void) 
    {
        return;
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator=(RandAccess const& rhs)
    { 
        if (this != &rhs)
            this->_val = rhs._val;
        return (*this);
    }

    template< class T >
    bool RandAccess<T>::operator==(RandAccess const& rhs) const
    {
        return this->_val == rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator!=(RandAccess const& rhs) const
    {
        return this->_val != rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator>(RandAccess const& rhs) const
    {
        return this->_val > rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator>=(RandAccess const& rhs) const
    {
        return this->_val >= rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator<(RandAccess const& rhs) const
    {
        return this->_val < rhs._val;
    }

    template< class T >
    bool RandAccess<T>::operator>(RandAccess const& rhs) const
    {
        return this->_val <= rhs._val;
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator++(void)
    {
        this->_val++;
        return *this;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator++(int)
    {
        RandAccess<T> tmp(*this);
        this->_val++;
        return tmp;
    }

    template< class T >
    RandAccess<T>& RandAccess<T>::operator--(void)
    {
        this->_val--;
        return *this;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator--(int)
    {
        RandAccess<T> tmp(*this);
        this->_val--;
        return tmp;
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator+(difference_type n) const
    {
        return RandAccess(this->_val + n);
    }

    template< class T >
    RandAccess<T> RandAccess<T>::operator-(difference_type n) const
    {
        return RandAccess(this->_val - n);
    }

    template< class T >
    typename RandAccess<T>::difference_type RandAccess<T>::operator-(RandAccess const& n) const
    {
        return this->_val - n._val;
    }

    template< class T >
    RandAccess<T>&  RandAccess<T>::operator+=(difference_type n)
    {
        this->_val += n;
        return *this;
    }

    template< class T >
    RandAccess<T>&  RandAccess<T>::operator-=(difference_type n)
    {
        this->_val -= n;
        return *this;
    }

    template< class T >
    typename RandAccess<T>::pointer RandAccess<T>::operator->(void) const
    {
        return this->_val;
    }

    template< class T >
    typename RandAccess<T>::reference RandAccess<T>::operator*(void) const
    {
        return *this->_val;
    }

    template< class T >
    typename RandAccess<T>::reference RandAccess<T>::operator[](difference_type n) const
    {
        return this->_val[n];
    }
}

#endif