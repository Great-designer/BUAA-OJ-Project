#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,p,t;

int compar(const void *p1,const void *p2)
{
    int *a=(int *)p1;
    int *b=(int *)p2;
    if(*a>*b)
	{
		return 1;
	}
    else if(*a<*b)
	{
		return -1;
	}
    else
	{
		return 0;
	}
}

int a[100010];
int b[100010];
int c[100010];

int main() 
{
    int i,n,j,t,m,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        k=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<m;i++)
        {
            int flag=0;
            for(j=0;j<n;j++)
            {
                if(b[j]==a[i])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                c[k]=a[i];
                k++;
            }
        }
        qsort(c,k,sizeof(int),compar);
        if(c[0]==0)
        {
            printf("LOSER!");
        }
        else
        {
            printf("%d\n",k);
            for(i=0;i<k;i++)
            {
                printf("%d ",c[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

