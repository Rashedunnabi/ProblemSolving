#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), p(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : p)
            cin >> x;
        pair<ll, ll> ans = {a[0], -1};
        multiset<ll> st;
        for (ll i = n - 1; i >= 0; i--)
        {
            ll cnt = min(n - i, i + 1);
            st.insert(a[p[i] - 1]);
            while (st.size() > cnt)
                st.erase(st.begin());
            ans = max(ans, make_pair(*st.begin() * cnt, -cnt));
        }
        cout << ans.first << ' ' << -ans.second << endl;
    }
    return 0;
}
