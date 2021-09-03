#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


// 620 3 2 1 3 0 2

int main () {
	int A;
	cin >> A;
	int C[6] = {500, 100, 50, 10, 5, 1};
	int V[6];
	for (int i = 0; i < 6; i++) {
		cin >> V[i];
	}
	int ans = 0;
	int t = 0;

	for (int i = 0; i < 6; i++) {
		t = min(A/C[i], V[i]);
		A -= t * V[i];
		ans++;
	}
	printf("%d\n", ans);
}