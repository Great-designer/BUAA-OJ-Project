#include<stdio.h>
 
int m[550],c[550],w[550],f[2][30005],q[500005];
 
int main()
{
	int n,v;
	while(~scanf("%d%d",&n,&v))/*��N����Ʒ��һ������ΪV�ı���*/
	{
		int i; 
		for(i=1;i<=n;i++)/*��i����Ʒÿ��������c[i]����ֵ��w[i]�������m[i]������*/
		{
		    scanf("%d%d%d",&c[i],&w[i],&m[i]);
		}
		memset(f,0,sizeof(f));
		memset(q,0,sizeof(q));
		for(i=1;i<=n;i++)/*��ѧ���ɷ�����c[i]��f[now][v]��ʾǰi����Ʒǡ����һ������Ϊv�ı���������ֵ*/
		{
		    int now=i%2,last;/*c[i-1]������last��*/
		    last=now^1;
		    int j;
		    for(j=0;j<c[i];j++)/*j�������Ϊ������k*c[i]+j��������ÿ�δ�С�������c[i-1]���ݲ�����*/
			{
				//f[now][k*c[i]+j]
				//=max{f[last][j]+k*w[i]|0<=k<=m[i]}
				//=max(f[last][k*c[i]+j],f[last][j]+k*w[i])
				//=max(f[last][k*c[i]+j],f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i])
		        int Rear=1,Front=1;
		        q[1]=0;
		        int k;
		        for(k=0;k*c[i]+j<=v;k++)/*ȡ��������f[last][j]+k*w[i]ʱ��������ȡk��û��������*/
				{
		            while(Front!=Rear&&k-q[Front]>m[i])/*ά��һ���������У������д����k��ʹ����Ϊ���ֵ��ÿ�ΰѳ���m[i]����ɾȥ*/
					{
						Front++;
					}
		            f[now][k*c[i]+j]=(f[last][k*c[i]+j]>(f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i])?f[last][k*c[i]+j]:(f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i]));
		            while(Front<=Rear&&f[last][q[Rear]*c[i]+j]+w[i]*(k-q[Rear])<=f[last][k*c[i]+j])/*�Ѷ�βС��ö�ٵ�f[last][j]+k*w[i]ɾȥ*/
					{
						Rear--;
					}
		            q[++Rear]=k;/*��¼��ǰȡ�˶��ٸ�����Ʒ*/
		        }
		    }
		}
		printf("%d\n",f[n%2][v]);
	}
	return 0;
}
