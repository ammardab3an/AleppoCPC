#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e5+15, N = 1e3 + 1, inf = 1e9+9;

const int NMAX= 1E5+10;
const int MMAX= 1E5+10;
const int QMAX= 1E5+10;

int n, m, q;
int arr[NMAX];
int com[MMAX][3];
long long sumc[QMAX];
long long suma[NMAX];

int main () {

    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < m; i++)
    for(int j = 0; j < 3; j++){
        cin >> com[i][j];
    }


    while(q--){

        int l, r;
        cin >> l >> r; l--, r--;

        sumc[l] += 1;
        sumc[r+1] -= 1;
    }

    long long cum_sum = 0;
    for(int i = 0; i < m; i++){
        cum_sum += sumc[i];
        suma[com[i][0]-1] += cum_sum * com[i][2];
        suma[com[i][1]+1-1] -= cum_sum * com[i][2];
    }

    cum_sum = 0;
    for(int i = 0; i < n; i++){
        cum_sum += suma[i];
        cout << arr[i] + cum_sum << ' ';
    }

    cout << endl;
}
