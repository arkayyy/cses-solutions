#include <bits/stdc++.h>
using namespace std;

void permutations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin >> n;
    vector<long long int> out;
    long long int j = 1;

    if (n == 1)
    {
        cout << 1;
        return;
    }
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return;
    }

    j = 2;
    while (j <= n)
    {
        out.push_back(j);
        j += 2;
    }
    j = 1;
    while (j <= n)
    {
        out.push_back(j);
        j += 2;
    }

    for (auto i : out)
    {
        cout << i << " ";
    }
}

int main()
{

    permutations();

    return 0;
}
