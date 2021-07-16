//Practice link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
//Video link : https://www.youtube.com/watch?v=DfIoVCQ2Lvg&t=66s

/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void solve(Node* root,int K,int &counter,int &ans)
    {
        if(!root) return;
        solve(root->right,K,counter,ans);
        if(K==counter)
        {
            ans=root->data;
            counter++;
            return;
        }
        else
        {
            counter++;
        }
        solve(root->left,K,counter,ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans=-1;
        int counter=1;
        solve(root,K,counter,ans);
        return ans;
    }
};

/*
TC : O(K) 
SC : O(h)
*/