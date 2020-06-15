#include<stdio.h>
#include<string.h>

void PRT(const int a)
{
	if(a>=10)
	{
		PRT(a/10);
	}
	putchar(a%10+48);
} 

int n;
int stack[1234],top;
char used[1234]; 
void generPermutation()
{	
	if(top==n)
	{		
		int i;
		for(i=0;i<top;i++)			
		{
			PRT(stack[i]);
		}		
		putchar(10);		
		return;	
	} 	
	int i;
	for(i=1;i<=n;++i)
	{		
		if(!used[i])		
		{			
			used[i]=1;			
			stack[top++]=i;			
			generPermutation();				
			--top;			 			
			used[i]=0;	 		
		}	
	}
} 

int main()
{	
	while(~scanf("%d",&n))	
	{		
		generPermutation();		
		putchar(10);	
	}
}

