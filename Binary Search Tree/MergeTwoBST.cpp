//Practice link : https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
//Video link : https://www.youtube.com/watch?v=6S-dGFwiG2Y

/*
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
class Solution
{
    public:
    void findInorder(Node* root,vector<int> &vc)
    {
        if(!root) return;
        findInorder(root->left,vc);
        vc.push_back(root->data);
        findInorder(root->right,vc);
    }
 
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> t1;
       vector<int> t2;
       vector<int> ans;
       findInorder(root1,t1);
       findInorder(root2,t2);
       
       int p1=0,p2=0;
       
       t1.push_back(INT_MAX);
       t2.push_back(INT_MAX);
       
       //Merge two vectors present in sorted form into a new vector
       while(p1<t1.size()-1 || p2<t2.size()-1 )
       {
           if(t1[p1]<t2[p2])
           {
               ans.push_back(t1[p1]);
               p1++;
           }
           else
           {
               ans.push_back(t2[p2]);
               p2++;
           }
       }
        return ans;
    }
};

/*
TC : O(N+M)
SC : O(N+M)
*/