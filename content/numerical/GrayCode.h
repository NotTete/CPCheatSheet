/**
 * Author: N41h_Dr3s
 * Date: 2025-04-02
 * License: CC0
 * Source: https://cp-algorithms.com/algebra/gray-code.html
 * Description:
 * Time: O(1) and O(log n)
 * Status: 
 */
#pragma once
int g (int n) {return n ^ (n >> 1);}
int rev_g (int g) {
  int n = 0;
  for (; g; g >>= 1) n ^= g;
  return n;
}