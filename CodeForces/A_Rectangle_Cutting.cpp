#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);

    if (a & 1 && b & 1)
        no;
    else if (a % 2 == 0 && b % 2 == 0)
    {
        int c = a / 2;
        int r = b + b;

        if (max(r, c) != max(a, b) || min(r, c) != min(a, b))
        {
            yes;
            return;
        }

        c = b / 2;
        r = a + a;

        if (max(r, c) == max(a, b) && min(r, c) == min(a, b))
            no;
        else
            yes;
    }
    else
    {
        if (b % 2 == 0)
            swap(a, b);

        int c = a / 2;
        int r = b + b;

        if (max(r, c) == max(a, b) && min(r, c) == min(a, b))
            no;
        else
            yes;
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