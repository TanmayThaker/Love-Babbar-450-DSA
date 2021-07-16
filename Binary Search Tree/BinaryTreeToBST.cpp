// Practice link : https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#
//Video link : https://www.youtube.com/watch?v=8AnntMKIWlQ&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=9

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    void inorder(Node *root,vector<int> &v)
    {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void inorder_bst(Node *root,vector<int> &v,int &i)
    {
        if(!root) return;
        inorder_bst(root->left,v,i);
        root->data=v[i];
        i++;
        inorder_bst(root->right,v,i);
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int i=0;
        inorder_bst(root,v,i);
        return root;
    }
};

/*
Time Complexity: O(NLogN).
Auxiliary Space: O(N).
*/