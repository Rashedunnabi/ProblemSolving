#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int k, int start, vector<vector<int>> &ans, vector<int> &v, int target)
    {
        if (k == 0 && target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            if (i > target)
                break;
            v.push_back(i);
            func(k - 1, i + 1, ans, v, target - i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        func(k, 1, ans, v, target);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
    }
    return 0;
}