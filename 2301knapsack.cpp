#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, W;
int w[100], v[100];

int rec(int i, int j) {
	int res;
	if (i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i + 1, j);
	} else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return res;
}

int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;
	printf("%d\n", rec(0, W));
}
// n = 4
// (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}
// w = 5

// rec(0, 5) = max(rec(1, 5), rec(1, 3) + 3) :::: rec(0, 5) = 7
	// rec(1, 5) = max(rec(2, 5), rec(2, 4) + 2) :::: rec(1, 5) = 6
		// rec(2, 5) = max(rec(3, 5), rec(3, 2) + 4) :::: rec(2, 5) = 6
			// rec(3, 5) = max(rec(4, 3), rec(4, 3) + 2) :::: rec(3, 5) = 2
			// rec(3, 2) = max(rec(4, 2), rec(4, 0) + 2) :::: rec(3, 2) = 2
		
		// rec(2, 4) = max(rec(3, 4), rec(3, 1) + 4) :::: rec(2, 4) = 4
			// rec(3, 4) = max(rec(4, 4), max(4, 2) + 2) :::: rec(3, 4) = 2
			// rec(3, 1) = rec(4, 1) :::: rec(3, 1) = 0
	// rec(1, 3) = max(rec(2, 3), rec(2, 2) + 2) :::: rec(1, 3) = 4
		// rec(2, 3) = max(rec(3, 3), rec(3, 0) + 4) :::: rec(2, 3) = 4
			// rec(3, 3) = max(rec(4, 3), rec(4, 1) + 2) :::: rec(3, 3) = 2
			// rec(3, 0) = rec(4, 0) :::: rec(4, 0) = 0 :::: rec(3, 0) = 0
		// rec(2, 2) = rec(3, 2) :::: rec(2, 2) = 2
			// rec(3, 2) = max(rec(4, 2), rec(4, 0) + 2) :::: rec(3, 2) = 2