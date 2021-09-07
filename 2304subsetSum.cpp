#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 3
// a = {3, 5, 8}
// m = {3, 2, 2}
// K = 17

int n, K;

int main () {
	cin >> n;
	int a[n], m[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	cin >> K;

	bool dp[n + 1][K + 1];
	dp[0][0] = true;
	cout << dp[0][0] << dp[0][2] << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k <= m[i] && k * a[i] <= j; k++) {
				dp[i + 1][j] |= dp[i][j - k * a[i]];
			}
		}
	}
	
	if (dp[n][K]) printf("Yes\n");
	else printf("No\n");
}

// dp[i+1][j]:=i番目まででjが作れるか
// a |= b;
// a = a|b;
// 論理和(OR)のこと