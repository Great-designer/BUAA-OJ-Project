#include<stdio.h>
#include<stdlib.h>

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

struct node
{
	int num,x,y,id;
};

struct node c[1000010],f[1000010];

struct nnnn
{
	int x,y;
};

struct nnnn nf[6];

int n,m,q,cnt;
int v[1000010];

char cc(int nu,int pos)
{
	if((nu<1)||(nu>cnt)||(c[nu].x<1)||(c[nu].x>n)||(c[nu].y<1)||(c[nu].y>m)||(abs(c[nu].x-c[pos].x)+abs(c[nu].y-c[pos].y)!=1))
	{
		return 0;
	}
	return 1;
}

char check(int nu,int pos)
{
	if((nu<1)||(nu>cnt)||v[nu]||(c[nu].num!=c[pos].num))
	{
		return 0;
	}
	return cc(nu,pos);
}

int l,r,color;
int t[1000010];

void work(int nu)
{
	t[nu]=color;
	f[++r].x=c[nu].x;
	f[r].y=c[nu].y;
	f[r].id=nu;
	v[nu]=1;
}

int ret[1010],nc[1010],nd[1010],ne[1010],ccc[1010];
int ct[1000010],col[1000010];
char st[1000010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		cnt=0;
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%s",st+1);
			int j;
			for(j=1;j<=m;j++)
			{
				++cnt;
				c[cnt].num=(int)st[j]-48;
				c[cnt].x=i;
				c[cnt].y=j;
			}
		}
		color=0;
		for(i=1;i<=cnt;i++)
		{
			v[i]=0;
			t[i]=0;
		}
		for(i=1;i<=cnt;i++)
		{
			if(v[i]==0)
			{
				++color;
				t[i]=color;
				ct[color]=c[i].num;
				f[1].x=c[i].x;
				f[1].y=c[i].y;
				f[1].id=i;
				for(l=r=1;l<=r;++l)
				{
					int now=f[l].id;
					if(check(now-1,now))
					{
						work(now-1);
					}
					if(check(now+1,now))
					{
						work(now+1);
					}
					if(check(now-m,now))
					{
						work(now-m);
					}
					if(check(now+m,now))
					{
						work(now+m);
					}
				}
			}
		}
		int maxcol=0;
		for(i=1;i<=cnt;i++)
		{
			col[i]=0;
		}
		int ta=0;
		for(i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=m;j++)
			{
				++ta;
				++col[t[ta]];
				maxcol=(maxcol>t[ta]?maxcol:t[ta]);
			}
		}
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int df=0,np=(x-1)*m+y;
			if(cc(np-1,np))
			{
				ret[++df]=np-1;
			}
			if(cc(np+1,np))
			{
				ret[++df]=np+1;
			}
			if(cc(np-m,np))
			{
				ret[++df]=np-m;
			}
			if(cc(np+m,np))
			{
				ret[++df]=np+m;
			}
			for(i=1;i<=df;i++)
			{
				nc[i]=t[ret[i]];
			}
			qsort(nc+1,df,sizeof(int),compare);
			nd[1]=nc[1];
			int dx=1;
			for(i=2;i<=df;i++)
			{
				if(nc[i]!=nc[i-1])
				{
					nd[++dx]=nc[i];
				}
			}
			char fl=0;
			for(i=1;i<=dx;i++)
			{
				if(nd[i]==t[np])
				{
					fl=1;
					break;
				}
			}
			if(!fl)
			{
				for(i=1;i<=dx;i++)
				{
					ne[i]=ct[nd[i]];
				}
				for(i=0;i<=9;i++)
				{
					ccc[i]=0;
				}
				for(i=1;i<=dx;i++)
				{
					ccc[ne[i]]+=col[nd[i]];
				}
				int lk=0;
				for(i=0;i<=9;i++)
				{
					lk=(lk>ccc[i]?lk:ccc[i]);
				}
				printf("%d\n",lk+1);
			}
			else
			{
				int spj=0;
				for(i=1;i<=dx;i++)
				{
					if(nd[i]==t[np])
					{
						spj+=col[nd[i]];
					}
				}
				int dd=0;
				for(i=1;i<=dx;i++)
				{
					if(nd[i]!=t[np])
					{
						nf[++dd].x=ct[nd[i]];
						nf[dd].y=nd[i];
					}
				}
				for(i=0;i<=9;i++)
				{
					ccc[i]=0;
				}
				for(i=1;i<=dd;i++)
				{
					ccc[nf[i].x]+=col[nf[i].y];
				}
				int lk=0;
				for(i=0;i<=9;i++)
				{
					lk=(lk>ccc[i]?lk:ccc[i]);
				}
				printf("%d\n",(lk+1)>spj?(lk+1):spj);
			}
		}
	}
	return 0;
}

