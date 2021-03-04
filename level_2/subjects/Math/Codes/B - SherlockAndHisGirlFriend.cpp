#include <bits/stdc++.h>
using namespace std;
bool isPrime (int n){
    for (int i = 2 ; i * i <= n ; i++)
        if (n % i == 0) return 0;
    return 1;
}
int main () {
    int n, cnt = 1;
    cin >> n;
    vector <int> Ans;
    for (int i=2;i<=n + 1; i++){
        if (isPrime(i))Ans.push_back(1);
        else Ans.push_back(2), cnt = 2;
    }
    printf("%d\n",cnt);
    for (int x : Ans)printf("%d ",x);
}