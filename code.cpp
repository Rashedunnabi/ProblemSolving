#include <bits/stdc++.h>
using namespace std;
int build_num(int bit[])
{
    int ans = 0;
    for (int i = 0; i < 21; i++)
        if (bit[i])
            ans += (1 << i);

    return ans;
}
bool check(int k, vector<int> &arr)
{
    int n = arr.size();

    int bit[21] = {0};
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (arr[i] & (1 << j))
                bit[j]++;
        }
    }
    int preOr = build_num(bit);
    for (int i = k; i < n; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (arr[i - k] & (1 << j))
                bit[j]--;
            if (arr[i] & (1 << j))
                bit[j]++;
        }
        int newOr = build_num(bit);
        if (newOr != preOr)
            return false;
    }
    return true;
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        int n, i;
        scanf("%d", &t);
        vector<int> v(n);
        for (i = 0; i < n; i++)
            scanf("%d", &v[i]);

        int lo = 0, hi = n, mid;
        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            if (check(mid, v))
                hi = mid;
            else
                lo = mid;
        }
        printf("%d\n", hi);
    }
    return 0;
}