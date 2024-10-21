#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (max(a.first, a.second) == max(b.first, b.second))
        return min(a.first, a.second) < min(b.first, b.second);
    return max(a.first, a.second) < max(b.first, b.second);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
            cin >> vp[i].first >> vp[i].second;

        sort(vp.begin(), vp.end(), cmp);
        for (auto p : vp)
            cout << p.first << ' ' << p.second << ' ';
        cout << '\n';
    }
    return 0;
}