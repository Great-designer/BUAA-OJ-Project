#include <stdio.h>

int main()
{
	int a[100]= {0},b[100]= {0};
	int n,i,m;
	int pass,get;
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d",&pass,&get);
		a[pass]+=1,b[get]+=1;
	}
	scanf("%d",&m);
	if(a[m]|b[m])			     //条件判断，如果传接球不同时为零
		printf("%d %d",a[m],b[m]);
	else
		printf("N0t 1n my team!");
	return 0;
}