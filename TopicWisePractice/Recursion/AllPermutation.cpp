#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int index, vector<vector<int>> &ans, vector<int> &ar)
    {
        if (index == ar.size())
        {
            ans.push_back(ar);
            return;
        }
        for (int i = index; i < ar.size(); i++)
        {
            swap(ar[index], ar[i]);
            func(index + 1, ans, ar);
            swap(ar[index], ar[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &ar)
    {
        vector<vector<int>> ans;
        func(0, ans, ar);
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
        auto it = ob.permute(arr);
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