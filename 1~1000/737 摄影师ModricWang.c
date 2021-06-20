#include<stdio.h>

int n;
int tmp;
int ans;
int s[100010];
int top;

int main()
{
	scanf("%d", &n);
	s[top]=2147483647;
	top++;
	int i;
	for(i=1;i<=n;++i)
	{
		ans+=top-1;
		scanf("%d",&tmp);
		while(s[top-1]<tmp)
		{
			top--;
		}
		s[top]=tmp;
		top++;
	}
	printf("%d\n",ans);
}
