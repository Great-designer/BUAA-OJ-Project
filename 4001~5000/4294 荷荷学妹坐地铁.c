#include<stdio.h>

int main()
{
	int d1 = 0,d2 = 0,d3 = 0,n,m,p,cur,result;
	scanf("%d%d%d",&n,&m,&p);
	while(n--)
	{
		scanf("%d",&cur);
		d1 += cur;
	}
	if(d1 > 15)d1 = 15;
	while(m--)
	{
		scanf("%d",&cur);
		d2 += cur;
	}
	if(d2 > 15)d2 = 15;
	while(p--)
	{
		scanf("%d",&cur);
		d3 += cur;
	}
	if(d3 > 15)d3 = 15;
	result = d1 + d2 + d3;
	if(result > 40)result = 40;
	printf("%d\n",result);
	return 0;
}