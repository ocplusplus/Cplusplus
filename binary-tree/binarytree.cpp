#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IntBinaryTree.h"

using namespace std;

// Function to generate random numbers within a specified range
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(nullptr)); // Seed the random number generator

    IntBinaryTree tree;


    // Insert 20 random nodes into the binary tree
    for (int i = 0; i < 20; ++i) {
        int randomNumber = generateRandomNumber(1, 30);
        tree.insertNode(randomNumber);
    }

    // Display the tree using in-order traversal before showing the menu
    cout << "Binary Tree (In-order Traversal):\n";
    tree.displayInOrder(tree.root);
    cout << "\n\n";
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Display Inorder Traversal\n";
        cout << "2. Display Pre-order Traversal\n";
        cout << "3. Display Post-order Traversal\n";
        cout << "4. Delete a node within Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Inorder Traversal:\n";
            tree.displayInOrder(tree.root);
            break;
        case 2:
            cout << "Pre-order Traversal:\n";
            tree.displayPreOrder(tree.root);
            break;
        case 3:
            cout << "Post-order Traversal:\n";
            tree.displayPostOrder(tree.root);
            break;
        case 4:
            int valueToDelete;
            cout << "Enter the value of the node to delete: \n";
            cin >> valueToDelete;
            tree.deleteNode(valueToDelete, tree.root);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

// Default constructor
IntBinaryTree::IntBinaryTree() {
    root = nullptr;
}

// Function to insert a node into the binary tree
void IntBinaryTree::insertNode(int num) {
    TreeNode* newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    if (!root) {
        root = newNode;
    }
    else {
        TreeNode* temp = root;
        TreeNode* parent = nullptr;

        while (temp) {
            parent = temp;
            if (num < temp->value) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }

        if (num < parent->value) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
}

// Function to display nodes using in-order traversal
void IntBinaryTree::displayInOrder(TreeNode* nodePtr)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}


// Function to display nodes using pre-order traversal
void IntBinaryTree::displayPreOrder(TreeNode* nodePtr)
{
    if (nodePtr)
    {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

// Function to display nodes using post-order traversal
void IntBinaryTree::displayPostOrder(TreeNode* nodePtr)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}


// Function to delete a node with a given value
void IntBinaryTree::deleteNode(int num, TreeNode*& nodePtr) {
    if (nodePtr == nullptr) {
        cout << "Node with value " << num << " not found in the tree.\n";
        return;
    }

    if (num < nodePtr->value) {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->value) {
        deleteNode(num, nodePtr->right);
    }
    else {
        TreeNode* tempNode;

        if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
            tempNode = nodePtr;
            nodePtr = nullptr;
            delete tempNode;
        }
        else if (nodePtr->left == nullptr) {
            tempNode = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNode;
        }
        else if (nodePtr->right == nullptr) {
            tempNode = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNode;
        }
        else {
            tempNode = nodePtr->right;
            while (tempNode->left != nullptr) {
                tempNode = tempNode->left;
            }
            nodePtr->value = tempNode->value;
            deleteNode(tempNode->value, nodePtr->right);
        }
        cout << "Node with value " << num << " deleted from the tree.\n";
    }
}
