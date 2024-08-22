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
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int gc = 0;
        for (i = 0; i < n; i++)
            gc = __gcd(gc, v[i]);

        int one = count(v.begin(), v.end(), gc);
        if (one)
        {
            yes;
            continue;
        }
        sort(v.begin(), v.end());
        n = v.size();
        int x = v[0], y = -1;
        for (i = 0; i < n; i++)
        {
            if (v[i] % x != 0)
            {
                y = v[i];
                break;
            }
        }
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            if (v[i] % x != 0 && v[i] % y != 0)
            {
                flag = true;
            }
        }
        cout << (flag ? "NO\n" : "YES\n");
    }
    return 0;
}