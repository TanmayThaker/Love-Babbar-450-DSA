//Lowest Common Ancestor in a BST
//Practice link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
//Video link : https://www.youtube.com/watch?v=dX1YKKBiClo&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=8

//Function to find the lowest common ancestor in a BST.
Node *LCA(Node *root, int n1, int n2)
{
    //Your code here
    if (!root)
        return NULL;
    if (n1 < root->data and n2 < root->data)
        return LCA(root->left, n1, n2);
    if (n1 > root->data and n2 > root->data)
        return LCA(root->right, n1, n2);
    else
        return root;
}

/*
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
*/