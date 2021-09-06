#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 4
// (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}
// W = 5

int n, W;
int w[100], v[100];

int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
	
	int dp[n + 1][W + 1] = {0};
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j <= W; j++) {
			if(j < w[i]) {
				dp[i][j] = dp[i + 1][j];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[0][W] << endl;
}