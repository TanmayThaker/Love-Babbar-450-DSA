
//Problem link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

Node* Inpre(Node* root) //For Predecessor we go first left and then extreme right
{
    Node*p = root->left;
    while(p->right) p=p->right;
    return p;
}
Node* SucPre(Node* root) //For Succesor we first go right and then extreme left;
{
    Node *p = root->right;
    while(p->left) p=p->left;
    return p;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    // Your code goes here
    if(!root) return;
    if(root->key==key)
    {
        if(root->left) pre = Inpre(root);
        if(root->right) suc = SucPre(root);
        return;
    }
    else if(key>root->key)
    {
        pre=root; //If Key is greater than root->key, then we maintain a predecessor(pre)
        findPreSuc(root->right,pre,suc,key);
    }
    else if(key<root->key)
    {
        suc=root; //If Key is smaller than root->key, then we maintain a Succesor(suc)
        findPreSuc(root->left,pre,suc,key);
    }

}

/*
TC:O(h) where h is the height of the tree
*/