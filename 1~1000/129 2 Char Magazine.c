#include<stdio.h>
#include<string.h>
#include<math.h>

char s[101][1010]; 

int main()
{
	int n,i,j,k,l,count,p,max;
	while(~scanf("%d",&n))
	{
		max=0;
		for(i=0;i<n;i++)    
		{		
			scanf("%s",s[i]);	
		}	
		for(k='a';k<='z';k++)    
		{        
			for(l=k;l<='z';l++)        
			{			
				count=0;            
				for(i=0;i<n;i++)            
				{                
					p=strlen(s[i]);                
					for(j=0;j<p;j++)                
					{                    
						if(s[i][j]!=k&&s[i][j]!=l)					
						{						
							break;					
						}                
					}                
					if(j==p)				
					{					
						count+=p;				
					}            
				}            
				if(count>max) 			
				{				
					max=count;			
				}        
			}    
		}    
		printf("%d\n",max);    
	}
	return 0;
}

