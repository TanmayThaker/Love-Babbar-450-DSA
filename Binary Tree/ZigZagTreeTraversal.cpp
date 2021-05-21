/*
ZigZag Tree Traversal 
Easy Accuracy: 49.78% Submissions: 30254 Points: 2
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 <= N <= 104



*/

//User function Template for C++
/*Structure of the node of the binary tree is as
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

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	int f=1;
	vector<int> ans;
	queue<Node*>q;
	if(!root) return ans;
	q.push(root);
	while(!q.empty()){
	    vector<int> temp;
	    int sz=q.size();

	    while(sz--){
	        Node *t=q.front();
	        temp.push_back(t->data);
	        q.pop();
	        if(t->left) q.push(t->left);
	        if(t->right) q.push(t->right);
	    }
	    if(f%2==0) reverse(temp.begin(),temp.end());
	    for(int i=0;i<temp.size();i++) ans.push_back(temp[i]);
	    f=!f;
	}
	return ans;
}