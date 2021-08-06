#include<stdio.h>

int fix[300010];/*序号*/
int n;
int fa[300010];/*父节点*/
int dep[300010];/*深度*/
int a[300010];/*内容。本题的内容恰好是1到n，可以按这个顺序*/
long long ans;

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++) /*读入序号与内容*/
	{
		scanf("%d",&a[i]);
		fix[a[i]]=i;
	}
	for(i=1; i<=n; i++) /*建树，重点！*/
	{
		int last=0,f=i-1;/*父节点一定在前面，从i-1倒着找；从0顺着找子节点*/
		while(fix[f]>fix[i])/*较小数的序号靠后时*/
		{
			last=f;
			f=fa[f];
		}
		fa[i]=f;
		fa[last]=i;
	}
	dep[0]=-1;
	for(i=1; i<=n; i++) /*计算深度和*/
	{
		dep[a[i]]=dep[fa[a[i]]]+1;
		ans+=dep[a[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
