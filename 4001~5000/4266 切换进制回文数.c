#include<stdio.h>
int main()
{
	int q,m,i,j,x,judge,k;
	char c[]="0123456789ABCDEFGHIJ";
	char a[103];
	scanf("%d",&q);
	while(scanf("%d",&m)!=EOF)
	{
		i=0;
		judge=1;
		while (m>0)
		{
			x=m%q;
			a[i]=c[x];
			m=m/q;
			i++;
		}//进制转换
		j=0;
		for(k=i-1; j<k; k--)
		{
			if(a[j]!=a[k])
				judge=0;
			j++;
		}//回文数判断
		if (judge)
		{
			for (i--; i>=0; i--)
				printf("%c",a[i]);
			printf("\n");
		}
	}
	return 0;
}