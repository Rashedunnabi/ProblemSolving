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
int arr[N];

void solution()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> suf(n), pre(n);
    int soto = 0;
    set<int> s, ss;
    for (i = 0; i < n; i++)
    {
        s.insert(arr[i]);
        auto it = s.lower_bound(soto);
        while (it != s.end() && *it == soto)
        {
            soto++;
            it = s.lower_bound(soto);
        }
        pre[i] = soto;
    }

    soto = 0;
    for (i = n - 1; i >= 0; i--)
    {
        ss.insert(arr[i]);
        auto it = ss.lower_bound(soto);
        while (it != ss.end() && *it == soto)
        {
            soto++;
            it = ss.lower_bound(soto);
        }
        suf[i] = soto;
    }

    // for (auto val : pre)
    //     cout << val << ' ';
    // cout << '\n';
    // for (auto val : suf)
    //     cout << val << ' ';
    // cout << '\n';

    for (i = 0; i < n - 1; i++)
    {
        if (pre[i] == suf[i + 1])
        {
            cout << 2 << '\n'
                 << 1 << ' ' << i + 1 << '\n'
                 << i + 2 << ' ' << n << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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