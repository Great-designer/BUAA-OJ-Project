#include<stdio.h>
  
int fix[300010];/*���*/
int n;
int fa[300010];/*���ڵ�*/ 
int dep[300010];/*���*/ 
int a[300010];/*���ݡ����������ǡ����1��n�����԰����˳��*/
long long ans;

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)/*�������������*/
	{
		scanf("%d",&a[i]);
		fix[a[i]]=i;
	}
	for(i=1;i<=n;i++)/*�������ص㣡*/
	{
		int last=0,f=i-1;/*���ڵ�һ����ǰ�棬��i-1�����ң���0˳�����ӽڵ�*/
		while(fix[f]>fix[i])/*��С������ſ���ʱ*/
		{
			last=f;
			f=fa[f];
		}
		fa[i]=f;
		fa[last]=i;
	}
	dep[0]=-1;
	for(i=1;i<=n;i++)/*������Ⱥ�*/
	{
		dep[a[i]]=dep[fa[a[i]]]+1;
		ans+=dep[a[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
