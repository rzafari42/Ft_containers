/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:39:49 by rzafari           #+#    #+#             */
/*   Updated: 2021/11/08 12:11:07 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP
# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;

            explicit            stack (const container_type& ctnr = container_type());
            virtual             ~stack();
            bool                empty() const;
            size_type           size() const;
            value_type&         top();
            const value_type&   top() const;
            void                push (const value_type& val);
            void                pop();

            friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._ctnr == rhs._ctnr; };
            friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs._ctnr < rhs._ctnr; };
        
        protected:
            container_type      _ctnr;
    };
    
    //Non-member function overloads
    //Relational operators
    template <class T, class Container>
        bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#endif