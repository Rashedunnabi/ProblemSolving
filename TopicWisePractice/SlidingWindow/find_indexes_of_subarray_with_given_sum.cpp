#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long target)
    {
        int st = 0, en = 0;
        long long sum = 0;
        while (en <= n)
        {
            if (arr[en] == target)
                return {en + 1, en + 1};
            if (sum < target)
                sum += arr[en++];
            else if (sum == target)
            {
                if (sum > 0)
                    return {st + 1, en};
                else
                    sum += arr[en++], sum -= arr[st++];
            }
            else if (sum > target)
                sum -= arr[st++];
        }
        return {-1};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;

        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> ans = ob.subarraySum(arr, n, k);

        if (ans[0] == -1)
        {
            cout << -1 << '\n';
            continue;
        }
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}