#include<stdio.h>
#include<string.h>

int r[1007][1007];
char visit[1007];
int pre[1007];
int q[1007];
 
char bfs(int s,int t,int n)//bfsѰ������·���ҵ�����ture
{
    memset(q,0,sizeof(q));
    int front=0;
	int rear=0;
    memset(visit,0,sizeof(visit));
    memset(pre,-1,sizeof(pre));
    pre[s]=s;
    q[rear]=s;//q.push(s);
    rear++;
    visit[s]=1;
    while(rear!=front)//!q.empty()
	{
        int p=q[front];//q.front();
        front++;//q.pop();//��Ϊ�ڵ�������±��1��ʼ,���ڽӾ���洢
        int i;
        for(i=1;i<=n;++i)
		{
            if(r[p][i]>0&&!visit[i])
			{
                visit[i]=1;
                pre[i]=p;
                if(i==t)
                {
                	return 1;
				}
				q[rear]=i;//q.push(i);
    			rear++;
            }
        }
    }
    return 0;
}

int EK(int s,int t,int n)//inc��ʾ����·�����ӵ�����
{
    int maxflow=0;
    while(bfs(s,t,n))//�ӣ�ÿ��ѭ��һ��ʼ��Ҫ��incΪ0x7fffffff
	{
        int inc=0x7fffffff;
        int i;
        for(i=t;i!=s;i=pre[i])
		{
            if(inc>r[pre[i]][i])
			{
                inc=r[pre[i]][i];
            }
        }//����Ҫ���������֮��û�б�ʱȨ��r��ʼ��Ϊ0
        for(i=t;i!=s;i=pre[i])
		{
            r[pre[i]][i]-=inc;
            r[i][pre[i]]+=inc;
        }
        maxflow+=inc;
    }
    return maxflow;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(r,0,sizeof(r));
    int i;
    for(i=0;i<m;++i)
	{
		int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        r[a][b]+=c;//���Ƿ�Ϊ˫��·
        r[b][a]=c;
    }//Ĭ��s=1��t=n
    printf("%d\n",EK(1,n,n));
    return 0;
}
