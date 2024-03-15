#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    int n, i, j, k;
    cin >> n;

    vector<pair<int, int>> a, b, c;

    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back({x, i});
    }
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c.push_back({x, i});
    }

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    int sz = min(10, n);
    int ans = 0;

    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
        {
            for (k = 0; k < sz; k++)
            {
                if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second)
                {
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}