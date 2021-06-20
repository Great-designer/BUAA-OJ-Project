#include<stdio.h>

long long ans[30];

void init()
{
	ans[0]=1;
	ans[1]=2;
	ans[2]=4;
	ans[3]=11;
	ans[4]=31;
	ans[5]=83;
	ans[6]=227;
	ans[7]=616;
	ans[8]=1674;
	ans[9]=4550;
	ans[10]=12367;
	ans[11]=33617;
	ans[12]=91380;
	ans[13]=248397;
	ans[14]=675214;
	ans[15]=1835421;
	ans[16]=4989191;
	ans[17]=13562027;
	ans[18]=36865412;
	ans[19]=100210581;
	ans[20]=272400600;
	ans[21]=740461601;
	ans[22]=2012783315;
	ans[23]=5471312310;
}

int main()
{
	init();
	int q;
	while(~scanf("%d",&q))
	{
		while(q--)
		{
			int k;
			scanf("%d",&k);
			printf("%lld\n",ans[k]);
		}
	}
}