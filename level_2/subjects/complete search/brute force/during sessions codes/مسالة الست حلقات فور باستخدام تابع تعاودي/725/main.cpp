// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

int n;
int arr[15];

void itr_search()
{

    for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    for(int k = j+1; k < n; k++)
    for(int l = k+1; l < n; l++)
    for(int m = l+1; m < n; m++)
    for(int mm = m+1; mm<n; mm++)
    {

        cout << arr[i] << ' ' << arr[j] << ' ' << arr[k] << ' ' << arr[l] << ' ' << arr[m] << ' ' << arr[mm] << ' ' << endl;
    }
}

vector<int> cur;

void go(int pos, int k)
{

    if(pos == n)
    {

        if(!k)
        {
            for(int i : cur) cout << i << ' ' ;
            cout << endl;
        }
        return;
    }

    if(k > 0)
    {
        cur.push_back(arr[pos]);
        go(pos+1, k-1);
        cur.pop_back();
    } // take it (if you can)

    go(pos+1, k); // leave it

}

int32_t main()
{


#ifdef LOCAL
    freopenI;
    freopenO;
#endif


    cin >> n;
    for(int i=  0; i< n; i++) cin >> arr[i];
    go(0, 2);
}
