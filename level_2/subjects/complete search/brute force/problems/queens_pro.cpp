
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


int row[8];

bool good(int r, int c){
    
    for(int i = 0; i < c; i++){
        
        int cp = i;
        int rp = row[i];
        
        if(rp == r || cp == c || (abs(rp-r) == abs(cp-c))) return false;
    }
    
    return true;
}

int grid[8][8];

void go(int c){
    https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=691
    if(c == 8){
    
        memset(grid, 0, sizeof grid);
        for(int i = 0; i < 8; i++) grid[i][row[i]] = 1;
        
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++) cout << grid[i][j];
            cout << endl;
        }
        cout << endl;
    }
    
    for(int r = 0; r < 8; r++) if(good(r, c)){
        row[c] = r;
        go(c+1);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    go(0);
}
