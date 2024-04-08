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
        int ar[n];
        for (i = 0; i < n; i++)
            cin >> ar[i];

        set<int> s;

        vector<int> ans;
        int mex = 0;

        for (i = 0; i < n; i++)
        {
            if (s.find(mex) == s.end())
            {
            }
        }
    }
    return 0;
}