//Count triplets in a sorted doubly linked list whose sum is equal to a given value x
//Article link : https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

//Approach 1(Naive):
//One naive approach will be to run 3 loops and find the sum in the doubly linked list that equals to 'x'
// Time complexity of the avove approach will take O(N^3) 

//Approach 2 (Using Hashing)
//TC:O(N^2) SC:O(N)


/*
Create a hash table with (key, value) tuples represented as (node data, node pointer) tuples. Traverse the doubly linked list 
and store each node’s data and its pointer pair(tuple) in the hash table. Now, generate each possible pair of nodes. 
For each pair of nodes, calculate the p_sum(sum of data in the two nodes) and check whether (x-p_sum) exists in the hash table or not.
If it exists, then also verify that the two nodes in the pair are not same to the node associated with (x-p_sum) in the hash table
and finally increment count. Return (count / 3) as each triplet is counted 3 times in the above process.
*/

//CODE FOR HASHING METHOD

#include<bits/stdc++.h>
using namepsace std;

struct Node {
    int data;
    struct Node* next, *prev;
};
 
int countTriplets(struct Node* head,int x)
{
    struct Node* ptr,ptr1,ptr2;
    int count=0;
    unordered_map<int,Node*> mp;

    //insert the <node->data,node pointer> tuple in the map
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        mp[ptr->data]=ptr;
    }
    //generate all possible pairs
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
        {
            // p_sum - sum of elements in the current pair
            int p_sum=ptr1->data+ptr2->data;
            if(mp.find(x-p_sum)!=mp.end() and mp[x-p_sum]!=ptr1 and mp[x-p_sum]!=ptr2)
            {
                count++;
            }
        }
    }
    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return count/3;
}

void insert(struct Node** head, int data)
{
    // allocate node
    struct Node* temp = new Node();
 
    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node* head = NULL;
 
    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
}

//Approach 3 : Using Two pointer instead of Hashing
//Time complexity will be still O(N^2) but the space complexity will be O(1)

#include<bits/stdc++.h>
using namespace std;

 
// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};
 
// function to count pairs whose sum equal to given 'value'
int countPairs(struct Node* first, struct Node* second, int value)
{
    int count=0;

     // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while(first!=NULL aand second!=NULL and first!=second and second->next!=first)
    {
        //pair found
        if((first->data+second->data)==value)
        {
            count++;
            first=first->next;
            second=second->prev;
        }
        // if sum is greater than 'value'
        // move second in backward direction
        else if ((first->data + second->data) > value)
        {
            second = second->prev;
        }
        // else move first in forward direction
        else
        {
            first = first->next;
        }
           
    }
    return count;
}

int countTriplets(strict Node* head,int x)
{
    
    // if list is empty
    if (head == NULL)
        return 0;
 
    struct Node* current, *first, *last;
    int count = 0;
    
    //get pointer to the last node of the DLL
    last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }

    for(current=head;current!=NULL;current=current->next)
    {
        first=current->next;

        count+=countPairs(first,last,x-current->data);
    }
    return count;
}


void insert(struct Node** head, int data)
{
    // allocate node
    struct Node* temp = new Node();
 
    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
 
// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node* head = NULL;
 
    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
 
    int x = 17;
 
    cout << "Count = "
         << countTriplets(head, x);
    return 0;
