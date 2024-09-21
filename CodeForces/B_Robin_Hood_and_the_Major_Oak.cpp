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
        int n, k;
        cin >> n >> k;
        int st = n - k + 1;
        int od_st = (st & 1) ? st : st + 1;
        int od_en = (n & 1) ? n : n - 1;
        int odd = (od_en - od_st) / 2 + 1;
        cout << (odd & 1 ? "NO\n" : "YES\n");
    }
    return 0;
}