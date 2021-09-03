#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int V[6] = {1, 5, 10, 50, 100, 500};

int main() {
	int ans = 0;
	int A;
	int C[6];
	cin >> A;
	for (int i = 0; i < 6; i++) {
		cin >> C[i];
	}
	for (int i = 5; i >= 0; i--) {
		int t = min(A / V[i], C[i]);
		A -= t * V[i];
		ans += t;
	}
	printf("%d\n", ans);
	return 0;
}