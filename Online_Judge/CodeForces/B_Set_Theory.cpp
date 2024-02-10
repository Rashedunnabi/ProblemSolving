#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 2e6;
int dp[N], arr[101];
int main()
{
    Faster;
    int i, n, c, t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        c = 0;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        cout << "YES\n";
        for (i = 1; i < N; i++)
        {
            bool flag = 1;
            for (int j = 0; j < n; j++)
            {
                if (dp[i + arr[j]] == tc)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << i << ' ', c++;
                for (int j = 0; j < n; j++)
                    dp[i + arr[j]] = tc;
            }
            if (c == n)
                break;
        }
        cout << '\n';
    }
    return 0;
}