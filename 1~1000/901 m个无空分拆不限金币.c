#include<stdio.h>
#include<string.h>

int p[10005][1005];/*����Ȼ��n�ֲ�Ϊk�����ֵķ�����*/ 

int main()
{
	int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        memset(p,0,sizeof(p));
        p[0][0]=1;
        int i;
        for(i=1;i<=n;++i)
		{
			int j;
            for(j=1;j<=k;++j)
			{
                if(i-j>=0)/*p[i-j][j]���в��ִ���1*/
                {
                	p[i][j]=(p[i-j][j]+p[i-1][j-1])%1000007;/*p[i-1][j-1]������һ������Ϊ1��*/
				}
            }
        }
        printf("%d\n",p[n][k]);
    }
}


