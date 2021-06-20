#include<stdio.h>

int type(int m)
{
	if(m%4!=0||(m%100==0&&m%400!=0))
	{
		return 0;
	} 
	else
	{
		return 1;
	} 
}

char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int year[2]={365,366};
int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int days,dayofweek;
	int i=0,j=0;	
	while(~scanf("%d",&days))
	{        
		dayofweek=days%7;	    
		for(i=2000;days>=year[type(i)];i++)
		{ 
			days-=year[type(i)];
		} 
		for(j=0;days>=month[type(i)][j];j++)
		{ 
			days-=month[type(i)][j];
		} 
		printf("%d-%02d-%02d %s\n",i,j+1,days+1,week[dayofweek]);
	}
}


