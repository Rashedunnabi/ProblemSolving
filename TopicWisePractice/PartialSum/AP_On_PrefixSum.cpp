/*
Need to calculate the Arithmatic Progesssion between L...R
a[L]*1+a[L+1]*2+a[L+2]*3.......+a[R-L+1]
the result can very big return modulo 1e9+7
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 7, mod = 1e9 + 7;
int ar[N], preSum[N], B[N], preMul[N];

//  here we contain 1 based index
//  preSum contain prefix Sum of the aray a[i]=a[1]+a[2]+a[3]+....+a[i]
//  PreB[i]=a[1]*1+a[2]*2+a[3]*3+a[4]*4

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> ar[i];
        preSum[i] = preSum[i - 1] + ar[i];
        preMul[i] = preMul[i - 1] + (ar[i] * i);

        preSum[i] %= mod;
        preMul[i] %= mod;
    }

    // for (i = 1; i <= n; i++)
    //     cout << preSum[i] << ' ';
    // cout << '\n';

    int q;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r;
        int left = preMul[r] - preMul[l - 1];
        int right = (1 - l) * (preSum[r] - preSum[l - 1]);
        int ans = left + right;
        cout << ans << '\n';
    }

    return 0;
}