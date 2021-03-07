
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

lli mem[1010];
vi coins;

lli go(int num){
    
    if(num == 0) 
        return 1;
    
    if(mem[num] != -1)
        return mem[num];
        
    lli ans = 0;
    
    for(auto ncc : coins){
        if(num >= ncc) ans += go(num-ncc);
    }
    
    return mem[num] = ans;
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int num;
    cin >> num;
    
    int n;
    cin >> n;
    
    coins = vi(n, 0);
    for(auto &i : coins) cin >> i;
    
    memset(mem, -1, sizeof mem);
    
    cout << go(num);	
}
