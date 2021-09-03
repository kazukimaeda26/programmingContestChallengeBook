#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main () {
	int N;
	cin >> N;
	char S[N];
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	// S = "ACDBCB"
	int a = 0, b = N -1;

	while (a <= b) {
		bool left = false;
		for (int i = 0; a + i <= b; i++) {
			if(S[a + i] < S[b - i]) {
				left = true;
				break;
			}
			else if (S[a + i] > S[b - i]) {
				left = false;
				break;
			}
		}
		if (left) putchar(S[a++]);
		else putchar(S[b--]);
	}
	putchar('\n');

}