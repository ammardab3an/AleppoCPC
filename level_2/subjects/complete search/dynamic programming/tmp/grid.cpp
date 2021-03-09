
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

int n, r, c;
int a[502][502];
int mem[502][502];
int go(int x, int y){
   if (x == r - 1 && y == c - 1) {
       return 0;
   }
   int &ret = mem[x][y];
   int st = -1e9, nd = -1e9;
   if (x + 1 < r) st = go(x+1, y) + a[x][y];
   if (y + 1 < c) nd = go(x, y +1) + a[x][y];
   return ret = max(st, nd);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    int t;
    cin >>  t;
    while(t--){
        
        cin >> r >> c ;
        
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                cin >> a[i][j];
        memset(mem, -1, sizeof mem);
        
        cout << go(0, 0) << endl;
    }
}
