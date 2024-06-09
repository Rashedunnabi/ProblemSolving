// Question is Calculate the summation between L---R
// PrefixSum Technique

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, i;
    cin >> n;
    vector<int> v(n), preSum(n + 1);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        preSum[i + 1] = preSum[i] + v[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << "Sum between " << l << ' ' << r << ": " << (preSum[r] - preSum[l - 1]) << '\n';
    }

    return 0;
}