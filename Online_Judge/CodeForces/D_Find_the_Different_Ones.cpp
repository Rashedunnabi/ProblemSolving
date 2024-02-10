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
    int i, n, q;
    cin >> n;
    vector<int> a(n), pre(n);
    for (int &i : a)
    {
        cin >> i;
    }
    pre[n - 1] = -1;
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] == a[i + 1])
            pre[i] = pre[i + 1];
        else
            pre[i] = i + 1;
    }

    // for (i = 0; i < n; i++)
    //     cout << pre[i] << ' ';
    // cout << endl;

    cin >> q;
    for (i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (pre[l] > r || pre[l] == -1)
        {
            cout << -1 << ' ' << -1 << '\n';
        }
        else
        {
            cout << l + 1 << ' ' << 1 + pre[l] << '\n';
        }
    }
    cout << endl;
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