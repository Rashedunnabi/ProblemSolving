#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
const int bt = 63;

void solution()
{
    bool flag = 0;
    ll n, m, i, cnt = 0, last;
    cin >> n >> m;

    for (i = bt; i >= 0; i--)
    {
        if (n & (1LL << i))
        {
            if (m & (1LL << i))
            {
                cout << 1 << '\n'
                     << n << ' ' << m << '\n';
                return;
            }
            cnt++;
            last = i;
            if (cnt == 2)
                break;
        }
        else if (m & (1LL << i))
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << 2 << '\n'
         << n << ' ' << m + (1ll << last) << ' ' << m << '\n';
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