/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-11
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Circumcircle
 * Description:\\
\begin{minipage}{75mm}
The circumcirle of a triangle is the circle intersecting all three vertices. ccRadius returns the radius of the circle going through points A, B and C and ccCenter returns the center of the same circle.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-2mm}
\includegraphics[width=\textwidth]{content/geometry/circumcircle}
\end{minipage}
 * Status: tested
 */
#pragma once

vec2d circumCenter(vec2d a, vec2d b, vec2d c) {
  double d = 2 * cross(b - a, c - a);
  div0(d); // no circumcircle if A,B,C aligned
  vec2d ab = b - a;
  vec2d ac = c - a;

  double ab2 = ab.len2();
  double ac2 = ac.len2();

  vec2d num = (ab * ac2 - ac * ab2).perp(); // ojo cuidado con la implementacion del perp
  return a - num * (1.0 / d);
}
