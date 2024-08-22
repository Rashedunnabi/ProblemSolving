#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int
const int sz = 2e5 + 5, mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        int n;
        cin >> n;
        vector<pair<ll, ll>> v(n);
        for (auto &i : v)
        {
            cin >> i.first >> i.second;
        }
        sort(v.begin(), v.end());
        ordered_set oset;
        for (auto &i : v)
        {
            ans += oset.size() - oset.order_of_key(i.second);
            oset.insert(i.second);
        }
        cout << ans << "\n";
    }
    return 0;
}
