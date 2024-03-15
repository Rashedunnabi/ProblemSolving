#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
void solution()
{
    int n, i, j, cnt = 0;
    cin >> n;

    char arr[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == '1' && arr[i + 1][j] == '1' && arr[i][j + 1] == '1')
            {
                cout << "SQUARE\n";
                return;
            }
            if (arr[i][j] == '1')
            {
                cout << "TRIANGLE\n";
                return;
            }
        }
    }
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}