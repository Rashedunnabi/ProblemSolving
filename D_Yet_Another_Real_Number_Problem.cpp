#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, cnt = 0, sum = 0, preMax = -1;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            int newValue = v[i] + (cnt == 0 ? 0 : round(pow(2, cnt)));
            sum = ans +
        }
    }
    return 0;
}