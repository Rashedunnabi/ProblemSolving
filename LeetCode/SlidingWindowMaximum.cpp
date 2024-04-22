// https://leetcode.com/problems/sliding-window-maximum/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int i = 0, n = arr.size();

        for (i = 0; i < k; i++)
        {
            while (!dq.empty() && dq.back() < arr[i])
                dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());

        for (i = k; i < n; i++)
        {
            int pre = arr[i - k];
            if (!dq.empty() && dq.front() == pre)
                dq.pop_front();

            while (!dq.empty() && dq.back() < arr[i])
                dq.pop_back();

            dq.push_back(arr[i]);

            ans.push_back(dq.front());
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
        vector<int> v = ob.maxSlidingWindow(arr, k);
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}