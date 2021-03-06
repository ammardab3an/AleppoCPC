#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e6 + 16, inf = 1e9+9;

int main () {
    ll l, r;
    cin >> l >> r;
    printf("YES\n");
    for (ll i = l; i < r; i += 2) {
        printf("%I64d %I64d\n", i, i + 1);
    }
}
