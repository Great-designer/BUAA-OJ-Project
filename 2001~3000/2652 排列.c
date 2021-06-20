#include<stdio.h>

int a[10],r[10],n,m;
int b[10];

void f(int d)
{
    int i;
    int j=m;
    if(d==n)
    {
    	int flag=1;
    	for(i=0;i<m;i++)
    	{
    		if(a[i]!=b[i])
    		{
    			flag=0;
    			break;
			}
		}
		if(flag==1)
		{
			return;
		}
    	for(i=0;i<m;i++)
        {
            printf("%d ",a[i]);
        }
        for(i=0;i<m;i++)
        {
            b[i]=a[i];
        }
        printf("\n");
        return ;
    }
    for(i=0;i<n;++i)
    {
        if(r[i]==0&&j!=0)
        {
            a[d]=i+1;
            r[i]=1;
            j--;
            f(d+1);
            j++;
            r[i]=0;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    f(0);
    return 0;
}
