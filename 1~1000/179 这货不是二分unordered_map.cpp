#include<stdio.h>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<int,int>A;

int n, m, tmp;
int a[1000010];

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		A.clear();
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
		}
		for(i = 0; i < n; ++i)
		{
			if (!A.count(a[i]))
			{
				A[a[i]] = i;
			}
		}
		while (m--)
		{
			scanf("%d", &tmp);
			if (!A.count(tmp))
			{
				puts("error");
			}
			else
			{
				printf("%d\n", A[tmp] + 1);
			}
		}
	}
}