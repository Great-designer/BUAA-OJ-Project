#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#include<map>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string buf;
string p[2];
int index1, index2;

string getElem0()
{
	string ret = "";
	ret += p[0][index1++];
	while (islower(p[0][index1]))
	{
		ret += p[0][index1++];
	}
	return ret;
}

string getElem1()
{
	string ret = "";
	ret += p[1][index2++];
	while (islower(p[1][index2]))
	{
		ret += p[1][index2++];
	}
	return ret;
}

int getNum0()
{
	int ret = 0;
	while (isdigit(p[0][index1]))
	{
		ret = ret * 10 + p[0][index1++] - '0';
	}
	return ret;
}

int getNum1()
{
	int ret = 0;
	while (isdigit(p[1][index2]))
	{
		ret = ret * 10 + p[1][index2++] - '0';
	}
	return ret;
}

map<string,long long> merge(map<string,long long> a, map<string,long long> b)
{
	map<string,long long> c;
	for (map<string,long long>::iterator it = a.begin(); it != a.end(); ++it)
	{
		if (c.count(it->first))
		{
			c[it->first] += it->second;
		}
		else
		{
			c.insert(make_pair(it->first, it->second));
		}
	}
	for (map<string,long long>::iterator it = b.begin(); it != b.end(); ++it)
	{
		if (c.count(it->first))
		{
			c[it->first] += it->second;
		}
		else
		{
			c.insert(make_pair(it->first, it->second));
		}
	}
	return c;
}

void multiply(map<string,long long>& a, long long time)
{
	for (map<string,long long>::iterator it = a.begin(); it != a.end(); ++it)
	{
		it->second *= time;
	}
}

map<string,long long> dfs_0(char end)
{
	//对应一个元素的StateMap
	map<string,long long> ret;
	while (p[0][index1] && p[0][index1] != end && p[0][index1] != ')')
	{
		if (p[0][index1] == '+')
		{
			index1++;
			continue;
		}
		if (isdigit(p[0][index1]))
		{
			long long t = getNum0();
			map<string,long long> tmp = dfs_0('+');
			multiply(tmp, t);
			ret = merge(ret, tmp);
		}
		else
		{
			//非系数开头的话需要考虑括号
			if (p[0][index1] == '(')
			{
				index1++;
				map<string,long long> tmp = dfs_0(')');
				if (p[0][index1] == ')')index1++;
				if (isdigit(p[0][index1]))
				{
					multiply(tmp, getNum0());
				}
				ret = merge(ret, tmp);
			}
			else
			{
				string s = getElem0();
				if (isdigit(p[0][index1]))
				{
					if (ret.count(s))ret[s] += getNum0();
					else ret.insert(make_pair(s, getNum0()));
				}
				else
				{
					if (ret.count(s))ret[s] += 1;
					else ret.insert(make_pair(s, 1));
				}
			}
		}
	}
	return ret;
}

map<string,long long> dfs_1(char end)
{
	//对应一个元素的StateMap
	map<string,long long> ret;
	while (p[1][index2] && p[1][index2] != end && p[1][index2] != ')')
	{
		if (p[1][index2] == '+')
		{
			index2++;
			continue;
		}
		if (isdigit(p[1][index2]))
		{
			long long t = getNum1();
			map<string,long long> tmp = dfs_1('+');
			multiply(tmp, t);
			ret = merge(ret, tmp);
		}
		else
		{
			//非系数开头的话需要考虑括号
			if (p[1][index2] == '(')
			{
				index2++;
				map<string,long long> tmp = dfs_1(')');
				if (p[1][index2] == ')')index2++;
				if (isdigit(p[1][index2]))
				{
					multiply(tmp, getNum1());
				}
				ret = merge(ret, tmp);
			}
			else
			{
				string s = getElem1();
				if (isdigit(p[1][index2]))
				{
					if (ret.count(s))ret[s] += getNum1();
					else ret.insert(make_pair(s, getNum1()));
				}
				else
				{
					if (ret.count(s))ret[s] += 1;
					else ret.insert(make_pair(s, 1));
				}
			}
		}
	}
	return ret;
}

int main()
{
	buf.resize(100010);
	p[0].resize(100010);
	p[0].resize(100010);
	while (cin >> buf)
	{
		int splitPos = buf.find("=");
		p[0] = buf.substr(0, splitPos);
		p[1] = buf.substr(splitPos + 1, buf.size() - splitPos - 1);
		index1 = index2 = 0;
		map<string,long long> ans1, ans2, tmp;
		while (1)
		{
			tmp = dfs_0('+');
			ans1 = merge(ans1, tmp);
			if (index1 >= p[0].size())break;
			index1++;
		}
		while (1)
		{
			tmp = dfs_1('+');
			ans2 = merge(ans2, tmp);
			if (index2 >= p[1].size())break;
			index2++;
		}
		map<string,long long>::iterator m1 = ans1.begin(), m2 = ans2.begin();
		while (1)
		{
			if (m1 == ans1.end())break;
			if (m2 == ans2.end())break;
			if (m1->first != m2->first || m1->second != m2->second)break;
			*m1++, * m2++;
		}
		if (m1 == ans1.end() && m2 == ans2.end())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
