#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree {
public:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    //Default Constructor
    IntBinaryTree();

    // Function declarations for the member functions
    void insertNode(int);
    void displayInOrder(TreeNode*);
    void displayPreOrder(TreeNode*);
    void displayPostOrder(TreeNode*);
    void deleteNode(int, TreeNode*&);


};

#endif // INTBINARYTREE_H
