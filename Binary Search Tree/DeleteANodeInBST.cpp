//Problem link : https://leetcode.com/problems/delete-node-in-a-bst/submissions/
//Video link : https://www.youtube.com/watch?v=NL1ocKYzlAM

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMax(TreeNode* root,int maximum)
    {
        while(root!=NULL)
        {
            maximum=max(maximum,root->val);
            root=root->right;
        }
        return maximum;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL) return NULL;
        if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            if(root->left!=NULL and root->right!=NULL)
            {
                int v=findMax(root->left,INT_MIN);
                root->val=v;
                root->left=deleteNode(root->left,v);
                return root;
            }
            else if(root->left!=NULL)
            {
                return root->left;
            }
            else if(root->right!=NULL)
            {
                return root->right;
            }
            else
            {
                return NULL;
            }
        }
        return root;
    }
};