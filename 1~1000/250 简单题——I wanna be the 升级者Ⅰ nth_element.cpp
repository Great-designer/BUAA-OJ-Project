#include<iostream>
#include<algorithm>

using namespace std;

struct map
{
	int num;
	int size;
};

struct map maps[1000010];

bool cmp(struct map a, struct map b)
{
	return a.size > b.size;
}

int n, k;
bool isEnd;

void init()
{
	for (int i = 0; i < n; ++i)maps[i].num = i + 1;
}

int read()
{
	int k = 0;
	char c = getchar();
	while (!isdigit(c))c = getchar();
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	if (c == EOF)isEnd = true;
	return k;
}

void write(int a)
{
	if (a >= 10)write(a / 10);
	putchar(a % 10 + 48);
}

void print(int a, int b)
{
	putchar('m'), putchar('a'), putchar('p');
	write(a);
	putchar(' '), putchar(':'), putchar(' ');
	write(b);
	putchar('\n');
}

int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		init();
		for (int i = 0; i < n; ++i)maps[i].size = read();
		nth_element(maps, maps + k, maps + n, cmp);
		print(maps[k - 1].num, maps[k - 1].size);
	}
}
