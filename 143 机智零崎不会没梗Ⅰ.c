#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct node
{
    double w;
    double v;
    double temp;
};

int cmp(const void*p1,const void*p2)
{
	struct node*a=(struct node*)p1;
	struct node*b=(struct node*)p2;
	return a->temp<b->temp?1:-1;
};

struct node no[10005];

int main()
{
	int K;
	double G,N,ans;
    while(~scanf("%lf%d%lf",&G,&K,&N))
    {
        ans=0;
        memset(no,0,sizeof(no));
        int i;
        for(i=0;i<K;i++)
        {
            scanf("%lf%lf",&no[i].w,&no[i].v);
            no[i].temp=no[i].v/no[i].w;
        }
        qsort(no,K,sizeof(struct node),cmp);
        for(i=0;i<K;i++)
        {
            if(G>=no[i].w)
            {
                ans+=no[i].v;
                G-=no[i].w;
            }
            else
            {
                ans=ans+G*(no[i].temp);
                G=0;
            }
        }
        if(ans>=N)
        {
        	printf("summon!\n");
		}
        else
        {
        	printf("%.3lf\n",N-ans);
		}
    }
}

