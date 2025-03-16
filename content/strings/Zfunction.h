/**
 * Author: Jorge Hernández Palop
 * Description: zfun[i] = The length of the longest non trivial prefix that starts at position i and coincides with a prefix of s. zfun[0] = 0.
 * Time: O(n)
 * Source: Pavel Mavrin. A&DS course
 * Status: Tested on https://cses.fi/problemset/task/1753/
 */

vi zfun(const string& s) {
	vi z(sz(s)); int l = 0;
	rep(i, 1, sz(s)) {
		z[i] = max(min(z[i - l], z[l] + l - i), 0LL);
		while(i+z[i] < sz(s) && s[z[i]]==s[i+z[i]]) z[i]++;
		if(z[i] + i > z[l] + l) l = i;
	}
	return z; }