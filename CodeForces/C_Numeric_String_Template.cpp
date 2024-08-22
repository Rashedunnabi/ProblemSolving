#include <bits/stdc++.h>
using namespace std;

int32_t main()
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

        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            if (s.size() != n)
            {
                cout << "NO\n";
                continue;
            }
            map<int, char> mpi;
            map<char, int> mpc;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if ((mpi.find(v[i]) != mpi.end() && mpi[v[i]] != s[i]) || (mpc.find(s[i]) != mpc.end() && mpc[s[i]] != v[i]))
                {
                    flag = true;
                    break;
                }
                mpi[v[i]] = s[i];
                mpc[s[i]] = v[i];
            }

            cout << (flag ? "NO\n" : "YES\n");
        }
        cout << '\n';
    }
    return 0;
}