#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, cnt = 0;
        cin >> n;
        vector<int> v(n), odd;
        for (int &i : v)
            cin >> i;
        for (i = 0; i < n; i++)
        {
            if (v[i] & 1)
                cnt++;
            else
            {
                if (cnt)
                    odd.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt)
            odd.push_back(cnt);

        // sort(odd.rbegin(), odd.rend());

        int ans = n * (n + 1) / 2;

        for (int x : odd)
            ans -= (x * (x + 1) / 2);

        int maxAns = ans;
        for (int x : odd)
        {
            for (int i = 1; i <= x; i++)
            {
                int left = i - 1, right = x - i;
                int temp = x * (x + 1) / 2;
                temp -= (left * (left + 1) / 2);
                temp -= (right * (right + 1) / 2);
                maxAns = max(maxAns, ans + temp);
            }
        }
        cout << maxAns << '\n';
    }
    return 0;
}