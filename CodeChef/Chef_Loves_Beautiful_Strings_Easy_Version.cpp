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
        int n;
        string s;
        cin >> n >> s;
        priority_queue<int> pq;
        int ans = 0, cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
                cnt++;
            else
            {
                pq.push(cnt);
                cnt = 1;
            }
        }
        pq.push(cnt);
        while (pq.size() > 1)
        {
            int num = pq.top();
            pq.pop();
            num--;
            if (num > 0)
                pq.push(num);
            ans += pq.size() - 1;
        }
        cout << ans << endl;
    }
    return 0;
}