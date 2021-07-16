//Find maximum sum possible equal sum of three stacks 

#include<bits/stdc++.h>
using namespace std;

int main() {
 
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int s1[n1],s2[n2],s3[n3];
    for(int i=0;i<n1;i++) cin>>s1[i];
    for(int i=0;i<n2;i++) cin>>s2[i];
    for(int i=0;i<n3;i++) cin>>s3[i];
 
    int sum1=0;
    int sum2=0;
    int sum3=0;
    for(int i=0;i<n1;i++) sum1 += s1[i];
    for(int i=0;i<n2;i++) sum2 += s2[i];
    for(int i=0;i<n3;i++) sum3 += s3[i];
 
    int top1=0,top2=0,top3=0; //Top1 will be pointing to 1st element of stack 1 and similar thing goes for top2 and top3
    int ans = 0;
    while(true)
    {
        if(top1==n1 or top2==n2 or top3==n3)
        {
            ans=0;
            break;
        }
        if(sum1==sum2 and sum2==sum3)
        {
            ans=sum1;
            break;
        }
        if(sum1>=sum2 and sum1>=sum3)
        {
            sum1-=s1[top1++];
        }
        else if (sum2 >= sum1 && sum2 >= sum3){
            sum2 -= s2[top2++];
        }
        else if (sum3 >= sum2 && sum3 >= sum1){
            sum3 -= s3[top3++];
        }
    }
    cout<<ans;
    return 0;
}

//Time Complexity : O(n1 + n2 + n3) where n1, n2 and n3 are sizes of three stacks
//Space Complexity : O(1)