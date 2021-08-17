/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class MinHeap{
    public:
    // A utility function to swap two elements
        void swap(int & x, int & y) {
          int temp = x;
          x = y;
          y = temp;
        }
        int *harr;
        int capacity;
        int heap_size;
            
        MinHeap(int cap)
        {
            heap_size=0;
            capacity=cap;
            harr=new int[cap];
        }
        
        int parent(int i)
        {
            return i-1/2;
        }
        
        int left(int i)
        {
            return 2*i+1;
        }
        
        int right(int i)
        {
            return 2*i+2;
        }
        
        int getMin(){
            return harr[0]; 
        }
        
        void insertKey(int k)
        {
            if(heap_size==capacity)
            {
                cout<<"\nOverflow could not insert key";
                return;
            }
            
            //first insert new key element at last
            heap_size++;
            int i=heap_size-1;
            harr[i]=k;
            
            //Fix the minheap property if violated
            while(i!=0 and harr[parent(i)]>harr[i])
            {
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
        }
        void decreaseKey(int i,int val)
        {
            harr[i]=val;
            while(i!=0 and harr[parent(i)]>harr[i])
            {
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
        }
        void deleteKey(int i)
        {
            decreaseKey(i,INT_MIN);
            extractMin();
        }
        
        void linearSearch(int val)
        {
            for(int i=0;i<heap_size;i++)
            {
                if(val==harr[i])
                {
                    cout<<"Value Found";
                    return;
                }
            }
            cout<<"Value not found/n";
        }
        
        // Method to remove minimum element (or root) from min heap
        int extractMin(){
             if(heap_size<=0)
            {
                return INT_MAX;
            }
            
            if(heap_size==1)
            {
                heap_size--;
                return harr[0];
            }
            
            //Store the minimum value and remove it from Heap
            int root=harr[0];
            harr[0]=harr[heap_size-1];
            heap_size--;
            MinHeapify(0);
            return root;
        }
        
        // A recursive method to heapify a subtree with the root at given index
        // This method assumes that the subtrees are already heapified
        void MinHeapify(int i)
        {
            int l=left(i);
            int r=right(i);
            int smallest=i;
            if(l<heap_size and harr[l]<harr[i]) smallest=l;  
            if(r<heap_size and harr[r]<harr[smallest]) smallest=r;
            if(smallest!=i)
            {
                swap(harr[i],harr[smallest]);
                MinHeapify(smallest);
            }
        }
        
        void printArray() {
            for (int i = 0; i < heap_size; i++)
            {
                cout << harr[i] << " ";
            }
            cout << endl;
        }
        
        int height()
        {
            return ceil(log2(heap_size+1))-1;           
        }
       
};




int main() {
  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s;
  MinHeap obj(s);
  cout << "Min Heap Created" << endl;

  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout << "4. Get Min" << endl;
    cout << "5. Extract Min" << endl;
    cout << "6. Height of Heap" << endl;
    cout << "7. Print/Traversal Heap values" << endl;
    cout << "8. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
      obj.insertKey(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linearSearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET Min value : " << obj.getMin();
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT Min value : " << obj.extractMin();
      cout << endl;
      break;
    case 6:
      cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : " << endl;
      obj.printArray();

      cout << endl;
      break;

    case 8:
      system("cls");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}