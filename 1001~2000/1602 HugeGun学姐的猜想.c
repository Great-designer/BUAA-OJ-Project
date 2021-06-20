#include<stdio.h> 

int n,a[11],bo,i,sum; 

int main() 
{  
	scanf("%d",&n);  
	for(i=1;i<=n;i++)
	{ 
		scanf("%d",&a[i]);
	}  
	while(1)  
	{   
		bo=1;   
		for(i=1;i<=n;i++)
		{
			if(a[i]%2==0)
			{
				bo=0;
			}
		}   
		for(i=1;i<=n;i++)
		{
			if(!bo)
			{
				a[i]=(a[i]+1)/2;
			}
			else 
			{
				a[i]=3*a[i]+1;
			}
		}      
		sum++;   
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}   
		puts("");   
		bo=1;   
		for(i=1;i<=n;i++)
		{
			if(a[i]!=1)
			{
				bo=0;
			}
		}   
		if(bo||sum==66666)
		{
			break;
		}  
	}
}
