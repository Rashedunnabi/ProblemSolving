#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void solution()
{
    ll n, i;
    cin >> n;
    set<ll> s;
    bool turn = 1, win = 1;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }

    ll sum = 0;
    bool flag = true;
    vector<ll> v(s.begin(), s.end());
    n = v.size();

    for (i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            flag = (i & 1) ? 0 : 1;
            break;
        }

        ll val = v[i] - sum;
        if (val > 1)
        {
            flag = (i & 1) ? 0 : 1;
            break;
        }
        sum++;
    }

    cout << (flag ? "Alice\n" : "Bob\n");
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
