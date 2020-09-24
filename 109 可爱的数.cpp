#include<stdio.h>
#include<math.h>

#include<set>

using namespace std;

set<long long> res;

long long n;

int main()
{
    while(~scanf("%lld",&n))
	{
        res.clear();
        long long k=2;
        while(k<=(int)(sqrt(n)+1))
		{
            if(!(n%k))
			{
                n/=k;
                res.insert(k);
                continue;
            }
            k++;
        }
        res.insert(n);
        long long ans=1;
        set<long long>::iterator a;
        for(a=res.begin();a!=res.end();a++)
		{
            ans*=(*a);
        }
        printf("%lld\n",ans);
    }
}
