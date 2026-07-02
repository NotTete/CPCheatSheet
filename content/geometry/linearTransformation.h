/**
 * Author: Per Austrin, Ulf Lundstrom
 * Date: 2009-04-09
 * License: CC0
 * Source:
 * Description:\\
\begin{minipage}{75mm}
 Apply the linear transformation (translation, rotation and scaling) which takes line p0-p1 to line q0-q1 to point r.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-8mm}
\includegraphics[width=\textwidth]{content/geometry/linearTransformation}
\vspace{-2mm}
\end{minipage}
 * Status: not tested
 */
#pragma once

#include "Point.h"

vec2d linearTransformation(const vec2d& p0, const vec2d& p1,
		const vec2d& q0, const vec2d& q1, const vec2d& r) {
	vec2d dp = p1-p0, dq = q1-q0;
	vec2d num = {cross(dp, dq), dot(dp, dq)};
	return q0 + vec2d{cross(r-p0, num), dot(r-p0, num)} / dp.len2();
}
