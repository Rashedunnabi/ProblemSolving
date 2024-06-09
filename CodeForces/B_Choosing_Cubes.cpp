#include <bits/stdc++.h>
using namespace std;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define both cout << "MAYBE\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, f, k, i;
        cin >> n >> f >> k;

        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int value = v[f - 1], boro = 0, same = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] > value)
                boro++;
            if (v[i] == value)
                same++;
        }

        if (boro >= k)
            no;
        else if (boro + same <= k)
            yes;
        else
            both;
    }
    return 0;
}