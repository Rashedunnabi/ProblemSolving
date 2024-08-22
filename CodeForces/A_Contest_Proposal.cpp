#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {

        int n, i;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        int ans = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                ans++;
                a.push_back(b[i]);
                sort(a.begin(), a.end());
            }
        }
        cout << ans << '\n';
    }
    return 0;
}