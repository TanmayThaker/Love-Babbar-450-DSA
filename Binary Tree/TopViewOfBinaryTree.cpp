/*
Top View of Binary Tree 
Medium Accuracy: 32.3% Submissions: 68868 Points: 4
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105*/






class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> m;
        vector<int> ans;
        queue<pair<Node*,int>> q;
        if(!root) return ans;
        q.push({root,0});
        while(!q.empty()){
            Node *t=q.front().first;
            int h=q.front().second;
            q.pop();
            if(!m[h]) m[h]=t->data;
            if(t->left) q.push({t->left,h-1});
            if(t->right) q.push({t->right,h+1});
        }
        for(auto x:m) ans.push_back(x.second);
        return ans;
    }

};