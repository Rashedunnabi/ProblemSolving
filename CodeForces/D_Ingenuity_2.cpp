#include <bits/stdc++.h>
using namespace std;
#define ll long long

void type1(string &ans, vector<int> &v1, vector<int> &v2)
{
    int h = count(ans.begin(), ans.end(), 'H');
    int r = count(ans.begin(), ans.end(), 'R');
    bool turn = (h == 0);
    int mn = min(v1.size(), v2.size());
    while (mn--)
    {
        int x = v1.back();
        v1.pop_back();
        int y = v2.back();
        v2.pop_back();

        if (turn)
            ans[x] = ans[y] = 'H';
        else
            ans[x] = ans[y] = 'R';
        turn ^= 1;
    }
}

void type2(string &ans, vector<int> &v)
{
    int h = count(ans.begin(), ans.end(), 'H');
    int r = count(ans.begin(), ans.end(), 'R');
    bool turn = (h == 0);
    while (v.size())
    {
        int ind = v.back();
        v.pop_back();
        ans[ind] = (turn ? 'H' : 'R');
        turn ^= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        string s;
        cin >> n >> s;

        map<char, int> dx, dy;
        dx['S'] = 1, dx['N'] = -1, dx['E'] = 0, dx['W'] = 0;
        dy['S'] = 0, dy['N'] = 0, dy['E'] = 1, dy['W'] = -1;

        vector<int> south, north, east, west;
        string ans(n, '0');

        int x = 0, y = 0;
        for (i = 0; i < n; i++)
        {
            x += dx[s[i]];
            y += dy[s[i]];
            if (s[i] == 'S')
                south.push_back(i);
            if (s[i] == 'N')
                north.push_back(i);
            if (s[i] == 'E')
                east.push_back(i);
            if (s[i] == 'W')
                west.push_back(i);
        }

        if (abs(x) & 1 || abs(y) & 1)
        {
            cout << "NO\n";
            continue;
        }
        if (!x && !y && n == 2)
        {
            cout << "NO\n";
            continue;
        }

        type1(ans, north, south);
        type1(ans, east, west);
        type2(ans, south);
        type2(ans, north);
        type2(ans, west);
        type2(ans, east);

        cout << ans << '\n';
    }
    return 0;
}