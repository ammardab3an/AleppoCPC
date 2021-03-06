#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e6 + 16, inf = 1e9+9;

ll f (ll n, ll p) {
    ll x = 0;
    while (n){
        n /= p;
        x += n;
    }
    return x;
}

ll Ans = 1e18;

int main () {
    ll n, b;
    cin >> n >> b;
    for (ll i = 2; i<=b; i++) {
        if (i * i > b) i = b;
        int cnt = 0;
        while (b % i == 0) b /= i, cnt++;
        if (cnt) {
            Ans = min(f(n, i) / cnt , Ans);
        }
    }
    cout << Ans;
}
