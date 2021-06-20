#include<stdio.h>
#include<string.h>

char old[1000000],neww[100000];
int point;

int main(void)
{
	scanf("%s",old);
	while(scanf("%s",neww)!=EOF)
	{
		scanf("%d",&point);
		strcpy(old+point,neww);
	}
	puts(old);
	return 0;
}