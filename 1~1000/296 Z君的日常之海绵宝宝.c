#include<stdio.h>

long long time[2000010];
long long width[2000010];
long long length[2000010];

long long widthstack[2000010];
long long widthtop;
long long lengthstack[2000010];
long long lengthtop;

int counter;
int result;
long long input;

void init()
{
	int i;
	for(i=1;i<2000010;++i)
	{
		time[i]=(long long)i*(long long)(i+(long long)1);
	}
}

int main()
{
	init();
	scanf("%lld",&input);
	input*=6;
	long long temp;
	long long i;
	for(i=1;i<2000010;++i)
	{
		temp=input;
		if(temp%time[i]!=0)
		{
			continue;
		}
		temp/=time[i];
		temp+=(i-1);
		if(temp%3)
		{
			continue;
		}
		temp/=3;
		if(i>temp)
		{
			continue;
		}
		if(i==temp)
		{
			++result;
			width[counter]=i;
			length[counter++]=temp;
		}
		else
		{
			++result;
			++result;
			width[counter]=i;
			length[counter++]=temp;
			widthstack[widthtop]=temp;
			widthtop++;
			lengthstack[lengthtop]=i;
			lengthtop++;
		}
	}
	printf("%d\n",result);
	for(i=0;i<counter;++i)
	{
		printf("%lld %lld\n",width[i],length[i]);
	}
	while(widthtop!=0)
	{
		printf("%lld %lld\n",widthstack[widthtop-1],lengthstack[lengthtop-1]);
		widthtop--;
		lengthtop--;
	}
}
