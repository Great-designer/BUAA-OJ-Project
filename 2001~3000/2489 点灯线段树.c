#include<stdio.h> 
#include<stdlib.h> 

int l[100005];
int r[100005];
int t[200005][2];

int turn;

int cmp(const void *a,const void *b) 
{ 
	return *(int*)a-*(int*)b; 
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int i;
        int p=0;
        for(i=1;i<=k;i++)/* ����k��L��k��R */ 
        {
            scanf("%d%d",&l[i],&r[i]);
            t[++p][0]=l[i];
            t[p][1]=1;
            t[++p][0]=r[i]+1;/* ���ÿ������L����R+1 */
            t[p][1]=2;
        }
        qsort(t+1,k*2,8,cmp);/* ��С�������� */
        int ans=0;
        for(i=1;i<=k*2;i++)
        {
            if(t[i][1]==1)/* �������L��˵�����뵽��һ�����ط�Χ�� */
            {
                turn++;
            }
            else/* �������R+1��˵���뿪��һ�����صķ�Χ */
            {
                turn--;
            }
            if(turn%2==0)/* ���ı��turnΪż����˵�������ڵ�λ�õ���һ��λ�õĵƶ������� */
            {
                ans+=t[i][0]-t[i-1][0];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
