//Two approaches for this problem

void swap(int* first,int* second)
{
    int temp=*first;
    *first=*second;
    *second=temp;
}

//Approach 1
/*--------------------------------------------------*/
void rot(int arr[],int start,int end)
{
    int left=start;
    int right=end;
    while(left<right)
    {
        swap(&arr[left],&arr[right]);
        left++;
        right--;
    }
}

void rotate(int arr[], int n)
{
    rot(arr,0,n-1);
    rot(arr,1,n-1);
}

//Approach 2
/*--------------------------------------------------*/
void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;
}