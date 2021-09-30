#include "test_bst_func.hpp"

int main()
{
    BST tree = BST();
    Node *root = NULL;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 70);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    std::cout << "Inorder traversal of the given tree \n";
    tree.PrintInOrder(root);
 
    std::cout << "\nDelete 20\n";
    root = tree.delete_node(root, 20);
    std::cout << "Inorder traversal of the modified tree \n";
    tree.PrintInOrder(root);
 
    std::cout << "\nDelete 30\n";
    root = tree.delete_node(root, 30);
    std::cout << "Inorder traversal of the modified tree \n";
    tree.PrintInOrder(root);
 
    std::cout << "\nDelete 50\n";
    root = tree.delete_node(root, 50);
    std::cout << "Inorder traversal of the modified tree \n";
    tree.PrintInOrder(root);
 
    return 0;
}
