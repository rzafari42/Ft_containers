/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:16:49 by rzafari           #+#    #+#             */
/*   Updated: 2021/08/12 20:46:55 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>

namespace ft_
{
    template <bool, class _Tp = void>
    struct enable_if {};
    
    template <class _Tp>
    struct enable_if<true, _Tp>  {typedef _Tp type;};

    template <class InputIterator>
    size_t InputIterator_len(InputIterator first, InputIterator last)
    {
        for(size_t i = 0; first != last; first++)
            i++;
        return i;
    }
    
}

#endif