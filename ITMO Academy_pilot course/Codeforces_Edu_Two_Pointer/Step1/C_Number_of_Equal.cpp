#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    long long ans = 0;
    while (i < n && j < m)
    {
        while (a[i] != b[j])
        {
            if (a[i] < b[j])
                i++;
            else
                j++;
        }

        int cntA = 0, cntB = 0;
        while (j < m && a[i] == b[j])
            j++, cntA++;
        while (i < n && a[i] == b[j - 1])
            i++, cntB++;
        ans += (cntA * 1LL * cntB);
    }

    cout << ans << '\n';

    return 0;
}