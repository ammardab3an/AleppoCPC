
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

bool good(string str){
    
    stack<char> st;
    
    for(int i =0; i < str.size(); i++){
        
        if(!st.empty() && str[i] == ')' && st.top() == '('){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
    
    return st.empty();    
}

bool check(string s)
{
    int n = s.size();
    
    int balance = 0;
    
    for (auto c: s)
    {
        if (c==')') balance--; else balance++;
        if (balance<0) return false;
    }
    
    if (balance!=0) return false;
    
    return true;
}
 
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        string str;
        cin >> str;
        
        bool ans = false;
        
        for(int msk = 0; msk < (1 << 3); msk++){
            
            string cur = "";
            
            for(int p = 0; p < str.size(); p++){
                cur.push_back(msk & (1 << (str[p] - 'A')) ? '(' : ')');
            }
            
            if(good(cur)){
                cout << cur << endl;
                ans = true;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;

    }	
}
