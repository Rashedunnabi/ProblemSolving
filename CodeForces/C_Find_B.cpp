#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    int n, q, i;
    cin >> n >> q;
    vector<ll> v(n), preSum(n + 1), CountOne(n + 1);
    for (auto &i : v)
        cin >> i;
    for (i = 0; i < n; i++)
    {
        preSum[i + 1] = preSum[i] + v[i] - 1;
        CountOne[i + 1] = CountOne[i] + (v[i] == 1);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r || CountOne[r] - CountOne[l - 1] > preSum[r] - preSum[l - 1])
            no;
        else
            yes;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}