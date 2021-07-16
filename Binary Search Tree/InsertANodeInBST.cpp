
//Problem link : https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

//Function to insert a node in a BST.
Node* insert(Node* root, int Key)
{
    // Your code here
    if(root==NULL)
    {
        Node *x = new Node(Key);
        return x;
    }
    if(Key>root->data)
    {
        root->right = insert(root->right,Key);
    }
    else if(Key<root->data)
    {
        root->left = insert(root->left,Key);
    }
    return root;
}
