#include <bits/stdc++.h>
using namespace std;

bool check(int mid, const string &s, const string &t, const vector<int> &indices)
{
    unordered_set<int> deleted;
    for (int i = 0; i < mid; ++i)
        deleted.insert(indices[i]);

    int j = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (deleted.count(i))
            continue;
        if (s[i] == t[j])
            ++j;
        if (j == t.size())
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    vector<int> indices(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> indices[i];
        --indices[i]; // Adjust indices to 0-based indexing
    }

    int lo = 0, hi = n, ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, s, t, indices))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
