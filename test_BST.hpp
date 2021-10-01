/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_BST.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:44:26 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/01 14:42:54 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BST_HPP
# define TEST_BST_HPP
# include <iostream>


struct Node
{
    int key;
    Node *right;
    Node *left;
};

class BST
{
    public:
        BST();
        //BST(int value);
        ~BST();
        Node *newNode(int value);
        Node *insert(Node *node, int key);
        void PrintInOrder(Node *node);
        int min_node(Node *node);
        int max_node(Node *node);
        Node *delete_node(Node *node, int key);
};
#endif