#include<stdio.h>
#include<string.h>

char a[30005];
int n;
int count;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		count=0;
		scanf("%s",a);
		int len=strlen(a);
		int i;
		for(i=0;i<len;++i)
		{
			if(a[i]!='('&&a[i]!=')'&&a[i]!=',')
			{
				if(!((a[i+1]>='a'&&a[i+1]<='z')||(a[i+1]>='A'&&a[i+1]<='Z')))
				{
					if(a[i+1]!='(')
					{
						++count;
					}
					else if(a[i+1]=='('&&a[i+2]==','&&a[i+3]==')')
					{
						++count;
					}
				}
			}
		}
		printf("%d\n",count);
	}
}
