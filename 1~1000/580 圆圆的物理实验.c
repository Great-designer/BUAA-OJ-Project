#include<stdio.h>
int c[10];
struct node
{
	int point;
	char flag;
} now[10];
void init()
{
	c[1] = 4;
	c[2] = 3;
	c[3] = 5;
	c[4] = 6;
	c[5] = 4;
	c[6] = 6;
	c[7] = 5;
	c[8] = 4;
	c[9] = 3;
}
char s[105];
int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int res = 0 ;
		for(int i = 1 ; i <= 9 ; i++)
		{
			for(int j = 0 ; j < 9; j++)
			{
				now[j].flag = 1;
			}
			for(int j = 0 ; j < c[i]; j++)
			{
				scanf("%d", &now[j].point);
			}
			for(int z = 0 ; z < 2 ; z++)
				for(int j = 0 ; j < c[i]; j++)
				{
					scanf("%s", s);
					if(s[0] - '0' < 3)
					{
						now[j].flag = 0;
					}
				}
			for(int j = 0 ; j < c[i]; j++)
			{
				if(now[j].flag)
				{
					res += now[j].point;
				}
			}
		}
		printf("%d\n",res);
	}
}