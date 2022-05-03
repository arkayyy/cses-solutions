#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void dfs(int x, int y, int r,int c,  vector<vector<char>>& hotel, vector<vector<bool>>&visited)
{
    visited[x][y] = true;

    if(x+1<r && !visited[x+1][y])
        dfs(x+1,y,r,c,hotel,visited);
    if(x-1>=0 && !visited[x-1][y])
        dfs(x-1,y,r,c,hotel,visited);
    if(y+1<c && !visited[x][y+1])
        dfs(x,y+1,r,c,hotel,visited);
    if(y-1>=0 && !visited[x][y-1])
        dfs(x,y-1,r,c,hotel,visited);
}

void solve()
{
    int r, c;
    cin>>r>>c;
    vector<vector<char>> hotel(r, vector<char>(c,'#'));
    vector<vector<bool>> visited(r, vector<bool>(c,false));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='#')
                visited[i][j] = true;
            hotel[i][j] = ch;
        }
    }



    int cc = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        {
            if(!visited[i][j])
            {
                dfs(i,j,r,c,hotel,visited);
                cc++;
            }
        }
    }

    cout<<cc;

    


}


int main()
{
    IOS;
    // #ifdef LOCAL
    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    // #ifdef LOCAL
    // clock_t tStart = clock();
    // cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    // #endif
    return 0;
}