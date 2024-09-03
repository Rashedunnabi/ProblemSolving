#include <bits/stdc++.h>
using namespace std;
#define int long long

map<char, vector<int>> odd;
map<char, vector<int>> even;

int func(int index)
{
    int mOdd = 0, mEven = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        vector<int> &od = odd[ch];
        vector<int> &ev = even[ch];
        auto it1 = lower_bound(od.begin(), od.end(), index);
        auto it2 = lower_bound(ev.begin(), ev.end(), index);

        int f = distance(od.begin(), it1), s = distance(it1, od.end());
        int ff = distance(ev.begin(), it2), ss = distance(it2, ev.end());
        if (it1 != od.end() && *it1 == index)
            s--;
        if (it2 != ev.end() && *it2 == index)
            ss--;

        mOdd = max(mOdd, f + ss);
        mEven = max(mEven, ff + s);
    }
    return (mOdd + mEven);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        odd.clear();
        even.clear();

        int n;
        string s;
        cin >> n >> s;

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                odd[s[i]].push_back(i);
            else
                even[s[i]].push_back(i);
        }

        int maxi1 = -1, maxi2 = -1;
        for (auto val : odd)
            maxi1 = max(maxi1, (int)val.second.size());
        for (auto val : even)
            maxi2 = max(maxi2, (int)val.second.size());

        if (n % 2 == 0)
        {
            int ans = n - maxi1 - maxi2;
            cout << ans << '\n';
        }
        else
        {
            int maxi = -1, index = -1;
            for (int i = 0; i < n; i++)
            {
                int x = func(i);
                maxi = max(maxi, x);
            }
            int ans = n - maxi;
            cout << ans << '\n';
        }
    }
    return 0;
}