#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, sum = 0;
    cin >> n;
    sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << "\n";
    return 0;
}