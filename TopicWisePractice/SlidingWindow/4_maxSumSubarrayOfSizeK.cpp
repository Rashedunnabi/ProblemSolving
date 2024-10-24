#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    long maximumSumSubarray(int k, vector<int> &arr, int n)
    {
        int ans = 0, sum = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        ans = sum;
        for (int i = k; i < n; i++)
        {
            sum += arr[i] - arr[i - k];
            ans = max(ans, sum);
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.maximumSumSubarray(k, arr, n) << '\n';
    }
    return 0;
}