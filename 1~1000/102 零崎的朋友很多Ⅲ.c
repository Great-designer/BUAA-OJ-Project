#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int m[330][330];
int rightKey[330][330];
int p[330];
int n;

void printAnswer(int i,int j)
{    
	if(i==j)
	{
	    printf("A%d",i);
	}
	else
	{
		printf("(");        
		printAnswer(i,rightKey[i][j]);        
		printAnswer(rightKey[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	while(scanf("%d",&n)==1)    
	{
		int i;
		for(i=0;i<=n;i++)
		{
			scanf("%d",&p[i]);        
		}
		for(i=0;i<=n;i++)
		{
			m[i][i]=0;
		}
		int len;
		for(len=2;len<=n;len++)
		{
			for(i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;                
				m[i][j]=0x3f3f3f3f;
				int k;
				for(k=i;k<j;k++)
				{         
					int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					if(m[i][j]>=temp)
					{               
						m[i][j]=temp;                        
						rightKey[i][j]=k;
					}
				}
			}
		}     
		printAnswer(1,n);
		printf("\n");   
	} 
	return 0;
}

