#include <bits/stdc++.h>
using namespace std;

int allCombos(int n,int moves, int& cnt, vector<int> &dp) 
{
    if(n<0)
        return INT_MAX;
    
    if(dp[n]!=-1 )
        return dp[n];

    if(n==0)
    {
        // ans.push_back(move);
        cnt++;
        return moves;
    }

     int mini=INT_MAX;

    for(int i=1;i<=6;i++)
    {
        mini = min(mini,allCombos(n-i,moves+1,cnt,dp));
    }

    return dp[n]=mini;
  
}

int main()
{   int c=0;
vector<int> dp(5,-1);
    int d = allCombos(4,0,c,dp);
    cout<<c<<endl;
    return 0;
}