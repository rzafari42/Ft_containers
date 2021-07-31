/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:13:12 by rzafari           #+#    #+#             */
/*   Updated: 2021/07/31 18:06:14 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
# include <memory>

namespace ft_
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T           value_type;
            typedef Alloc       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ptrdiff_t   difference_type;
            typedef size_t      size_type;

        protected:
            Alloc __allocator; //copy of the allocator

        public:
            //Member Functions
                //Contructors
                explicit vector (const allocator_type& alloc = allocator_type());
                explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
                template <class InputIterator>
                        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
                vector (const vector& x);

                //Destructor
                ~vector();

                //operator=
                vector& operator= (const vector& x);

                class iterator
                {
                    iterator(void);
                    iterator(value_type *src);
                    iterator(iterator const& src);
                    ~iterator(void);
                    

                    bool operator==(const iterator& rhs) const;
                    bool operator!=(const iterator& rhs) const;
                    iterator operator++(int);
                    iterator& operator++(void);
                    iterator operator--(int);
                    iterator& operator--(void);
                    iterator& operator+= (difference_type n);
                    iterator& operator-= (difference_type n);
                    iterator operator+(difference_type n) const;
                    iterator operator+(difference_type n, const iterator &rhs);
                    iterator operator-(difference_type n) const;
                    bool operator>(const iterator& rhs) const;
                    bool operator<(const iterator& rhs) const;
                    bool operator>=(const iterator& rhs) const;
                    bool operator<=(const iterator& rhs) const;
                    reference operator*(void) const;
                    pointer operator->(void) const;
                    reference operator[] (difference_type n) const;                
                };
                //Iterators
                iterator begin(void);
                const_iterator begin(void) const;
                iterator end(void);
                const_iterator end(void) const;
                reverse_iterator rbegin(void);
                const_reverse_iterator rbegin(void) const;
                reverse_iterator rend(void);
                const_reverse_iterator rend(void) const;

                //Capacity
                size_type size(void) const;
                size_type max_size(void) const;
                void resize (size_type n, value_type val = value_type());
                size_type capacity(void) const;
                bool empty(void) const;
                void reserve (size_type n);

                //Element Access
                reference operator[] (size_type n);
                const_reference operator[] (size_type n) const;
                reference at (size_type n);
                const_reference at (size_type n) const;
                reference front(void);
                const_reference front(void) const;
                reference back(void);
                const_reference back(void) const;

                //Modifiers
                template <class InputIterator>
                    void assign (InputIterator first, InputIterator last);
                void assign (size_type n, const value_type& val);
                void push_back (const value_type& val);
                void pop_back(void);
                iterator insert (iterator position, const value_type& val);	
                void insert (iterator position, size_type n, const value_type& val);	
                template <class InputIterator>
                    void insert (iterator position, InputIterator first, InputIterator last);
                iterator erase (iterator position);
                iterator erase (iterator first, iterator last);
                void swap (vector& x);
                void clear(void);

                //Allocator
                allocator_type get_allocator() const;
    };

    //Non-member function overloads
    //relational operators
    template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    //Swap
    template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif