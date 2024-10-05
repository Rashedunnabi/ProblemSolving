#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "All can eat.\n"
#define no cout << "Some starve.\n"

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
        }
        int cnt = 500;
        while (cnt--)
        {
            vector<int> tmp = v;
            for (int i = 0; i < n; i++)
                tmp[i] = v[tmp[i]];
            v = tmp;
        }
        is_sorted(v.begin(), v.end()) ? yes : no;
    }
    return 0;
}