#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    lli n;
    cin>>n;
    vector<lli> a(n,0);
    lli i=0;
    while(i<n)
    {
        cin>>a[i++];
    }
    lli ans = 0;
    lli x = 1; // increment that can be done
    for(lli i=1;i<n;i++)
    {
        if(a[i]<a[i-1])  // if the elements have to be made strictly increasing (equal not allowed), then we have to check for if(a[i]<=a[i-1])
        {
            lli p = (a[i-1]-a[i]) ;  //if the elements have to be made strictly increasing from the previous element, p=(a[i-1]-a[i])+1 
            ans+=p;
            a[i]+=(p);
        }
    }
     cout<<ans;
     return 0;
}