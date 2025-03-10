/*
	Problem: https://cses.fi/problemset/task/2107
*/

#include <bits/stdc++.h>
using namespace std;

#include "../../content/strings/KMP.h"
#include "../../content/strings/Zfunc.h"

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	vi z = zfunc(s);
	rep(i, 0, sz(s)) {
		cout << z[i];
		if(i + 1 != sz(s)) cout << " ";
		cout << "\n";
	}

	vi p = kmp(s);
	rep(i, 0, sz(s)) {
		cout << p[i];
		if(i + 1 != sz(s)) cout << " ";
		cout << "\n";
	}
}