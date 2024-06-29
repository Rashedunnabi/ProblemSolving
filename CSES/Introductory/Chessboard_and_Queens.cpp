#include <bits/stdc++.h>
using namespace std;

int ans;

char arr[10][10];
int column[30], rightA[30], leftA[30];

void func(int r)
{
    if (r == 8)
    {
        ans++;
        return;
    }

    for (int c = 0; c < 8; c++)
    {
        if (column[c] == 0 && rightA[r - c + 7] == 0 && leftA[r + c] == 0 && arr[r][c] == '.')
        {
            column[c] = rightA[r - c + 7] = leftA[r + c] = 1;
            func(r + 1);
            column[c] = rightA[r - c + 7] = leftA[r + c] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            cin >> arr[i][j];
    }
    func(0);
    cout << ans << endl;

    return 0;
}