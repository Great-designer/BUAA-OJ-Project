#include<stdio.h>

#include<queue>
 
using namespace std;

int res[200010];
int d[200010];
int g[200010][100];
int top[200010];

priority_queue<int> q;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    int i;
    for(i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        g[b][top[b]]=a;
		top[b]++;
        d[a]++;
    }
    for(i=1;i<=n;++i)
    {
        if(d[i]==0)
        {
        	q.push(i);
		}
    }
    int cnt=0;
    while(!q.empty())
    {
        int cur=q.top();
		q.pop();
        res[++cnt]=cur;
        for(i=0;i<top[cur];i++)
        {
            if(!--d[g[cur][i]])
            {
                q.push(g[cur][i]);
            }
        }
    }
    for(i=n;i>0;--i)
    {
        printf("%d ",res[i]);
    }
}
