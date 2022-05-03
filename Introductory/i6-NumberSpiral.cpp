#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int r, c;
        cin >> r >> c;
        long long int ans; //final ans to be stored
        long long int rindex = r - 1, cindex = c - 1;
        bool rowStart = false;
        if (r > c)
            rowStart = true;

        if (rowStart)
        {
            long long int oadder = 3;
            long long int start = 1, end = 1;
            long long int i = 0;

            if (r == 2)
                start = 2;
            if (r > 2)
                start = ((((r - 1)) * ((2) + ((r - 2) * 2))) >> 1) + 1; // Arithmetic progression sum

            end = (((r)) * ((2) + ((r - 1) * 2))) >> 1; // Arithmetic progression sum

            //LOOPING GIVES TLE

            // while(i<rindex)
            // {
            //     rowStart = !rowStart;
            //     start = end+1;
            //     end+=oadder;
            //     oadder+=2;
            //     i++;
            // }
            if (r & 1 == 1)
            {
                ans = start + cindex;
            }
            else
            {
                ans = end - cindex;
            }
        }
        else
        {
            bool colStart = false;
            long long int oadder = 3;
            long long int i = 0;
            long long int start = 1, end = 1;
            if (c == 2)
                start = 2;
            if (c > 2)
                start = (((((c - 1)) * ((2) + ((c - 2) * 2)))) >> 1) + 1; // Arithmetic progression sum

            end = (((c)) * ((2) + ((c - 1) * 2))) >> 1; // Arithmetic progression sum

            // while(i<cindex)
            // {
            //     colStart=!colStart;
            //     start = end+1;
            //     end+=oadder;
            //     oadder+=2;
            //     i++;
            // }

            if (c & 1 == 1)
            {
                ans = end - rindex;
            }
            else
            {

                ans = start + rindex;
            }
        }

        cout << ans << endl;
    }
    return 0;
}