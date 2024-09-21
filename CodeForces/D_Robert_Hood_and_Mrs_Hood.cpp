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
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> ar(n + 2, 0), id;
        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;
            ar[l]++;
            ar[r + 1]--;
            id.push_back(l);
        }
        for (int i = 1; i <= n; i++)
            ar[i] += ar[i - 1];
        sort(id.begin(), id.end());
        int maxi = 0, bro = 1, mini = k + 1, mom = 1;
        for (int i = 1; i <= n - d + 1; i++)
        {
            int x = upper_bound(id.begin(), id.end(), i + d - 1) - lower_bound(id.begin(), id.end(), i + 1);
            int dif = ar[i] + x;
            if (dif > maxi)
            {
                maxi = dif;
                bro = i;
            }
            if (dif < mini)
            {
                mini = dif;
                mom = i;
            }
        }
        cout << bro << " " << mom << '\n';
    }
    return 0;
}