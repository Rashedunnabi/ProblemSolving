#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(v) v.begin(), v.end()

void solution()
{
    int n, i;
    cin >> n;
    char trumpCard;
    cin >> trumpCard;

    map<char, deque<int>> mp;
    for (i = 0; i < n + n; i++)
    {
        int x;
        char ch;
        cin >> x >> ch;
        mp[ch].push_back(x);
    }
    for (auto &val : mp)
    {
        sort(val.second.begin(), val.second.end());
    }

    vector<pair<string, string>> vp;
    for (auto &val : mp)
    {
        if (val.first == trumpCard)
            continue;

        while (val.second.size() >= 2)
        {
            int x = val.second.back(), y = val.second.front();
            val.second.pop_back(), val.second.pop_front();
            string s1 = to_string(x) + val.first;
            string s2 = to_string(y) + val.first;
            vp.push_back({s1, s2});
            if (val.second.size() <= 1)
            {
                break;
            }
        }
    }

    for (auto &val : mp)
    {
        if (val.first == trumpCard)
            continue;
        if (val.second.size() == 0)
            continue;
        if (mp[trumpCard].size() == 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        int x = val.second.back(), y = mp[trumpCard].front();
        val.second.pop_back(), mp[trumpCard].pop_front();
        string s1 = to_string(x) + val.first;
        string s2 = to_string(y) + trumpCard;
        vp.push_back({s2, s1});
    }

    if (mp[trumpCard].size() & 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (i = 0; i < mp[trumpCard].size(); i += 2)
    {
        int x = mp[trumpCard][i + 1], y = mp[trumpCard][i];

        string s1 = to_string(x) + trumpCard;
        string s2 = to_string(y) + trumpCard;
        vp.push_back({s1, s2});
    }

    for (auto val : vp)
    {
        cout << val.second << ' ' << val.first << '\n';
    }
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}