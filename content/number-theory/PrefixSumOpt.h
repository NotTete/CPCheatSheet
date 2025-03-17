/**
 * Author: N41h_Dr3s
 * Date: 2025-03-16
 * Description: Let $f$ the multiplactive function to compute its prefix sum. Let $g$ and $c$
 * multiplicative functions so that $f*g$ = $c$ and both 3 can be computed in constant time.
 * Time: O(n^{2/3})
 * Status: Not-tested
 */
#pragma once
unordered_map<int, int> mem;
int calc (int x) {
  if (x <= 0) return 0;
  if (x <= th) return p_f(x);
  if(mem.count(x) != 0) return mem[x];
  int ans = 0;
  for (int i = 2, la; i <= x; i = la + 1) {
    la = x/(x/i);
    ans += (p_g(la)-p_g(i-1))*calc(x / i);
  }
  return mem[x] = (p_c(x) - ans)/p_g(1);
}