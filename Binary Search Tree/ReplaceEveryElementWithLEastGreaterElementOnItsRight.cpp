Node* insert(Node* root,int data,Node* &suc)
{
    if(node==NULL)
    {
        return root=newNode(data);
    }
    if(data<root->data)
    {
        suc=root;
        root->left=insert(root->left,data,suc);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data,suc)
    }
    return root;
}

void replace(int arr[],int n)
{
    Node* root=NULL;
    for(int i=n-1;i>=0;i--)
    {
        Node* su=NULL;
        root=insert(root,arr[i],suc);
        if(suc)
        {
            arr[i]=suc->data;
        }
        else{
            arr[i]=-1;
        }
    }
}

/*
TC:(nlogn) Average case || O(N^2) --> In worst case i.e. when tree is skewed
SC : O(N) 
*/