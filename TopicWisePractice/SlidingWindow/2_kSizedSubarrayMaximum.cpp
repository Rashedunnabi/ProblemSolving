#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && dq.back() < arr[i])
                dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());

        for (int i = k; i < n; i++)
        {
            int x = arr[i - k];
            if (!dq.empty() && dq.front() == x)
                dq.pop_front();

            while (!dq.empty() && dq.back() < arr[i])
                dq.pop_back();
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }

    // using set concept
    vector<int> max_of_subarrays2(int *arr, int n, int k)
    {
        vector<int> ans;
        multiset<int> ms;
        for (int i = 0; i < k; i++)
            ms.insert(arr[i]);

        ans.push_back(*ms.rbegin());

        for (int i = k; i < n; i++)
        {
            ms.insert(arr[i]);
            ms.erase(ms.find(arr[i - k]));
            ans.push_back(*ms.rbegin());
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
        auto it = ob.max_of_subarrays(arr, n, k);
        for (auto val : it)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}