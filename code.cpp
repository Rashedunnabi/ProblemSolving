#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int minOperationsToUnite(const string &s)
{
    map<char, ll> mp;
    for (char c : s)
        mp[c]++;
    ll mini = s.size();
    for (auto val : mp)
    {
        char ch = val.first;
        int p = val.second;
        ll m = 0;
        for (int i = 0; i < p; ++i)
        {
            if (s[i] == ch)
                m++;
        }
        mini = min(mini, abs(p - m));
        for (int i = p; i < s.size(); ++i)
        {
            if (s[i - p] == ch)
                m--;
            if (s[i] == ch)
                m++;
            mini = min(mini, abs(p - m));
        }
    }

    return mini;
}

int main()

{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)

    {

        string s;

        cin >> s;

        cout << minOperationsToUnite(s) << endl;
    }

    return 0;
}
