/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:07:10 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/09 14:32:57 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_CLASS_HPP
# define REVERSE_CLASS_HPP
# include "RandAccess_class.hpp"
# include "utils.hpp"
# include <iterator>

namespace ft
{
    template < class Iterator >
    class reverse_iterator
    {
        protected:
            Iterator _base;

        public:
            typedef Iterator        iterator_type;
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;

            //Member Functions
                //Constructors
                reverse_iterator() : _base() {} //default
                explicit reverse_iterator(iterator_type it) : _base(it) {}//initialization
                template < class Iter >
                    reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {} //copy
                template <class Iter> 
                    reverse_iterator &operator=(const reverse_iterator<Iter> &x) { _base = x.base(); return *this; };

                iterator_type       base() const { return _base; };
                reference           operator*() const { Iterator tmp = _base; return *--tmp; };
                pointer             operator->() const { return &(operator*()); };
                reverse_iterator    operator+(difference_type n) const { return reverse_iterator(_base - n); };
                reverse_iterator    operator-(difference_type n) const { return reverse_iterator(_base + n); };
                template <class T>
                    difference_type		operator-(reverse_iterator<T> const& n) { return n.base().operator-(_base); };
                reverse_iterator&   operator++() {--_base; return *this; };
                reverse_iterator    operator++(int) { reverse_iterator tmp(*this); --_base; return tmp; };
                reverse_iterator&   operator--(){ ++_base; return *this; };
                reverse_iterator    operator--(int) { reverse_iterator tmp(*this); ++_base; return tmp; };
                reverse_iterator&   operator+=(difference_type n) { _base -= n; return *this; };
                reverse_iterator&   operator-=(difference_type n) { _base += n; return *this; };
                reference           operator[](difference_type n) const { return *(*this + n); };

            //Relational operators
                /*template <class Iter>
                    bool operator==(const reverse_iterator<Iter>& rhs) const;
                template <class Iter>
                    bool operator!=(const reverse_iterator<Iter>& rhs) const;
                template <class Iter>
                    bool operator<(const reverse_iterator<Iter>& rhs) const;
                template <class Iter>
                    bool operator<=(const reverse_iterator<Iter>& rhs) const;
                template <class Iter>
                    bool operator>(const reverse_iterator<Iter>& rhs) const;
                template <class Iter>
                    bool operator>=(const reverse_iterator<Iter>& rhs) const;*/
    };
    
    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return lhs.base() <= rhs.base();
    } 

    template <class Iterator>
        reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
        {
            return reverse_iterator<Iterator>(rev_it.base() - n);
        }

    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
        {
            return lhs.base() - rhs.base();
        }
}

#endif