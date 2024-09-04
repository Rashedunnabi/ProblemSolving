#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int ind, vector<vector<int>> &ans, vector<int> &v, vector<int> &ar)
    {
        ans.push_back(v);
        for (int i = ind; i < ar.size(); i++)
        {
            if (i == ind || ar[i - 1] != ar[i])
            {
                v.push_back(ar[i]);
                func(i + 1, ans, v, ar);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &ar)
    {
        sort(ar.begin(), ar.end());
        vector<vector<int>> ans;
        vector<int> v;
        func(0, ans, v, ar);
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
        auto it = ob.subsetsWithDup(arr);

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