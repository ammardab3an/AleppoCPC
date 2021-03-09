
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
int arr[NMAX][2];
int mem[NMAX][1 << 3];

int go(int pos, int msk){
    
    if(pos == n){
        return (msk == ((1 << 3)-1)) ? 0 : INF;
    }
    
    int &ret = mem[pos][msk];
    if(ret+1) return ret;
    
    int stPath = go(pos+1, msk);
    int ndPath = go(pos+1, msk | arr[pos][1]) + arr[pos][0];
    
    return ret = min(stPath, ndPath);
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n;
    for(int i = 0; i < n; i++){
        
        cin >> arr[i][0];
        
        arr[i][1] = 0;
        
        string str;
        cin >> str;
        
        for(auto c : str){
            arr[i][1] |= 1 << (c - 'A');
        }   
    }
    
    memset(mem, -1, sizeof mem);
    
    cout << (go(0, 0) != INF ? mem[0][0] : -1) << endl;
}
