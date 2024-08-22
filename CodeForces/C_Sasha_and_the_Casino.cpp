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
    ll k, x, a, i, u = 0, flag = 1;
    cin >> k >> x >> a;
    for (i = 0; flag && i < x; i++)
    {
        ll val = (u + k - 1) / (k - 1);
        if (val == 0)
            u += 1;
        else
            u += val;

        flag = (val <= a);
    }
    if (k * (a - u) > a)
        yes;
    else
        no;
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