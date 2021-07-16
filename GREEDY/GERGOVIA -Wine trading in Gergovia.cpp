//GERGOVIA -Wine trading in Gergovia (SPOJ Problem)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (true)
    {
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<long long int, long long int>> buy;
        vector<pair<long long int, long long int>> sell;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                buy.push_back({a[i], i});
            }
            else
            {
                sell.push_back({a[i], i});
            }
        }
        long long int ans = 0;
        long long int i = 0, j = 0;
        while (i < buy.size() and j < sell.size())
        {
            int x = min(buy[i].first, -sell[j].first);
            buy[i].first -= x;
            sell[j].first += x;
            long long int diff = abs(buy[i].second - sell[j].second);
            ans += (x * diff);
            if (buy[i].first == 0)
            {
                i++;
            }
                
            if (sell[j].first == 0)
            {
                j++;
            }
        }
        cout << ans << endl;
        cin >> n;
        if (n == 0)
        {
             break;
        }
    }
    return 0;
}
