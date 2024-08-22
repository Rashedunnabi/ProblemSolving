#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ansX = 1, ansY = 1, preCnt = -1;
        for (int i = 1; i <= n; i++)
        {
            vector<char> v(m);
            for (char &i : v)
                cin >> i;

            int cnt = count(v.begin(), v.end(), '#');
            if (cnt == 0 || cnt < preCnt)
                continue;

            preCnt = cnt;
            int mid = (cnt + 1) / 2;
            for (int j = 0; j < m; j++)
            {
                if (v[j] == '#')
                {
                    mid--;
                    if (mid == 0)
                    {
                        ansX = i;
                        ansY = j + 1;
                    }
                }
            }
        }
        cout << ansX << ' ' << ansY << '\n';
    }
    return 0;
}