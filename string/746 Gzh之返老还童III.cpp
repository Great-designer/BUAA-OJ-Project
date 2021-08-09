#include<stdio.h>
#include<string.h>
#include<string>

using namespace std; 

struct SAMNode
{
	struct SAMNode *fa,*next[130];
	int len;
	int id,pos;
};

struct SAMNode pool[500020],*root,*last;
int Size;

struct SAMNode *nnode(int len)
{
	pool[Size].fa=0;
	pool[Size].len=len;
	memset(pool[Size].next,0,sizeof(pool[Size].next));
	pool[Size].id=Size;
	return &pool[Size++];
}

struct SAMNode *nnode(struct SAMNode *p)
{
	pool[Size]=*p;
	pool[Size].id=Size;
	return &pool[Size++];
}

void SAMinit()
{
	Size=0;
	root=last=nnode(0);
	pool[0].pos=0;
}

void add(int x,int len)
{
	struct SAMNode *p=last,*np=nnode(p->len+1);
	np->pos=len;
	last=np;
	for(;p&&!p->next[x];p=p->fa)
	{
		p->next[x]=np;
	}
	if(!p)
	{
		np->fa=root;
		return;
	}
	struct SAMNode *q=p->next[x];
	if(q->len==p->len+1)
	{
		np->fa=q;
		return;
	}
	struct SAMNode *nq=nnode(q);
	nq->len=p->len+1;
	q->fa=nq;
	np->fa=nq;
	for(;p&&p->next[x]==q;p=p->fa)
	{
		p->next[x]=nq;
	}
}

void SAMbuild(char *s)
{
	SAMinit();
	int len=strlen(s);
	int i; 
	for(i=0;i<len;i++)
	{
		add(s[i],i+1);
	}
}

char str1[250010],str2[250010],str3[250010];

int main()
{
	int t=100;
	while(t--)
	{
		scanf("%s%s%s",str1,str2,str3);
		string a=str1,b=str2,c=str3;
		int pos;
		while((pos=a.find(c))!=a.npos)
		{
			a.replace(pos,c.size(),"");
		}
		while((pos=b.find(c))!=b.npos)
		{
			b.replace(pos,c.size(),"");
		}
		strcpy(str1,a.c_str()),strcpy(str2,b.c_str());
		SAMbuild(str1);
		int len=strlen(str2);
		struct SAMNode *tmp=root;
		int ans=0;
		int t=0;
		int i;
		for(i=0;i<len;i++)
		{
			if(tmp->next[str2[i]])
			{
				tmp=tmp->next[str2[i]];
				t++;
			}
			else
			{
				while(tmp&&!tmp->next[str2[i]])
				{
					tmp=tmp->fa;
				}
				if(tmp==NULL)
				{
					tmp=root;
					t=0;
				}
				else
				{
					t=tmp->len+1;
					tmp=tmp->next[str2[i]];
				}
			}
			ans=(ans>t)?ans:t;
		}
		printf("%d\n",ans);
	}
	return 0;
}

