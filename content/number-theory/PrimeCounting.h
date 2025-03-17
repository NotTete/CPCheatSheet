/**
 * Author: N41h_Dr3s
 * Date: 2025-03-16
 * Description: Given an integer it gives you $\pi$(n). 
 * Time: O(n^{3/4})
 * Status: Not-tested
 */
#pragma once
int count_primes(int n) {
	int sq=sqrt(n),a=0;
	set<int> V;
	for (int k = 1; k * k <= n; ++k)	V.insert(n / k), V.insert(k);
	vector<int> v(V.begin(), V.end()), dp = v;
	auto geti = [&](int x) {return (x>sq? (int)(v.size() - n/x):x-1);};
	for (int p = 2; p * p <= n; p++) {
		if (dp[geti(p)] != dp[geti(p - 1)]) {
			a++;
			for (int i = (int)v.size() - 1; i >= 0; i--) {
				if (v[i] < p * p) break;
				dp[i] -= dp[geti(v[i] / p)] - a;
			}
		}
	}
	return dp[geti(n)] - 1;
}