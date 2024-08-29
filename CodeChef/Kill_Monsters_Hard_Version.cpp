#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// st.order_of_key (k) : Number of items strictly smaller than k
// st.find_by_order(k) : K-th element in a set (counting from zero)

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, x, k;
        cin >> n >> x >> k;

        vector<ll> h(n);
        for (ll &i : h)
            cin >> i;

        sort(h.rbegin(), h.rend());
        ll killed = 0, extra = 0;

        pbds st;
        for (ll i = 0; i < n; i++)
        {
            if (h[i] < x)
            {
                killed++;
                x = h[i];
            }
            else
            {
                st.insert(h[i]);
                ll ex = st.order_of_key(x * k);
                extra = max(extra, ex);
            }
        }
        ll ans = killed + extra;
        cout << ans << '\n';
    }
    return 0;
}