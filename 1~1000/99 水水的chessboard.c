#include<stdio.h>
#include<string.h>

char occur[10][10];

struct pp
{
	int first;
	int second;
};

struct pp que[2020];
int front;
int rear;

char a[2020],b[2020];
int startX,startY,endX,endY;

int nx[8]={1,1,2,2,-1,-1,-2,-2};
int ny[8]={2,-2,1,-1,2,-2,1,-1};

int BFS(int x,int y)
{
	int cur=0,last=1;
	int nlast=1,steps=0;
	front=rear=0;
	struct pp temp;
	temp.first=x;
	temp.second=y;
	que[rear]=temp;
	rear++;
	while(front!=rear)
	{
		struct pp place=que[front];
		front++;
		cur++;
		if(place.first==endX&&place.second==endY)
		{
			return steps;
		}
		occur[place.first][place.second]=1;
		int i;
		for(i=0;i<8;++i)
		{
			int nextx=place.first+nx[i];
			int nexty=place.second+ny[i];
			if(nextx>=1&&nexty<=8&&nexty>=1&&nexty<=8&&!occur[nextx][nexty])
			{
				temp.first=nextx;
				temp.second=nexty;
				que[rear]=temp;
				rear++;
				nlast++;
			}
		}
		if(cur==last)
		{
			last=nlast;
			steps++;
		}
	}
	return -1;
}

int main()
{
	while(~scanf("%s%s",a,b))
	{
		startX=a[0]-'a'+1;
		startY=a[1]-'0';
		endX=b[0]-'a'+1;
		endY=b[1]-'0';
		memset(occur,0,sizeof(occur));
		printf("It takes %d steps to get from %s to %s\n",BFS(startX,startY),a,b);
	}
}
