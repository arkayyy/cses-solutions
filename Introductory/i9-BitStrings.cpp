#include<bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long bin_exp(long long a, long long b)
{
    if(b==0) return 1;

    long long res = 1;
    if(b%2!=0) //if remaining power is ODD
        res = a;

    return (res%MOD *bin_exp(a,b/2)%MOD *bin_exp(a,b/2)%MOD)%MOD;
        
}

int main()
{
    long long n;
    cin>>n;
    cout<<bin_exp(2,n)%MOD<<endl;
    return 0;
}