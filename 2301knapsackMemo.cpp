#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 4
// (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}
// W = 5

int n, W;
int w[100], v[100];

int dp[101][101];

int rec(int i, int j) {
	if(dp[i][j] > 0) {
		return dp[i][j];
	} 
	int res;
	if(i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i + 1, j);
	} else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}


int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;

	cout << rec(0, W) << endl;
}