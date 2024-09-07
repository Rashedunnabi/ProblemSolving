#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int n, int i, vector<vector<string>> &ans, vector<string> &v, vector<bool> &left, vector<bool> &right, vector<bool> &col)
    {
        if (i == n)
        {
            ans.push_back(v);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            int l = i + j, r = i - j + n;
            if (col[j] || left[l] || right[r])
                continue;

            col[j] = left[l] = right[r] = true;
            v[i][j] = 'Q';
            func(n, i + 1, ans, v, left, right, col);
            col[j] = left[l] = right[r] = false;
            v[i][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);

        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;

        vector<bool> left(2 * n), right(2 * n), col(n + 1);
        func(n, 0, ans, v, left, right, col);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution ob;
    auto it = ob.solveNQueens(n);
    for (auto v : it)
    {
        for (auto val : v)
            cout << val << '\n';
        cout << '\n';
    }
    return 0;
}
