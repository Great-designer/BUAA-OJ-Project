#include<stdio.h>
#include<string.h> 
#include<queue> 

using namespace std;

char c[10010];
long long f[10010];

priority_queue<long long> q;

long long n,ans;
char s[2020];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
    	int sum=0;
		scanf("%s",s);
        getchar();
        memset(f,0,sizeof(f));
        int lens=strlen(s);
        int i;
        for(i=1;i<=lens;i++)
        {
            c[i]=s[i-1];
            f[c[i]]++;
        }
        while(!q.empty())
        {
        	q.pop();
		}
        for(i=65;i<=122;i++)
        {
            if(f[i]>0)
            {
                sum++;
                q.push(-f[i]);
            }
        }
        ans=0;
        while(q.size()>1)
        {
            long long a=q.top();
            q.pop();
            long long b=q.top();
            q.pop();
            ans-=(a+b);
            q.push(a+b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
