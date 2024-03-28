#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;

        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                for (j = 0; j < n; j++)
                {
                    if (j % 2 == 0)
                        cout << "##";
                    else
                        cout << "..";
                }
                cout << '\n';
                for (j = 0; j < n; j++)
                {
                    if (j % 2 == 0)
                        cout << "##";
                    else
                        cout << "..";
                }
            }
            else
            {
                for (j = 0; j < n; j++)
                {
                    if (j % 2 == 0)
                        cout << "..";
                    else
                        cout << "##";
                }
                cout << '\n';
                for (j = 0; j < n; j++)
                {
                    if (j % 2 == 0)
                        cout << "..";
                    else
                        cout << "##";
                }
            }
            cout << '\n';
        }
    }
    return 0;
}