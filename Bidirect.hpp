/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirect.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:39 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/29 10:38:46 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECT_HPP
# define BIDIRECT_HPP
# include "Bidirect_class.hpp"

namespace ft
{
    template <class T>
    Bidirect<T>::Bidirect() : _val(NULL)
    {
    }

    template <class T>
    Bidirect<T>::Bidirect(T *src) : _val(src)
    {
    }

    template <class T>
    Bidirect<T>::Bidirect(Bidirect const& src)
    {
        *this = src;
    }

    template <class T>
    Bidirect<T>::~Bidirect()
    {
    }

    template <class T>
    Bidirect<T>& Bidirect<T>::operator=(Bidirect const& rhs)
    {
        if (this != &rhs)
            _val = rhs._val;
        return *this; 
    }

    template <class T>
    bool Bidirect<T>::operator==(Bidirect const& rhs)
    {
            return _val == rhs._val;
    }

    template < class T >
    bool Bidirect<T>::operator!=(Bidirect const& rhs)
    {
        return _val != rhs._val;
    }

    template < class T >
    Bidirect<T>& Bidirect<T>::operator++()
    {
        _val++;
        return *this;
    }

    template < class T >
    Bidirect<T> Bidirect<T>::operator++(int)
    {
        Bidirect<T> tmp(*this);
        tmp = _val;
        _val++;
        return tmp;
    }

    template < class T >
    Bidirect<T>& Bidirect<T>::operator--()
    {
        _val--;
        return *this;
    }

    template < class T >
    Bidirect<T> Bidirect<T>::operator--(int)
    {
        Bidirect<T> tmp(*this);
        tmp = _val;
        _val--;
        return tmp;
    }

    template < class T >
    Bidirect<T>::reference Bidirect<T>::operator*() const
    {
        return *_val;
    }

    template < class T >
    Bidirect<T>::pointer Bidirect<T>::operator->() const
    {
        return _val;
    }
}

#endif