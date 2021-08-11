#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
//const int ULTRA = 1e14;
const int PROMAX = 1e6 + 5;
const int PRO = 1e5 + 5;
#define countSetbits(x) __builtin_popcountll(x)
#define debugArray(a, n) for(int i = 0; i<n; i++) cerr<<a[i]<<(i == n-1?"":" ");
#define debugVal(x) cerr<<x;
#define all(x) x.begin(), x.end()
#define lla(x) x.rbegin(), x.rend()
#define pb push_back
// fast IO
#define ThinkTwice ios_base::sync_with_stdio(false), cin.tie(NULL);
// for grid problems
int    dx[] = {-1,  0,  1,  0, -1, -1,  1,  1};
int    dy[] = { 0,  1,  0, -1, -1,  1,  1, -1};
char  dir[] = {'U','R','D','L'};
// powers
inline int powmod(int a, int b, int mod) {int res=1; while(b>0) {if(b&1) res=(res*a)%mod; a=(a*a)%mod, b>>=1; } return res;}
inline int power(int a, int b) {int res=1; while(b>0) {if(b&1) res*=a; a*=a, b>>=1;} return res; }
// vector input
template <class X> istream& operator>>(istream &cin, vector<X> &a) {int n = a.size(); for(int i = 0; i<n; i++) cin>>a[i]; return cin;}
// vector output
template <class X> ostream& operator<<(ostream &cout, vector<X> const &a) {for(int i = 0; i<a.size(); i++) cout<<a[i]<<" "; return cout;}
// pair output
template <class X, class Y> ostream& operator<<(ostream &cout, pair <X, Y> const &p) {cout<<p.first<<" "<<p.second; return cout; }
//__________________________________________________________________

void getHash(string a, vector <int> &dp, vector <int> &inv) {
	int value = 0;
	int power = 1;
	int p = 31; // prime number > number of lowercase char
	int i = 0;
	for(auto x: a) {
		// +1 to remove initial collision, hash(a) = hash(aa)
		value = (value + (x - 'a' + 1)*power)%MOD;
		// store value and inverse-modulo to use for substringHash calc
		dp[i] = value;
		inv[i++] = powmod(power, MOD-2, MOD);
		power = (power*p)%MOD;
	}
}

int substringHash(vector <int> &dp, vector <int> &inv, int l, int r) {
	int res = dp[r];
	if(l > 0) res -= dp[l-1];
	res = (res * inv[l])%MOD; // multiply precalcuated inverse-modulo to take MOD
	return res;
}

void solve() {
	string a; cin>>a;
	int n = a.length();
	vector <int> dp(n), inv(n);
	getHash(a, dp, inv);
	int q; cin>>q;
	while(q--) {
		int l, r; cin>>l>>r;
		cout<<substringHash(dp, inv, l, r)<<endl;	
	}
}

signed main() {
	ThinkTwice
	int t = 1;
	// cin>>t;

	for(int i = 1; i<=t; i++) {
		// cout<<"Case #"<<i<<": ";
		solve();
	}
}

//__________________________________________________________________
/*
Sample Input:
abcdefghi
3
0 1
3 5
0 8

Sample Output:
63
5925
509234931

*/
