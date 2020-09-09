#include<stdio.h>
#include<math.h>
   
double phi1=(1+sqrt(5))/2;
double phi2=(-1+sqrt(5))/2;

int main()   
{   
    int x,y;   
    while(~scanf("%d%d",&x,&y))
    {
    	if(x==y)
    	{
    		printf("Nova\n");
    		continue;
		}
    	int a=x*phi1;
    	int b=x*phi2;
    	if(y<=a&&y>b)
    	{
    		printf("LaoWang\n");
    		continue;
		}
    	printf("Nova\n");   
	}
}
