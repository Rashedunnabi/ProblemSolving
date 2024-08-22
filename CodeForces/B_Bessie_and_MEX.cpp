#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, mex = 0;
        cin >> n;
        vector<int> ans(n);
        vector<bool> vis(n + 1);
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x >= 0)
                ans[i] = mex;
            else
                ans[i] = mex - x;

            vis[ans[i]] = 1;
            while (vis[mex])
                mex++;
        }
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}