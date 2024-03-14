#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define int ll

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int t;

const int N = 3e5 + 20, inf = 1e9 + 20;
int cnt[N];

vector<int> ps;

inline int sum(int l, int r)
{
    return ps[r] - ps[l];
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n;

        vector<int> a, res;
        ps.clear();
        ps.pb(0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.pb(x);
            ps.pb(ps.back() + x);
        }

        vector<int> prv, nxt;
        prv.resize(n);
        nxt.resize(n);

        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
                prv[i] = prv[i - 1];
            else
                prv[i] = i;
        }

        nxt[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] == a[i + 1])
                nxt[i] = nxt[i + 1];
            else
                nxt[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int v1 = inf, v2 = inf;

            {
                int low = 0, high = i + 1;

                while (high - low > 1)
                {
                    int mid = (low + high) / 2;

                    int val = sum(i - mid, i);
                    if (prv[i - 1] <= i - mid)
                        val = a[i - 1];

                    if (val > a[i])
                        high = mid;
                    else
                        low = mid;
                }

                if (high != i + 1)
                    v1 = high;
            }

            {
                int low = 0, high = n - i;

                while (high - low > 1)
                {
                    int mid = (low + high) / 2;

                    int val = sum(i + 1, i + mid + 1);
                    if (nxt[i + 1] >= i + mid)
                        val = a[i + 1];

                    if (val > a[i])
                        high = mid;
                    else
                        low = mid;
                }

                if (high != n - i)
                    v2 = high;
            }
            res.pb(min(v1, v2));
        }

        for (int i = 0; i < n; i++)
        {
            cout << (res[i] == inf ? -1 : res[i]) << ' ';
        }

        cout << '\n';
    }
}
