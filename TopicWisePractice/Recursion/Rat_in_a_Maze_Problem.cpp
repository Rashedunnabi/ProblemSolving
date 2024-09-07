#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void func(int i, int j, string &s, vector<string> &ans, vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (i == n - 1 && j == n - 1 && mat[i][j] == 1)
        {
            ans.push_back(s);
            return;
        }
        if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0)
            return;

        mat[i][j] = 0;

        s.push_back('U');
        func(i - 1, j, s, ans, mat);
        s.pop_back();

        s.push_back('D');
        func(i + 1, j, s, ans, mat);
        s.pop_back();

        s.push_back('L');
        func(i, j - 1, s, ans, mat);
        s.pop_back();

        s.push_back('R');
        func(i, j + 1, s, ans, mat);
        s.pop_back();

        mat[i][j] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        string s;
        vector<string> ans;
        func(0, 0, s, ans, mat);

        if (ans.size() == 0)
            ans.push_back("-1");

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n;
    m = n;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    Solution ob;
    auto v = ob.findPath(mat);
    for (auto val : v)
        cout << val << '\n';
    return 0;
}