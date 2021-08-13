/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandAccess_class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:19:35 by rzafari           #+#    #+#             */
/*   Updated: 2021/08/13 19:07:33 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDACCESS_CLASS_HPP
# define RANDACCESS_CLASS_HPP

namespace ft_
{
    template < class T >
    class RandAccess
    {
        protected:
            RandAccess          *_val;

        public:
            typedef T&          reference;
            typedef T*          pointer;
            typedef ptrdiff_t   difference_type;

            RandAccess(void);
            RandAccess(RandAccess const& src);
            virtual ~RandAccess(void);
            RandAccess& operator=(RandAccess const& rhs);

            bool            operator==(RandAccess const& rhs) const;
            bool            operator!=(RandAccess const& rhs) const;
            bool            operator>(RandAccess const& rhs) const;
            bool            operator>=(RandAccess const& rhs) const;
            bool            operator<(RandAccess const& rhs) const;
            bool            operator<=(RandAccess const& rhs) const;

            RandAccess<T>&  operator++(void);
            RandAccess<T>   operator++(int);
            RandAccess<T>&  operator--(void);
            RandAccess<T>   operator--(int);
            RandAccess<T>   operator+(difference_type n) const;
            friend RandAccess<Spe>	operator+(difference_type n, const RandAccess &rhs) { return rhs.operator+(n); }
            RandAccess<T>   operator-(difference_type n) const;
            difference_type operator-(RandAccess const& n) const;
            RandAccess<T>&  operator+=(difference_type n);
            RandAccess<T>&  operator-=(difference_type n);

            pointer         operator->(void) const;
            reference       operator*(void) const;
            reference       operator[](difference_type n) const;
    };
}

#endif