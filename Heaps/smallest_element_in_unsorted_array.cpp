//Optimal aaproach using Quick select


//C++ Solution for Kth Largest (QuickSelect Implementation) :
class Solution {
public:
    int partition(vector<int>& nums,int l,int h)
    {
        int pivot=l;
        int i=l,j=h;
        while(i<j)
        {
           while(i<=j && nums[i]<=nums[pivot])
               i++;
           while(i<=j && nums[j]>nums[pivot])
               j--;
            
            if(i>j)
            break;
            
            swap(nums[i],nums[j]);
        }
        
        swap(nums[pivot],nums[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        int l=0,h=nums.size()-1;
        int res;
        while(l<=h)
        {
            res=partition(nums,l,h);
            if(res==k)
                return nums[res];
            else if(res>k)
                h=res-1;
            else
                l=res+1;
        }
        return -1;
    }
};

//Using set STL

using namespace std;
 
int main()
{
 
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    set<int> s(arr, arr + n);
    set<int>::iterator itr
        = s.begin(); // s.begin() returns a pointer to first
                     // element in the set
    advance(itr, k - 1); // itr points to kth element in set
 
    cout << *itr << "\n";
 
    return 0;
}
