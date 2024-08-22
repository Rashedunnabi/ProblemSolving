#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    pbds os;
    for (i = 0; i < k; i++)
        os.insert({v[i], i});

    cout << os.find_by_order((k - 1) / 2)->first << ' ';
    for (i = 0; i < n - k; i++)
    {
        os.erase({v[i], i});
        os.insert({v[i + k], i + k});
        cout << os.find_by_order((k - 1) / 2)->first << ' ';
    }
    cout << '\n';

    return 0;
}