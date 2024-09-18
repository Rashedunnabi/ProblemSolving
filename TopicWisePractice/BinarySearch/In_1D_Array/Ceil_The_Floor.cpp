#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    pair<int, int> p;
    // Find the iterator pointing to the first element not less than x
    auto it = lower_bound(a.begin(), a.end(), x);
    // Determine the ceil value
    if (it != a.end())
        p.second = *it; // Ceil is the element at lower_bound
    else
        p.second = -1; // No element greater than or equal to x

    // Determine the floor value
    if (it != a.begin())
    {
        if (it != a.end() && *it == x)
            p.first = *it; // If exact element found, floor is x itself
        else
            p.first = *(--it); // Floor is the previous element
    }
    else
    {
        p.first = -1; // No element smaller than or equal to x
    }

    return p; // Return the pair (floor, ceil)
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;

    pair<int, int> result = getFloorAndCeil(arr, arr.size(), x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;

    return 0;
}
