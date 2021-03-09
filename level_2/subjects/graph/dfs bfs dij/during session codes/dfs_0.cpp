
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

vi adj[111];
bool vis[111];

void dfs(int u){
    
    vis[u] = 1;
    
    cout << u+1 << endl;
    
    for(auto v : adj[u]) if(!vis[v]){
        dfs(v);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int n, m;
    cin >> n >> m;
    
    
    for(int i = 0; i < m; i++){
        
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    
    dfs(0);
    
    queue <int> q;
    
    int lvl[n]{0};
    
    for(int i = 0; i < n; i++) lvl[i] = INF;
    
    lvl[0] = 1;
    q.push(0);
    
    while(!q.empty()){
        
        int u = q.front(); q.pop();
        
        for (int v : adj[u]) {
            
            if (lvl[v] == INF){
                
                lvl[v] = lvl[u] + 1;
                q.push(v);
            }
        }
    } 
    
    for (int i=0;i<n;i++) {
        printf("dis(%d,%d) = %d\n",1, i+ 1, lvl[i]-1);
    }
    
    
    
    
}
