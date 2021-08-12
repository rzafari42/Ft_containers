/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:13:12 by rzafari           #+#    #+#             */
/*   Updated: 2021/08/12 20:27:54 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP
# include <memory>
# include <vector>
# include "../utils.hpp"

namespace ft_
{

    /*template<typename Vector>
    class VectorIterator
    {
        public:
            using value_type = typename Vector::value_type;
		    using ReferenceType
            typedef typename allocator_type::difference_type    difference_type;

            vectorIterator(void);
            vectorIterator(vectorIterator const & src);
            vectorIterator &operator=(vectorIterator const& rhs);
            ~vectorIterator(void);


            iterator        operator++(int);
            iterator&       operator++(void);
            iterator        operator--(int);
            iterator&       operator--(void);
            iterator&       operator+= (difference_type n);
            iterator&       operator-= (difference_type n);
            iterator        operator+(difference_type n) const;
            iterator        operator+(difference_type n, const iterator &rhs);
            iterator        operator-(difference_type n) const;
            bool            operator==(const iterator& rhs) const;
            bool            operator!=(const iterator& rhs) const;
            bool            operator>(const iterator& rhs) const;
            bool            operator<(const iterator& rhs) const;
            bool            operator>=(const iterator& rhs) const;
            bool            operator<=(const iterator& rhs) const;
            pointer         operator->(void) const;
            reference       operator*(void) const;
            reference       operator[](difference_type n) const;
            difference_type		operator-(const RandIte<value_type> &n) const { return super::operator-(n); };
    };*/

    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef pointer                                     iterator;
            typedef const_pointer                               const_iterator;
            //typedef ft_::reverse_iterator<iterator>          reverse_iterator;
            //typedef ft_::reverse_iterator<const_iterator>    const_reverse_iterator;

        public:
            //Member Functions
                //Contructors
                explicit vector(const allocator_type& alloc = allocator_type());
                explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
                template <class InputIterator>
                    vector(typename ft_::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type());
                vector(const vector& x);

                //Destructor
                ~vector();

                //operator=
                vector& operator=(const vector& x);

                //Iterators
                iterator                begin(void);
                const_iterator          begin(void) const;
                iterator                end(void);
                const_iterator          end(void) const;
                reverse_iterator        rbegin(void);
                const_reverse_iterator  rbegin(void) const;
                reverse_iterator        rend(void);
                const_reverse_iterator  rend(void) const;

                //Capacity
                size_type   size(void) const;
                size_type   max_size(void) const;
                size_type   capacity(void) const;
                bool        empty(void) const;
               /*(1)*/ void        resize(size_type n, value_type val = value_type());
               /*(2)*/ void        reserve(size_type n);

                //Element Access
                reference       operator[](size_type n);
                const_reference operator[](size_type n) const;
                reference       at(size_type n);
                const_reference at(size_type n) const;
                reference       front(void);
                const_reference front(void) const;
                reference       back(void);
                const_reference back(void) const;

                //Modifiers
                template <class InputIterator>
                    void        assign(InputIterator first, InputIterator last);
                void            assign(size_type n, const value_type& val);
                void            push_back(const value_type& val);
                void            pop_back(void);
                iterator        insert(iterator position, const value_type& val);	
                void            insert(iterator position, size_type n, const value_type& val);	
                template <class InputIterator>
                    void        insert(iterator position, InputIterator first, InputIterator last);
                iterator        erase(iterator position);
                iterator        erase(iterator first, iterator last);
                void            swap(vector& x);
                void            clear(void);

                //Allocator
                allocator_type get_allocator() const;

        private:
            T*          _data;
            Allocator   _allocator;
            size_type   _size;
            size_type   _capacity;
    };

    //Non-member function overloads
    //relational operators
    template <class T, class Alloc>
        bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
        bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    //Swap
    template <class T, class Alloc>
        void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif