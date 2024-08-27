#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    long long int maxSumWithK(long long int ar[], long long int n, long long int k)
    {
        long long int sum = 0, ans = LONG_LONG_MIN, j = 0, best_till_j = 0;
        for (int i = 0; i < k; i++)
            sum += ar[i];
        ans = max(ans, sum);
        for (int i = k; i < n; i++)
        {
            sum += ar[i];
            best_till_j += ar[j++]; // kadane's algo
            ans = max(ans, sum);
            if (best_till_j < 0)
            {
                sum -= best_till_j;
                ans = max(sum, ans);
                best_till_j = 0;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.maxSumWithK(arr, n, k) << '\n';
    }
    return 0;
}