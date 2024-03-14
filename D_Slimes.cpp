#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

const int N = 3e5 + 7;
int v[N], prv[N], nxt[N], ans[N];
ll PreSum[N];

ll sum(int l, int r)
{
    return PreSum[r] - PreSum[l];
}

void solution()
{
    int n, i;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        PreSum[i + 1] = PreSum[i] + v[i];
    }

    for (i = 1; i < n; i++)
    {
        if (v[i - 1] == v[i])
            prv[i] = prv[i - 1];
        else
            prv[i] = i;
    }

    nxt[n - 1] = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (v[i] == v[i + 1])
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        if (i > 0 && v[i - 1] > v[i])
        {
            ans[i] = 1;
            continue;
        }
        if (i + 1 < n && v[i + 1] > v[i])
        {
            ans[i] = 1;
            continue;
        }
        ll v1 = INT_MAX, v2 = INT_MAX;

        int lo = 0, hi = i + 1, mid;
        {
            while (hi - lo > 1)
            {
                mid = lo + (hi - lo) / 2;
                ll val = sum(i - mid, i);
                if (prv[i - 1] <= i - mid)
                    val = v[i - 1];
                if (val > v[i])
                    hi = mid;
                else
                    lo = mid;
            }
            if (hi != i + 1)
                v1 = hi;
        }
        {
            lo = 0, hi = n - i;

            while (hi - lo > 1)
            {
                mid = lo + (hi - lo) / 2;
                ll val = sum(i + 1, i + 1 + mid);
                if (nxt[i + 1] >= i + mid)
                    val = v[i + 1];
                if (val > v[i])
                    hi = mid;
                else
                    lo = mid;
            }
            if (hi != n - i)
                v2 = hi;
        }
        ans[i] = min(v1, v2);
    }

    for (i = 0; i < n; i++)
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << ' ';
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