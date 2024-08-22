#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    set<int> mex;
    for (i = 0; i <= n; i++)
        mex.insert(i);

    multiset<int> cur;
    for (i = 0; i < k; i++)
    {
        cur.insert(a[i]);
        mex.erase(a[i]);
    }
    int ans = *mex.begin();

    for (i = k; i < n; i++)
    {
        int prev = a[i - k];
        cur.erase(cur.find(prev));
        if (cur.find(prev) == cur.end())
            mex.insert(prev);

        cur.insert(a[i]);
        mex.erase(a[i]);
        ans = min(ans, *mex.begin());
    }
    cout << ans << '\n';

    return 0;
}