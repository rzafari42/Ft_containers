/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:17:24 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/14 10:29:19 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_HPP
# define REVERSE_HPP
# include "Reverse_class.hpp"

namespace ft
{
    template< class Iterator >
    reverse_iterator<Iterator>::reverse_iterator() : _base()
    {
    }

    template< class Iterator >
    reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _base(it)
    {
    }

    template< class Iterator >
    template < class Iter >
    reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base())
    {
    }

    template< class Iterator >
    typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const
    {
        return _base;
    }

    template< class Iterator >
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
    {
        return (--Iterator(_base)).operator*();
    }

    template< class Iterator >
    typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
    {
        return &(operator*());
    }

    template< class Iterator >
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const
    {
        return reverse_iterator(_base.operator-(n));
    }

    template< class Iterator >
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const
    {
        return reverse_iterator(_base.operator+(n));
    }

    template< class Iterator >
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
    {
        _base--;
        return *this;
    }

    template< class Iterator >
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
    {
        reverse_iterator tmp(*this);
        _base--;
        return tmp;
    }

    template< class Iterator >
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
    {
        _base++;
        return *this;
    }

    template< class Iterator >
    reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
    {
        reverse_iterator tmp(*this);
        _base++;
        return tmp;
    }

    template< class Iterator >
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(difference_type n)
    {
        _base -= n;
        return *this;
    }

    template< class Iterator >
    reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(difference_type n)
    {
        _base += n;
        return *this;
    }

    template< class Iterator >
    typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const
    {
        return *(*this + n);
    }

    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator==(const reverse_iterator<Iter>& rhs) const
    {
        return _base.operator==(rhs.base());
    }

    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator!=(const reverse_iterator<Iter>& rhs) const
    {
        return _base.operator!=(rhs.base());
    }
    
    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator<(const reverse_iterator<Iter>& rhs) const
    {
        return _base.operator>(rhs.base());
    }

    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator<=(const reverse_iterator<Iter>& rhs) const
    {
        return _base.operator>=(rhs.base());
    }

    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator>(const reverse_iterator<Iter>& rhs) const
    {
        return _base.operator<(rhs.base());
    }

    template< class Iterator >
    template <class Iter>
    bool reverse_iterator<Iterator>::operator>=(const reverse_iterator<Iter>& rhs) const 
    {
        return _base.operator<=(rhs.base());
    }
}

#endif