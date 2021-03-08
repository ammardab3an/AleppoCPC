// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int NMAX = 2e5 + 10;

int n;
int arr[NMAX][2];
int mem[NMAX][1 << 3];

int go(int pos, int msk){
	
	if(pos == n)
		return msk == ((1 << 3)-1) ? 0 : 1e9;

	int &ret = mem[pos][msk];
	if(ret + 1) return ret;

	int stPath = go(pos+1, msk);
	int ndPath = go(pos+1, msk | arr[pos][1]) + arr[pos][0];

	return ret = min(stPath, ndPath);
}

int main () {

	cin >> n;
	for(int i = 0; i < n; i++){

		cin >> arr[i][0];

		arr[i][1] = 0;

		string str;
		cin >> str;

		for(auto c : str){
			arr[i][1] |= 1 << (c - 'A');
		}
	}
	
	memset(mem, -1, sizeof mem);
	cout << (go(0, 0) < 1e9 ? mem[0][0] : -1) << endl;
}
