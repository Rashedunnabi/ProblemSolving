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
        string s;
        cin >> s;

        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3, 2));

        string period;
        if (hour >= 12)
        {
            period = "PM";
            if (hour > 12)
                hour -= 12;
        }
        else
        {
            period = "AM";
            if (hour == 0)
                hour = 12;
        }

        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << period << endl;
    }
    return 0;
}