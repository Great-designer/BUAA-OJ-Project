#include<stdio.h>

int a[100005];

int main()
{
    int n,i,j,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for(j=0;j<i;j++)
        {
            if(a[j]>a[i])
            {
                s++;
            }
        }
    }
    printf("%d",s);
}
