#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (auto &i : v)
            cin >> i;
        int one = count(v.begin(), v.end(), 1);
        int zero = count(v.begin(), v.end(), 0);
        int fst = one % 2;
        int snd = min(zero, one);
        cout << fst << ' ' << snd << '\n';
    }
    return 0;
}