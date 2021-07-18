#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void rotate(int arr[],int s,int e)
{
    int temp = arr[e];
    for(int i=e-1;i>=s;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[s] = temp;
    
}
void rearrange(int *arr,int n)
{
    int i=0,j=0,k=0;
    while(i<n and j<n and k<n)
    {
        //Even index must have positive number
        if(k%2==0)
        {
            //check if positive value is present
            if(arr[k]>0)
            {
                //find the first negative number
                i=k;
                j=k;
                while(i<n and arr[i]>0) i++;
                if(i>=n) break;
                rotate(arr,j,i);
            }
        }
        else
        {
            if(arr[k]<0)
            {
                j=k;
                i=k;
                while(j<n and arr[j]<0) j++;
                if(j>=n) break;
                rotate(arr,i,j);
            }
        }
        k++;
    }
}


int main()
{
     
    int arr[] = { -5, -2, 5, 2,
                 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

void rightRotate(int a[], int wrongIndex, int idx){
    int temp=a[idx];
    for(int i=idx;i>wrongIndex;i--){
        a[i]=a[i-1];
    }
    a[wrongIndex]=temp;
}

void rearrange(int a[], int n)
{
    int wrongIndex = -1;
 
    for (int idx = 0; idx < n; idx++)
    {
        if (wrongIndex >= 0)
        {
            if ((a[wrongIndex] <0 && a[idx] >= 0) || (a[wrongIndex] >= 0 && a[idx] < 0))
            {
                rightRotate(a,wrongIndex,idx);
                if (idx - wrongIndex >= 2)
                    wrongIndex+=2;
                else
                    wrongIndex = -1;
            }
        }
 
        if (wrongIndex == -1) {
            if ((a[idx] >= 0 && idx%2==0)|| (a[idx] < 0 && idx%2==1)) {
                wrongIndex = idx;
            }
        }
    }
}
int main(){
int a[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
int n=sizeof(a)/sizeof(a[0]);
rearrange(a,n);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
    return 0;
}

*/