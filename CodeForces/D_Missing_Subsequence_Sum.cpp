#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;

        int bt = log2(k);

        set<int> st;
        for (i = 0; i <= 20; i++)
            st.insert((1 << i));
        st.erase(1 << bt);

        vector<int> v(st.begin(), st.end());

        int val = (1 << bt) - 1;
        if (k - val - 1 > 0)
            v.push_back(k - val - 1);

        val = k + 1;
        while (v.size() < 24)
        {
            v.push_back(val);
            val += k;
        }

        sort(v.begin(), v.end());
        cout << v.size() << '\n';
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}