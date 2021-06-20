#include<stdio.h>

char a[10000];
 
int main()
{
    int n,counter;
    while(~scanf("%d",&n))
    {
        counter=0;
        scanf("%s",a);
        int i;
        for(i=1;i<=n-2;i++)
        {
            if(a[i-1]<='z'&&a[i-1]>='a'&&a[i]<='Z'&&a[i]>='A'&&a[i+1]<='z'&&a[i+1]>='a')
            {
                counter++;
            }
        }
        if(counter!=0)
        {
            printf("Yes\n");
        }
        else
        {
        	printf("No\n");
        }
    }
}

