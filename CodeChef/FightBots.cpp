#include <bits/stdc++.h>
using namespace std;

int Xmove(char ch)
{
    if (ch == 'R')
        return 1;
    if (ch == 'L')
        return -1;
    else
        return 0;
}
int Ymove(char ch)
{
    if (ch == 'U')
        return 1;
    if (ch == 'D')
        return -1;
    else
        return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {

        int n, a, b, x = 0, y = 0, time = 0;
        cin >> n >> a >> b;

        vector<pair<pair<int, int>, int>> vp; // point with time
        vp.push_back({{x, y}, time});

        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;

            x += Xmove(ch);
            y += Ymove(ch);
            time++;
            vp.push_back({{x, y}, time});
        }

        bool flag = false;
        for (auto val : vp)
        {
            int xx = val.first.first, yy = val.first.second, tt = val.second;

            int dis = abs(xx - a) + abs(yy - b);
            if (dis <= tt && abs(dis - tt) % 2 == 0)
                flag = true;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}