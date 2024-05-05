#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n - 1), ans(1, 200000);
        for (int &i : v)
            cin >> i;
        for (int &i : v)
            ans.push_back(ans.back() + i);
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}