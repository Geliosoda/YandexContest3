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
const int INF = 1e9 + 10;
const int64 INF64 = 1e18;

void solve()
{
	int64 k;
	string s;
	cin >> k >> s;

	map<char, vector<pint64>> m;
	map<char, int64> p;

	int64 lt = 0, rt = 0;
	while (rt != s.size())
	{
		if (s[lt] == s[rt])
		{
			rt++;
		}
		else
		{
			m[s[lt]].push_back(mp(lt, rt - 1));
			lt = rt;
		}
	}
	m[s[lt]].push_back(mp(lt, rt - 1));

	for (auto it = m.begin(); it != m.end(); it++)
	{
		int64 ma = -1;
		int64 l = 0, r = 0, t = k, sum = ((it->yy)[l].second - (it->yy)[l].first) + 1;
		while (r != (it->yy).size())
		{
			if (r != (it->yy).size() - 1)
			{
				if ((it->yy)[r + 1].first - (it->yy)[r].second - 1 <= t)
				{
					sum += (it->yy)[r + 1].first - (it->yy)[r].second - 1;
					sum += ((it->yy)[r + 1].second - (it->yy)[r + 1].first) + 1;
					t -= (it->yy)[r + 1].first - (it->yy)[r].second - 1;
					r++;
				}
				else
				{
					ma = max(ma, sum + t);
					sum -= (it->yy)[l + 1].first - (it->yy)[l].second - 1;
					sum -= ((it->yy)[l].second - (it->yy)[l].first) + 1;
					t += (it->yy)[l + 1].first - (it->yy)[l].second - 1;
					l++;
				}
			}
			else
			{
				sum += min((it->yy)[l].first, t);
				t -= min((it->yy)[l].first, t);
				sum += min((int)s.size() - (it->yy)[r].second - 1, t);
				t -= min((int)s.size() - (it->yy)[r].second - 1, t);
				ma = max(sum, ma);
				r++;
			}
		}

		p[it->first] = ma;
	}

	int64 ma = -1;
	for (auto it = p.begin(); it != p.end(); it++)
	{
		ma = max(it->second, ma);
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