#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i, n, x, y = 0, ans = 0;
        cin >> n >> x >> y;

        ans = x - 2;
        set<int> st;
        for (i = 0; i < x; i++)
        {
            int x;
            cin >> x;
            st.insert(x);
        }
        for (auto i : st)
        {
            int nxt = i + 1, nxt2 = i + 2;
            if (nxt > n)
                nxt -= n;
            if (nxt2 > n)
                nxt2 -= n;
            if (st.find(nxt) == st.end() && st.find(nxt2) != st.end())
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}