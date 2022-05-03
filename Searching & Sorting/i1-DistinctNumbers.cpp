#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;



int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin >> n;
    unordered_map<lli,lli> nums;
    lli i = 0;
    lli c = 0;
    lli t;
    while (i < n)
    {
        
        cin >> t;
        if(nums.find(t)==nums.end())
        {nums[t] = 1;c++;}
        i++;
    }

    cout << c;
    return 0;
}