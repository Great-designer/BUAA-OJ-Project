#include<stdio.h>

int n;
char stack[132],top;
 
void generBrackets(int nfront, int nback)
{
	if(top==2*n)
	{
		int i;
		for(i=0;i<top;i++)
		{
			putchar(stack[i]);
		}		
		putchar(10);		
		return;
	} 	
	if(nfront<n)
	{		
		stack[top++]='(';		
		generBrackets(nfront+1,nback);
		--top;
	}
	if(nback<n&&nback<nfront)
	{
		stack[top++]=')';		
		generBrackets(nfront,nback+1);		
		--top;
	}
}

int main()
{	
	while(~scanf("%d",&n))
	{
		top=0;		
		generBrackets(0,0);		
		puts("");
	}
}

