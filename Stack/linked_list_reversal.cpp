#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

void Reverse(Node* head)
{
    stack<Node*> S;
    // to push nodes in stack
    while(head != NULL)
    {
        S.push(head);
        head = head->link;
    }

    while(!S.empty())
    {
        cout<< S.top()->data <<" ";
        S.pop();
    }
}

int main()
{
    
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    node1->data = 10;
    node1->link = node2;

    node2->data = 20;
    node2->link = node3;
  
    node3->data = 30;
    node3->link = NULL;

    Reverse(node1);

}