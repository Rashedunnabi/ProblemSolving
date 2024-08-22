#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    int j = 0;
    for (i = 0; i < m; i++)
    {
        while (a[j] < b[i] && j < n)
            j++;
        cout << j << ' ';
    }
    cout << '\n';

    return 0;
}