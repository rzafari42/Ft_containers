/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:01:55 by rzafari           #+#    #+#             */
/*   Updated: 2021/09/29 11:35:25 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
#include "stack_class.hpp"

namespace ft
{
    template < class T, class Container >
    stack<T, Container>::stack(const container_type& ctnr) : _ctnr(ctnr) {}

    template < class T, class Container >
    stack<T, Container>::~stack()
    {
        return ;
    }

    template < class T, class Container >
    bool stack<T, Container>::empty() const
    {
        return _ctnr.empty();
    }

    template < class T, class Container >
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return _ctnr.size();
    }

    template < class T, class Container >
    typename stack<T, Container>::value_type& stack<T, Container>::top()
    {
        return _ctnr.back();
    }

    template < class T, class Container >
    const typename stack<T, Container>::value_type&  stack<T, Container>::top() const
    {
        return _ctnr.back();
    }

    template < class T, class Container >
    void stack<T, Container>::push(const value_type& val)
    {
        return _ctnr.push_back(val);
    }

    template <class T, class Container >
    void stack<T, Container>::pop()
    {
        return _ctnr.pop_back();
    }

    template <class T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr == rhs._ctnr;
    }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr != rhs._ctnr;
    }

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr < rhs._ctnr;
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr <= rhs._ctnr;
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr > rhs._ctnr;
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._ctnr >= rhs._ctnr;
    }

}

#endif
