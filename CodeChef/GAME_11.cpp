#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        sort(rall(a)), sort(rall(b));
        if (n < 4 || m < 4 || n + m < 11)
        {
            cout << -1 << '\n';
            continue;
        }

        ll sum = 0LL;
        for (i = 0; i < 4; i++)
            sum += a[i] + b[i];

        vector<int> newVec;
        for (i = 4; i < n; i++)
            newVec.push_back(a[i]);
        for (i = 4; i < m; i++)
            newVec.push_back(b[i]);

        sort(rall(newVec));
        for (i = 0; i < 3; i++)
            sum += newVec[i];

        cout << sum << '\n';
    }
    return 0;
}