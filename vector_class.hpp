/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:13:12 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/09 15:37:48 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
# include <memory>
# include <vector> //To withdraw before pushing on the vogsphere
//# include "Iterators/RandAccess_class.hpp"
//# include "Iterators/RandAccess.hpp"
# include "RandAccess_class.hpp"
# include "RandAccess.hpp"
//# include "Iterators/Reverse_class.hpp"
//# include "Iterators/Reverse.hpp"
# include "Reverse_class.hpp"
# include "Reverse.hpp"
# include "utils.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;
            typedef ptrdiff_t                                   difference_type;

        class iterator : public RandAccess<T>
        {
            public:
                iterator();
                iterator(T *src);
                iterator(const RandAccess<T>& src);
                iterator(iterator const& src);
                virtual ~iterator();
    
                reference       operator*() const;
                pointer         operator->() const;
                reference       operator[](size_type n) const;
                iterator&       operator+=(difference_type n);
                iterator&       operator-=(difference_type n);
        };

        class const_iterator : public RandAccess<T>
        {
            public:
		        const_iterator(T *src);
                const_iterator();
                const_iterator(const RandAccess<T> &src);
                virtual ~const_iterator();

                reference               operator*() const;
                pointer                 operator->() const;
                const_reference         operator[](size_type n) const;
                const_iterator&         operator+=(difference_type n);
                const_iterator&         operator-=(difference_type n);
        };

        public:
            typedef ft::reverse_iterator<iterator>             reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>       const_reverse_iterator;

        public:
            //Member Functions
                //Contructors
                explicit vector(const allocator_type& alloc = allocator_type());
                explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
                template <class InputIterator>
                    vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type());
                vector(const vector& x);

                //Destructor
                ~vector();

                //operator=
                vector& operator=(const vector& x);

                //Iterators
                iterator                begin();
                const_iterator          begin() const;
                iterator                end();
                const_iterator          end() const;
                reverse_iterator        rbegin();
                const_reverse_iterator  rbegin() const;
                reverse_iterator        rend();
                const_reverse_iterator  rend() const;

                //Capacity
                size_type   size() const;
                size_type   max_size() const;
                size_type   capacity() const;
                bool        empty() const;
               /*(1)*/ void        resize(size_type n, value_type val = value_type());
               /*(2)*/ void        reserve(size_type n);

                //Element Access
                reference       operator[](size_type n);
                const_reference operator[](size_type n) const;
                reference       at(size_type n);
                const_reference at(size_type n) const;
                reference       front();
                const_reference front() const;
                reference       back();
                const_reference back() const;

                //Modifiers
                template <class InputIterator>
                    void            assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);
                void            assign(size_type n, const value_type& val);
                void            push_back(const value_type& val);
                void            pop_back();
                iterator        insert(iterator position, const value_type& val);	
                void            insert(iterator position, size_type n, const value_type& val);	
                template <class InputIterator>
                    void        insert(iterator position, InputIterator first, InputIterator last);
                iterator        erase(iterator position);
                iterator        erase(iterator first, iterator last);
                void            swap(vector& x);
                void            clear();

                //Allocator
                allocator_type get_allocator() const;

        private:
            T*              _data;
            allocator_type  _alloc;
            size_type       _size;
            size_type       _capacity;
    };

    //Non-member function overloads
    //relational operators
    template <class T, class Alloc>
        bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    //Swap
    template <class T, class Alloc>
        void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif