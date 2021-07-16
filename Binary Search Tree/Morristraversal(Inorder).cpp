//Video link : https://www.youtube.com/watch?v=Bdhgc5tJDHE

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
    Node (int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
void inorder(Node *root)
{
    Node *curr=root;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            Node* temp=curr->left;
            Node* leftPointer=curr->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=curr;
            curr->left=NULL;
            curr=leftPointer;
        }
        else
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}
int main()
{
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    inorder(root);
}