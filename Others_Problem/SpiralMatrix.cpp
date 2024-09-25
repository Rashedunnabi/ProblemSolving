#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &ar)
{
    vector<int> v;
    int row = ar.size(), col = ar[0].size();
    int top = 0, down = row - 1, left = 0, right = col - 1;
    while (top <= down && left <= right)
    {
        for (int j = left; j <= right; j++)
            v.push_back(ar[top][j]);
        top++;
        for (int i = top; i <= down; i++)
            v.push_back(ar[i][right]);
        right--;

        if (top <= down)
        {
            for (int j = right; j >= left; j--)
                v.push_back(ar[down][j]);
            down--;
        }
        if (left <= right)
        {
            for (int i = down; i >= top; i--)
                v.push_back(ar[i][left]);
            left++;
        }
    }
    return v;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> ar[i][j];
    }

    auto v = spiral(ar);
    for (auto val : v)
        cout << val << ' ';
    cout << '\n';
    return 0;
}
