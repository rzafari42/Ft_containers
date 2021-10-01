/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst_func.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:48:40 by rzafari           #+#    #+#             */
/*   Updated: 2021/10/01 14:58:03 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BST_FUNC_HPP
# define TEST_BST_FUNC_HPP
# include "test_BST.hpp"
# include <memory>

 
BST::BST()
{
}

/*BST::BST(int value)
{
    _root->key = value;
    _root->left = _root->right = NULL;
}*/

BST::~BST()
{
}

Node *BST::newNode(int value)
{
    Node *node = new Node;
    node->key = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

Node *BST::insert(Node *node, int key)
{
    if (node == NULL)
        node = newNode(key);     
    if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    return node;    
}

void BST::PrintInOrder(Node *node)
{
    if (node)
    {
        PrintInOrder(node->left);
        std::cout << node->key << ' ';
        PrintInOrder(node->right);
    }
}

int BST::min_node(Node *node)
{
    Node* leftmost = node;

    while (leftmost && leftmost->left != NULL)
        leftmost = leftmost->left;
    return leftmost->key; 
}

int BST::max_node(Node *node)
{
    Node* rightmost = node;

    while (rightmost && rightmost->left != NULL)
        rightmost = rightmost->left;
    return rightmost->key; 
}

Node *BST::delete_node(Node *node, int key)
{
    if (node == NULL)
        return node;
    if (key > node->key)
    {
        node->right = delete_node(node->right, key);
        return node;
    }
    else if (key < node->key)
    {
        node->left = delete_node(node->left, key);
        return node;
    }

    if (node->left == NULL)
    {
        Node *tmp = node->right;
        delete node;
        return tmp;
    }
    else if (node->right == NULL)
    {
        Node *tmp = node->left;
        delete node;
        return tmp;
    }
    //2 Children case: Get the inOrder successor (smallest in the right subtree)
    else
    {
        Node *succParent = node;
        Node *succ = node->right;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succParent->left;  
        }
        if (succParent != node)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        node->key = succ->key; 
        delete succ;
        return node;
    }
   
    return node;
}

#endif