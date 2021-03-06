#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e6 + 16, inf = 1e9+9;
ll powmod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll powmod(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}
int main () {
    string s;
    cin >> s;
    int n = s.size();
    ll first_answer = powmod(9, n - 1);
    ll second_answer = 1;
    ll best = 0;
    for (int i=0;i<n;i++){
        if (s[i] > '0' || ( i == 0 && s[i] > '1' )){
            best = max(second_answer * (s[i] - '0' -1) * powmod(9, n - i - 1), best);
            second_answer *= (s[i] - '0');

        }
        else {
            second_answer *= (s[i] - '0');
        }
    }
    best = max (best, second_answer );
    cout << max(best, first_answer);
}
