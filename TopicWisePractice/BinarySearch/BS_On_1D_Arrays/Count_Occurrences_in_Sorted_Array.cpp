#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

int count(vector<int> &nums, int n, int target)
{
    auto i1 = lower_bound(nums.begin(), nums.end(), target);
    auto i2 = upper_bound(nums.begin(), nums.end(), target);
    return (i2 - i1); // Return the count of target
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int result = count(nums, nums.size(), target);
    cout << "Number of occurrences of " << target << " is: " << result << endl;

    return 0;
}
