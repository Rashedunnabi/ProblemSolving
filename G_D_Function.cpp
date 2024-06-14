#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int countValidNumbers(int l, int r, int k)
{
    if (k == 1)
    {
        // When k == 1, every number in the range [10^l, 10^r) satisfies the condition
        return (r - l) * 9 % MOD;
    }

    int count = 0;
    int start = 1;
    for (int i = 0; i < l; ++i)
        start *= 10;
    int end = start * 10;

    for (int i = start; i < end; ++i)
    {
        int sum_digits = 0, x = i;
        while (x)
        {
            sum_digits += x % 10;
            x /= 10;
        }
        int kn = k * i;
        int kn_sum_digits = 0;
        while (kn)
        {
            kn_sum_digits += kn % 10;
            kn /= 10;
        }
        if (kn_sum_digits == k * sum_digits)
        {
            ++count;
        }
    }

    return count % MOD;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> results(t);

    for (int case_num = 0; case_num < t; ++case_num)
    {
        int l, r, k;
        cin >> l >> r >> k;

        if (l == r - 1)
        {
            results[case_num] = countValidNumbers(l, r, k);
        }
        else
        {
            int count = 0;
            for (int i = l; i < r; ++i)
            {
                count = (count + countValidNumbers(i, i + 1, k)) % MOD;
            }
            results[case_num] = count;
        }
    }

    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
