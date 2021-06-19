#include<stdio.h>
#include<string.h>
int toShi(int n,char a[])
{	
	int len = strlen(a);	
	int i,ans=0;	
	for(i=0;i<len;i++)
	{		
		if(a[i]>='0'&&a[i]<='9')
		{			
			ans=ans*n+a[i]-'0';		
		}		
		else
		{			
			ans = ans*n+a[i]-'A'+10;		
		}
	}		
	return ans;
}
void toB(int ans,int b)
{	
	char arr[100];	
	int i,j=0,tmp;	
	while(ans!=0)
	{		
		tmp = ans%b;		
		if(tmp>=10)
		{
			arr[j++] = tmp-10+'A';		
		}
		else
		{			
			arr[j++] = tmp+'0';		
		}		
		ans = ans/b;	
	}	
	for(i=j-1;i>=0;i--)
	{		
		printf("%c",arr[i]);	
	}
}
int main()
{	
	char a[100];	
	int n,b;
	int tmp1;	
	scanf("%d%d%s",&n,&b,a);
	tmp1=toShi(n,a);
	toB(tmp1,b);
	return 0;
}

