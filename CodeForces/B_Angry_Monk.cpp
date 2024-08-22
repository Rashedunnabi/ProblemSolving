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
        int n, k, i;
        cin >> n >> k;
        vector<int> v(k);
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int sum = 0;
        for (i = 0; i < k - 1; i++)
            sum += (v[i] + v[i] - 1);

        cout << sum << '\n';
    }
    return 0;
}
