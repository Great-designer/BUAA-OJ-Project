#include<stdio.h>
#include<string.h>

int c[550];/*��i����Ʒ��ռ�ÿռ���c[i]����ֵ��w[i]��*/ 
int w[550];
int f[30300];

int main()
{
	int n,v;/*��N����Ʒ��һ������ΪV�ı�����ÿ����Ʒ��ѡ���޼�����⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ����*/ 
	while(~scanf("%d%d",&n,&v))
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&c[i],&w[i]);
		}
		memset(f,0,sizeof(f)); 
		for(i=1;i<=n;i++)/*��ѧ���ɷ���ȡ���ټ�c[i]*/
		{
			int j;
			for(j=c[i];j<=v;j++)/*ÿ�δ�С�������c[i]���ݲ����£���Ҫһ��������ѡ���i����Ʒ���ӽ��f[j-c[i]]*/
			{
				f[j]=(f[j]>(f[j-c[i]]+w[i])?f[j]:(f[j-c[i]]+w[i]));/*ǰi����Ʒǡ����һ������Ϊj�ı������Ի�õ�����ֵ*/
			}
		}
		printf("%d\n",f[v]);
	}
}
