#include<stdio.h>

int main()
{
	int sum=0,temp,flag=1;
	char c=0;
	while(c!='#')
	{
		if(scanf("%d",&temp)==0)
		{
			scanf("%c",&c);
		}
		else
		{
			sum+=temp;
			flag=0;
		}
	}
	if(sum==0&&flag) printf("No numbers");
	else printf("%d",sum);
	return 0;
}