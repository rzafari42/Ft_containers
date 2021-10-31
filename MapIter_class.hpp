/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIter_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:34:57 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/26 11:41:09 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITER_CLASS_HPP
# define MAPITER_CLASS_HPP
# include "utils.hpp"
# include "map_class.hpp"

namespace ft
{
    template < class T, typename Node >
    class MapIter
    {
        protected:
            Node    *_node;

        public:
            typedef T                   value_type;
            typedef value_type&         reference;
            typedef value_type const&   const_reference;
            typedef value_type*         pointer;
            typedef ptrdiff_t           difference_type;
            typedef Node*               node_ptr;

            MapIter();
            MapIter(MapIter const& src);
            MapIter(Node *src);
            virtual ~MapIter();
            MapIter&  operator=(MapIter const& rhs);


            bool operator==(MapIter const& rhs);
            bool operator!=(MapIter const& rhs);
            MapIter& operator++();
            MapIter operator++(int);
            MapIter& operator--();
            MapIter operator--(int);

            reference operator*() const;
            pointer operator->() const;

            template <class, class, class, class>
            friend class map;
            template <class, class>
            friend class MapIter;
    };
}

#endif