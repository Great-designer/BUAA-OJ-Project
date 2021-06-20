#include<stdio.h>
#include<stdlib.h>

struct stu
{
	int data;
	int num;
	int shili;
};

struct stu a[25000];

int cmp(const void*p1,const void*p2)
{
	struct stu *x=(struct stu*)p1;
	struct stu *y=(struct stu*)p2;
	if(x->data==y->data)
	{
		return x->num>y->num;
	}
	return x->data<y->data;
}

int n,r,q;

int main()
{
	scanf("%d%d%d",&n,&r,&q);
	int i; 
	for(i=0;i<2*n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].num=i;
	}
	for(i=0;i<2*n;i++)
	{
		scanf("%d",&a[i].shili);
	}
	int j;
	for(j=0;j<r;j++)
	{
		qsort(a,2*n,sizeof(struct stu),cmp);
		for(i=0;i<2*n;i+=2)
		{
			if(a[i].shili<a[i+1].shili)
			{
				a[i+1].data++;
			}
			else if(a[i].shili>a[i+1].shili)
			{
				a[i].data++;
			}
		}
	}
	qsort(a,2*n,sizeof(struct stu),cmp);
	printf("%d\n",a[q-1].num+1);
	return 0;
}
