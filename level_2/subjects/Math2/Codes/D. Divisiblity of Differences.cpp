#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e6 + 16, inf = 1e9+9;

int main () {
    int n, k, m, x;
    cin >> n >> k >> m;
    vector <int> a[m];
    for (int i=0;i<n;i++){
        cin >> x;
        int y = x;
        x %= m;
        a[x].push_back(y);
    }
    for (vector <int> u : a) {
        if (u.size() >= k) {
            printf("YES\n");
            for (int i=0;i<k;i++)
                printf("%d ", u[i]);
            return 0;
        }
    }
    printf("NO");
}
