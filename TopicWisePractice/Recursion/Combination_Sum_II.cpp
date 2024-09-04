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
            if (i > index && ar[i] == ar[i - 1])
                continue;
            if (ar[i] > target)
                break;

            v.push_back(ar[i]);
            func(i + 1, ans, v, ar, target - ar[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &ar, int target)
    {
        sort(ar.begin(), ar.end());
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
        auto it = ob.combinationSum2(arr, target);

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