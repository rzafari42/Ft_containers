/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:07:10 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/29 10:30:05 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_CLASS_HPP
# define REVERSE_CLASS_HPP
# include "RandAccess_class.hpp"
# include "utils.hpp"

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
                reverse_iterator(); //default
                explicit reverse_iterator(iterator_type it); //initialization
                template < class Iter >
                    reverse_iterator(const reverse_iterator<Iter>& rev_it); //copy

                iterator_type       base() const;
                reference           operator*() const;
                pointer             operator->() const;
                reverse_iterator    operator+(difference_type n) const;
                friend reverse_iterator    operator+(difference_type n, reverse_iterator const& rhs) { return rhs.operator+(n); }
                reverse_iterator    operator-(difference_type n) const;
                template <class T>
                difference_type		operator-(reverse_iterator<T> const& n) { return n.base().operator-(_base); };
                reverse_iterator&   operator++();
                reverse_iterator    operator++(int);
                reverse_iterator&   operator--();
                reverse_iterator    operator--(int);
                reverse_iterator&   operator+=(difference_type n);
                reverse_iterator&   operator-=(difference_type n);
                reference           operator[](difference_type n) const;

            //Non-Member function overloads
            //Relational operators
                template <class Iter>
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
                    bool operator>=(const reverse_iterator<Iter>& rhs) const;
    };
}

#endif