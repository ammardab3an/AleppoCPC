// Problem: A. Party
// Contest: Codeforces - Codeforces Beta Round #87 (Div. 1 Only)
// URL: https://codeforces.com/problemset/problem/115/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int ans;
vector<int> adj[2020];
vector<int> vec;
bool vis[2020];

void dfs(int nd, int lvl){
    
    vis[nd] = true;    
    
    ans = max(ans, lvl);
    
    for(auto nxt : adj[nd]) if(!vis[nxt]){
        dfs(nxt, lvl+1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    
    int n;
    cin >> n;
    
    ans = 1;
    
    for(int i = 0; i < n; i++){
        
        int par;
        cin >> par; par--;
        
        if(par == -2){
            vec.push_back(i);
            continue;
        }
        
        adj[i].push_back(par);
        adj[par].push_back(i);
    }
    
    for(int i = 0; i < vec.size(); i++){
        dfs(vec[i], 1);
    }
    
    cout << ans << endl;
}
