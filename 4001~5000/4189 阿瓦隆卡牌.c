#include<stdio.h>

int main()
{
	char a[6];
	scanf("%c %c %c %c %c %c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
	int count=0;
	int i;
	for(i=0;i<5;i++)
	{
		if(a[i]=='W')
		{
			count++;
		}
	}
	printf("%d\n",count);
	if(count>=3&&a[5]=='H')
	{
		printf("King Arthur Win\n");
	}
	else
	{
		printf("Medrawt Win\n");
	}
}