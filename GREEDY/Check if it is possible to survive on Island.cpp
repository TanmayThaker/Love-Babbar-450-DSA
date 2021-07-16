

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//'n' is Maximum Unit of Food you can buy each day
// 'S' is Number of days you are required to survive
// 'M' is Number of Food required to survive each day

int main() {
	int s,n,m;
	cin>>s>>n>>m;
	int x = s/7; //'x' represents  number of sundays
	int y = s-x;//'y' represents how many days can we purchase food
	int sm = s*m;
	int days = sm/m;
	if (sm%m != 0)
	{
	    days++;
	}
	if(days<=y) 
	{
	    cout<<"Yes "<<days;
	}
	else
	{
	    cout<<"No ";
	}
	return 0;
	
}





















//Check if it is possible to survive on Island

// C++ program to find the minimum days on which
// you need to buy food from the shop so that you
// can survive the next S days
#include <bits/stdc++.h>
using namespace std;

// function to find the minimum days
void survival(int S, int N, int M)
{

	// If we can not buy at least a week
	// supply of food during the first week
	// OR We can not buy a day supply of food
	// on the first day then we can't survive.
	if (((N * 6) < (M * 7) && S > 6) || M > N)
		cout << "No\n";
	else {
		// If we can survive then we can
		// buy ceil(A/N) times where A is
		// total units of food required.
		int days = (M * S) / N;
		if (((M * S) % N) != 0)
			days++;
		cout << "Yes " << days << endl;
	}
}

// Driver code
int main()
{
	int S = 10, N = 16, M = 2;
	survival(S, N, M);
	return 0;
}
 