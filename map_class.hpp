/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:19:19 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/10 18:12:20 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAP_CLASS_HPP
# define MAP_CLASS_HPP
# include <memory>
# include <utility>
# include <iostream>
# include "RandAccessIter.hpp"
# include "ReverseIter.hpp"
# include "MapIter.hpp"
# include "utils.hpp"
# include <iterator>

namespace ft 
{
    ////////////////////////
    //        LESS       //
    ///////////////////////
    template <class T> 
    struct less : std::binary_function <T,T,bool> 
    {
        bool operator() (const T& x, const T& y) const {return x < y;}
    };

    ////////////////////////
    //        PAIR       //
    ///////////////////////
   template <class T1, class T2> 
   struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void) : first(), second() { return; };
		template<class U, class V>
		    pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { return; };
		pair(const first_type& a, const second_type& b) : first(a), second(b) { return; };
		pair& operator=(const pair& pr) { first = pr.first; second = pr.second; return *this; };
	};

    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    { 
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };

    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    };

    template <class T1, class T2>
    bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first && lhs.second < rhs.second);
    };

    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first <= rhs.first && lhs.second <= rhs.second);
    };

    template <class T1, class T2>
    bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first > rhs.first && lhs.second > rhs.second);
    };

    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
    {
        return (lhs.first >= rhs.first && lhs.second >= rhs.second); 
    };

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y) 
    {
        return (pair<T1,T2>(x,y) );
    };

    template< class T1, class T2 >
    std::ostream & operator<<( std::ostream & flux, ft::pair<T1, T2> const & rhs)
    {
        flux << rhs.second << std::endl;
        return flux;
    }

    ////////////////////////
    //        MAP        //
    ///////////////////////

    template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public:
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef pair<const key_type, mapped_type>			                value_type;
            typedef Compare                                                     key_compare;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef ptrdiff_t                                                   difference_type;
            typedef size_t                                                      size_type;
            typedef ft::Node<value_type>                                        node_type;
            typedef node_type*                                                  node_ptr;
            typedef typename allocator_type::template rebind<node_type>::other  _new;

            //Iterators
            typedef ft::MapIter<value_type, node_type>          iterator;
            typedef ft::MapIter<const value_type, node_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;


            class value_compare
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {};

                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const 
                    {
                        return comp(x.first, y.first);
                    }
            };

            //Member functions
                //Constructors
                explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
                template <class InputIterator>
                        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
                map (const map& x);
                
                // Destructor
                ~map();

                //Operator=
                map& operator=(const map& x);

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
                pair<iterator,bool> insert(const value_type& val);
                iterator insert (iterator position, const value_type& val);
                template <class InputIterator>
                    void insert (InputIterator first, InputIterator last);

                void erase(iterator position);
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
                const_iterator upper_bound (const key_type& k ) const;
                pair<iterator,iterator>             equal_range (const key_type& k);
                pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

                //Allocator
                allocator_type get_allocator() const;

                //Binary Search Tree specific functions
                node_ptr newNode(value_type &data);
                void createGhost(bool add);
                node_ptr insertNode(node_ptr node, value_type data);
                void _setGhost(bool add);
                node_ptr delete_node(node_ptr node, value_type data);
                void     PrintInOrder(node_ptr node);

        private:
            allocator_type                              _alloc;
            size_type                                   _size;
            size_type                                   _max_size;
            key_compare                                 _comp;
            std::allocator<node_type>                   _node_alloc;
            node_ptr                                    _root;
            node_ptr                                    _ghost;
            node_ptr                                    _GreatestData;
        
         public:
            node_ptr    get_root(){ return this->_root;};
    };

    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs == rhs)
            return false;
        return true;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), --lhs.end(), rhs.begin(), --rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    void	swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
    {
        lhs.swap(rhs);
    }
}
#endif