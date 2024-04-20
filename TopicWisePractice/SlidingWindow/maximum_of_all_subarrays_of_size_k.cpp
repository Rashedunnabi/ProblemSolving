#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(const vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
            cin >> a[i];

        vector<int> ans = slidingMaximum(a, k);
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}