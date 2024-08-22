#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, i, j, k;
    cin >> n >> m;
    int ar[n + m], a[n], b[m];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];

    i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            ar[k++] = a[i++];
        else
            ar[k++] = b[j++];
    }
    while (i < n)
        ar[k++] = a[i++];
    while (j < m)
        ar[k++] = b[j++];

    for (i = 0; i < n + m; i++)
        cout << ar[i] << ' ';
    cout << '\n';
    return 0;
}