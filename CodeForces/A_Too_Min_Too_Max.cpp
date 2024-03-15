#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(all(v));

    int d = v[0], b = v[1], c = v[n - 2], a = v[n - 1];
    ll sum = abs(a - b) + abs(b - c) + abs(c - d) + abs(d - a);
    cout << sum << '\n';
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