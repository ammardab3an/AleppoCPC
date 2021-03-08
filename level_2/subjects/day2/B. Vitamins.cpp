#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+1;
int n, a[M], dp[M][12];
string s[M];
int rec( int i, int msk ){
    if (msk == (1 << 3) - 1)return 0;
    if (i == n){
        return msk == (1 << 3) - 1?0:1e9;
    }
    int &ret = dp[i][msk];
    if (ret + 1)return ret;
    ret = rec(i+1,msk);
    int z = msk;
    for (int j=0;j<s[i].size();j++){
        z |= ( 1 << (s[i][j]-'A'));
    }
    return ret = min(ret, a[i] + rec( i+1,z) );
}
int main () {
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        cin >> a[i] >> s[i];
    }
    memset(dp, -1, sizeof dp);
    int Ans =  rec(0,0);
    if (Ans == 1e9) Ans = -1;
    cout << Ans;
}
