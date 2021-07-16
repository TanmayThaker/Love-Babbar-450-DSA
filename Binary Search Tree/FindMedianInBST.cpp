//Practice link : https://practice.geeksforgeeks.org/problems/median-of-bst/1
//Video link : https://www.youtube.com/watch?v=XIjko1AgEmM&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=14

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
void count_nodes(Node* root,int &n)
{
    if(!root) return;
    count_nodes(root->left,n);
    n++;
    count_nodes(root->right,n);
}
void func(Node* root,Node* &curr,Node* &prev,int &c,int k, int &f)
{
    if(!root) return;
    func(root->left,curr,prev,c,k,f);
    if(prev==NULL)
    {
        prev=root;
        c++;
    }
    else if(c==k)
    {
        c++;
        curr=root;
        f=1;
        return;
    }
    else if(f==0)
    {
        c++;
        prev=root;
    }
    func(root->right,curr,prev,c,k,f);
}
// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root)
{
      //Code here
    int n= 0;
    count_nodes(root,n);
    Node *prev=NULL;
    Node *curr=NULL;
    int c=1;
    int x=(n/2)+1;
    int f=0;
    func(root,curr,prev,c,x,f);
    if(n&1)
    {
        float ans=(curr->data)*1.0;
        return ans;
    }
    else
    {
        float ans=((curr->data+prev->data)*1.0)/(2*1.0);
        return ans;
    }
}