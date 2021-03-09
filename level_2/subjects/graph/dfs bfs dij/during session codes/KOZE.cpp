// Problem: Sheep
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/KOZE/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
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
char grid[255][255];
bool vis[255][255];

pii mvArr[] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

bool good(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m;
}

pii go(int i, int j){
    
    queue<pii> que;
    que.push({i, j});
    vis[i][j] = 1;
    
    bool b = false;
    
    int cnt_k = 0, cnt_v = 0;
    
    while(!que.empty()){
        
        pii fr = que.front(); que.pop();
        
        int ci = fr.first;
        int cj = fr.second;
        
        if(grid[ci][cj] == 'k') cnt_k++;
        if(grid[ci][cj] == 'v') cnt_v++;
        
        if(i == 0 || i == n-1 || j == 0 || j == m-1) b = true;
        
        for(auto p : mvArr){
            
            int ni = ci + p.first;
            int nj = cj + p.second;
            
            if(good(ni, nj) && (grid[ni][nj] != '#') && !vis[ni][nj]){
                vis[ni][nj] = true;
                que.push({ni, nj});
            }
        }
    }    
    
    if(!b){
        if(cnt_k > cnt_v) cnt_v = 0;
        if(cnt_v >= cnt_k) cnt_k = 0;
    }
    
    return {cnt_k, cnt_v};
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    int cnt_k = 0, cnt_v = 0;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        
        if(!vis[i][j] && grid[i][j] != '#'){
            
            pii ret = go(i, j);
            
            cnt_k += ret.first;
            cnt_v += ret.second;
        }   
    }
    
    cout << cnt_k << ' ' << cnt_v << endl;
}
