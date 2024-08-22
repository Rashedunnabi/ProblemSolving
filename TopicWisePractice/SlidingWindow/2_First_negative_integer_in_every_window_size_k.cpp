#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
    {
        deque<long long> dq;
        vector<long long> ans;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] < 0)
                dq.push_back(arr[i]);
        }

        if (dq.size())
            ans.push_back(dq.front());
        else
            ans.push_back(0);

        for (int i = k; i < n; i++)
        {
            if (arr[i - k] < 0)
                dq.pop_front();
            if (arr[i] < 0)
                dq.push_back(arr[i]);

            if (dq.size())
                ans.push_back(dq.front());
            else
                ans.push_back(0);
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
        cin >> n;
        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        vector<long long> ans = ob.printFirstNegativeInteger(arr, n, k);
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}