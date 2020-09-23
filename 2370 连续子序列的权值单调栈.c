#include<stdio.h>
#include<string.h>

int n;
int data[50005];
int ma[50005];
int mi[50005];
int topma;
int topmi;
int mal[50005],mar[50005],mil[50005],mir[50005];

int main()
{
	while(~scanf("%d",&n))
	{
		topma=0;
		topmi=0;
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&data[i]);
			while(topma!=0&&(data[ma[topma-1]]<=data[i]))
			{
				topma--;
			}
			while(topmi!=0&&(data[mi[topmi-1]]>=data[i]))
			{
				topmi--;
			}
			mal[i]=(topma!=0?(ma[topma-1]+1):1);
			mil[i]=(topmi!=0?(mi[topmi-1]+1):1);
			ma[topma]=i;
			topma++;
			mi[topmi]=i;
			topmi++;
		}
		topma=0;
		topmi=0;
		for(i=n;i>=1;i--)
		{
			while(topma!=0&&(data[ma[topma-1]]<data[i]))
			{
				topma--;
			}
			while(topmi!=0&&(data[mi[topmi-1]]>data[i]))
			{
				topmi--;
			}
			mar[i]=(topma!=0?(ma[topma-1]-1):n);
			mir[i]=(topmi!=0?(mi[topmi-1]-1):n);
			ma[topma]=i;
			topma++;
			mi[topmi]=i;
			topmi++;
		}
		long long ans1=0;
		long long ans2=0;
		for(i=1;i<=n;i++)
		{
			ans1+=(long long)data[i]*(i-mal[i]+1)*(mar[i]-i+1);
			ans2+=(long long)data[i]*(i-mil[i]+1)*(mir[i]-i+1);
		}
		printf("%lld\n",(ans1-ans2));
	}
	return 0;
}
