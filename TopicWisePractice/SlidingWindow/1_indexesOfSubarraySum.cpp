#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {

        int j = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == s)
            {
                return {i + 1, i + 1};
            }

            sum += arr[i];
            while (sum > s)
                sum -= arr[j++];
            if (sum == s && i >= j)
            {
                return {j + 1, i + 1};
            }
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
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long target;
        cin >> target;
        Solution ob;
        auto it = ob.subarraySum(arr, n, target);
        cout << it[0] << ' ' << it[1] << '\n';
    }
    return 0;
}