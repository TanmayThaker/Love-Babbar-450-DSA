//Sort a “K” Sorted Doubly Linked List
//Article link : https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
//Video Solution : https://www.youtube.com/watch?v=hgcKeJiBCc8


#include <bits/stdc++.h>
using namespace std;
 
// a node of the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct compare
{
    bool operator()(struct Node* first,struct Node* second)
    {
        return first->data>second->data;
    }
};

struct Node* sort(struct Node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    priority_queue<Node*, vector<Node*>,compare> pq;

    struct Node* newHead = NULL, *curr;

    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for(int i=0;head!=NULL and i<=k ;i++)
    {
        pq.push(head);

        head=head->next;
    }
    while(!pq.empty())
    {
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if(newHead==NULL)
        {
            newHead=pq.top();
            newHead->prev=NULL;
            curr=newHead;
        }
        else
        {
            curr->next=pq.top();
            pq.top()->prev=curr;
            curr=pq.top();
        }
        pq.pop();
        if(head!=NULL)
        {
            pq.push(head);
            head=head->next;
        }
    }
    curr->next=NULL;
    return newHead;
}

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
          (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 
// Driver program to test above
int main()
{
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    printList(head);
 
    // sort the biotonic DLL
    head = sort(head, k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
}

/*
Time Complexity: O(n*log k)
Auxiliary Space: O(k)
*/