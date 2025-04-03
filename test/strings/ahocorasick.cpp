#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;

template<int first = 'A', int alpha = 26>
struct AhoCorasick {
	struct Node {
		int child[alpha]; int nmatch, back;
		Node(int v) { memset(child, v, sizeof(child)); }
	};
	vector<Node> N;

	void insert(string& s) {
		int k = 0;
		for (char c : s) {
			int& n = N[k].next[c - first];
			if(n == -1) { n = sz(s); N.emplace_back(-1); }
			k = n;
		}
		N[k].nmatch++;
	}

	AhoCorasick(vector<string>& pv) : N(1, -1) {
		rep(i, 0, sz(pv)) insert(pv[i]);
		N[0].back = sz(N);
		N.emplace_back(0);
		
		queue<int> q;
		for(q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i, 0, alpha) {
				int& ed = N[n].next[i], y = N[prev].next[i];
			}
		}
	} 
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	string s;
	cin >> s;

	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	AhoCorasick automaton(v);
}
