#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include<unordered_map>
using namespace std;

unordered_map<int,pair<pair<int,int>,pair<int,int> > > m;

int res;
int n, k;
int num1, num2, num3;
char op[10];
char cu[3] = "Cu";
char fe[3] = "Fe";
char au[3] = "Au";
char ag[4] = "Ag";

int readNum()
{
	int k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

void readOp()
{
	int index = 0;
	char c = getchar();
	while (!isalpha(c))
	{
		c = getchar();
	}
	while (isalpha(c))
	{
		op[index++] = c;
		c = getchar();
	}
}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		m.clear();
		while (n--)
		{
			num1 = readNum();
			num2 = readNum();
			num3 = readNum();
			readOp();
			if (!m.count(num1)) m[num1] = make_pair(make_pair(0, 0), make_pair(0, 0));
			if (!m.count(num2)) m[num2] = make_pair(make_pair(0, 0), make_pair(0, 0));
			if (!m.count(num3)) m[num3] = make_pair(make_pair(0, 0), make_pair(0, 0));
			if (!strcmp(op, fe))
			{
				m[num1].second.second++, m[num2].second.second++, m[num3].second.second++;
			}
			else if (!strcmp(op, cu))
			{
				m[num1].second.first++, m[num2].second.first++, m[num3].second.first++;
			}
			else if (!strcmp(op, ag))
			{
				m[num1].first.second++, m[num2].first.second++, m[num3].first.second++;
			}
			else if (!strcmp(op, au))
			{
				m[num1].first.first++, m[num2].first.first++, m[num3].first.first++;
			}
		}
		while (k--)
		{
			num1 = readNum();
			if (!m.count(num1))
			{
				printf("0Au 0Ag 0Cu 0Fe\n");
			}
			else
			{
				printf("%dAu %dAg %dCu %dFe\n", m[num1].first.first, m[num1].first.second, m[num1].second.first, m[num1].second.second);
			}
		}
	}
}