// Tested on https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

vi kmp(const string& s) {
	vi res(sz(s));
	rep(i, 1, sz(s)) {
		int k = res[i - 1];
		while(k > 0 && s[k] != s[i]) k = res[k - 1];
		res[i] = k + (s[k] == s[i]);
	}
	return res;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s, p;
	cin >> s >> p;
	int n = p.size();
	p += "$" + s;
	int c = 0;
	for(int i : kmp(p)) {
		c += i == n;
	}
	cout << c << "\n";
}
