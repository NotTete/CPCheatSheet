/**
 * Author: N41h_Dr3s
 * Date: 2025-03-25
 * License: CC0
 * Source: 
 * Description: Given an integer $n$ it return an integer $g$ that $\{g^k:k\in\mathbb{N}_0\} = \mathbb{Z}_n*$. The primitive Root is also called generator of the group $\mathbb{Z}_n*$.
 * This code is only valid when n is a prime number.\\
 * if $n$ is $p^k$ and $g$ is a primitive root of $p$:\\
 *  $g^p \equiv g \pmod{p^2} \iff g+p$ is a primitive root of $n$\\
 * 	$g^p \not\equiv g \pmod{p^2} \iff g$ is a primitive root of $n$\\
 * if $n$ is $2 \cdot p^k$ and $g$ is a primitive root of $p^k$:\\
 *  $g$ is odd $\iff g$ is a primitive root of $n$\\
 * 	$g$ is even $\iff g+p^k$ is a primitive root of $n$\\
 * Time: Assuming the generalized Riemann hypothesis, $O(\log^8 n)$
 * Status:
 */
#pragma once

#include "ModPow.h"

int generator (int p) {
	vector<int> fact; int phi=p-1,n=phi,i,res,ok=0;
	for (i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back(i);
			while (n % i == 0) n /= i;
		}
	if(n > 1) fact.push_back (n);
	for (res = 2; (res<=p)&&(!ok); ++res)
		for (ok = true, i=0; i<fact.size() && ok; ++i) 
			ok &= powmod(res, phi/fact[i], p) != 1;
	return (ok? res-1:-1);
}
