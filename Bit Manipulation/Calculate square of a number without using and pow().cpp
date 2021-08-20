//Calculate square of a number without using *, / and pow()

// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int n)
{
	// handle negative input
	if (n < 0)
		n = -n;

	// Initialize result
	int res = n;

	// Add n to res n-1 times
	for (int i = 1; i < n; i++)
		res += n;

	return res;
}

// Driver code
int main()
{
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}


//optimised approach

// Square of a number using bitwise operators
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{
	// Base case
	if (n == 0)
		return 0;

	// Handle negative number
	if (n < 0)
		n = -n;

	// Get floor(n/2) using right shift
	int x = n >> 1;

	// If n is odd
	if (n & 1)
		return ((square(x) << 2) + (x << 2) + 1);
	else // If n is even
		return (square(x) << 2);
}

// Driver Code
int main()
{
	// Function calls
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}

