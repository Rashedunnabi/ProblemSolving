#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i;
    cin >> n;

    int a[n], b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<int, int>> vp;

    for (i = 0; i < n; i++)
    {
        vp.push_back({a[i], b[i]});
    }
    sort(all(vp));
    for (i = 0; i < n; i++)
        cout << vp[i].first << ' ';
    cout << '\n';
    for (i = 0; i < n; i++)
        cout << vp[i].second << ' ';
    cout << '\n';
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