/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:19:19 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/11 13:32:06 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAP_CLASS_HPP
# define MAP_CLASS_HPP
# include <memory>
# include <utility>
# include "RandAccess.hpp"
# include "Reverse.hpp"
# include "Bidirect.hpp"
# include <iterator>
# include "utils.hpp"
# include <map>

namespace ft 
{

    ////////////////////////
    //        NODE       //
    ///////////////////////
    template<class T>
    struct Node
    {
        T       key;
        Node    *right;
        Node    *left;
        Node    *parent;
    };


    ////////////////////////
    //        LESS       //
    ///////////////////////
    template <class T> 
    struct less : binary_function <T,T,bool> 
    {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };
    
    ////////////////////////
    //        PAIR       //
    ///////////////////////
    template < class T1, class T2 >
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type  first;
        second_type second;

        pair() : first(), second() { return ;}
        template<class U, class V>
            pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {return;}
        pair (const first_type& a, const second_type& b) : first(a), second(b) { return; }

        pair& operator= (const pair& pr) {first = pr.first; second = pr.second; return *this; }
    };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first = rhs.first && lhs.second = rhs.second);}

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first != rhs.first && lhs.second != rhs.second);}

    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first < rhs.second && lhs.second < rhs.second);}

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first <= rhs.second && lhs.second <= rhs.second);}

    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first > rhs.second && lhs.second > rhs.second);}

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first >= rhs.second && lhs.second >= rhs.second);}





    ////////////////////////
    //        MAP        //
    ///////////////////////

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const key_type, mapped_type>			value_type;
            typedef Compare                                     key_compare;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::refence            reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;
            typedef ptrdiff_t                                   difference_type;
            typedef Node<value_type>                            node_type;
            typedef node_type*                                  node_ptr;

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
                bool operator() (const value_tye& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };

        class iterator : public Bidirect<value_type>
        {
            public:
                typedef value_type&         reference;
                typedef value_type const&   const_reference;
                typedef value_type*         pointer;
                typedef ptrdiff_t           difference_type;

            public : 
                iterator();
                iterator(T *src);
                iterator(iterator const& src);
                iterator(const Bidirect<value_type>& src);
                virtual ~iterator();

                iterator& operator++();
                iterator  operator++(int);
                iterator& operator--();
                iterator  operator--(int);
    
                reference operator*() const;
                pointer   operator->() const;
        };

        class const_iterator : public Bidirect<value_tpe>
        {
            public:
                typedef value_type const&   reference;
                typedef value_type const&   const_reference;
                typedef value_type const*   pointer;
                typedef ptrdiff_t           difference_type;

            public : 
                const_iterator();
                const_iterator(T *src);
                const_iterator(iterator const& src);
                const_iterator(const Bidirect<value_type>& src);
                virtual ~const_iterator();

                const_iterator& operator++();
                const_iterator  operator++(int);
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
                node_ptr newNode(int value);
                node_ptr insertNode(node_ptr node, int key);
                void     PrintInOrder(node_ptr node);
                node_ptr min_node(node_ptr node);
                node_ptr max_node(node_ptr node);
                node_ptr delete_node(node_ptr node, int key);

        private:
            T*                                          _data;
            allocator_type                              _alloc;
            size_type                                   _size;
            size_type                                   _max_size;
            key_compare                                 _comp;
            std::allocator<node_type>                   _node_alloc;
            node_ptr                                    _root;
            node_ptr                                    _ghost;
    };


}
#endif