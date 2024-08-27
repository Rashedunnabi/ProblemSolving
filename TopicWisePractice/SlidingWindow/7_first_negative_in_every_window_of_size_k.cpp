#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
    {
        deque<long long> dq;
        vector<long long> v;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                dq.push_back(arr[i]);

            // operation
            if (i > k - 1)
            {
                if (!dq.empty() && dq.front() == arr[i - k])
                    dq.pop_front();
            }
            if (i >= k - 1)
            {
                if (dq.empty())
                    v.push_back(0);
                else
                    v.push_back(dq.front());
            }
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
        long long int n, k;
        cin >> n >> k;
        long long int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto it = ob.printFirstNegativeInteger(arr, n, k);
        for (auto val : it)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}