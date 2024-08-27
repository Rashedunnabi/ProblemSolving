#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        vector<int> v;
        map<int, int> mp;
        for (int r = 0; r < n; r++)
        {
            mp[arr[r]]++;
            if (r > k - 1)
            {
                mp[arr[r - k]]--;
                if (mp[arr[r - k]] == 0)
                    mp.erase(arr[r - k]);
            }
            if (r >= k - 1)
                v.push_back(mp.size());
        }
        return v;
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
        auto v = ob.countDistinct(arr, n, k);
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}