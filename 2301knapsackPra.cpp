#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// n = 4
// (w, v) = {(2, 3), (1, 2), (3, 4), (2, 2)}
// W = 5

int n, W;
int w[100], v[100];

int knap (int i, int bag) {
	int res;
	if (i == n) {
		res = 0;
	} else if (bag < w[i]) {
		res = knap(i + 1, bag);
	} else {
		res = max(knap(i + 1, bag), knap(i + 1, bag - w[i]) + v[i]);
	}
	return res;
}


int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cin >> W;

	cout << knap(0, W) << endl;
}