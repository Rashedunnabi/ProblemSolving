#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || a[i] <= v.back())
            {
                v.push_back(a[i]);
            }
        }
        int ans = n;
        reverse(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            // use n-1-i type2 and v[i] type1 moves
            ans = min(ans, n - i - 1 + v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}