#include<stdio.h>
#include<stdlib.h>

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int a[500005];

int n,m;

int check(int x)
{
    int cnt=0,j=1,i;
	while(j<n)
	{
		i=j;
		while(i<=n)
		{
			if(a[i+1]-a[j]<=x)
			{
				i++;
			}
			else
			{
				break;
			}
		}
		if(i!=j)
		{
			j=i;
			cnt++;
		}
		else
		{
			return 0;
		}	
	} 
	if(cnt<=m) 
	{
		return 1;
	}
    return 0; 
}

int L;

void solve()
{
    int l=0,r=L,mid;
    while(l<r)
    {
        mid=(l+r)/2;
    	if(check(mid)) 
    	{
    		r=mid;
		}
		else
		{
			l=mid+1;
		}
    }
    printf("%d\n",r);
}

int main()
{
    while(scanf("%d%d%d",&L,&n,&m)!=EOF)
    {
    	a[1]=0;
    	int i;
    	for(i=1;i<=n;i++) 
    	{
    		scanf("%d",&a[i+1]);
		}
        n++;
        qsort(a+1,n,sizeof(int),compare);
        a[n+1]=L;
        n++;
        solve();
    }
}
