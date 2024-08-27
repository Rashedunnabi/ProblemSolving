#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long int maxSumWithK(long long int ar[], long long int n, long long int k)
    {
        int sum = 0, ans = LONG_LONG_MIN, j = 0, last = 0;
        for (int i = 0; i < k; i++)
            sum += ar[i];
        ans = max(ans, sum);
        for (int i = k; i < n; i++)
        {
            sum += ar[i];
            last += ar[j++];
            ans = max(ans, sum);
            if (last < 0)
            {
                sum -= last;
                ans = max(sum, ans);
                last = 0;
            }
        }
        return ans;
    }
};

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    Solution ob;
    cout << ob.maxSumWithK(ar, n, k) << '\n';

    return 0;
}