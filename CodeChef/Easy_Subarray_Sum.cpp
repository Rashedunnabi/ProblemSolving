#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int i = 0, j = n - 1, cnt = 0;
        while (v[i] <= 0 && i < n)
            i++;
        while (v[j] <= 0 && j >= 0)
            j--;

        if (i >= j)
            cnt = 0;
        else
        {
            for (int k = i; k <= j; k++)
            {
                if (v[k] < 0)
                    cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}