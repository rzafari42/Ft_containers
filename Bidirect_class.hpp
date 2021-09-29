/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirect_class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/29 09:25:42 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECT_CLASS_HPP
# define BIDIRECT_CLASS_HPP
# include <iterator>

namespace ft
{
    template < class T >
    class Bidirect
    {
        public:
            typedef T&  reference;
            typedef T*  pointer;

            Bidirect();
            Bidirect(T *src);
            Bidirect(Bidirect const& src);
            virtual ~Bidirect();
            Bidirect&  operator=(Bidirect const& rhs);

            bool operator==(Bidirect const& rhs);
            bool operator!=(Bidirect const& rhs);
            Bidirect<T>& operator++();
            Bidirect<T>  operator++(int);
            Bidirect<T>& operator--();
            Bidirect<T>  operator--(int);

            reference operator*() const;
            pointer operator->() const;

        protected:
            T       *_val;
    };
}

#endif