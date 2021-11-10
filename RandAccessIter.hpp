/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandAccessIter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:19:35 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/09 14:52:43 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDACCESSITER_HPP
# define RANDACCESSITER_HPP
# include "utils.hpp"

namespace ft
{
    template < class T >
    class RandAccess
    {
        protected:
            T          *_val;

        public:
            typedef T&          reference;
            typedef T*          pointer;
            typedef ptrdiff_t   difference_type;

            RandAccess() : _val(NULL) {}
            RandAccess(T *src) : _val(src) {}
            RandAccess(RandAccess const& src) : _val(NULL) { *this = src; }
            virtual ~RandAccess() {}
            RandAccess& operator=(RandAccess const& rhs) {
                if (this != &rhs)
                    _val = rhs._val;
                return (*this);
            };

            bool            operator==(RandAccess const& rhs) const { return _val == rhs._val; }
            bool            operator!=(RandAccess const& rhs) const { return _val != rhs._val; }
            bool            operator>(RandAccess const& rhs) const { return _val > rhs._val; }
            bool            operator>=(RandAccess const& rhs) const { return _val >= rhs._val; }
            bool            operator<(RandAccess const& rhs) const { return _val < rhs._val; };
            bool            operator<=(RandAccess const& rhs) const { return _val <= rhs._val; };

            RandAccess<T>&  operator++() { _val++; return *this; }
            RandAccess<T>   operator++(int) {  RandAccess<T> tmp(*this); _val++; return tmp; }
            RandAccess<T>&  operator--() { _val--; return *this; }
            RandAccess<T>   operator--(int) { RandAccess<T> tmp(*this); _val--; return tmp; }
            RandAccess<T>   operator+(difference_type n) const { return RandAccess(_val + n); }
            friend RandAccess<T>    operator+(difference_type n, RandAccess const& rhs) { return rhs.operator+(n); }

            RandAccess<T>   operator-(difference_type n) const { return RandAccess(_val - n); }
            difference_type operator-(RandAccess const& n) const { return _val - n._val; }
            RandAccess<T>&  operator+=(difference_type n) { _val += n; return *this; }
            RandAccess<T>&  operator-=(difference_type n) { _val -= n; return *this; }

            pointer         operator->() const { return _val; }
            reference       operator*() const { return *_val; }
            reference       operator[](difference_type n) const { return _val[n]; }
    };
}

#endif