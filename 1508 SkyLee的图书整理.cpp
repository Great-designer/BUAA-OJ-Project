#include<stdio.h>

#include<map>

using namespace std;

int main()
{
    int n,t,x,i;
    while(~scanf("%d %d",&n,&t))
	{
        map<int,int> count;
        for(i=0;i<n;i++)
		{
            scanf("%d",&x);
            count[x]++;
        }
        for(i=0;i<t;i++)
		{
            scanf("%d",&x);
            printf("%d ",count[x]);
        }
        printf("\n");
    }
    return 0;
}
