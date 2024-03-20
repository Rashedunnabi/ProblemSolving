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
    int n, x, i, ind = -1;
    cin >> n >> x;

    vector<int> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == x)
            ind = i;
    }

    int lo = 0, hi = n, mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (v[mid] <= x)
            lo = mid;
        else
            hi = mid;
    }
    if (v[lo] == x)
    {
        cout << 0 << '\n';
        return;
    }
    cout << "1\n";
    cout << lo + 1 << ' ' << ind + 1 << '\n';
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
