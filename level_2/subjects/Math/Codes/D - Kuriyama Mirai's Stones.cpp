#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+1;

long long arr[M + 123];
long long pre[M + 123];
long long presort[M + 123];

int main(){

    int n;
    cin >> n;// >> m;

    for(int i = 0; i< n; i++) cin >> arr[i];

    pre[0] = arr[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];

    sort(arr, arr+n);

    presort[0] = arr[0];
    for(int i = 1; i < n; i++) presort[i] = presort[i-1] + arr[i];
int m;
    cin >> m;
    while(m--){

        int type, l, r;
        cin >> type >> l >> r; l--, r--;

        if(type == 1){

            long long csum = pre[r];// - pre[l] +arr[l];
            if(l) csum -= pre[l-1];

            cout << csum << endl;
        }
        else{

            long long csum = presort[r];// - pre[l] +arr[l];
            if(l) csum -= presort[l-1];

            cout << csum << endl;

        }

    }
}
