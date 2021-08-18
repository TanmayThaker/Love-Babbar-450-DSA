//Convert BST to Min Heap
// Link : https://www.geeksforgeeks.org/convert-bst-min-heap/

#include <bits/stdc++.h>
using namespace std;
 
// structure of a node of BST
struct Node
{
    int data;
    Node *left, *right;
};

struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

//function prototype for preOrderTraversal
void preorderTraversal(Node*);

void inorderTraversal(Node* root,vector<int> &index)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->left,index);
    index.push_back(root->data);
    inorderTraversal(root->right,index);
}

void BSTToMinHeap(Node *root,vector<int> index,int *i)
{
    if(root==NULL)
    {
        return;
    }
    root->data = index[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, index, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, index, i);
}
void convertToMinHeapUtil(Node *root)
{
    vector<int> index;
    int i=-1;
    inorderTraversal(root, index);
    BSTToMinHeap(root,index,&i);
}


void preorderTraversal(Node *root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}

int main()
{
    // BST formation
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}