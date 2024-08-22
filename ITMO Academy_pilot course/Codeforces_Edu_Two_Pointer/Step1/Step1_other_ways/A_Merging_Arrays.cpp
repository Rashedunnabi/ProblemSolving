#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, i;
    cin >> n >> m;
    int ar[n + m];
    for (i = 0; i < n + m; i++)
        cin >> ar[i];
    sort(ar, ar + n + m);
    for (i = 0; i < n + m; i++)
        cout << ar[i] << ' ';
    cout << '\n';
    return 0;
}