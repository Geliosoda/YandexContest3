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

bool is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool check(string& s)
{
	string tmp;
	string l = "+-*()";
	bool fg = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			if (!(is_digit(s[i])))
			{
				bool f = false;
				for (int j = 0; j < l.size(); j++)
				{
					if (s[i] == l[j])
						f = true;
				}

				if (!f || (!tmp.empty() && s[i] != '(' && tmp.back() != ')' && !is_digit(tmp.back())))
					return false;
			}
			else if ((is_digit(s[i])) && !tmp.empty() && fg == true && (is_digit(tmp.back())))
			{
				return false;
			}

			fg = false;
			tmp.push_back(s[i]);
		}
		else
		{
			fg = true;
		}
	}

	s = tmp;
	return true;
}

int priority(char c)
{
	switch (c)
	{
	case '+':
		return 0;
	case '-':
		return 0;
	case '*':
		return 1;
	default:
		return 0;
	}
}

bool brackets(string s)
{
	int c = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			c++;
		else if (s[i] == ')')
			c--;

		if (c < 0)
			return false;
	}

	if (c != 0)
		return false;
	return true;
}

int64 f(int64 p1, int64 p2, char c)
{
	switch (c)
	{
	case '+':
		return p1 + p2;
	case '-':
		return p1 - p2;
	case '*':
		return p1 * p2;
	default:
		break;
	}
}

void solve()
{
	string s;
	getline(cin, s);
	if (!check(s) || !brackets(s) || (!is_digit(s[s.size() - 1]) && s[s.size() - 1] != ')'))
	{
		cout << "WRONG\n";
		return;
	}

	stack<char> o;
	vector<string> ans;

	string num;
	for (int i = 0; i < s.size(); i++)
	{
		if (is_digit(s[i]))
		{
			num.push_back(s[i]);
		}
		else
		{
			if (s[i] == '(')
			{
				o.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (!num.empty())
				{
					ans.push_back(num);
					num = "";
				}
				while (o.top() != '(')
				{
					ans.push_back(string(1, o.top()));
					o.pop();
				}
				o.pop();
			}
			else
			{
				if (!num.empty())
				{
					ans.push_back(num);
					num = "";
				}
				while (!o.empty() && priority(o.top()) >= priority(s[i]) && o.top() != '(')
				{
					ans.push_back(string(1, o.top()));
					o.pop();
				}
				o.push(s[i]);
			}
		}
	}
	if (!num.empty())
		ans.push_back(num);

	while (!o.empty())
	{
		ans.push_back(string(1, o.top()));
		o.pop();
	}

	stack<int64> b;
	for (int i = 0; i < ans.size(); i++)
	{
		if (!is_digit(ans[i][0]))
		{
			int64 p1 = b.top();
			b.pop();
			int64 p2 = b.top();
			b.pop();
			b.push(f(p2, p1, ans[i][0]));
		}
		else
		{
			b.push(stoi(ans[i]));
		}
	}

	cout << b.top();
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