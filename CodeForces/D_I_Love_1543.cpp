#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto &it : v)
            cin >> it;

        int top = 0, down = n - 1, left = 0, right = m - 1, ans = 0;
        while (top <= down && left <= right)
        {
            string s;
            for (int j = left; j <= right; j++)
                s.push_back(v[top][j]);
            top++;
            for (int i = top; i <= down; i++)
                s.push_back(v[i][right]);
            right--;

            if (top <= down)
            {
                for (int j = right; j >= left; j--)
                    s.push_back(v[down][j]);
                down--;
            }
            if (left <= right)
            {
                for (int i = down; i >= top; i--)
                    s.push_back(v[i][left]);
                left++;
            }
            s += s.substr(0, 3);

            for (int i = 0; i < s.length() - 3; i++)
                ans += s.substr(i, 4) == "1543";
        }
        cout << ans << '\n';
    }
    return 0;
}