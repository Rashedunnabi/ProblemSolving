#include <bits/stdc++.h>
using namespace std;
void solution()
{
    int n, i;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int min_req = 0;
    set<int> idxs;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            min_req = max(min_req, a[i - 1] - a[i]);
            idxs.insert(i);
        }
    }

    for (auto &i : idxs)
        a[i] += min_req;

    if (is_sorted(a.begin(), a.end()))
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
