/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:13:12 by rzafari           #+#    #+#             */
/*   Updated: 2021/07/28 20:00:48 by rzafari          ###   ########.fr       */
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
            typedef Alloc  allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;

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
                    size_type size() const;
                    size_type max_size() const;
                    void resize (size_type n, value_type val = value_type());
                    size_type capacity() const;
                    bool empty() const;
                    void reserve (size_type n);

                    //Element Access
                    reference operator[] (size_type n);
                    const_reference operator[] (size_type n) const;
                    reference at (size_type n);
                    const_reference at (size_type n) const;
                    reference front();
                    const_reference front() const;
                    reference back();
                    const_reference back() const;

                    //Modifiers
                    template <class InputIterator>
                        void assign (InputIterator first, InputIterator last);
                    void assign (size_type n, const value_type& val);
                    void push_back (const value_type& val);
                    void pop_back();
                    iterator insert (iterator position, const value_type& val);	
                    void insert (iterator position, size_type n, const value_type& val);	
                    template <class InputIterator>
                        void insert (iterator position, InputIterator first, InputIterator last);
                    iterator erase (iterator position);
                    iterator erase (iterator first, iterator last);
                    void swap (vector& x);
                    void clear();

                    //Allocator
                    allocator_type get_allocator() const;
            
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
    };
}

#endif
