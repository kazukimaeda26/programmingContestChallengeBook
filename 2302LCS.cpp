#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 4
// m = 4
// s = "abcd"
// t = "becd"

int n, m;
string s, t;

int main () {
	cin >> n >> m;
	cin >> s >> t;

	int dp[n + 1][m + 1] = {};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1; 
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i+ 1][j]);
			}
		}

	}
	cout << dp[n][m] << endl;
}
