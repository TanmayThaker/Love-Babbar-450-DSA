/*Height of Binary Tree 
Easy Accuracy: 65.76% Submissions: 88037 Points: 2
Given a binary tree, find its height.


Example 1:

Input:
      1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

*/

//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(!node) return 0;
        int x=height(node->left);
        int y=height(node->right);
        return max(x,y)+1;
    }
};