#include<stdio.h>
#include<string.h>

struct pair
{
	int first;
	int second;
};

char s[5010][5010]; 
int h,w; 
int p[4]={ -1,1,0,0 };
struct pair nq[200010];
int nqfront;
int nqrear;
struct pair q[200010];
int qfront;
int qrear;

int bfs() 
{    
	int res=0;    
	char t;    
	nq[nqrear].first=0;
	nq[nqrear].second=0;
	nqrear=(nqrear+1)%200000;  
	while(nqfront!=nqrear)    
	{        
		t=s[nq[nqfront].first][nq[nqfront].second];        
		res++;        
		while(nqfront!=nqrear)
		{
			q[qrear].first=nq[nqfront].first;
			q[qrear].second=nq[nqfront].second;
			qrear=(qrear+1)%200000;
			s[nq[nqfront].first][nq[nqfront].second]='.';
			nqfront=(nqfront+1)%200000;  
		}  
		while(qfront!=qrear)        
		{            
			int x=q[qfront].first;            
			int y=q[qfront].second;
			qfront=(qfront+1)%200000;
			int i;
			for(i=0;i<4;i++)            
			{                
				int fx=x+p[i];                
				int fy=y+p[3-i];                
				if(fx<0||fx>=h)
				{
					continue;  
				}         
				if(fy<0||fy>=w) 
				{
					continue; 
				}      
				if(s[fx][fy]=='.')
				{
					continue;
				}               
				if(s[fx][fy]!=t)                
				{                    
					nq[nqrear].first=fx;
					nq[nqrear].second=fy;
					nqrear=(nqrear+1)%200000;
					continue;                
				}
				q[qrear].first=fx;
				q[qrear].second=fy;
				qrear=(qrear+1)%200000;
				s[fx][fy]='.';            
			}        
		}    
	}    
	return res; 
} 

int main() 
{       
	scanf("%d%d",&h,&w);
	int i;    
	for(i=0;i<h;++i)    
	{        
		scanf("%s",s[i]);    
	}    
	printf("%d",bfs());    
	return 0; 
}

