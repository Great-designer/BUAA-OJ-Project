#include<stdio.h>
#include<string.h>

int pd[50005][2];/*����Ȼ��n�ֲ�Ϊk�����ֵĻ��췽����*/

int main()
{
	int n;
    while(~scanf("%d",&n))
    {
        memset(pd,0,sizeof(pd));
        pd[0][0]=1;
        int ans=0;
        int j;
        for(j=1;j<350;++j)
		{
			int i;
            for(i=0;i<350;++i)
			{
                pd[i][j&1]=0;/*pd[i][j]ֻ��pd[][j]��pd[][j-1]�й�*/
			}
            for(i=0;i<=n;++i)
			{
                if(i-j>=0)/*pd[i-j][j]���в��ִ���1*/
                {
                	pd[i][j&1]=(pd[i-j][j&1]+pd[i-j][(j-1)&1])%1000007;/*pd[i-j][j-1]������һ������Ϊ1��*/
				}
            }
            ans=(ans+pd[n][j&1])%1000007;
        }
        printf("%d\n",ans);
    }
}


