#include<stdio.h>
#include<string.h>

char mat[5005][5005];
int match[5005];//��¼�к�i��Ů��ѡ���Ů����ţ�δ��ѡ��0
char vis[5005];//ÿ�μ�¼�к�i�Ƿ�ռ����

char Hungary(int x,int n)
{
	int i; 
	for(i=1;i<=n;i++)
	{
		if(mat[x][i]&&!vis[i])//�����������match[i]û�б����β��ұ�����
		{     
			vis[i]=1;
            if(!match[i]||Hungary(match[i],n))//���match[i]û�б�ռ�û����ܰ�ռ��match[i]���˻�һ�����ߣ���·ԭ�����û�б�ռ���򲻻�ִ�к���Ĳ���
			{
                match[i]=x;//��һ����������ִ��Ҫ��match[i]ƥ���x�������ܸ���λ�ó�������Ϊ������ռ�˱��Ů����ƥ�������       
                return 1;
            } 
        }
    }
    return 0;
}

int main()
{
	int n;
    while(scanf("%d",&n)!=EOF)
	{
        memset(mat,0,sizeof(mat));
        memset(match,0,sizeof(match));//match[]�����ŵ����Ѿ�ƥ��õķ����������0��δƥ�� 
        int i;
		for(i=1;i<=n;i++)
		{
			int x;
            scanf("%d",&x);
            if(x!=0)
            {
            	mat[x][i]=1;
			}
        }
        for(i=1;i<=n;i++)
		{
			int x;
            scanf("%d",&x);
            if(x!=0)
            {
            	mat[i][x]=1;
			}
        }
        int ans=0;
        for(i=1;i<=n;i++)//�������㷨������
		{
            memset(vis,0,sizeof(vis));//visÿһ�ζ������е�������Ŷ����Ϊû��������ע������vis[]��match[]���鹦�ܵ����� 
            ans+=Hungary(i,n);//�����ֱ������������ڳ�λ������+1
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
