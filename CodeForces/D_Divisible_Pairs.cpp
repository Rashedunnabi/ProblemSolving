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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    map<int, map<int, int>> g;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        g[a[i] % x][a[i] % y]++;
    }

    auto complement = [&](int p)
    {
        return (x - (p % x)) % x;
    };

    int tot = 0;
    for (int &i : a)
    {
        tot += g[complement(i)][i % y] - (i % x == complement(i));
    }
    cout << (tot >> 1) << '\n';
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