
//Practice Link : https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

//GFG SOLUTION

class Solution
{
	public:
	struct Node
	{
	    int data;
	    Node *left;
	    Node *right;
	    
	    Node(int x)
	    {
	        data=x;
	        left=right=NULL;

	    }
	};
	struct compare
	{
	    bool operator()(Node *l,Node* r)
	    {
	        return (l->data > r->data);
	    }
	};
	    void preOrder(vector<string> &v,Node *root,string s)
	    {
	        if(!root) return;
	        
	        if(!root->left and !root->right)
	        {
	            v.push_back(s);
	        }
	        preOrder(v,root->left,s+"0");
	        preOrder(v,root->right,s+"1");
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    vector<string> v;
		    priority_queue<Node*,vector<Node*>,compare> pq;
		    for(int i=0;i<f.size();i++)
		    {
		        Node *temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    for(int i=1;i<N;i++)
		    {
		        Node *x = pq.top();
		        pq.pop();
		        Node *y = pq.top();
		        pq.pop();
		        
		        Node *temp = new Node(x->data+y->data);
		        temp->left=x;
		        temp->right=y;
		        pq.push(temp);
		    }
		    preOrder(v,pq.top(),"");
		    return v;
		}
};















// ----------------------------------------------------------------------------------------------------------------------- //
/*
	Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calles minHeapify(). So, overall complexity is O(nlogn).
If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.
Applications of Huffman Coding:
	1. They are used for transmitting fax and text.
	2. They are used by conventional compression formats like PKZIP, GZIP, etc.
 It is useful in cases where there is a series of frequently occurring characters.
*/


//C++ program to implement Huffman Coding

#include<bits/stdc++.h>
using namespace std;

//A Huffman Tree Node
struct MinHeapNode
{
    //One of input characters
    char data;

    //Frequency of Character
    unsigned freq;

    //Left and Right Child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

//For Comparison of two heap Nodes 
//(Needed in MinHeap)
struct compare
{
    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }

};

//Prints Huffman Code from the root of the tree
void printCodes(struct MinHeapNode* root,string str)
{
    if(!root)
    {
        return;
    }

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

//Main function that build Huffman Tree and prints codes 
//by traversing the built Huffman Tree

vector<string> HuffmanCodes(char data[],int freq[],int size)
{
    struct MinHeapNode *left,*right,*top;

    //Cretaing a Min Heap and inserts all characters of data[]
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;

    for(int i=0;i<size;i++)
    {
        minHeap.push(new MinHeapNode(data[i],freq[i]));

    }

    //Iterate while size of Heap doesn't become 1
    while(minHeap.size()!=1)
    {
        //Extract two minimum freq items from minHeap
        left = minHeap.top();
        minHeap.pop();

        right=minHeap.top();
        minHeap.pop();

        // Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used
        top = new MinHeapNode('$',left->freq+right->freq);

        top->left=left;
        top->right=right;

        minHeap.push(top);
    }

    //Print the Huffman Codes uisng the Huffman Tree built above
    printCodes(minHeap.top(),"");

}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}