#include <bits/stdc++.h>

using namespace std;
 bool isPrime (int n){
    for (int i = 2 ; i * i <= n ; i++)
        if (n % i == 0) return 0;
    return 1;
}
const int M = 998244353;

int main() {
	int n;
    cin >> n;
    int Ans= 0;
    for (int i=2;i<=n;i++){
        int x = i;
        int cnt = 0;
        for (int j = 2;j*j<=x;j++){
            if (x % j == 0){
                if (isPrime(j))cnt++;
                if (j * j == x)continue;
                if (isPrime(x / j))cnt++;
            }
        }
        if (cnt == 2) Ans++;
    }
    printf("%d",Ans);
	return 0;
}
