#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct hash
{
    char *s;
    int next;
};

struct HashList
{
	struct hash list[30010];
    int head[23333],cnt;
};

void init(struct HashList *a)
{
    memset(a->head,0,sizeof(a->head));
    a->cnt=0;
}

int hashcode(char *s)
{
    int len=strlen(s);
    long long ret=strlen(s);
    int i;
    for(i=0;i<len;++i)
    {
    	ret=(ret*761153+1LL*s[i])%23333;
	}
    return ret;
}

void add(struct HashList *a,char *s,int code)
{
    a->list[++a->cnt].s=s;
    a->list[a->cnt].next=a->head[code];
    a->head[code]=a->cnt;
}

char find(struct HashList *a,char *s,int code)
{
	int i;
    for(i=a->head[code];i;i=a->list[i].next)
	{
        if(!strcmp(a->list[i].s,s))
		{
			return 1;
		}
    }
    return 0;
}

struct HashList hashlist;

int t;
char s[30010];
int len;
char *str[30010];
int size;
char flag;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s);
		init(&hashlist);
		size=0;
		flag=1;
		int i;
		for(i=0;i<len;++i)
		{
		    if(isalpha(s[i])&&flag)
			{
				str[++size]=&s[i];
				flag=0;
			}
		    else if(!isalpha(s[i]))
			{
				s[i]='\0';
				flag=1;
			}
		}
		flag=1;
		for(i=1;i<=size&&flag;++i)
		{
		    int code=hashcode(str[i]);
		    if(!find(&hashlist,str[i],code))
			{
				add(&hashlist,str[i],code);
			}
		    else
			{
				flag=0;
			}
		}
		puts(flag?"NO":"YES");
	}
}
