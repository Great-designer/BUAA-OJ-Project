#include<stdio.h>
#include<string.h>

int a[111],b[111],en1,en2;
char s[111],t[111];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
		en1=0;
		en2=0;
		scanf("%s%s",s+1,t+1);
	    while(s[en1+1]>='0'&&s[en1+1]<='9')
	    {
	        en1++;
	    }
	    while(t[en2+1]>='0'&&t[en2+1]<='9')
	    {
	        en2++;
	    }
	    int i;
	    for(i=1;i<=en1;i++)
	    {
	        a[en1-i+1]=s[i]-'0';
	    }
	    for(i=1;i<=en2;i++)
	    {
	        b[en2-i+1]=t[i]-'0';
	    }
	    int ex=0;
	    for(i=1;i<=en1;i++)
	    {
	        a[i]-=b[i]+ex;
	        if(a[i]<0)
	        {
	            ex=1;
	            a[i]+=10;
	        }
	        else
	        {
	            ex=0;
	        }
	    }
	    while(a[en1]==0&&en1)
	    {
	        en1--;
	    }
	    if(!en1)
	    {
	        en1++;
	    }
	    for(i=en1;i>=1;i--)
	    {
	        printf("%d",a[i]);
	    }
	    printf("\n");
	}
}
