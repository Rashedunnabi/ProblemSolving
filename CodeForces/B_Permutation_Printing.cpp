#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void solution()
{
    int n, i;
    cin >> n;
    int hi = n, lo = 1;
    for (i = 0; i < n; i++)
    {
        if (i & 1)
            cout << lo++ << ' ';
        else
            cout << hi-- << ' ';
    }
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}