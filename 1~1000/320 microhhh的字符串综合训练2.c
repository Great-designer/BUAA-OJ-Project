#include<stdio.h>
#include<string.h>

void getNext(int next[],char str[])
{
	int t=next[0]=-1;
	int len=strlen(str);
	int j=0;
	while(j<len-1)
	{
		if(t<0||str[j]==str[t])
		{
			next[++j]=++t;
		} 
		else
		{
			t=next[t];
		} 
	}
}

char a[1010],b[10010];
char sub[1010];
int next[1010];
char match;

int t;
int lena,lenb;

int main()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		match=1;
		memset(sub,0,sizeof(sub));
		memset(next,0,sizeof(next));
		scanf("%[^\n\r]",a);
		getchar();
		scanf("%[^\n\r]",b);
		getchar();
		lenb=strlen(b);
		int i=0,j=0,k=0;
		while(a[k])
		{
			if(a[k]!='*')
			{
				sub[i++]=a[k++];
			}
			if(a[k]=='*'||a[k]=='\0')
			{
				if(a[k]!='\0')
				{
					k++;
				}
				if(i)
				{
					while(a[k]=='*')
					{
						k++;
					}
					int s=0;
					i=0;
					lena=strlen(sub);
					getNext(next,sub);
					while(j<lenb&&s<lena)
					{
						if(s==-1||sub[s]==b[j])
						{
							++j;
							++s;
						}
						else
						{
							s=next[s];
						}
					}
					if(s!=lena)
					{
						match=0;
						break;
					}
					memset(sub,0,sizeof(sub));
					memset(next,0,sizeof(next));
				}
			}
		}
		if(match)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
}
