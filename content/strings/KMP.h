/**
 * Author: Jorge Hernández Palop
 * Description: kmp[i] = The length of the longest non trivial suffix that ends at position i and coincides with a prefix of s.
 * Time: O(n)
 * Status: Tested on https://cses.fi/problemset/task/1753/
 */

vi kmp(const string& s) {
	vi res(sz(s));
	rep(i, 1, sz(s)) {
		int k = res[i - 1];
		while(k > 0 && s[k] != s[i]) k = res[k - 1];
		res[i] = k + (s[k] == s[i]);
	}
	return res; }