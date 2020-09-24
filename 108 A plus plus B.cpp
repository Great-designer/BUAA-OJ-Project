#include<stdio.h>

#include<algorithm>
#include<set>

using namespace std;

char tmp[3];
char op;
int t,n,m;
int tmpint;

int main()
{
    while(~scanf("%d%d",&n,&m))
	{
        set<int> a,b;
        int i;
        for(i=0;i<n;++i)
		{
            scanf("%d",&tmpint);
            a.insert(tmpint);
        }
        for(i=0;i<m;++i)
		{
            scanf("%d",&tmpint);
            b.insert(tmpint);
        }
        set<int> c;
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
        printf("%.2lf%%\n",c.size()*200.0/(n+m));
    }
}
