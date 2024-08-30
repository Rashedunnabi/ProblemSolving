#include <bits/stdc++.h>
using namespace std;

void func(vector<vector<int>> &ans, vector<int> &v, vector<int> &nums, int i)
{
    if (i == nums.size())
    {
        ans.push_back(v);
        return;
    }
    func(ans, v, nums, i + 1); // not take
    v.push_back(nums[i]);
    func(ans, v, nums, i + 1); // take
    v.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> v;
    func(ans, v, nums, 0);
    return ans;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    auto it = subsets(v);
    for (auto val : it)
    {
        for (auto e : val)
            cout << e << ' ';
        cout << '\n';
    }
    cout << '\n';
}