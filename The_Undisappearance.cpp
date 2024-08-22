#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int left, int right, int x, vector<int> &arr)
{
    int n = arr.size();
    if (left == -1 || right == -1)
        return 0;

    int cnt = count(arr.begin() + left, arr.begin() + right + 1, x);
    if (cnt > 0)
        return 0;

    int leftExt = left;
    while (leftExt > 0 && arr[leftExt - 1] != x)
        leftExt--;

    int rightExt = right;
    while (rightExt < n - 1 && arr[rightExt + 1] != x)
        rightExt++;

    return (left - leftExt + 1) * (rightExt - right + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        int fa = -1, la = -1, fb = -1, lb = -1, fc = -1, lc = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                if (fa == -1)
                    fa = i;
                la = i;
            }
            else if (arr[i] == 2)
            {
                if (fb == -1)
                    fb = i;
                lb = i;
            }
            else if (arr[i] == 3)
            {
                if (fc == -1)
                    fc = i;
                lc = i;
            }
        }

        int total = 1LL * n * (n + 1) / 2;
        total -= func(fa, la, 3, arr);
        total -= func(fb, lb, 1, arr);
        total -= func(fc, lc, 2, arr);

        cout << total << endl;
    }
    return 0;
}
