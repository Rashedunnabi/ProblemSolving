#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define yes cout << "YES\n"
#define no cout << "NO\n"
const int N = 2e5 + 7;

void solution()
{
    int n, m, k, i;
    cin >> n >> m >> k;
    vector<int> a(k + 1), b(k + 1), v(k + 1);
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= k)
        {
            a[x] = 1;
            v[x] = 1;
        }
    }
    for (i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x <= k)
        {
            b[x] = 1;
            v[x] = a[x] + b[x];
        }
    }

    // for (int i : a)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : b)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : v)
    //     cout << i << " ";
    // cout << endl;

    int ac = 0, bc = 0;
    for (i = 1; i <= k; i++)
    {
        if (v[i] == 0)
        {
            no;
            return;
        }
        if (v[i] == 1)
        {
            if (a[i])
                ac++;
            if (b[i])
                bc++;
        }
    }

    // cout << ac << ' ' << bc << '\n';

    if (ac <= k / 2 && bc <= k / 2)
        yes;
    else
        no;
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