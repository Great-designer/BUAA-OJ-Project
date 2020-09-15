#include<stdio.h>

int i,n,a[1050],Left,Right;

int main()
{
	scanf("%d",&n);
    for(i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    a[0]=1;
	a[n]=-1;
    for(i=1;i<=n;i++)
	{
        Left=i-1;
        while(a[Left]==0)
		{
			Left--;
		}
        Right=i;
        while(a[Right]==0)
		{
			Right++;
		}
        if(a[Left]>0&&a[Right]<0)
		{
			printf("%d ",i);
		}
    }
    printf("\n");
}


