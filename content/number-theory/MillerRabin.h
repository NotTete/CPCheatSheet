/**
 * Author: chilli, c1729, Simon Lindholm
 * Date: 2019-03-28
 * License: CC0
 * Source: Wikipedia, https://miller-rabin.appspot.com/
 * Description: Deterministic Miller-Rabin primality test.
 * Guaranteed to work for numbers up to $7 \cdot 10^{18}$; for larger numbers, use Python and extend A randomly.
 * Time: 7 times the complexity of $a^b \mod c$.
 * Status: Stress-tested
 */
#pragma once

#include "ModMulLL.h"

bool MillerRabin(unsigned int n) { // returns true if n is prime, else returns false.
	unsigned int r = __builtin_ctzll(n-1); int d = n >> r;
	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}) {
		if (n == a) return true;
		unsigned int x = modpow(a, d, n), res = !(x == 1 || x == n - 1);
		for(int i = 1; i < r; i++) x = (__int128)x*x%n, res&=(x!=n-1);
		if(res) return false;
	}
	return (n>=2);
}
