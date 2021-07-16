#include<bits/stdc++.h>
uisng namespace std;

class LRUCache
{
    //store keys of cache
    list<int> dq;

    //store references of keys in cache
    unordered_map<int,list<int>::iterator> ma;
    int csize; //maximum capacity of a cache

    public:
        LRUCache(int);
        void refer(int);
        void display();
};

//Declare the size
LRUCache::LRUCache(int n)
{
    csize=n;
}

//Refers key x within the LRU cache
void LRUCache::refer(int x)
{
    //not present in the cache
    if(ma.find(x)==ma.end())
    {
        //cache is full
        if(dq.size()==csize)
        {
            //delete the least recently used element
            int last = dq.back();

            //pops the last element
            dq.pop_back();

            //Erase the last
            ma.erase(last); 
        }
    }
    else{
        //Present in the cache
        dq.erase(ma[x]);
    }
    //update the reference
    dq.push_front(x);
    ma[x]=dq.begin();
}

//Function to display the contents of the cache
void LRUCache::display()
{
    // Iterate in the deque and print 
	// all the elements in it 
	for (auto it = dq.begin(); it != dq.end(); 
		it++) 
		cout << (*it) << " "; 

	cout << endl; 
}


// Driver Code 
int main() 
{ 
	LRUCache ca(4); 

	ca.refer(1); 
	ca.refer(2); 
	ca.refer(3); 
	ca.refer(1); 
	ca.refer(4); 
	ca.refer(5); 
	ca.display(); 

	return 0; 
} 

//-----------------------------------------------------------------------------------------------------------------------------------------------------
//ANOTHER GOOD APPROACH BY STRIVER:

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
  public:
  class node
  {
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
  };
  node* head=new node(-1,-1);
  node* tail=new node(-1,-1);
  
  int cap;
  unordered_map<int,node*> m;
  
  LRUCache(int capacity)
  {
      cap=capacity;
      head->next=tail;
      tail->prev=head;
  }
  void addNode(node* newnode)
  {
      node* temp=head->next;
      newnode->next=temp;
      newnode->prev=head;
      head->next=newnode;
      temp->prev=newnode;
  }
  void deleteNode(node* delnode)
  {
      node* delprev=delnode->prev;
      node* delnext=delnode->next;
      delprev->next=delnext;
      delnext->prev=delprev;
  }
  int get(int key_)
  {
      if(m.find(key_)!=m.end())
      {
          node* resnode=m[key_];
          int res=resnode->val;
          m.erase(key_);
          deleteNode(resnode);
          addNode(resnode);
          m[key_]=head->next;
          return res;
      }
      return -1;
  }
  void put(int key_,int value)
  {
      if(m.find(key_)!=m.end())
      {
          node* existingnode=m[key_];
          m.erase(key_);
          deleteNode(existingnode);
      }
      if(m.size()==cap)
      {
          m.erase(tail->prev->key);
          deleteNode(tail->prev);
      }
      addNode(new node(key_,value));
      m[key_]=head->next;
  }
};

