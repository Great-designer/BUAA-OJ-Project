#include<stdio.h>
#include<math.h>
#include<string.h> 

struct circle
{
	double x;
	double y;
	double r;
};

struct circle list[55];
char ain[55];
char bin[55];

int n;

double dis(double x1,double y1,double x2,double y2)
{
	double p=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(p);
}

void acheck(double x,double y)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(dis(x,y,list[i].x,list[i].y)<=list[i].r)
		{
			ain[i]=1;
		}
		else
		{
			ain[i]=0;
		}
	}
}

void bcheck(double x,double y)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(dis(x,y,list[i].x,list[i].y)<=list[i].r)
		{
			bin[i]=1;
		}
		else
		{
			bin[i]=0;
		}
	}
}

int ans()
{
	int t=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(ain[i]!=bin[i])
		{
			t++;
		}
	}
	return t;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(list,0,sizeof(list));
		memset(ain,0,sizeof(ain));
		memset(bin,0,sizeof(bin));
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&list[i].x);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&list[i].y);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&list[i].r);
		}
		double x1,x2,y1,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		acheck(x1,y1);
		bcheck(x2,y2);
		int www=ans();
		printf("%d\n",www);
	}
}
