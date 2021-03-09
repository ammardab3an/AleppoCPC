// Problem: Labyrinth
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/LABYR1/
// Memory Limit: 1536 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

int n, m;
char grid[1010][1010];
bool vis[1010][1010];
pii mvArr[] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

bool good(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

int ans_i, ans_j, ans_dis;

void dfs(int i, int j, int dis){
    
    vis[i][j] = true;
    
    if(ans_dis < dis){
        ans_i = i;
        ans_j = j;
        ans_dis = dis;
    }
    
    for(auto p : mvArr){
        
        int ni = i + p.first;
        int nj = j + p.second;
        
        if(good(ni, nj) && grid[ni][nj] == '.' && !vis[ni][nj]){
            
            dfs(ni, nj, dis+1);   
        } 
    }    
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> m >> n;
        for(int i = 0; i < n; i++) 
            cin >> grid[i];
        
        ans_dis = -1;
        memset(vis, 0, sizeof vis);
    
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(grid[i][j] == '.' && !vis[i][j]){    
            dfs(i, j, 0);
        }
        
        memset(vis, 0, sizeof vis);
        
        ans_dis = -1;
        dfs(ans_i, ans_j, 0);
        
        cout << ans_dis << endl;
    }	
}
