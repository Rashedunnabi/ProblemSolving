#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(const vector<int> &arr, int k)
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