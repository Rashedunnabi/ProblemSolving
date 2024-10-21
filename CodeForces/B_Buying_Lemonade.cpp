#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        sort(v.begin(), v.end());

        int sum = 0, used = 0;
        for (int i = 0; i < n; i++)
        {
            int newValue = v[i] - used;
            used += newValue;

            if (newValue == 0)
            {
                sum++;
                continue;
            }

            if (newValue * (n - i) >= k)
            {
                sum += k;
                break;
            }
            else
            {
                sum += (newValue * (n - i)) + 1;
                k -= newValue * (n - i);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}