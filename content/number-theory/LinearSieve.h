/**
 * Author: N41h_Dr3s
 * Date: 2025-03-16
 * Description: Linear Sieve for prime numbers.
 * Can be used for precomputing multiplicative functions
 * Time: O(n)
 * Status: Not-tested
 */
#pragma once
void sieve () {
  //asignar 1
  for (int i=2; i <= N; i++) {
    if (lp[i] == 0){ // i es primo
      lp[i] = i; pr.push_back(i); // asignar primo
    }
    for (int j = 0; i * pr[j] <= N; j++) {
      lp[i*pr[j]] = pr[j];
      if (i%pr[j] == 0) {/*asignar multiplo*/;break;}
      else{/*asignar coprimo*/}
    }
  }
}