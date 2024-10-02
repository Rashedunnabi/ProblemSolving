#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int max_row = -1, max_number = 0, n = arr.size(), m = arr[0].size();
        for (int i = 0; i < n; i++)
        {
            int lo = -1, hi = m;
            while (hi - lo > 1)
            {
                int mid = (hi + lo) / 2;
                if (arr[i][mid] == 1)
                    hi = mid;
                else
                    lo = mid;
            }
            if (m - hi > max_number)
            {
                max_number = m - hi;
                max_row = i;
            }
        }
        return max_row;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    Solution ob;
    cout << ob.rowWithMax1s(arr) << '\n';

    return 0;
}