#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v, int ind)
{
    vector<int> newVec;
    for (int i = 0; i < v.size(); i++)
    {
        if (i != ind)
            newVec.push_back(v[i]);
    }
    int n = newVec.size();
    vector<int> gcdVec(n - 1);
    for (int i = 0; i < n - 1; i++)
        gcdVec[i] = __gcd(newVec[i], newVec[i + 1]);

    bool flag = is_sorted(gcdVec.begin(), gcdVec.end());
    return flag;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n), gcdVec(n - 1);
        for (int &i : v)
            cin >> i;

        for (i = 0; i < n - 1; i++)
            gcdVec[i] = __gcd(v[i], v[i + 1]);

        if (is_sorted(gcdVec.begin(), gcdVec.end()))
        {
            cout << "YES\n";
            continue;
        }
        bool flag = 0;
        for (i = 0; i < n - 2; i++)
        {
            if (gcdVec[i] > gcdVec[i + 1])
            {
                flag |= check(v, max(0, i - 1));
                flag |= check(v, i);
                flag |= check(v, min(n, i + 1));
                flag |= check(v, min(n, i + 2));
                break;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}