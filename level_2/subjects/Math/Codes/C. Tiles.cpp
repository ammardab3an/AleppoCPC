#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 998244353;
 
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	n += m;
	m = 2;
	int ret = 1;
	while (n) {
		if (n & 1) {
			ret = ((long long)ret * m) % M;
		}
		m = ((long long)m * m) % M;
		n >>= 1;
	}
	printf("%d", ret);
	return 0;
}