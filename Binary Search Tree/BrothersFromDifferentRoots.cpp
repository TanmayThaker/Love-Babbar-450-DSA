
//Practice link : https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#
// Video link : https://www.youtube.com/watch?v=h7uGc48yb14&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=13


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
int c; //counter
bool fetch(Node* root2,int k)
{
    if(!root2) return false;
    if(root2->data==k) return true;
    bool x,y;
    x=false;
    y=false;
    if(k<root2->data) x=fetch(root2->left,k);
    else if(k>root2->data) y=fetch(root2->right,k);
    return x or y;
}

void solve(Node* root1,Node* root2,int k)
{
    if(!root1) return;
    solve(root1->left,root2,k);
    if(fetch(root2,k-root1->data)) 
    {
        c++;
    }
    solve(root1->right,root2,k);
}
// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    c=0;
    solve(root1,root2,x);
    return c;
}

/*
TC : O(N*H)
SC : O(1)
*/