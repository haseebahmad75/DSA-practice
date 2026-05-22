#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* Insert(Node* root, int value)
{
    if(root == NULL)
    {
        return new Node(value);
    }

    if(value <= root->data)
    {
        root->left = Insert(root->left,value);
    }
    if(value > root->data)
    {
        root->right = Insert(root->right,value);
    }
    return root;

}

// Breadth-first Search
// Level order traversal of tree
void LevelOrder(Node* root)
{
    if(root == NULL) return;
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        Node* current = Q.front(); // returns the element at the front of queue
        cout<<current->data <<"  ";
        if(current->left != NULL) // pushing the children of this current node into the queue
        {
            Q.push(current->left);
        }
        if(current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop(); // removing the element at front of queue
    }
}

void PreOrder(Node* root)
{
    if(root == NULL) return;
    cout<<root->data <<"  ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    Node* root = NULL;
    root = Insert(root,1); // root stores the address of the inserted value, if we don't store the address, then next values won't be inserted
    Insert(root,2);
    Insert(root,3);
    Insert(root,4);
    Insert(root,5);
    Insert(root,6);

    cout<<"Level Order Traversal:  "; 
    LevelOrder(root);

    cout<<"\nPre-Order Traversal:  ";
    PreOrder(root);

}

