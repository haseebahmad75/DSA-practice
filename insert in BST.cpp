#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {} // constructor to initialize struct members
};

Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return new Node(value); // creates a new node and return its address
    }

    if(value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrder(Node*root)
{
    if(root == nullptr) return; // root acts as root of whole tree, when this function is called 1st time, and then act as the root of a subtree
    inOrder(root->left); // explore everything smaller(left)
    cout<<root->data <<" "; // print the current node
    inOrder(root->right); // explore everyrthing larger(right)
}

int main()
{
    Node* root = nullptr;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    cout<< "Sorted tree (inOrder): ";
    inOrder(root);
    return 0;
}



