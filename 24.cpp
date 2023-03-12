#define _CRT_SECURE_NO_WARNINGS
#define ALL(x) (x).begin(), (x).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define xx first
#define yy second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#include <iostream>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <list>
#include <cctype>
#include <regex>
#include <unordered_map>

using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef pair<int, int> pint;
typedef pair<int64, int64> pint64;
typedef vector<int> vint;
typedef vector<bool> vbool;
typedef vector<int64> vint64;
typedef vector<uint64> uvint64;

template<typename T1, typename T2>
istream& operator >> (istream& in, pair<T1, T2>& p)
{
	return in >> p.first >> p.second;
}

template<typename T1, typename T2>
ostream& operator << (ostream& out, pair<T1, T2>& p)
{
	return out << p.first << ' ' << p.second;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		in >> v[i];
	}
	return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		out << v[i] << ' ';
	}
	return out;
}

const double PI = 3.1415926535897932384626433832795;
const double EPS = numeric_limits<double>::epsilon();
const int N = 1e5 + 100;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const int64 INF64 = 1e18;

const int64 beg = 9 * 3600, en = 18 * 3600, p1 = 13 * 3600, p2 = 14 * 3600;
//int f(int n)
//{
//	if (dp[n] != -1)
//		return dp[n];
//	if (n >= p1 && n <= p2)
//		return dp[n] = f(n - 1);
//	auto v = a.lower_bound(n);
//	return dp[n] = max(((!(n - v->second >= p1 && n - v->second <= p2)
//		&& n - v->second > beg) ? f(n - v->second) + 1 : -1), f(n - 1));
//}

void solve()
{
	int64 n;
	cin >> n;
	map<int64, int64> a;
	vector<int64> dp(en + 1, -1);

	for (int i = 0; i < n; i++)
	{
		int64 h, m, s, v;
		char c;
		cin >> h >> c >> m >> c >> s >> v;
		int64 l = h * 3600 + m * 60 + s;
		a[l] = v;
	}

	dp[beg] = 0;
	for (int i = beg; i < en; i++)
	{
		auto it = a.upper_bound(i);
		it--;
		int64 j = i + it->second;
		if (!(j > p1 && j < p2) && j <= en && !(i < p1 && j > p1) && !(i >= p1 && i < p2))
		{
			dp[j] = max(dp[j], dp[i] + 1);
			dp[i + 1] = max(dp[i + 1], dp[i]);
		}
		else
		{
			dp[i + 1] = max(dp[i], dp[i + 1]);
		}
	}

	cout << dp[en];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("peacefulsets.in", "r", stdin);
	//freopen("peacefulsets.out", "w", stdout);
#endif

	solve();

	return 0;
}