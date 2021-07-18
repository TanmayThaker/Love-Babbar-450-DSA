// Practice link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

/*
Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N)
*/


class Solution{
  public:
   long long int n = 1e9+4;
   long long int merge(long long arr[],long long s,long long e)
   {
       long long int mid = (s+e)/2;
       long long int inv=0;
       long long int i=s;
       long long int j=mid+1;
       long long int k=s;
       long long int temp[n];
       while(i<=mid and j<=e)
       {
           if(arr[i]<=arr[j])
           {
               temp[k++]=arr[i++];
           }
           else
           {
               temp[k++]=arr[j++];
               inv+=(mid+1-i);
           }
       }
       while(i<=mid)
       {
           temp[k++]=arr[i++];
       }
       while(j<=e)
       {
           temp[k++]=arr[j++];
       }
       for(int i=s;i<=e;i++){
            arr[i] = temp[i];
        }
       return inv;
   }
   long long int mergeSort(long long arr[],long long int s,long long int e)
   {
       long long int inv=0;
       if(s>=e)
       {
           return inv;
       }
       long long int mid = (s+e)/2;
       
       inv+=mergeSort(arr,s,mid);
       inv+=mergeSort(arr,mid+1,e);
       
       inv+=merge(arr,s,e);
       return inv;
   }
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        n=(long long int)N;
        mergeSort(arr,0,N-1);
    }

   

};