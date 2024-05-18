#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    vector<int> arr(n), mp(100010);
    for (int &i : arr)
        cin >> i;

    long long l = 0, ans = 0, count = 0;
    for (int r = 0; r < n; r++)
    {
        mp[arr[r]]++;
        if (mp[arr[r]] == 1)
            count++;

        while (count > k)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
                count--;
            l++;
        }
        ans += (r - l + 1LL);
    }
    cout << ans << "\n";

    return 0;
}
