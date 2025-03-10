/**
 * Author: NotTete
 * License: CC0
 * Description: zfunc[i] computes the length of the longest common prefix of s[i:] and s,
 * except z[0] = 0. (abacaba -> 0010301)
 * Time: O(n)
 * Status: Tested with https://cses.fi/problemset/task/2107
 */
#pragma once

vi zfunc(const string& s) {
	vi z(sz(s));
	int l = 0;
	rep(i, 1, sz(s)) {
		z[i] = max(min(z[i - l], z[l] + l - i), 0);
		while (i + z[i] < sz(z) && s[z[i]] == s[i + z[i]]) z[i]++;
		if(z[i] + i > z[l] + l) l = i;
	}
	return z;
}
