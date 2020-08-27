#include<stdio.h>

void PRT(const int a)
{
	if(a>=10)
	{
		PRT(a/10);
	}
	putchar(a%10+48);
}

int n, m;
int stack[10], top;
char used[10]; 
void generPermutation()
{
	if(top == m)
	{		
		int i;
		for(i=0; i<top; i++)
		{
			PRT(stack[i]), putchar(32);
		}		
		putchar(10);		
		return;	
	} 	
	int i;
	for(i=1; i<=n; i++)
	{		
		if (!used[i])		
		{			
			used[i] = 1;			
			stack[top++] = i;			
			generPermutation();	
			--top;			
			used[i] = 0;	
		}	
	}
}
int main()
{	
	scanf("%d%d",&n,&m);
	generPermutation();
}

