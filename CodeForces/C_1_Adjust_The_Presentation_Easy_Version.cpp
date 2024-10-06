#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, q, j = 0;
        cin >> n >> m >> q;

        vector<int> a(n), b(m);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        set<int> st;
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            if (j < n && b[i] == a[j])
                st.insert(a[j++]);
            else if (st.find(b[i]) == st.end())
                flag = true;
        }
        cout << (flag ? "TIDAK\n" : "YA\n");
    }
    return 0;
}