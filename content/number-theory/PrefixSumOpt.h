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
int calc (int x, int ans = 0) {
  if(x<= th) return (x<=0? 0: p_f(x));
  if(mem.count(x) != 0) return mem[x];
  for (int i = 2, la; i <= x; i = la + 1) 
    ans += (p_g(la = x/(x/i))-p_g(i-1))*calc(x / i);
  return mem[x] = (p_c(x) - ans)/p_g(1);
}