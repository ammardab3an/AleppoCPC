#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e6 + 16, inf = 1e9+9;

int main () {
    int n, x;
    cin >> n;
    vector <int> v;
    for (int i=0;i<n;i++) {
        cin >> x;
        if (i){
            int y = v.back();
            if (__gcd(x, y) != 1)v.push_back(1);
        }
        v.push_back(x);
    }
    cout << v.size() - n << endl;
    for (int x : v) cout << x << ' ';
}
