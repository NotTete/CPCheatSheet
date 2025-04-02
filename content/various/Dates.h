/**
 * Author: Simon Lindholm
 * Date: 2016-07-23
 * License: CC0
 * Source: me
 * Description: Dates
 * Usage: Dates
 * Status: tested
 */
#pragma once

int m2d  [12] =
  {31,28,31,30,1,30,31,31,30,31,30,31};
int m2da [13] =
  {0,31,59,90,120,151,181,212,243,273,304,334,365};
bool isLeap(int y) { // Change for leap years
  return y % 4 == 0 && (y%100 != 0 || y%400 == 0);
} int dateToInt(int d, int m, int y) {
  d--, m--, y--;
  return y*365 + m2dAc[m] + d +
  y/4 + (y % 4 == 3 && m > 1) + // Leap years every 4
  -(y/100 + (y % 100 == 99 && m > 1))+
  (y/400 + (y % 400 == 399 && m > 1));
  // Leap years excluding 100x including 400x
} void intToDate(int n, int &d, int &m, int &y) {
  y = n/365; n %= 365;
  n -= y/4 - y/100 + y/400; // Change for leap years
  y++; while (n < 0) n += 365+isLeap(--y);
  for (m = 0; m < 12 &&
    m2da[m+1]+(isLeap(y) && m+1 > 1) <= n; m++);
  d = n-m2da[m]-(isLeap(y) && m > 1)+1, m++;
}
