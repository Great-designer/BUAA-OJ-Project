#include<stdio.h>
#include<map>

using namespace std;

map<int,bool> m;

int main()
{
    int n,x,y,z;
    while(~scanf("%d",&n))
	{
        m.clear();
        int i;
        for(i=0;i<n;i++)
		{
            scanf("%d%d%d",&x,&y,&z);
            m[((((x+50)<<7)+y+50)<<7)+z+50]=1;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
		{
            scanf("%d%d%d",&x,&y,&z);
            printf(m[((((x+50)<<7)+y+50)<<7)+z+50]?"YES\n":"NO\n");
        }
    }
}

