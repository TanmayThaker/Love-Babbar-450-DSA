//Populate Inorder Successor for all nodes
//Practice link : https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
//Video link : https://www.youtube.com/watch?v=W25l6evkk_U&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=7

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:
    void func(Node* root,Node* &prev)
    {
        if(!root) return;
        func(root->left,prev);
        if(prev!=NULL)
        {
            prev->next=root;
        }
        prev=root;
        func(root->right,prev);
    }
    void populateNext(Node *root)
    {
        //code here
        Node *prev=NULL;
        func(root,prev);
    }
};

/*
TC : O(n) 'n' because we are traversing all the nodes
SC : O(h)  h is the height of the tree.
*/