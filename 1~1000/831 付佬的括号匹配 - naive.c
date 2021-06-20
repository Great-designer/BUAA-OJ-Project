#include<stdio.h>
#include<string.h>

char a[60][60]; 
int b[60];

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
		getchar();
		int i;
		int j=0;
		for(i=0;i<n;i++)
		{
			gets(a[i]);
			if(a[i][0]=='('&&a[i][strlen(a[i])-1]==')')
			{
				b[j]=i;
				j++;
			}
		}
		printf("%d\n",j);
		for(i=0;i<j;i++)
		{
			printf("%s\n",a[b[i]]);
		}
		printf("----------\n");
    }
    return 0;
}

