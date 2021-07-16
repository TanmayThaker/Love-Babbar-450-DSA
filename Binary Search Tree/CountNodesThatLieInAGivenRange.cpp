//Count BST Nodes That lie in a given Range
//Practice link : https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
// Video link : https://www.youtube.com/watch?v=Wt0h_RX35HY&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=16


//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here
  if(!root) return 0;
  if(root->data>=l and root->data<=h)
  {
    return 1+getCount(root->left,l,h)+getCount(root->right,l,h); 
  }
  else if(root->data<l)
  {
      return getCount(root->right,l,h);
  }
  else return getCount(root->left,l,h);
}

/*
 Time Complexity: O(N)
 Auxiliary Space: O(Height of the BST).
*/
