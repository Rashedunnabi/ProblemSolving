#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        ll k;
        cin >> n >> k;

        deque<int> dq(n);
        for (auto &e : dq)
            cin >> e;

        while (dq.size() > 1 && k)
        {
            int mini = min(dq.back(), dq.front());
            if (k >= 2 * mini)
            {
                dq.front() -= mini;
                dq.back() -= mini;
                k -= 2 * mini;
            }
            else
            {
                dq.front() -= (k + 1) / 2; // ceil
                dq.back() -= k / 2;        // floor
                k = 0;
            }
            if (dq.front() == 0)
                dq.pop_front();
            if (dq.back() == 0)
                dq.pop_back();
        }
        int ans = n - dq.size();
        if (dq.size() && dq.front() <= k)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}