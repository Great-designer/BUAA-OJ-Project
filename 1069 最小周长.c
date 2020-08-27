#include<stdio.h>
#include<math.h> 

int main()
{
	int s;
	scanf("%d",&s);
	int i=(int)sqrt((double)s);
	while(s%i!=0)
	{
		i--;
	}
	s/=i;
	printf("%d\n",2*(s+i));
}

