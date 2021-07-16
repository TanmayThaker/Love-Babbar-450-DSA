//Convert Normal BST into a Balanced BST
//Video link : https://www.youtube.com/watch?v=ceGBg3g18js&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=10

vector<Node*> inorder; //This vector stored the inorder traversal of the tree
int start=0;
int end=0;

Node* solve(int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=inorder[mid];

    root->left=solve(start,mid-1);
    root->right=solve(mid+1,end);

    return root;
}
/*
TC : O(N) // We are traversing to all the nodes of the tree
SC : O(N) We are storing inorder traversal in an array
*/
