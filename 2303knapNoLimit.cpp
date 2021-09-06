#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 3
// (w, v) = {(3, 4), (4, 5), (2, 3)}
// W = 7

int n, W;

int main () {
	cin >> n;
	int w[n], v[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;

	int dp[n + 1][W + 1] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			for (int k = 0; k * w[i] <= j; k++) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
			}
		}
	}
	printf("%d\n", dp[n][W]);
}