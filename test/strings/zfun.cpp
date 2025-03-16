// Tested on https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

vi zfun(const string& s) {
    vi z(sz(s)); int l = 0;
    rep(i, 1, sz(s)) {
        z[i] = max(min(z[i - l], z[l] + l - i), 0LL);
        while (i + z[i] < sz(s) && s[z[i]] == s[i + z[i]]) z[i]++;
        if(z[i] + i > z[l] + l) l = i;
    }
	return z;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s, p;
	cin >> s >> p;
	int n = p.size();
	p += "$" + s;
	int c = 0;
	for(int i : zfun(p)) {
		c += i == n;
	}
	cout << c << "\n";
}
