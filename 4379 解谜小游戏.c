#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct data
{
	double value;
	int order;
	int rank;
	char str[100];
} list[500005];

int cmp1(const void *p1, const void *p2)
{
	if(fabs(((struct data *)p1)->value-((struct data *)p2)->value)<1e-8) return 0;
	else if(((struct data *)p1)->value>((struct data *)p2)->value) return 1;
	else return -1;
}

int cmp2(const void *p1, const void *p2)
{
	if(((struct data *)p1)->order==((struct data *)p2)->order) return 0;
	else if(((struct data *)p1)->order>((struct data *)p2)->order) return 1;
	else return -1;
}

int main()
{
	int n=0,i;
	while(scanf("%s",list[n].str)!=EOF)
	{
		list[n].order=n+1;
		list[n].value=atof(list[n].str);
		n++;
	}
	printf("%d\n",n);
	qsort(list,n,sizeof(struct data),cmp1);
	list[0].rank=1;
	for(i=1; i<n; i++)
	{
		if(fabs(list[i].value-list[i-1].value)<1e-8) list[i].rank=list[i-1].rank;
		else list[i].rank=i+1;
	}
	qsort(list,n,sizeof(struct data),cmp2);
	for(i=0; i<n; i++)
	{
		printf("%d: %s\n",list[i].rank,list[i].str);
	}
	return 0;
}