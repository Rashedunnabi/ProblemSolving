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

        if (is_sorted(v.begin(), v.end()))
        {
            yes;
            continue;
        }
        int ind = -1;
        for (i = 1; i < n; i++)
        {
            if (v[i - 1] > v[i])
            {
                ind = i;
                break;
            }
        }
        if (is_sorted(v.begin(), v.begin() + ind) && is_sorted(v.begin() + ind, v.end()) && v[n - 1] <= v[0])
            yes;
        else
            no;
    }
    return 0;
}