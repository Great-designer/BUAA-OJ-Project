#include<stdio.h>
#include<stdlib.h>

struct edg
{
    int x,y,z;
};

int compare(const void*p1,const void*p2)
{
	return (*(struct edg*)p2).z<(*(struct edg*)p1).z?1:-1;
}

int pre[100010],s[100010];
struct edg e[100010];

int find(int x)
{
    if(pre[x]!=x)
    {
    	pre[x]=find(pre[x]);
	}
    return pre[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
		long long res=0;
        scanf("%d",&n);
        int i;
        for(i=1;i<n;++i)
        {
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
            res+=e[i].z;
        }
        for(i=1;i<=n;++i)
        {
            pre[i]=i;
			s[i]=1;
        }
        qsort(e+1,n-1,sizeof(e[1]),compare);
        for(i=1;i<n;++i)
        {
            int fx=find(e[i].x);
			int fy=find(e[i].y);
            if(fx!=fy)
            {
                pre[fx]=fy;
                res+=(long long)(e[i].z+1)*(s[fx]*s[fy]-1);
                s[fy]+=s[fx];
                s[fx]=0;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
