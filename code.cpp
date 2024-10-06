#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        multiset<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
                odd.insert(x);
            else
                even.insert(x);
        }
        while (odd.size() > 1)
        {
            int fst = *odd.begin();
            int lst = *odd.rbegin();
            odd.erase(odd.find(fst));
            odd.erase(odd.find(lst));
            int x = (fst + lst) / 2;
            if (x & 1)
                odd.insert(x);
            else
                even.insert(x);
        }
        while (even.size() > 1)
        {
            int fst = *even.begin();
            int lst = *even.rbegin();
            even.erase(even.find(fst));
            even.erase(even.find(lst));
            int x = (fst + lst) / 2;
            even.insert(x);
        }

        int ans = -1;
        if (odd.size())
            ans = *odd.begin();
        if (even.size())
        {
            if (ans != -1)
                ans = (ans + *even.begin()) / 2;
            else
                ans = *even.begin();
        }
        cout << ans << '\n';
    }
    return 0;
}