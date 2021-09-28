/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:19:19 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/28 17:29:17 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAP_CLASS_HPP
# define MAP_CLASS_HPP
# include <memory>
# include <map>
# include <utility>
# include "RandAccess.hpp"
# include "Reverse.hpp"
# include <iterator>

namespace ft 
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> > 
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef std::pair<const key_type,mapped_type>       value_type;
            typedef Compare                                     key_compare;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::refence            reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;
            typedef ptrdiff_t                                   difference_type;

        class iterator : public Bidirect<value_type>
        {
            public:
                typedef value_type&         reference;
                typedef value_type const&   reference;
                typedef value_type*         pointer;
                typedef ptrdiff_t           difference_type;

            public : 
                iterator();
                iterator(T *src);
                iterator(iterator const& src);
                iterator(const Bidirect<value_type>& src);
                virtual ~iterator();

                iterator& operator++();
                iterator  opeator++(int);
                iterator& operator--();
                iterator  operator--(int);
    
                reference operator*() const;
                pointer   operator->() const;
        };

        class const_iterator : public Bidirect<value_tpe>
        {
            public:
                typedef value_type&         reference;
                typedef value_type const&   reference;
                typedef value_type*         pointer;
                typedef ptrdiff_t           difference_type;

            public : 
                const_iterator();
                const_iterator(T *src);
                const_iterator(iterator const& src);
                const_iterator(const Bidirect<value_type>& src);
                virtual ~const_iterator();

                const_iterator& operator++();
                const_iterator  opeator++(int);
                const_iterator& operator--();
                const_iterator  operator--(int);
    
                reference operator*() const;
                pointer   operator->() const;
        };

        public:
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

        public:
            //Member functions
                //Constructors
                explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
                template <class InputIterator>
                        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
                map (const map& x);
                
                // Destructor
                ~map();

                //Operator=
                map& operator= (const map& x);

                //Iterators
                iterator begin();
                const_iterator begin() const;
                iterator end();
                const_iterator end() const;
                reverse_iterator rbegin();
                const_reverse_iterator rbegin() const;
                reverse_iterator rend();
                const_reverse_iterator rend() const;

                //Capacity
                bool empty() const;
                size_type size() const;
                size_type max_size() const;

                //Element Access
                mapped_type& operator[] (const key_type& k);

                //Modifiers
                pair<iterator,bool> insert (const value_type& val);
                iterator insert (iterator position, const value_type& val);
                template <class InputIterator>
                    void insert (InputIterator first, InputIterator last);
                
                void erase (iterator position);
                size_type erase (const key_type& k);
                void erase (iterator first, iterator last);

                void swap (map& x);
                void clear();

                //Observers
                key_compare key_comp() const;
                value_compare value_comp() const;
                
                //Operation
                iterator find (const key_type& k);
                const_iterator find (const key_type& k) const;
                size_type count (const key_type& k) const;
                iterator lower_bound (const key_type& k);
                const_iterator lower_bound (const key_type& k) const;
                iterator upper_bound (const key_type& k);
                const_iterator upper_bound (const key_type& k) const;
                pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
                pair<iterator,iterator>             equal_range (const key_type& k);

                //Allocator
                allocator_type get_allocator() const;
    };
}
#endif