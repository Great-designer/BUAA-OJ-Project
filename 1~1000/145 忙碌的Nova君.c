#include<stdio.h>
#include<stdlib.h>

int order[10010];

struct node
{
	int start,end;
	int id;
};

struct node act[10010];

int cmp(const void*p1,const void*p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
    return a->end>b->end;
};

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&act[i].start,&act[i].end);
            act[i].id=i+1;
    	}
        qsort(act,n,sizeof(struct node),cmp);
        order[0]=0;
        int number=1;
        for(i=1;i<n;i++)
        {
            if(act[i].start>=act[order[number-1]].end)
            {
            	order[number++]=i;
			}            
        }
        printf("%d\n",number);
    }
}
