
/*
	link: https://practice.geeksforgeeks.org/sumblems/maximize-arrii-of-an-array0026/1#
	sol: https://www.geeksforgeeks.org/maximize-sum-arrii/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N logN)
*/

const long long int mod = (int)1e9 + 7;
int Maximize(int a[], int n)
{
	long long int sum = 0;
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		sum += (i * (a[i] % mod)) % mod;
		sum = sum % mod;
	}
	return sum;
}