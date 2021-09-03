#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main () {
	int n;
	cin >> n;
	// Sは開始時刻、Tは終了時刻
	int S[n], T[n];
	for (int i = 0; i < n ; i++) {
		cin >> S[i] >> T[i];
	}
	pair<int, int> itv[n];
	for (int i = 0; i < n; i++) {
		itv[i].first = T[i];
		itv[i].second = S[i];
	}
	sort(itv, itv + n);
	//itv("終了時刻", "開始時刻")であり終了時刻の早い順に並んでいる

	int ans = 0;
	// t:最後に選んだ仕事の終了時刻
	int t;
	for (int i = 0; i < n; i++) {
		if (t < itv[i].second) {
			ans++;
			t = itv[i].first;
		}
	}
	printf("%d\n", ans); 
}