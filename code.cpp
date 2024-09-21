#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, d, k;
        cin >> n >> d >> k;
        vector<pair<int, int>> jobs(k);
        for (int i = 0; i < k; i++)
        {
            cin >> jobs[i].first >> jobs[i].second;
        }
        sort(jobs.begin(), jobs.end());
        auto calc_overlap = [&](int start)
        {
            int cnt = 0;
            for (auto job : jobs)
            {
                if (max(job.first, start) <= min(job.second, start + d - 1))
                    cnt++;
            }
            return cnt;
        };

        int maxi = 0, mini = k + 1, bro = 1, mom = 1;
        for (int i = 1; i <= n - d + 1; i++)
        {
            int val = calc_overlap(i);
            if (val > maxi)
            {
                maxi = val;
                bro = i;
            }
            if (val < mini)
            {
                mini = val;
                mom = i;
            }
        }
        cout << bro << ' ' << mom << '\n';
    }

    return 0;
}
