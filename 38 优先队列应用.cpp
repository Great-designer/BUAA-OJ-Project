#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        priority_queue<int> q;
        int i;
        for(i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            q.push(-tmp);
        }
        int res=0;
        while(q.size()>1)
        {
            int merge=q.top();
            q.pop();
            merge+=q.top();
            q.pop();
            res+=merge;
            q.push(merge);
        }
        printf("%d\n",-res);
    }
}
