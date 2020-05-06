#include<stdio.h>
#include<stdlib.h> 

int n,m,l;

struct Path
{
    int c,k;
};

int compare(const void*p1,const void*p2)
{
	struct Path*b=(struct Path*)p1;
	struct Path*a=(struct Path*)p2;
	return (a->k>b->k||(a->k==b->k&&a->c<b->c))?1:-1;
}

struct Path e[100010];
int pre[10010],end[10010],T,i,j,p,q,t;

int main()
{
    scanf("%d",&T);
    for(j=1;j<=T;j++)
	{
        scanf("%d%d%d",&n,&m,&l);
        for(i=0;i<m;i++)
		{
			scanf("%d%d",&e[i].c,&e[i].k);
		}
        qsort(e,m,sizeof(struct Path),compare);
        for(i=0;i<n;i++)
		{
			pre[i]=i;
		}
        for(i=0;i<m;i++)
		{
            p=e[i].c,q=p+1;
            if(i&&e[i].c==e[i-1].c&&e[i].k==e[i-1].k);
            else
			{
				t=pre[p],pre[p]=pre[q],pre[q]=t;
			}
        }
        printf("Case %d #:",j);
        for(i=0;i<n;i++)
		{
			printf(" %d",pre[i]);
		}
        putchar('\n');
    }
    return 0;
}
