#include <bits/stdc++.h>
using namespace std;

long long int longestRepLength(string str)
{
    if(str.length()==1)
        return 1;
    long long int i = 0, n = (long long int)(str.length()), maxc = INT_MIN;
    while (i < n - 1)
    {
        long long int c = 1;
        while (str[i] == str[i + 1])
           { c++;i++;}

        maxc = max(maxc, c);
        i++;
    }
    return maxc;
}

int main()
{
    string str;
    cin>>str;
    cout << longestRepLength(str);
    return 0;
}