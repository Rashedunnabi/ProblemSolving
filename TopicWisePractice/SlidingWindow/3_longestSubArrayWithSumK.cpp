#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        int sum = 0, ans = 0;
        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int need = sum - k;
            if (mp.find(need) != mp.end())
                ans = max(ans, i - mp[need]);
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(arr, n, k) << '\n';
    }
    return 0;
}