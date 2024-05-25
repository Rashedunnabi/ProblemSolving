#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<pair<int, int>> vp; // value,type
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
    }
    sort(vp.begin(), vp.end());
    int n = vp.size(), r = 0, mini = LONG_LONG_MAX, ind = -1, cnt = 0;
    vector<int> freq(4);
    for (int l = 0; l < n; l++)
    {
        while (r < n && cnt < 4)
        {
            freq[vp[r].second]++;
            if (freq[vp[r].second] == 1)
                cnt++;
            r++;
        }
        if (cnt == 4)
        {
            int diff = vp[r - 1].first - vp[l].first;
            if (diff < mini)
            {
                mini = diff;
                ind = l;
            }
        }
        freq[vp[l].second]--;
        if (freq[vp[l].second] == 0)
            cnt--;
    }
    freq[0] = freq[1] = freq[2] = freq[3] = cnt = 0;
    for (int i = ind; i < n; i++)
    {
        if (freq[vp[i].second] == 0)
        {
            cnt++;
            freq[vp[i].second] = vp[i].first;
        }
        if (cnt == 4)
            break;
    }
    for (auto val : freq)
        cout << val << ' ';
    cout << '\n';

    return 0;
}