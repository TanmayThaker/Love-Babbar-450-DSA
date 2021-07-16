
//Practice link : https://practice.geeksforgeeks.org/problems/largest-bst/1
//Video link : https://www.youtube.com/watch?v=6nJ_fUcCTNU

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

vector<int> solve(Node* root)
{
    if(!root) return {1,0,INT_MAX,INT_MIN};
    if(!root->left and !root->right) return {1,1,root->data,root->data};
    
    vector<int> left=solve(root->left);
    vector<int> right=solve(root->right);
    
    if(left[0] and right[0])
    {
        if(root->data>left[3] and root->data<right[2])
        {
            int x=left[2];
            int y=right[3];
            if(x==INT_MAX) x=root->data;
            if(y==INT_MIN) y=root->data;
            return {1,left[1]+right[1]+1,x,y};
        }
    }
    return {0,max(left[1],right[1]),0,0};
}


/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
	//Your code here
	vector<int> ans=solve(root);
	return ans[1];
}

/*
TC : O(N)
SC : O(N)
*/