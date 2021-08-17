/*
Naive Approach: Below is the step by step explanation of the naive approach to do this:



Write a recursive program for level order traversal of a tree.
Traverse each level of both the trees one by one and store the result of traversals in 2 different vectors, one for each tree.
Sort both the vectors and compare them iteratively for each level, if they are same for each level then return true else return false.
Time Complexity: O(n^2), where n is the number of nodes.
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};


bool areAnagrams(Node *root1,Node* root2)
{
    //base cases
    if(root1==NULL and root2==NULL)
    {
        return true;
    }
    if(root1==NULL or root2==NULL)
    {
        return false;
    }


    queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);

    while(true)
    {
        //n1 and n2 indicates the number of Nodes at each level of 
        //their respective binary tress
        int n1=q1.size();
        int n2=q2.size();

        if(n1!=n2)
        {
            return fasle;
        }

        if(n1==0) break;

        vector<int> curr_level1,curr_level2;
        while(n1>0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if(node1->left!=NULL)
            {
                q1.push(node1->left);
            }
            if (node1->right != NULL){
                q1.push(node1->right);
            }

            n1--;

            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL){
                q2.push(node2->left);
            }
                
            if (node2->right != NULL){
                q2.push(node2->right);
            }
       
            sort(curr_level1.begin(),curr_level1.end());
            sort(curr_level2.begin(),curr_level2.end());

            if(curr_level1!=curr_level2)
            {
                return false;
            }

            return true;

        }
    }
}


Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}