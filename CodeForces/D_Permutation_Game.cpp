#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, b, s, i, bodya = 0, sasha = 0, sumB = 0, sumS = 0;
        cin >> n >> k >> b >> s;
        b--, s--;

        vector<int> p(n), a(n), vb(n), vs(n);
        for (int &i : p)
            cin >> i, i--;
        for (int &i : a)
            cin >> i;

        for (i = 0; i < n; i++)
        {
            vb[i] = a[b], vs[i] = a[s];
            b = p[b], s = p[s];
        }

        for (i = 0; i < min(n, k); i++)
        {
            sumB += vb[i], sumS += vs[i];
            bodya = max(bodya, sumB + (k - i - 1) * vb[i]);
            sasha = max(sasha, sumS + (k - i - 1) * vs[i]);
        }
        if (bodya == sasha)
            cout << "Draw\n";
        else if (bodya < sasha)
            cout << "Sasha\n";
        else
            cout << "Bodya\n";
    }
    return 0;
}