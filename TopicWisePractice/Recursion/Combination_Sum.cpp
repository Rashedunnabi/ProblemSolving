#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int index, vector<vector<int>> &ans, vector<int> &v, vector<int> &ar, int target)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < ar.size(); i++)
        {
            if (target - ar[i] >= 0)
            {
                v.push_back(ar[i]);
                func(i, ans, v, ar, target - ar[i]);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &ar, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        func(0, ans, v, ar, target);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto it = ob.combinationSum(arr, target);

        for (auto v : it)
        {
            for (auto val : v)
                cout << val << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}