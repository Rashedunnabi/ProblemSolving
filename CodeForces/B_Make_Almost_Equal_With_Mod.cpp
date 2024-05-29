#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<int> &v, int mod)
{
    set<int> st;
    for (auto val : v)
        st.insert(val % mod);
    return st.size() == 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        for (int i = 1; i <= 60; ++i)
        {
            if (check(v, 1LL << i))
            {
                cout << (1LL << i) << '\n';
                break;
            }
        }
    }

    return 0;
}
