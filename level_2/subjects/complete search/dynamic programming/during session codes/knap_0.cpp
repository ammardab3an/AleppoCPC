
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int k, n, vid=1;
int arr[2020][2];
int mem[2020][2020];
int vis[2020][2020];

int go(int pos, int left){
    
    if(pos == n){
        return 0;
    }    
    
    int ans = go(pos+1, left);
    
    if(arr[pos][0] <= left)
        ans = max(ans, go(pos+1, left-arr[pos][0])  + arr[pos][1]);
        
    return ans;    
}

int dp(int pos, int left){
    
    if(vis[pos][left] == vid){
        return mem[pos][left];
    }
    
    vis[pos][left] = vid;
    return mem[pos][left] = go(pos, left);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> k >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }	
    
    cout << dp(0, k) << endl; vid++;
}
