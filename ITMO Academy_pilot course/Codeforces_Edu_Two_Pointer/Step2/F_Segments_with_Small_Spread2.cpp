#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int j = 0, ans = 0;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(v[i]);
        int dif = *st.rbegin() - *st.begin();
        while (dif > k)
        {
            st.erase(st.find(v[j]));
            dif = *st.rbegin() - *st.begin();
            j++;
        }
        ans += i - j + 1;
    }

    cout << ans << '\n';

    return 0;
}
