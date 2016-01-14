/**
 * Author: Unknown
 * Description: Matrix tree theorem. Counts the number of spanning trees in an undirected graph.
 * Source: Unknown
 * Date: 2014-11-27
 * Usage:
 *  vvll mat(N, vector<ll>(N));
 *  addEdge(mat, u, v); // for each edge (u, v)
 *  ll nSpanningTrees = det(reduce(mat));
 */

typedef vector<vector<ll>> vvll;
ll det(vvll& a) { // integer determinant
	ll ans = 1;
	rep(i,0,a.size()) {
		rep(j,i+1,a.size()) {
			while (a[j][i] != 0) {
				ll t = a[i][i] / a[j][i];
				rep(k,i,a.size())
					a[i][k] = (a[i][k] - a[j][k] * t);
				rep(k,0,a.size())
					swap(a[i][k], a[j][k]);
				ans = -ans;
			}
		}
		if (!a[i][i]) return 0;
		ans *= a[i][i];
	}
	return ans;
}

void addEdge(vvll& mat, int a, int b){
	mat[a][a]++; mat[b][b]++;
	mat[a][b]--; mat[b][a]--;
}

vvll reduce(vvll& mat){
	vvll ret = mat;
	ret.pop_back();
	trav(r, ret) r.pop_back();
	return ret;
}
