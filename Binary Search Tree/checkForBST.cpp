//Practice link : https://practice.geeksforgeeks.org/problems/check-for-bst/1
//Video link : https://www.youtube.com/watch?v=Zh38jz-y7P0&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=7

class Solution
{
    public:
    void func(Node *root,Node* &prev,int &f)
    {
        if(!root) return;
        func(root->left,prev,f);
        if(prev!=NULL and root->data<=prev->data)
        {
            f=0;
            return;
        }
        prev=root;
        func(root->right,prev,f);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        int f=1;
        Node *prev=NULL;
        func(root,prev,f);
        return f;
    }
};


/*
TC : O(n) 'n' because we are traversing all the nodes
SC : O(h)  h is the height of the tree.
*/