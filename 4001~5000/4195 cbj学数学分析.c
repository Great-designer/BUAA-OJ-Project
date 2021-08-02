#include <stdio.h>
#include <stdlib.h>
int arr0[200000] = {0};
int cmp(const void *a,const void *b)
{
	return *((int *)b) - (*(int *)a);
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i = 0; i < n; i++)
	{
		scanf("%d",arr0 + i);
	}
	qsort(arr0,n,sizeof(int),cmp);
	double s = 0;
	for(i = 0; i < m; i++)
	{
		s += arr0[i];
	}
	s /= m;
	if(s >= 60.0)
	{
		printf("%.3f\n",s);
	}
	else
	{
		puts("Jianglaoshi%%%");
	}
	return 0;
}