#include <iostream>
using namespace std;
int build_num(int bit[])
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
        if (bit[i])
            ans += (1 << i);

    return ans;
}
bool maximumOR(int arr[], int n, int k)
{
    int bit[32] = {0};
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i] & (1 << j))
                bit[j]++;
        }
    }

    int preOr = build_num(bit);

    for (int i = k; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i - k] & (1 << j))
                bit[j]--;
        }
        for (int j = 0; j < 32; j++)
        {
            if (arr[i] & (1 << j))
                bit[j]++;
        }
        int newOr = build_num(bit);
        if (newOr != preOr)
            return false;
    }
    return true;
}

// Driver Code
int main()
{
    // Given array arr[]
    int arr[] = {2, 5, 3, 6, 11, 13};

    // Given subarray size K
    int k = 3;
    int n = sizeof arr / sizeof arr[0];

    // Function Call
    cout << maximumOR(arr, n, k);

    return 0;
}
