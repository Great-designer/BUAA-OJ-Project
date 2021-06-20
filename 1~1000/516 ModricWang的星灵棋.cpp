#include<stdio.h>
#include<string.h>

#include<set>

using namespace std; 

set<unsigned int> vis[5];

bool win[171];

struct State
{
	unsigned char row[4],col[4];
	unsigned char left,right;
	unsigned char rc[2][2];
	short step,turn;
};

bool putChess(struct State *s,const int r,const int c,unsigned char p)
{
	unsigned char pl2r=p<<2*r,pl2c=p<<2*c,al2r=~(3<<2*r),al2c=~(3<<2*c);
	s->row[r]&=al2c,s->row[r]|=pl2c;
	if(win[s->row[r]])
	{
		return 1;
	}
	s->col[c]&=al2r,s->col[c]|=pl2r;
	if(win[s->col[c]])
	{
		return 1;
	} 
	if(r==c)
	{
		s->left&=al2c,s->left|=pl2c;
		if(win[s->left])
		{
			return 1;
		}
	}
	if(r+c==3)
	{
		s->right&=al2r,s->right|=pl2r;
		if(win[s->right])
		{
			return 1;
		}
	}
	return 0;
}

struct State q[666666];

int head;
int tail;

bool getChess(int r,int c)
{
	if(r<0||c<0||r>3||c>3)
	{
		return 0;
	}
	else
	{
		return ((unsigned char)(q[head].row[r]>>2*c)&3)==q[head].turn;
	}
}

void before(int first,int second,int kind)
{
	q[tail]=q[head];
	q[tail].rc[first][second]+=kind;
	++q[tail].step; 
}

void after()
{
	if(!vis[q[head].turn+1].count(*(unsigned int*)q[tail].row)) 
	{ 
		vis[q[head].turn+1].insert(*(unsigned int*)q[tail].row); 
		q[tail].turn=3-q[head].turn; 
		tail++;
	} 
}

int main()
{
	struct State src;
	memset(&src,0,sizeof src);
	win[170]=win[85]=1;
	int firstzero=1;
	int r;
	for(r=0;r<4;++r)
	{
		char str[123];
		scanf("%s",str);
		int c;
		for(c=0;c<4;++c)
		{
			switch(str[c])
			{
				case 'B':
					if(putChess(&src,r,c,1))
					{
						puts("0"); 
						return 0;
					} 
					break;
				case 'W':
					if(putChess(&src,r,c,2))
					{
						puts("0");
						return 0;
					} 
					break;
				case 'O':
					if(firstzero)
					{ 
						src.rc[1][0]=r,src.rc[0][0]=c,firstzero=0;
					}
					else
					{ 
						src.rc[1][1]=r,src.rc[0][1]=c;
					}
					break;
			}
		}
	}
	head=0,tail=2;
	q[0]=q[1]=src;
	q[1].turn=2;
	vis[2].insert(*(unsigned int*)src.row);
	vis[3].insert(*(unsigned int*)src.row);
	for(;head!=tail;head++)
	{
		if(getChess(q[head].rc[1][1]-1,q[head].rc[0][1])) 
		{ 
			before(1,1,-1);
			if(putChess(&q[tail],q[tail].rc[1][1],q[head].rc[0][1],0)||putChess(&q[tail],q[head].rc[1][1],q[head].rc[0][1],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][1],q[head].rc[0][1]-1)) 
		{ 
			before(0,1,-1);
			if(putChess(&q[tail],q[head].rc[1][1],q[tail].rc[0][1],0)||putChess(&q[tail],q[head].rc[1][1],q[head].rc[0][1],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][1]+1,q[head].rc[0][1]))
		{ 
			before(1,1,1);
			if(putChess(&q[tail],q[tail].rc[1][1],q[head].rc[0][1],0)||putChess(&q[tail],q[head].rc[1][1],q[head].rc[0][1],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][1],q[head].rc[0][1]+1)) 
		{ 
			before(0,1,1);
			if(putChess(&q[tail],q[head].rc[1][1],q[tail].rc[0][1],0)||putChess(&q[tail],q[head].rc[1][1],q[head].rc[0][1],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		}
		if(getChess(q[head].rc[1][0]-1,q[head].rc[0][0])) 
		{ 
			before(1,0,-1);
			if(putChess(&q[tail],q[tail].rc[1][0],q[head].rc[0][0],0)||putChess(&q[tail],q[head].rc[1][0],q[head].rc[0][0],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][0],q[head].rc[0][0]-1)) 
		{ 
			before(0,0,-1);
			if(putChess(&q[tail],q[head].rc[1][0],q[tail].rc[0][0],0)||putChess(&q[tail],q[head].rc[1][0],q[head].rc[0][0],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][0]+1,q[head].rc[0][0])) 
		{ 
			before(1,0,1);
			if(putChess(&q[tail],q[tail].rc[1][0],q[head].rc[0][0],0)||putChess(&q[tail],q[head].rc[1][0],q[head].rc[0][0],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		} 
		if(getChess(q[head].rc[1][0],q[head].rc[0][0]+1)) 
		{ 
			before(0,0,1);
			if(putChess(&q[tail],q[head].rc[1][0],q[tail].rc[0][0],0)||putChess(&q[tail],q[head].rc[1][0],q[head].rc[0][0],q[head].turn))
			{
				printf("%d",q[tail].step);
				return 0;
			}
			after();
		}
	}
}
