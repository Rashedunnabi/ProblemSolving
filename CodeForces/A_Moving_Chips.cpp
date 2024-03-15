#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 0, pre = -1, f = 0;
        cin >> n;
        vector<int> v;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i > 0 && x == 1 && v.back() == 1)
                continue;
            v.push_back(x);
        }
        n = v.size();
        for (i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                if (!f)
                    f = 1, pre = i;
                else
                    ans += i - pre - 1, pre = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}