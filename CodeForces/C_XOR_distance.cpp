#include <bits/stdc++.h>
using namespace std;
#define ll long long
long reverseBits(long n)
{
    vector<int> v;
    long long ans = 0, i;
    for (i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
            v.push_back(1);
        else
            v.push_back(0);
    }
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            ans = ans + 0LL + (1LL << i);
        }
    }
    return ans;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll ans = reverseBits(x);
        cout << ans << '\n';
    }
    return 0;
}