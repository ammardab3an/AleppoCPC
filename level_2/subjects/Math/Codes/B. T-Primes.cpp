#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
bool isNotPrime[N];
int main () {
    isNotPrime[1] = true;
    for (int i=2;i<N;i++){
        if (!isNotPrime[i]) {
            for (long long j = 1ll * i * i; j < N; j+=i){
                isNotPrime[j] = true;
            }
        }
    }
    int t;
    cin >> t;
    long long n;
    while (t--){
        cin >> n;
        int z = sqrt(n);
        if (!isNotPrime[z] && z * 1ll * z == n) {
            printf("YES\n");
        }
        else printf("NO\n");
    }
}
