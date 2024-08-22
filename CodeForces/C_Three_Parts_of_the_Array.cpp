#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int sum1 = 0, sum2 = 0, ans = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (sum1 < sum2)
            sum1 += v[i++];
        else
            sum2 += v[j--];

        if (sum1 == sum2)
            ans = sum1;
    }
    cout << ans << '\n';

    return 0;
}