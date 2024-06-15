#include <bits/stdc++.h>
using namespace std;

int main()
{
    char arr[3][4];
    memset(arr, 'x', sizeof(arr));
    for (int i = 0; i < 3; i++)
    {
        // cout << arr[i] << ' ';
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
