#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int minimumLength = k * 1LL * (k + 1) / 2;
        minimumLength += (k - 1);
        if (minimumLength <= n)
            yes;
        else
            no;
    }
    return 0;
}