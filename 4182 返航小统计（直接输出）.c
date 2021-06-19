#include<stdio.h>

int main()
{
	int date;
	scanf("%d",&date);
	int n;
	scanf("%d",&n);
	int num=0;
	int i;
	for(i=0;i<n;i++)
	{
		int id,day,hour,min;
		scanf("%d%d%d:%d",&id,&day,&hour,&min);
		if(day==date)
		{
			printf("%08d %02d:%02d\n",id,hour,min);
			num++;
		}
	}
	printf("%d\n",num);
}