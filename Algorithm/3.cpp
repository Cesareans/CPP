#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 21;
const int L = 1 << 20;
int f[2][L];
int p[N][N], q[N][N], pw[L];

int cal(int s) {
	int ans = 0;
	while (s) {
		ans++;
		s -= s & (-s);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> q[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		pw[1 << i] = i;
	}

	int lm = 1 << n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < lm; j++) {
			if (cal(j) != i) {
				continue;
			}
			int k = j;
			while (k) {
				int t = k & (-k);
				f[i & 1][j] = max(f[i & 1][j], f[(i + 1) & 1][j & (~t)] + p[i][pw[t] + 1] * q[pw[t] + 1][i]);
				k -= t;
			}
		}
	}

	cout << f[n & 1][lm - 1];
	return 0;
}