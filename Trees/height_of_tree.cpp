#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int FindHeight(Node* root)
{
    if(root == nullptr) // this acts as root of tree of 1st iteration, and root of each subtree of next iterations
    return -1;

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(35);
    root->left->left = new Node(15);
    root->right->right = new Node(40);

    cout<<"Height of tree: " <<FindHeight(root);

}