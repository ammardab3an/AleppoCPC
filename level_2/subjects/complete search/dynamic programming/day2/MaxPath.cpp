#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[555][555];
int mem[555][555];

int go(int i, int j){

	if(i == n-1 && j == m-1)
		return arr[i][j];

	int &ret = mem[i][j];
	if(ret + 1) return ret;

	int stPath = -1e9, ndPath = -1e9;

	if(i+1 < n) stPath = go(i+1, j);
	if(j+1 < m) ndPath = go(i, j+1);

	return ret = max(stPath, ndPath) + arr[i][j];
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) cin >> arr[i][j];

	memset(mem, -1, sizeof mem);

	cout << go(0, 0) << endl;
}

