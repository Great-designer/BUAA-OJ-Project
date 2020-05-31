#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
	double v;
	double t;
	double time;
};

int cmp(const void*p1,const void*p2)
{
	struct Node*a=(struct Node*)p1;
	struct Node*b=(struct Node*)p2;
    return a->time>b->time?1:-1;
};

struct Node no[10000];

int main()
{
    int N;
    while(~scanf("%d",&N))
    {
    	int i;
        for(i=0;i<N;i++)
        {
        	scanf("%lf%lf",&no[i].v,&no[i].t);
            no[i].v/=3.6;
            if(no[i].t<0)
            {
            	no[i].v=0.1;
			}
            no[i].time=no[i].t+(3000.0/(no[i].v));
        }
        qsort(no,N,sizeof(struct Node),cmp);
        int ans=ceil(no[0].time);
        printf("%d\n",ans);
    }
}
