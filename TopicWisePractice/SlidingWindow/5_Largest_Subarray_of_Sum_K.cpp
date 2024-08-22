#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long largestSubarrayOfSumK(int targetSum, vector<int> &arr, int n)
    {
        long long sum = 0;
        int ans = 0, j = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            while (sum > targetSum)
                sum -= arr[j++];

            if (sum == targetSum)
                ans = max(ans, i - j + 1);
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
        int n, targetSum;
        cin >> n >> targetSum;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.largestSubarrayOfSumK(targetSum, arr, n) << '\n';
    }
    return 0;
}