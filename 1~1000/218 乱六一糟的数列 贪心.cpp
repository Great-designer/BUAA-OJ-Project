#include<stdio.h>
#include<string.h>

#include<set>
using namespace std;

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int n;
int tmp;
int count1;
int ans;
int last_position;
bool occur[1300000];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		set<int> flag;
		n <<= 1;
		ans = 0, last_position = 0;
		for (int i = 2; i <= n; i += 2)flag.insert(i);
		for (int i = 1; i <= n; ++i)
		{
			tmp = read();
			if (tmp == 1)
			{
				set<int>::iterator it = flag.begin();
				if (*it <= i)
				{
					flag.erase(it);
				}
			}
		}
		write(flag.size()), putchar('\n');
	}
}