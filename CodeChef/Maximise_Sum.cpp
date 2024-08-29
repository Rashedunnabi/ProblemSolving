#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int minus = 0, zero = 0;
        int minAbsValue = LLONG_MAX;
        int sum = 0LL;

        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += abs(v[i]);
            if (v[i] < 0)
                minus++;
            if (v[i] == 0)
                zero++;
            minAbsValue = min(minAbsValue, abs(v[i]));
        }

        if (minus % 2 == 0 || zero > 0)
            cout << sum << '\n';
        else
            cout << sum - 2 * minAbsValue << '\n';
    }
    return 0;
}
