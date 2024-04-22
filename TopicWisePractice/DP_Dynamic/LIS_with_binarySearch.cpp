#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end())
            lis.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return lis.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}
