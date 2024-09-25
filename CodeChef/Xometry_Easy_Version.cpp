#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int val = *max_element(v.begin(), v.end());
        int lg = log2(val) + 1;
        int sz = 1LL << lg;
        vector<int> freq(sz);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xor_value = v[i] ^ v[j];
                cnt += freq[xor_value];
                freq[xor_value]++;
            }
        }
        cout << (cnt * 8) << '\n';
    }
    return 0;
}
