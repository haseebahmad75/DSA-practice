#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/*Count the nodes in the left subtree.

Count the nodes in the right subtree.

The total size is left_size + right_size + 1 (the +1 represents the current node). */

int sizeOfTree(Node* root)
{
    if(root == nullptr) return 0;

    int leftSubtree = sizeOfTree(root->left);
    int rightSubtree = sizeOfTree(root->right);

    return leftSubtree + rightSubtree + 1;
}

void preOrder(Node* root)
{
    if(root == nullptr) return;
    cout<<root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->right = new Node(4);
    root->right->right = new Node(5);

    cout<<"Size of tree: " <<sizeOfTree(root) <<endl;
    cout<<"PreOrder traversal of tree: ";
    preOrder(root);
}