#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+1;
const int R = 502, C = 502;
int r, c, a[R][C], dp[R][C], vis[R][C];
string s[M];
int rec( int i, int j){
    if (i > r - 1) return -1e9;
    if (j > c - 1) return -1e9;
    if (i == r - 1 && j == c  - 1) {
        return a[i][j];
    }
    int &ret = dp[i][j];
    if (vis[i][j]) return dp[i][j];
    ret = -1e9;
    ret = max(a[i][j] + rec(i + 1 ,j), ret);
    ret = max(a[i][j] + rec(i ,j + 1), ret);
    vis[i][j] = 1;
    return ret;
}
int main () {
    cin >> r >> c;
    memset(dp, -1, sizeof dp);
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            cin >> a[i][j];
    cout << rec(0, 0);
}
