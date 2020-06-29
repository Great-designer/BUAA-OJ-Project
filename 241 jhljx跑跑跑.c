#include<stdio.h>

int a[10010];
int b[10010];
int m,n,total,tn,i,j,num,counter;

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        total=n*m;
        tn=n;
        counter=num=0;
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&a[i]);
		}
        for(i=1;i<=total;i++)
        {
        	b[i]=i;
		}
        qsort(a+1,n,sizeof(int),compare);
        for(i=total;i>=1&&tn>0;i--)
        {
            if(a[tn]!=b[i])
            {
            	counter++;
			}
            else
            {
                if(0==counter)
                {
                	num++;
				}
                else
                {
                	counter--;
				}
                tn--;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

