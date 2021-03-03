
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

int n, d;
int arr[1030][3];
int cnt[1030][1030];

bool good(int i, int j){
    
    if(i < 0 || i >= 1030) return false;
    if(j < 0 || j >= 1030) return false;
    
    return true;
    
    // return (i >= 0) && (i < 1030) && (j >= 0) && (j < 1030);
}
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> d >> n;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> arr[i][j];
            
        memset(cnt, 0, sizeof cnt);
        
        int ans_cnt = 0;
        int ans_i = 0;
        int ans_j = 0;
        
        for(int i = 0; i < n; i++){
            
            int cur_i = arr[i][0];
            int cur_j = arr[i][1];
            int cur_cnt = arr[i][2];
            
            for(int ni = cur_i-d; ni <= cur_i+d; ni++)
            for(int nj = cur_j-d; nj <= cur_j+d; nj++) 
                if(good(ni, nj)) {
                    cnt[ni][nj] += cur_cnt;
                    
                    if(ans_cnt < cnt[ni][nj]){
                        
                        ans_cnt = cnt[ni][nj];
                        ans_i = ni;
                        ans_j = nj;
                    }
                }
        }
        
        for(int i=  0; i < 10; i++){
            for(int j = 0; j< 10; j++) cout << cnt[i][j] << ' ';
            cout << endl;
        }
        cout << ans_i << ' '<< ans_j << ' ' << ans_cnt << endl; 
    }	
}
