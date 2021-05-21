
//----------------------------------SOLUTION 1---------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d", &t);
    while (t--)
    {
            map<int, Node *> m;
            int n;
        scanf("%d",&n);
        struct Node *root = NULL;
        while (n--)
        {
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                if (m.find(n1) == m.end())
                {
                    parent = new Node(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                }
                else
                    parent = m[n1];
                child = new Node(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                m[n2] = child;
        }
        leftView(root);
        cout << endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
// A wrapper over leftViewUtil()

/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000



*/
void printLeftview(bool *levels, Node *root, int curr)
{
    if (!root)
        return;

    if (levels[curr] == false)
    {
        levels[curr] = true;
        cout << root->data << " ";
    }
    printLeftview(levels, root->left, curr + 1);  //left child called
    printLeftview(levels, root->right, curr + 1); //right child called
}

void leftView(Node *root)
{
    // Max height of tree assumed to be 100
    //Therefore for skew tree, max levels = 100
    bool levels[202] = {false};
    printLeftview(levels, root, 0);
}


//------------------------------------------SOLUTION 2 ---------------------------------------------------

/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(!root) return ans;
   queue<Node *> q;
   q.push(root);
   while(!q.empty()){
       int sz = q.size();
       ans.push_back(q.front()->data);
       while(sz--){
           Node * t=q.front();
           q.pop();
           if(t->left) q.push(t->left);
           if(t->right) q.push(t->right);
       }
   }
   return ans;
}s