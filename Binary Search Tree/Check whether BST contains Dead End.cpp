//Check whether BST contains Dead End
//Practice link : https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
//Video link : https://www.youtube.com/watch?v=eZMCRBrMznA&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=17

//--------------------------------------------------------------------------------------------------------------------------------------------

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/


bool solve(Node* root,int low,int up)
{
    if(!root) return false;
    if(low==up) return true;
    return solve(root->left,low,root->data-1) or solve(root->right,root->data+1,up);
}
/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    solve(root,1,INT_MAX);
}


/*
TC : O(N)
SC : O(1)
*/