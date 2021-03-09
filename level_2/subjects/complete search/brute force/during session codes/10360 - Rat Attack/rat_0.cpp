
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
int grid[1030][1030];
int cnt[1030][3];

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
        {
            cin >> arr[i][j];
            // grid[arr[i][0]][arr[i][1]] = arr[i][2];
        }
   
            
        
        memset(cnt, 0, sizeof cnt);
        
        
        int ans_cnt = 0;
        int ans_i;
        int ans_j;
        
        for(int i = 0; i < 1030; i++)
        for(int j = 0; j < 1030; j++){
            
            int cur_ans = 0;
            
            for(int k = 0; k < n; k++){
                
                if(max(abs(i-arr[k][0]) , abs(j - arr[k][1])) <= d){
                    cur_ans += arr[k][2];
                }
            }
            
            
            if(ans_cnt < cur_ans){
                
                ans_cnt = cur_ans;
                ans_i = i ;
                ans_j = j;
            }
        }
        
        cout << ans_i << ' '<< ans_j << ' ' << ans_cnt << endl;
        
    }	
}
