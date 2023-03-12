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

void solve()
{
	int64 n;
	cin >> n;

	vector<int64> a(n);
	cin >> a;

	int64 ma = -1;
	int64 cnt = 0;
	int64 locmi = INF64;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			cnt++;
			locmi = min(locmi, a[i]);
		}
		else
		{
			ma = max(ma, cnt * locmi);
			cnt = 0;
			locmi = INF64;
		}
	}
	ma = max(cnt * locmi, ma);

	vector<int64> ans1(n);
	stack<pint64> s1;
	s1.push(mp(a[0], 0));
	for (int i = 1; i < n; i++)
	{
		while (!s1.empty() && s1.top().first > a[i])
		{
			ans1[s1.top().second] = i;
			s1.pop();
		}
		s1.push(mp(a[i], i));
	}

	while (!s1.empty())
	{
		ans1[s1.top().second] = n;
		s1.pop();
	}

	vector<int64> ans2(n);
	stack<pint64> s2;
	s2.push(mp(a[0], 0));
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s2.empty() && s2.top().first > a[i])
		{
			ans2[s2.top().second] = i;
			s2.pop();
		}
		s2.push(mp(a[i], i));
	}

	while (!s2.empty())
	{
		ans2[s2.top().second] = -1;
		s2.pop();
	}

	for (int i = 0; i < n; i++)
	{
		ma = max(ma, a[i] * (ans1[i] - ans2[i] - 1));
		//ma = max(ma, a[i] * (i - ans2[i]));
	}

	cout << ma;
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