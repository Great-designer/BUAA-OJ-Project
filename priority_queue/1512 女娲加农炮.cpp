#include<stdio.h>

#include<queue>

using namespace std;

priority_queue<int> q;

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
        while(!q.empty())
		{
			q.pop();
		}
		int num;
		int i;
        for(i=1;i<=n;i++)
		{
            scanf("%d",&num);
            q.push(-num);
        }
        long long ans=0;
		int x,y;
        for(i=1;i<n;i++)
		{
            x=q.top();
			q.pop();
            y=q.top();
			q.pop();
            ans+=x+y;
            q.push(x+y);
        }
        printf("%lld\n",-ans);
    }
    return 0;
}
