
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

int n;
int arr[NMAX];
int mem[222][222][222];

int go(int pos, int wpos, int bpos){
    
    if(pos == n) return 0;
    
    int &ret = mem[pos][wpos+1][bpos+1];
    if(ret + 1) return ret;
    
    int stPath = go(pos+1, wpos, bpos) +1;
    
    int ndPath = INF, rdPath = INF;
    
    if(bpos == -1 || arr[bpos] < arr[pos]){
        ndPath = go(pos+1, wpos, pos);
    }
    
    if(wpos == -1 || arr[wpos] > arr[pos]){
        rdPath = go(pos+1, pos, bpos);
    }
    
    return ret = min({stPath, ndPath, rdPath});
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(true){
        
        cin >> n;
        if(n == -1)break;
        
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        memset(mem, -1, sizeof mem);
        
        cout << go(0, -1, -1) << endl;
    }
}
