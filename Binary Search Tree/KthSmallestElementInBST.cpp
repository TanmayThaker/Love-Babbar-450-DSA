//Kth Smallest element in BST
//Practice link : https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
//Video link : https://www.youtube.com/watch?v=DfIoVCQ2Lvg&t=66s
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

class Solution{
  public:
    void solve(Node* root,int K,int &counter,int &ans)
    {
        if(!root) return;
        solve(root->left,K,counter,ans);
        if(K==counter)
        {
            ans=root->data;
            //if u dry run the code with yourself 
            //then u find that if u not change counter in if condition then ,
            //when u returning in stack back then if condition again satisfied and our ans->data will be replaced
            counter++; //
            return;
        }
        else
        {
            counter++;
        }
        solve(root->right,K,counter,ans);
    }
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
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