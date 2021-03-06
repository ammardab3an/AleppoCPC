int gcd_extended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
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
ll modInverse(int a, int n) {
    if (__gcd(a, m) != 1) return -1; // no Solution
    return powmod(a, m-2, m);
}

ll lcm (ll a, ll b) {
    return a / __gcd(a, b) * b;
}

inline ll mod (ll n, ll k) {
    return n<0?( k-(-n%k) ):n%k;
}

bool dioph (ll a,ll b,ll c,ll &x, ll &y) {
    ll gcd,te,tee;
    int A = (a<0)?-1:1, B = (b<0)?-1:1, C = (c>0)?-1:1;
    a = abs(a), b = abs(b), c = abs(c);
    gcd = gcdExtended(a,b,te,tee);
    x = te, y = tee;
    if (c%gcd){
        return 0;
    }
    x *= C*A*c/gcd;
    y *= C*B*c/gcd;
    return 1;
}

vector <pair<ll,ll>> bezout (ll a,ll b, ll n) {
    vector <pair<ll,ll>> v;
    ll x, y;
    ll gcd = gcdExtended(a,b,x,y);
    for (ll i=0;i<n;i++) {
        v.push_back ( {x + i*b/gcd, y - i*a/gcd } );
    }
}

