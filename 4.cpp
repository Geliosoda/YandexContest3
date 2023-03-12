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
const int INF = 1e9;
const int64 INF64 = 1e18;

void solve()
{
	int n, k, a, b;
	cin >> n >> k >> a >> b;

	int d = (n + 1) / 2;
	if (k % 2 == 0)
	{
		int l1 = a + (k / 2), l2 = a - (k / 2);
		bool b1 = (l1 < d || (l1 == d && (n % 2 == 0 || b == 1))), b2 = (l2 > 0);
		if (b1 && b2 || (b1 && !b2))
			cout << l1 << ' ' << b;
		else if (b2)
			cout << l2 << ' ' << b;
		else
			cout << -1;
	}
	else
	{
		int l1 = a + (k / 2) + (b == 2 ? 1 : 0), l2 = a - (k / 2) - (b == 1 ? 1 : 0);
		bool b1 = (l1 < d || (l1 == d && (n % 2 == 0 || b == 2))), b2 = (l2 > 0);

		if (b1 && b2)
		{
			if (abs(a - l1) < abs(a - l2))
				cout << a + (k / 2) + (b == 2 ? 1 : 0) << ' ' << (b == 2 ? 1 : 2);
			else
				cout << a - (k / 2) - (b == 1 ? 1 : 0) << ' ' << (b == 1 ? 2 : 1);
		}
		else if (b1)
			cout << a + (k / 2) + (b == 2 ? 1 : 0) << ' ' << (b == 2 ? 1 : 2);
		else if (b2)
			cout << a - (k / 2) - (b == 1 ? 1 : 0) << ' ' << (b == 1 ? 2 : 1);
		else
			cout << -1;

		/*if (l1 < d || (l1 == d && (n % 2 == 0 || b == 2)))
			cout << a + (k / 2) + (b == 2 ? 1 : 0) << ' ' << (b == 2 ? 1 : 2);
		else if (l2 > 0)
			cout << a - (k / 2) - (b == 1 ? 1 : 0) << ' ' << (b == 1 ? 2 : 1);
		else
			cout << -1;*/
	}
	cout << '\n';
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