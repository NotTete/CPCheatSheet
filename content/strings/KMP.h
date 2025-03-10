/**
 * Author: Johan Sannemo. 
 * Date: 2016-12-15
 * License: CC0
 * Description: kmp[x] is the length of the longest prefix of s that ends at x,
 * other than s[0...x] itself. Example: (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 * Time: O(n)
 * Status: Tested with https://cses.fi/problemset/task/2107
 */
#pragma once

vi kmp(const string& s) {
	vi p(sz(s));
	rep(i, 1, sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}