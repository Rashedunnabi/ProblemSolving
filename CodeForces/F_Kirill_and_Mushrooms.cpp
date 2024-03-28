#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int a[n + 1], p[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        ordered_set os;
        for (int i = 1; i <= n; i++)
            os.insert({a[i], i});

        int ans = -1, cnt = -1;
        for (int i = 1; i <= n; i++)
        {
            if (os.size() >= i)
            {
                auto temp = *os.find_by_order(i - 1);
                int res = temp.first * i;
                if (res > ans)
                {
                    ans = res;
                    cnt = i;
                }
            }
            os.erase({a[p[i]], p[i]});
        }
        cout << ans << " " << cnt << "\n";
    }
    return 0;
}