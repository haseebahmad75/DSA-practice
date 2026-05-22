#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return new Node(value);
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

int FindMin(Node* root)
{
    Node* current = root;
    while(current->left != NULL) // the leftmost node in a binary tree is the minimum
    {
        current = current->left;
    }
    return current->data;
}

int FindMax(Node* root)
{
    Node* current = root;
    while(current->right != NULL) // the rightmost node in a binary tree is the maximum
    {
        current = current->right;
    }
    return current->data;
}

int main()
{
    Node* root;
    root = NULL;

    root = insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,5);
    insert(root,10);
    insert(root,45);
    insert(root,50);

    cout<<"Minimum element in the tree: " <<FindMin(root) <<endl;
    cout<<"Maximum element in the tree: " <<FindMax(root) <<endl;
}