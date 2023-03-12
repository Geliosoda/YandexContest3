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

bool is_equal(string s1, string s2)
{
	if (s1[0] != '<' || s2[0] != '<'
		|| s1[s1.size() - 1] != '>' || s2[s2.size() - 1] != '>'
		|| s1.size() - 2 != s2.size() - 3 || s2.size() <= 1 || s2[1] != '/')
		return false;
	int i = 1, j = 2;
	while (i < s1.size() - 1 && j < s2.size() - 1)
	{
		if (s1[i] != s2[j] || s1[i] == '<' || s1[i] == '>' || s1[i] == '/'
			|| s2[j] == '<' || s2[j] == '>' || s2[j] == '/')
			return false;
		i++; j++;
	}
	return true;
}

void solve()
{
	string s;
	cin >> s;

	string alf = "</>";
	char f = 'a', e = 'z';
	for (int i = 0; i < s.size(); i++)
	{
		char tmp = s[i];
		stack<string> a;
		bool fg = false;
		for (int j = f; j <= e; j++)
		{
			s[i] = (char)j;
			string s2;
			s2.push_back(s[0]);
			bool fg1 = true;
			for (int k = 1; k < s.size(); k++)
			{
				if (s[k] == '<' || k == s.size() - 1)
				{
					if (k == s.size() - 1)
						s2.push_back(s[k]);
					if (s2.size() > 1 && s2[1] == '/' || k == s.size() - 1)
					{
						if (!a.empty() && is_equal(a.top(), s2))
						{
							a.pop();
						}
						else
						{
							fg1 = false;
							break;
						}
					}
					else
					{
						a.push(s2);
					}
					s2 = "<";
				}
				else
				{
					s2.push_back(s[k]);
				}
			}

			if (!fg1 || !a.empty())
			{
				while (!a.empty())
					a.pop();
				continue;
			}
			fg = true;
			break;
		}

		if (fg)
			break;
		while (!a.empty())
			a.pop();

		for (int j = 0; j < alf.size(); j++)
		{
			s[i] = alf[j];
			string s2;
			s2.push_back(s[0]);
			bool fg1 = true;
			for (int k = 1; k < s.size(); k++)
			{
				if (s[k] == '<' || k == s.size() - 1)
				{
					if (k == s.size() - 1)
						s2.push_back(s[k]);
					if (s2.size() > 1 && s2[1] == '/' || k == s.size() - 1)
					{
						if (!a.empty() && is_equal(a.top(), s2))
						{
							a.pop();
						}
						else
						{
							fg1 = false;
							break;
						}
					}
					else
					{
						a.push(s2);
					}
					s2 = "<";
				}
				else
				{
					s2.push_back(s[k]);
				}
			}

			if (!fg1 || !a.empty())
			{
				while (!a.empty())
					a.pop();
				continue;
			}
			fg = true;
			break;
		}

		if (!fg)
			s[i] = tmp;
	}

	cout << s;
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