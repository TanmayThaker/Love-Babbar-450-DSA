//Practice link:
//GFG ACCEPTED SOLUTION:
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node * root)
    {
        // code here
        queue<Node*> q;
        q.push(root);
        bool nullish=false;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
            {
                if(nullish || temp->left->data>=temp->data)
                {
                    return false;
                }
                q.push(temp->left);
            }
            else{
                nullish=true; //this is the leaf node as no further node exists on left child
            }
    
            if(temp->right)
            {
                if(nullish || temp->right->data>=temp->data)
                {
                    return false;
                }
                q.push(temp->right);
            }
            else{
                nullish=true;
            }
        }
        return true;
        }
};

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if(ob.isHeap(root))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }


    return 0;
}  // } Driver Code Ends






//-------------------------------------------------------------------------------------------------------------------------

//Check if a given Binary Tree is Heap
//Iterative solution or level order traversal

#include <bits/stdc++.h>
 
using namespace std;
 
// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
// To add a new node
struct Node* newNode(int k)
{
    struct Node* node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}
 
 bool isHeap(Node* root)
 {
    queue<Node*> q;
    q.push(root);
    bool nullish=false;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left)
        {
            if(nullish || temp->left->data>=temp->data)
            {
                return false;
            }
            q.push(temp->left);
        }
        else{
            nullish=true; //this is the leaf node as no further node exists on left child
        }

        if(temp->right)
        {
            if(nullish || temp->right->data>=temp->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else{
            nullish=true;
        }
    }
    return true;
 }

 int main()
{
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
 
    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
 
    return 0;
}

//Recursive Solution
/*Approach
Given a binary tree, we need to check it has heap property or not, Binary tree need to fulfill the following two conditions for being a heap – 

It should be a complete tree (i.e. all levels except last should be full).
Every node’s value should be greater than or equal to its child node (considering max-heap).


Every Node can have 2 children, 0 child (last level nodes) or 1 child (there can be at most one such node).
If Node has No child then it’s a leaf node and returns true (Base case)
If Node has one child (it must be left child because it is a complete tree) then we need to compare this node with its single child only.
If the Node has both child then check heap property at Node at recur for both subtrees. 
Complete code
*/
 
#include <bits/stdc++.h>
 
using namespace std;
  
/*  Tree node structure */
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};
  
/* Helper function that
allocates a new node */
struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

unsigned int countNodes(struct Node* root)
{
    if(root==NULL)
    {
        return (0);
    }
    return (1+countNodes(root->left)+countNodes(root->right));
}

//Function to check if a Binary Tree is Complete or not

bool isComplete(struct Node* root,unsigned int index, unsigned int number_nodes)
{
    if(root==NULL)
    {
        return true;
    }

    //If index assigned to current node is more than number of nodes in a tree
    //then tree is not complete

    if(index>=number_nodes)
    {
        return false;
    }
    //Recur for left and right subtrees
    return (isComplete(root->left,2*index+1,number_nodes) and isComplete(root->right,2*index+2,number_nodes));
}


//Function to check heapify property in the tree

bool isHeapUtil(struct Node* root)
{
    //base case i.e. single node i.e. the root node
    if(root->left==NULL and root->right==NULL)
    {
        return true;
    }

    if(root->right==NULL)
    {
        return (root->key >=root->left->key);
    }
    else{
        //  Check heap property at Node and
        //  Recursive check heap
        // property at left and right subtree
        if(root->key>=root->left->key and root->key>=root->right->key)
        {
            return ((isHeapUtil(root->left)) &&
                    (isHeapUtil(root->right)));
        }
        else{
            return false;
        }
    }

}

bool isHeap(struct Node* root)
{
    // These two are used
    // in isCompleteUtil()
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
  
    if (isCompleteUtil(root, index,
                       node_count)
        && isHeapUtil(root))
        return true;
    return false;
}

int main()
{
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
  
    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
  
    return 0;
}