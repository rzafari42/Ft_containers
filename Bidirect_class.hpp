/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirect_class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/13 11:39:03 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECT_CLASS_HPP
# define BIDIRECT_CLASS_HPP
# include <iterator>

namespace ft
{
    template < class T, typename node >
    class MapIter
    {
        protected:
            T       *_val;
            node    *node;

        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef value_type const&   const_reference;
            typedef value_type*         pointer;
            typedef ptrdiff_t           difference_type;
            typedef node*               node_ptr;

            MapIter();
            MapIter(MapIter const& src);
            virtual ~MapIter();
            MapIter&  operator=(MapIter const& rhs);

            bool operator==(MapIter const& rhs);
            bool operator!=(MapIter const& rhs);
            MapIter<T, node>& operator++();
            MapIter<T, node>  operator++(int);
            MapIter<T, node>& operator--();
            MapIter<T, node>  operator--(int);

            reference operator*() const;
            pointer operator->() const;
    };
}

#endif