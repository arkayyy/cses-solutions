#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<long long > s1, s2;
   
    long long n;
    cin>>n;

    long long sumAll = (n*(n+1))/2;

    if(sumAll%2!=0) { cout<<"NO"<<endl; return 0;}

    long long target = sumAll/2;

    long long diff = n;

    for(long long i = 1; i<=n; i++)
        s1.insert(i);

    while(s1.count(target)==0)
    {
        target -= diff;
        s1.erase(diff);
        s2.insert(diff);
        diff--;
    }

    s1.erase(target);
    s2.insert(target);

    cout<<"YES"<<endl;

    cout<<s1.size()<<endl;
    for(auto s: s1)
        cout<<s<<" ";
    
    cout<<endl;

    cout<<s2.size()<<endl;
    for(auto s: s2)
        cout<<s<<" ";

    return 0;

    return 0;

}