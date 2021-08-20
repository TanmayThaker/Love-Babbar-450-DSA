//Given a two integers say a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator

//Naive or Brute Force approach
#include <bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor)
{
    int sign = ((dividend<0)^(divisor<0))?-1:1;

    dividend = abs(dividend);
    divisor=abs(divisor);

    int quotient = 0;
    while(dividend>=divisor)
    {
        dividend-=divisor;
        quotient++;
    }
    if(sign==-1) quotient=-quotient;
    return quotient;
}

int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
}
/*
TC:O(a)
SC:O(1)
*/

//---------------------------------------------------------------------------------------------------------------------------

//Optimised approach

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor)
{
    int sign = ((dividend<0)^(divisor<0))?-1:1;
    dividend = abs(dividend);
    divisor=abs(divisor);
    long long quotient=0,t=0;
    for(int i=31;i>=0;i--)
    {
        if(t+(divisor<<i)<=dividend)
        {
            t+=divisor<<i;
            quotient=quotient||1LL<<i;
        }
    }
    if(sign==-1) quotient=-quotient;
    return quotient;
}

int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
}

/*
Time complexity : O(log(a)) 
Auxiliary space : O(1)
*/