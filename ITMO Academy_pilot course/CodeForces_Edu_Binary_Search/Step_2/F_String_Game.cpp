#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
int vis[N], ar[N];
bool check(int mid, string &s, string &t)
{
    int n = s.length(), m = t.length();
    for (int i = 0; i <= n + 10; i++)
        vis[i] = 0;
    for (int i = 0; i < mid; i++)
        vis[ar[i]] = 1;
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (vis[i])
            continue;
        if (s[i] == t[j])
            ++j;
        if (j == t.size())
            return true;
    }
    return j == m;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s >> t;
    int i, n = s.size();
    for (i = 0; i < n; i++)
        cin >> ar[i], ar[i]--;
    int lo = 0, hi = n + 1, mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid, s, t))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}