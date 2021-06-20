#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

void write(long long x)
{
    if(x<0)
	{
		putchar('-');
		x=-x;
	}
    if(x>9)
	{
		write(x/10);
	}
    putchar(x%10+48);
}

int cnt;

long long read()
{
    long long k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        if(c=='-')
		{
			f=-1;
		}
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        k=(k<<1)+(k<<3)+c-48;
        c=getchar();
    }
    return k*f;
}

vector<long long> a[100050],b[100050];

long long c[100050];
int id[100050];

bool cmp(long long a,long long b)
{
	return a>b;
}

bool cmpDeck(int x,int y)
{
	return b[x][0]>b[y][0];
}

long long t,k,n,Size;
long long x,y;

struct Sum
{
    long long sum;
    int amark,bmark;
    Sum(long long s=0,int a=0,int b=0)
	{
		sum=s,amark=a,bmark=b;
	}
    bool operator < (const Sum &o) const
	{
        return sum < o.sum;
    }
};

priority_queue<Sum>q;

int main()
{
    t=read();
    while(t--)
	{
        while(!q.empty())
		{
			q.pop();
		}
        x=y=cnt=0;
        memset(id,0,sizeof(id));
        k=read(),n=read();
        int i;
        for(i=0;i<=k;++i)
        {
        	a[i].clear(),b[i].clear();
		}
        for(i=1;i<=k;++i)
		{
            c[++cnt]=read();
            if(c[cnt]==1)
			{
                x=read(),y+=x,--cnt;
                continue;
            }
            b[cnt].resize(c[cnt]);
            int j;
            for(j=0;j<c[cnt];++j)
            {
            	b[cnt][j]=read();
			}
            sort(b[cnt].begin(),b[cnt].end(),cmp);
            y+=b[cnt][0];
            for(j=1;j<c[cnt];++j)
            {
            	b[cnt][j-1]=b[cnt][j]-b[cnt][j-1];
			}
            b[cnt].pop_back();
            id[cnt]=cnt;
        }
        if(cnt==0)
		{
			write(y),putchar('\n');
			continue;
		}
        sort(id+1,id+cnt+1,cmpDeck);
        for(i=1;i<=cnt;++i)
        {
        	c[i]=(a[i]=b[id[i]]).size();
		}
        write(y),putchar(' ');
        y+=a[1][0];
        q.push(Sum(y,1,0));
        for(i=1;i<n&&!q.empty();++i)
		{
            Sum big=q.top();
            q.pop();
            write(big.sum),putchar(' ');
            if(big.bmark<c[big.amark]-1)
            {
            	q.push(Sum(big.sum+a[big.amark][big.bmark+1],big.amark,big.bmark+1));
			}
            if(big.amark<cnt)
			{
                q.push(Sum(big.sum+a[big.amark+1][0],big.amark+1,0));
                if(!big.bmark)
                {
                	q.push(Sum(big.sum-a[big.amark][0]+a[big.amark+1][0],big.amark+1,0));
				}
            }
        }
        putchar('\n');
    }
}
