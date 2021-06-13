#include<stdio.h>
#include<string.h>

int a[400010];

int getFather(int x)
{
	return a[x] ? a[x] = getFather(a[x]) : x;//最顶层有的话，就返回最顶层，否则自己就是最顶层
}

int main()
{
	int m,lo,hi;
	while(scanf("%d%d%d", &m, &lo, &hi) != EOF)
	{
		char flag=1;
		memset(a, 0, sizeof(a));
		while(m--)
		{
			int l,r;
			scanf("%d%d", &l, &r);
			l = getFather(l);
			while(l <= r)
			{
				//左端点往右边挪，减少答案值
				a[l] = l + 1;//l被拯救了
				l = getFather(l);
			}
		}
		int i;
		for(i = lo; i <= hi; ++i)
		{
			if(!a[i])
			{
				printf("%d\n", i);
				flag=0;
				break;
			}
		}
		if(flag)
		{
			puts("War,war never changes.");
		}
	}
	return 0;
}