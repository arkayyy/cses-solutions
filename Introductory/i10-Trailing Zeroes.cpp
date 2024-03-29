#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

//-----------------------------------------MACROS---------------------------------------------------------------//
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
 
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
 
#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define len(ds) ds.size()
#define pb emplace_back
#define ALL(v) v.begin(), v.end()
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define arlen(a) sizeof(a)/sizeof(a[0]) //length of static array

#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define ret return
#define print(a) cout<<a<<"\n"
#define arprint(a,l,r) for(int J=l; J<=r; J++) cout<<a[J]<<" "; cout<<"\n";
#define stprint(st) while(!st.empty()) {print(st.top()); st.pop();}
#define qprint(q) while(!q.empty()) {print(q.front()); q.pop();}


template<typename T> void scan(T &x)
{
    x = 0;
    bool neg = 0;
    register T c = getchar();
 
    if (c == '-')
        neg = 1, c = getchar();
 
    while ((c < 48) || (c > 57))
        c = getchar();
 
    for ( ; c < 48||c > 57 ; c = getchar());
 
    for ( ; c > 47 && c < 58; c = getchar() )
        x= (x << 3) + ( x << 1 ) + ( c & 15 );
 
    if (neg) x *= -1;
}
 
template<typename T> void printn(T n)
{
    bool neg = 0;
 
    if (n < 0)
        n *= -1, neg = 1;
 
    char snum[65];
    int i = 0;
    do
    {
        snum[i++] = n % 10 + '0';
        n /= 10;
    }
 
    while (n);
    --i;
 
    if (neg)
        putchar('-');
 
    while (i >= 0)
        putchar(snum[i--]);
 
    putchar('\n');
}


//-------------------------------------------END OF MACROS-----------------------------------------------------------//


void solve()
{
    long long n;
    cin>>n;
    long long cnt = 0;
    for(long long i = 5; i<=n; i*=5)
        cnt += (n/i);
    cout<<cnt<<endl;
}

int32_t main()
{
    ios;
    ll t = 1;
    //scan(t);
    TC(t)
        solve();
    ret 0;
}