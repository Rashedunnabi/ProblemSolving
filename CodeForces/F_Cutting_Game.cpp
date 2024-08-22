#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, n, m, i;
        cin >> a >> b >> n >> m;

        vector<pair<int, int>> vertical, horizondal;
        for (i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            vertical.emplace_back(x, y);
            horizondal.emplace_back(y, x);
        }
        sort(vertical.begin(), vertical.end());
        sort(horizondal.begin(), horizondal.end());

        set<pair<int, int>> deleted;
        vector<int> ans(2);
        int up = 1, down = a;
        int left = 1, right = b;
        int verticalLeft = 0, verticalRight = n - 1;
        int horizondalLeft = 0, horizondalRight = n - 1;
        for (i = 0; i < m; i++)
        {
            int x;
            char ch;
            cin >> ch >> x;

            if (ch == 'U')
            {
                up += x;
                while (verticalLeft <= verticalRight && vertical[verticalLeft].first < up)
                {
                    if (deleted.find(vertical[verticalLeft]) == deleted.end())
                    {
                        ans[i % 2]++;
                        deleted.insert(vertical[verticalLeft]);
                    }
                    verticalLeft++;
                }
            }
            if (ch == 'D')
            {
                down -= x;
                while (verticalLeft <= verticalRight && vertical[verticalRight].first > down)
                {
                    if (deleted.find(vertical[verticalRight]) == deleted.end())
                    {
                        ans[i % 2]++;
                        deleted.insert(vertical[verticalRight]);
                    }
                    verticalRight--;
                }
            }
            if (ch == 'L')
            {
                left += x;
                while (horizondalLeft <= horizondalRight && horizondal[horizondalLeft].first < left)
                {
                    if (deleted.find({horizondal[horizondalLeft].second, horizondal[horizondalLeft].first}) == deleted.end())
                    {
                        ans[i % 2]++;
                        deleted.insert({horizondal[horizondalLeft].second, horizondal[horizondalLeft].first});
                    }
                    horizondalLeft++;
                }
            }
            if (ch == 'R')
            {
                right -= x;
                while (horizondalLeft <= horizondalRight && horizondal[horizondalRight].first > right)
                {
                    if (deleted.find({horizondal[horizondalRight].second, horizondal[horizondalRight].first}) == deleted.end())
                    {
                        ans[i % 2]++;
                        deleted.insert({horizondal[horizondalRight].second, horizondal[horizondalRight].first});
                    }
                    horizondalRight--;
                }
            }
        }
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    return 0;
}