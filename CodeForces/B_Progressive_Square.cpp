#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, c, d, i, j, sz;
        cin >> n >> c >> d;
        sz = n * n;
        vector<int> v(sz), arr;
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                int val = v[0] + (i * c) + (j * d);
                arr.push_back(val);
            }
        }
        sort(arr.begin(), arr.end());
        cout << (arr == v ? "YES\n" : "NO\n");
    }
    return 0;
}