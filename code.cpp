#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> od; // previously declared
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        od.push_back(x);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int index;
        cin >> index;

        auto it1 = lower_bound(od.begin(), od.end(), index);
        int f = distance(od.begin(), it1);
        int s = distance(it1, od.end());
        if (it1 != od.end() && *it1 == index)
            s--;
        cout << f << ' ' << s << '\n';
        // cout << "Small= " << f << " : Greater= " << s << '\n';
    }

    return 0;
}