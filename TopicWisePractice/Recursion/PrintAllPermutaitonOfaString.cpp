#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(vector<vector<int>> &ans, vector<int> &v, vector<int> &vis, vector<int> &ar)
    {
        if (v.size() == ar.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < ar.size(); i++)
        {
            if (vis[i])
                continue;
            v.push_back(ar[i]);
            vis[i] = 1;
            func(ans, v, vis, ar);
            v.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int> &ar)
    {
        int n = ar.size();
        vector<int> vis(n);
        vector<vector<int>> ans;
        vector<int> v;
        func(ans, v, vis, ar);
        return ans;
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
        Solution ob;
        auto it = ob.permute(arr);

        for (auto v : it)
        {
            for (auto val : v)
                cout << val << ' ';
            cout << '\n';
        }
    }
    return 0;
}