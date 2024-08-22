#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int N = 510;
char arr[N][N];

void solution()
{
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cin >> arr[i][j];
    }

    char leftUpper = arr[1][1], leftDown = arr[n][1], rightUpper = arr[1][m], rightDown = arr[n][m];
    bool flag = false;
    if (leftUpper == rightDown || leftDown == rightUpper)
        flag = 1;

    if (leftUpper == leftDown)
    {
        for (i = 1; i <= n; i++)
        {
            if (arr[i][m] == leftUpper)
                flag = 1;
        }
    }

    if (leftUpper == rightUpper)
    {
        for (i = 1; i <= m; i++)
        {
            if (arr[n][i] == leftUpper)
                flag = 1;
        }
    }

    if (rightDown == leftDown)
    {
        for (i = 1; i <= m; i++)
        {
            if (arr[1][i] == rightDown)
                flag = 1;
        }
    }
    if (rightDown == rightUpper)
    {
        for (i = 1; i <= n; i++)
        {
            if (arr[i][1] == rightDown)
                flag = 1;
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
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