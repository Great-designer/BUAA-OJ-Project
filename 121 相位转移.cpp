#include<stdio.h>
#include<limits.h>
#include<string.h>

#include<algorithm>

using namespace std;

int lo,hi,mi;

void write(int x)
{
    if(x>9)
	{
		write(x/10);
	}
    putchar(x%10+48);
}

int read()
{
    int k=0;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        k=(k<<1)+(k<<3)+c-48;
        c=getchar();
    }
    return k;
}

int x,m,t;
int a[100010];
int s[100010];
int pre,now;

void printAS()
{
    puts("a is ");
    int i;
    for(i=1;i<=m;++i)
	{
		printf("%d ",a[i]);
	}
    puts("");
    for(i=1;i<=m;++i)
	{
		printf("%d ",s[i]);
	}
    puts("");
}

int main()
{
    while(~scanf("%d%d%d",&x,&m,&t))
	{
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        pre=0;
        lo=hi=x;
        int i;
        for(i=1;i<=m;++i)
		{
            s[i]=read();
        }
        s[++m]=x;
        sort(s+1,s+m+1);
        for(i=1;i<=m;++i)
		{
            a[i]=s[i]-s[i-1];
            if(a[i]<lo)
			{
				lo=a[i];
			}
        }
        if(t==m-1)
		{
			write(x);
			putchar('\n');
			continue;
		}
        else if(t==0)
		{
			write(lo);
			putchar('\n');
			continue;
		}
        while(lo<=hi)
		{
            mi=(lo+hi)>>1;
            int needK=0;
            int cur=1;
            while(cur<=m)
			{
                if(cur==m)
				{
                    if(a[cur]<mi)
					{
						needK+=1;
					}
                    break;
                }
                else if(a[cur]<mi)
				{
                    int *pos=lower_bound(s+cur+1,s+m+1,s[cur]+mi-a[cur]);
                    needK+=pos-s-cur;
                    cur=pos-s+1;
                }
                else
				{
                    cur++;
                }
            }
            if(needK>t)
			{
                hi=mi-1;
            }
            else
			{
                lo=mi+1;
            }
        }
        write(lo-1);
		putchar('\n');
    }
}
