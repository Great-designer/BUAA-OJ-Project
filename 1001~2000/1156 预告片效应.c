#include<stdio.h>

int main()
{
	int a1,b1,c1,d1,a2,b2,c2,d2,count=0;
	scanf("%d:%d%d:%d%d:%d%d:%d,", &a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
	if(a2+40>60)  //考虑加上 40 分钟后可能小时需要加一
	{
		a1++;
		a2-=20;
	}
	else
	{
		a2+=40;
	}
	if(a1<b1) //针对小时进行大小判断
		printf("%d:%d\n",b1,b2);
	else if(a1==b1)  //若相等再判断分钟的大小关系
	{
		if(a2<=b2)
			printf("%d:%d\n",b1,b2);
		else
			count++;
	}
	else
		count++;
	if(a1<c1)
		printf("%d:%d\n",c1,c2);
	else if(a1==c1)
	{
		if(a2<=c2)
			printf("%d:%d\n",c1,c2);
		else
			count++;
	}
	else
		count++;
	if(a1<d1)
		printf("%d:%d\n",d1,d2);
	else if(a1==d1)
	{
		if(a2<=d2)
			printf("%d:%d\n",d1,d2);
		else
			count++;
	}
	else
		count++;
	if(count==3) //如果 count 为三，意味着三场都无法赶上
		printf("NO!");
}