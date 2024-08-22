#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        map<int, int> mp;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = 0;
        for (auto val : mp)
            ans += (val.second > 1);

        cout << ans << '\n';
    }
    return 0;
}